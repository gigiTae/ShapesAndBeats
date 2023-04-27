#pragma once

#include "pch.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "Object_Cascade.h"

void Object_InitJustSquare2(Object* obj)
{
	obj->name = "��"; //* �� �� �� �� �� �� �� ���� �� �� �� �� ��
	obj->background = 1;
	obj->foreground = 1;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateJustSquare2;
	obj->Object_Render = Object_RenderJustSquare2;
}

static int sq_colorPalete[] = { GRAY, YELLOW, DARK_YELLOW,RED,DARK_RED,DARK_VIOLET }; //���->����

static int sq_PalletIndex = 0;

#define flickeringTime obj->value1 //�����̴� �ð�
#define lifeTime obj->value2
#define flicker obj->background //������ ����, 1�� -1�� bool���� ǥ��.
#define isflickering obj->foreground //������ �ð��� ����Ǹ� 0�̵Ǿ� ������ ����

void Object_UpdateJustSquare2(Object* obj)
{
	obj->time += TimeMgr_deltaTime;

	if (obj->time >= flickeringTime)
	{


		isflickering = 0;
	}
}


void Object_RenderJustSquare2(Object* obj)
{
	if (isflickering == 1)
	{
		if (flicker == 1)
		{
			RenderMgr_Draw(obj->x, obj->y, obj->name, WHITE, WHITE);
		}
		else
		{
			RenderMgr_Draw(obj->x, obj->y, obj->name, YELLOW, BLACK);
		}

		flicker *= -1;
	}
	else
	{
		if (lifeTime * 5 / 6 < obj->time) RenderMgr_DrawC(obj->x, obj->y, 1, "*", sq_colorPalete[5], BLACK);
		else if (lifeTime * 4 / 6 < obj->time) RenderMgr_DrawC(obj->x, obj->y, 1, "*", sq_colorPalete[4], BLACK);
		else if (lifeTime * 3 / 6 < obj->time) RenderMgr_DrawC(obj->x, obj->y, 1, "*", sq_colorPalete[3], BLACK);
		else if (lifeTime * 2 / 6 < obj->time) RenderMgr_DrawC(obj->x, obj->y, 1, "*", sq_colorPalete[2], BLACK);
		else if (lifeTime * 1 / 6 < obj->time) RenderMgr_DrawC(obj->x, obj->y, 1, "*", sq_colorPalete[1], BLACK);
		else								   RenderMgr_DrawC(obj->x, obj->y, 1, "*", sq_colorPalete[0], BLACK);
	}
}