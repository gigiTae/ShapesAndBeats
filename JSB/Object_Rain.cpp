#pragma once

#include "pch.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "EventMgr.h"
#include "SceneMgr.h"
#include "Scene.h"

#include "Object_Cascade.h"

void Object_InitRain(Object* obj)
{
	obj->name = "●"; //* ● ◎ ⊙ ◈ ■ ▣ ▒ ㅁⅹ × ＋ ¤ ο ｏ ◆
	obj->background = 1;
	obj->foreground = 1;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateRain;
	obj->Object_Render = Object_RenderRain;
}

#define timer obj->background //떨어지는 속도 조절을 위한 타이머
#define color obj->value1  
#define direction obj->value2 //0이면 위에서 아래, //1이면 오른쪽에서 왼쪽
#define RAIN_DOWNSPEED 80
#define RAIN_PROGRESS_SPEED 30

extern int c_colorPalete[];

void Object_UpdateRain(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	timer += (int)TimeMgr_deltaTime;

	if (timer >= RAIN_DOWNSPEED )
	{
		if (RAIN_PROGRESS_SPEED * 5 < obj->time) 
		{
			if (obj->value2 == 0) obj->y++;
			else obj->x--;
		}
		timer -= RAIN_DOWNSPEED;
	}
} 
 

void Object_RenderRain(Object* obj)
{	
	//떨어지기전 미리 경고
	if (RAIN_PROGRESS_SPEED * 3 > obj->time)
	{
		RenderMgr_Draw(obj->x, obj->y, obj->name, GRAY, WHITE);
	}

	if (RAIN_PROGRESS_SPEED * 3< obj->time && obj->time < RAIN_PROGRESS_SPEED * 4)
	{
		RenderMgr_Draw(obj->x, obj->y, obj->name, color, DARK_GRAY);
	}

	//떨어지는 부분
	if (RAIN_PROGRESS_SPEED *4 < obj->time)
	{
		RenderMgr_DrawC(obj->x, obj->y, 1, obj->name, color, BLACK);
	}
}

//위에서 떨어지는 비를 시간 간격에 따라 생성시키는 스레드
unsigned RainDispensorThread(void* arg) {

	for (int i = 0; i < 25; i++)
	{
		if (SceneMgr_curScene->objPlayer == nullptr) break;
		EventMgr_AddObject_value(Object_InitRain, rand() % 58 + 1, 0, 3000, c_colorPalete[rand() % 6], 0);
		Sleep(600);
	}
	return 0;
}

//진행방향 ( 오른쪽 -> 왼쪽 ) 비를 시간 간격에 따라 생성시키는 스레드
unsigned RainDispensorThread2(void* arg) {

	for (int i = 0; i < 20; i++)
	{
		if (SceneMgr_curScene->objPlayer == nullptr) break;
		EventMgr_AddObject_value(Object_InitRain, 60, rand() % 26 + 2, 6000, c_colorPalete[rand() % 6], 1);
		Sleep(500);
	}
	return 0;
}