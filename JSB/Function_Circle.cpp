#pragma once
#define _USE_MATH_DEFINES

#include "pch.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "EventMgr.h"
#include "SceneMgr.h"
#include "Scene.h"

#include "Object_Cascade.h"
#include "math.h"

extern int c_colorPalete[];



//�� ������ ������� ���� �׷���
//x,y�� ������ ��ǥ�� �־�� ��
//õ�忡�� �Ѹ� ��, angle_dx�� ����� ��� startAngle�� 0~180 // ������ ��� 180~360�� ��쿡�� ȭ�鿡 ��µ�.
void DrawCircleWithCenter(int CenterX, int CenterY, double r, double startAngle, double angle_dx, int color, int drawSpeed, int drawCount, int lifeTime, int isCollider)
{
	double startRadian = startAngle * M_PI / 180.0;
	int newCenterX = CenterX + (int)round(r * cos(startRadian));
	int newCenterY = CenterY + (int)round(r * sin(startRadian));
	double newAngle = startAngle + 180;

	//CircleData* data = new CircleData{ newCenterX, newCenterY, r, newAngle, angle_dx, color, drawSpeed, drawCount, lifeTime, isCollider };
	CircleData* data = (CircleData*)malloc(sizeof(CircleData));
	// �����Ҵ��� �����ϴ� ����ó�� ���ִ°��� ���� !-> malloc�� ���а���
	assert(data);
	data->centerX = newCenterX;
	data->centerY = newCenterY;
	data->r = r;
	data->angle = newAngle;
	data->angle_dx = angle_dx;
	data->color = color;
	data->drawSpeed = drawSpeed;
	data->drawCount = drawCount;
	data->lifeTime = lifeTime;
	data->isCollider = isCollider;

	_beginthreadex(NULL, 0, CircleThread, data, 0, NULL);
}

//���� ��ǥ ���� ����ؼ� ���� �ѷ��ִ� ������ 
unsigned CircleThread(void* arg) {
	CircleData* args = (CircleData*)arg;

	for (int i = 0; i < args->drawCount; i++)
	{
		args->angle += args->angle_dx;
		double radian = args->angle * M_PI / 180.0;
		int x = args->centerX + (int)round(args->r * cos(radian));
		int y = args->centerY + (int)round(args->r * sin(radian));


		if (SceneMgr_curScene->objPlayer == nullptr) break;
		if (args->isCollider == 1)  //�浹�ϴ� �׸�, �Ķ���
		{
			EventMgr_AddObject_value(Object_InitJustSquare, xConversion(x), yConversion(y), args->lifeTime, args->drawSpeed, args->lifeTime);
		}
		else if(args->isCollider == 0)//���ϰ�� �׸�(�浹 x)
		{
			EventMgr_AddObject(Object_InitNCSquare, xConversion(x), yConversion(y), args->lifeTime);
		}
		else //�浹�ϴ� �׸�, �����
		{
			EventMgr_AddObject_value(Object_InitJustSquare2, xConversion(x), yConversion(y), args->lifeTime, args->drawSpeed, args->lifeTime);
		}
		Sleep(args->drawSpeed);
	}

	free(args); 
	return 0;
}

//õ�� �κ� ���� ��ġ�� ���� ������ ������Ű�� ������
unsigned CircleDispensorThread(void* arg) {
	
	for (int i = 0; i < 35; i++)
	{
		if (SceneMgr_curScene->objPlayer == nullptr) break;
		int angle = rand() % 360;
		int dx = 4; 
		if (angle > 180) dx = -4;

		DrawCircleWithCenter((rand() % 50) - 50, (rand() % 8) + 15, (rand() % 10) + 20, angle, dx, c_colorPalete[rand() % 6], 70, 70, 1500, true);
		Sleep(800);
	}
	return 0;
}

//�� ���� �߽����� ������� ���� �׸��� ������
unsigned SpiningCircleThread(void* arg) {
	c_SpinData* args = (c_SpinData*)arg;
	double angleToSum = 360.0 / args->emissionCount;

	for (int i = 0; i < args->emissionCount; i++) {
		if (SceneMgr_curScene->objPlayer == nullptr) break;
		DrawCircleWithCenter(0, 0, 15, args->startAngle + angleToSum*i, args->angle_dx, c_colorPalete[rand() % 6], 80, 50, 600, 2);
		
		Sleep(args->coolTime);
	}

	free(args); 
	return 0;
}

//������ xy��ǥ�� �ܼ� xy��ǥ�� ��ȯ
int xConversion(int x) {
	return x + 30;
}

int yConversion(int y) {
	return -1 * (y - 15);
}