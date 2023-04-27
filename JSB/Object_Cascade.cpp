#pragma once
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "SoundMgr.h"
#include "EventMgr.h"

#include "Object_Cascade.h"
#include "Object_Firework.h"
#include "Function_WindowBounce.h"
#include "Object_Starfall.h"

#include "math.h"

int c_colorPalete[] = {BLUE, DARK_BLUE, DARK_VIOLET, VIOLET, DARK_SKYBLUE, GRAY };
extern bool bg_FlickStatement;

void Object_InitCascade(Object* obj) {
	obj->name = "■";
	obj->background = BLACK;
	obj->foreground = VIOLET;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateCascade;
	obj->Object_Render = Object_RenderCascade;
}


void Object_UpdateCascade(Object* obj) {
	
	obj->time += TimeMgr_deltaTime;

	if (obj->value1 == 0)
	{
		obj->value1++;
		SoundMgr_PlaySound(CASCCADE);
		EventMgr_AddObject(Object_InitBackgroundFlicker, 0, 0, 0);
	}
	
	else if (obj->value1 == 1) // 1페이즈 (원 + 비)
	{ 
		obj->value1++;
		
		_beginthreadex(NULL, 0, CircleDispensorThread, NULL, 0, NULL);
		_beginthreadex(NULL, 0, RainDispensorThread, NULL, 0, NULL);	
	}

	
	else if (obj->value1 == 2) //2페이즈 (원 + 직선)
	{	
		if(obj->value2 ==0 && obj->time > 14500 ) //직선 그리기
		{
			obj->value2++;
			EventMgr_AddObject_value(Object_InitStraight, 10, 32, 10000, 200, RED);
		}

		else if (obj->value2 == 1 && obj->time > 15600) 
		{
			obj->value2++;
			EventMgr_AddObject_value(Object_InitStraight, 53, 32, 10000, 200, RED);
		}

		else if (obj->value2 == 2 && obj->time > 18300)
		{
			obj->value2++;
			EventMgr_AddObject_value(Object_InitStraight, 6, 32, 10000, 200, RED);
		}

		else if (obj->value2 == 3 && obj->time > 20000)
		{
			obj->value2++;
			EventMgr_AddObject_value(Object_InitStraight, 50, 32, 10000, 200, RED);		
		}

		else if (obj->value2 == 4 && obj->time > 22000)
		{
			obj->value2++;
			EventMgr_AddObject_value(Object_InitStraight, 8, 32, 10000, 200, RED);
		}

		else if (obj->value2 == 5 && obj->time > 23800)
		{
			obj->value2++;
			EventMgr_AddObject_value(Object_InitStraight, 54, 32, 10000, 200, RED);
		}

		else if (obj->value2 == 6 && obj->time > 26200)
		{
			obj->value2++;
			EventMgr_AddObject_value(Object_InitStraight, 11, 30, 10000, 200, RED);
		
			obj->value2 = 0;
			obj->value1++;	
		}
	}


	else if (obj->value1 == 3) //꽃
	{
		if (obj->value2 == 0 && obj->time > 29500) 
		{
			obj->value2++;
			for (int i = 0; i < 9; i++) 
			{
				DrawCircleWithCenter(0, 0, 18, 0 + 40*i, 4, DARK_GRAY, 90, 25, 900, false);
			}
		}
		 
		else if (obj->value2 == 1 && obj->time > 30100)
		{
			DrawCircleWithCenter(0, 0, 18, 0, 3, c_colorPalete[rand() % 6], 90, 30, 600, 2);
			obj->value2++;
		}

		else if (obj->value2 == 2 && obj->time > 30130)
		{
			DrawCircleWithCenter(0, 0, 18, 40, 3, c_colorPalete[rand() % 6], 90, 30, 600, 2);
			obj->value2++;
		}

		else if (obj->value2 == 3 && obj->time > 30160)
		{
			DrawCircleWithCenter(0, 0, 18, 80, 3, c_colorPalete[rand() % 6], 90, 30, 600, 2);
			obj->value2++;
		}

		else if (obj->value2 == 4 && obj->time > 30190)
		{
			DrawCircleWithCenter(0, 0, 18, 120, 3, c_colorPalete[rand() % 6], 90, 30, 600, 2);
			obj->value2++;
		}

		else if (obj->value2 == 5 && obj->time > 30220)
		{
			DrawCircleWithCenter(0, 0, 18, 160, 3, c_colorPalete[rand() % 6], 90, 30, 600, 2);
			obj->value2++;
		}

		else if (obj->value2 == 6 && obj->time > 30250)
		{
			DrawCircleWithCenter(0, 0, 18, 200, 3, c_colorPalete[rand() % 6], 90, 30, 600, 2);
			obj->value2++;
		}

		else if (obj->value2 == 7 && obj->time > 30280)
		{
			DrawCircleWithCenter(0, 0, 18, 240, 3, c_colorPalete[rand() % 6], 90, 30, 600, 2);
			obj->value2++;
		}

		else if (obj->value2 == 8 && obj->time > 30310)
		{
			DrawCircleWithCenter(0, 0, 18, 280, 3, c_colorPalete[rand() % 6], 90, 30, 600, 2);
			obj->value2++;
		}

		else if (obj->value2 == 9 && obj->time > 30340)
		{
			DrawCircleWithCenter(0, 0, 18, 320, 3, c_colorPalete[rand() % 6], 90, 30, 600, 2);
			obj->value2++;
		}

		else if (obj->value2 == 10 && obj->time > 31350) //도
		{
			DrawCircleWithCenter(0, 0, 15, 100, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 280, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 11 && obj->time > 31650) //솔
		{
			DrawCircleWithCenter(0, 0, 15, 85, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 175, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 12 && obj->time > 31900) //레
		{
			DrawCircleWithCenter(0, 0, 15, 0, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 180, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 13 && obj->time > 32200) //미
		{
			DrawCircleWithCenter(0, 0, 15, 65, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 245, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 14 && obj->time > 32700) //라
		{
			DrawCircleWithCenter(0, 0, 15, 30, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 210, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 15 && obj->time > 32900) //도
		{
			DrawCircleWithCenter(0, 0, 15, 15, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 195, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 16 && obj->time > 33500) //시
		{
			c_SpinData* spinData = (c_SpinData*)malloc(sizeof(c_SpinData));
			spinData->angle_dx = 3;	spinData->coolTime = 20; spinData->emissionCount = 9; spinData->startAngle = 0;
			_beginthreadex(NULL, 0, SpiningCircleThread, spinData, 0, NULL);

			obj->value2++;
		}
		////////////////////////////////////////////////////////////////////
		else if (obj->value2 == 17 && obj->time > 35370) //도
		{
			DrawCircleWithCenter(0, 0, 15, 100, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 280, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 18 && obj->time > 35600) //라
		{
			DrawCircleWithCenter(0, 0, 15, 130, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 310, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 19 && obj->time > 36000) //솔
		{
			DrawCircleWithCenter(0, 0, 15, 40, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 220, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 20 && obj->time > 36480) //미
		{
			DrawCircleWithCenter(0, 0, 15, 85, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 265, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 21 && obj->time > 36900) //라
		{
			DrawCircleWithCenter(0, 0, 15, 0, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 180, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}
		
		else if (obj->value2 == 22 && obj->time > 37230) //시
		{
			DrawCircleWithCenter(0, 0, 15, 25, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 205, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 23 && obj->time > 37480) //도
		{
			c_SpinData* spinData = (c_SpinData*)malloc(sizeof(c_SpinData));
			spinData->angle_dx = -3;	spinData->coolTime = 20; spinData->emissionCount = 9; spinData->startAngle = 0;
			_beginthreadex(NULL, 0, SpiningCircleThread, spinData, 0, NULL);
			obj->value2++;
		}
		//////////////////////////////////////////////////////////
		
		else if (obj->value2 == 24 && obj->time > 38980) //도
		{
			DrawCircleWithCenter(0, 0, 15, 30, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 210, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 25 && obj->time > 39330) //솔
		{
			DrawCircleWithCenter(0, 0, 15, 10, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 190, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 26 && obj->time > 39800) //레
		{
			DrawCircleWithCenter(0, 0, 15, 90, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 270, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 27 && obj->time > 40030) //미
		{
			DrawCircleWithCenter(0, 0, 15, 150, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 320, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 28 && obj->time > 40500) //라
		{
			DrawCircleWithCenter(0, 0, 15, 00, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 180, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 29 && obj->time > 40700) //도
		{
			DrawCircleWithCenter(0, 0, 50, 00, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 230, 180, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}
////////////////////////////////////////////////////////////
		else if (obj->value2 == 30 && obj->time > 41230) //파
		{
			c_SpinData* spinData = (c_SpinData*)malloc(sizeof(c_SpinData));
			spinData->angle_dx = -3;	spinData->coolTime = 20; spinData->emissionCount = 9; spinData->startAngle = 0;
			_beginthreadex(NULL, 0, SpiningCircleThread, spinData, 0, NULL);
			obj->value2++;
		}

		else if (obj->value2 == 31 && obj->time > 43100) //미~~ 솔시
		{
			c_SpinData* spinData = (c_SpinData*)malloc(sizeof(c_SpinData));
			spinData->angle_dx = 3;	spinData->coolTime = 20; spinData->emissionCount = 9; spinData->startAngle = 0;
			_beginthreadex(NULL, 0, SpiningCircleThread, spinData, 0, NULL);
			obj->value2++;
		}

		else if (obj->value2 == 32 && obj->time > 44980) //도
		{
			c_SpinData* spinData = (c_SpinData*)malloc(sizeof(c_SpinData));
			spinData->angle_dx = 3;	spinData->coolTime = 20; spinData->emissionCount = 9; spinData->startAngle = 0;
			_beginthreadex(NULL, 0, SpiningCircleThread, spinData, 0, NULL);
			obj->value2++;
		}
////////////////////////////////////////////////////////////////////
		else if (obj->value2 == 33 && obj->time > 46590) //도
		{
			DrawCircleWithCenter(0, 0, 15, 100, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 280, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			_beginthreadex(NULL, 0, RainDispensorThread2, NULL, 0, NULL);
			obj->value2++;
		}

		else if (obj->value2 == 34 && obj->time > 46760) //솔
		{
			DrawCircleWithCenter(0, 0, 15, 85, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 175, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 35 && obj->time > 47300) //레
		{
			DrawCircleWithCenter(0, 0, 15, 90, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 270, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 36 && obj->time > 47565) //미
		{
			DrawCircleWithCenter(0, 0, 15, 150, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 330, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 37 && obj->time > 47950) //라
		{
			DrawCircleWithCenter(0, 0, 15, 30, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 210, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 38 && obj->time > 48280) //도
		{
			DrawCircleWithCenter(0, 0, 15, 15, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 195, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 39 && obj->time > 48720) //시
		{
			c_SpinData* spinData = (c_SpinData*)malloc(sizeof(c_SpinData));
			spinData->angle_dx = -3;	spinData->coolTime = 20; spinData->emissionCount = 9; spinData->startAngle = 0;
			_beginthreadex(NULL, 0, SpiningCircleThread, spinData, 0, NULL);
			obj->value2++;
		}
		//////////////////////////////////////////////////////////

		else if (obj->value2 == 40 && obj->time > 50380) //미
		{
			DrawCircleWithCenter(0, 0, 15, 100, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 280, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 41 && obj->time > 50600) //시
		{
			DrawCircleWithCenter(0, 0, 15, 130, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 310, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 42 && obj->time > 51020) //솔
		{
			DrawCircleWithCenter(0, 0, 15, 40, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 220, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 43 && obj->time > 51520) //미
		{
			DrawCircleWithCenter(0, 0, 15, 85, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 265, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 44 && obj->time > 52000) //라
		{
			DrawCircleWithCenter(0, 0, 15, 0, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 180, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 45 && obj->time > 52230) //도
		{
			DrawCircleWithCenter(0, 0, 15, 25, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 205, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 46 && obj->time > 52500) //레
		{
			c_SpinData* spinData = (c_SpinData*)malloc(sizeof(c_SpinData));
			spinData->angle_dx = -3;	spinData->coolTime = 20; spinData->emissionCount = 9; spinData->startAngle = 0;
			_beginthreadex(NULL, 0, SpiningCircleThread, spinData, 0, NULL);
			obj->value2++;
		}
///////////////////////////////////////////////////////////////////

		else if (obj->value2 == 47 && obj->time > 54140) //도
		{
			DrawCircleWithCenter(0, 0, 15, 30, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 210, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 48 && obj->time > 54380) //시
		{
			DrawCircleWithCenter(0, 0, 15, 10, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 190, 3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 49 && obj->time > 55290) //솔
		{
			DrawCircleWithCenter(0, 0, 15, 90, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 270, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 50 && obj->time > 56010) //시
		{
			DrawCircleWithCenter(0, 0, 15, 150, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			DrawCircleWithCenter(0, 0, 15, 320, -3, c_colorPalete[rand() % 6], 80, 50, 600, true);
			obj->value2++;
		}

		else if (obj->value2 == 51 && obj->time > 56450) //도
		{
			c_SpinData* spinData = (c_SpinData*)malloc(sizeof(c_SpinData));
			spinData->angle_dx = -3;	spinData->coolTime = 20; spinData->emissionCount = 9; spinData->startAngle = 0;
			_beginthreadex(NULL, 0, SpiningCircleThread, spinData, 0, NULL);
			obj->value2++;
		}

		else if (obj->value2 == 52 && obj->time > 57050) //~
		{
			c_SpinData* spinData = (c_SpinData*)malloc(sizeof(c_SpinData));
			spinData->angle_dx = -3;	spinData->coolTime = 20; spinData->emissionCount = 9; spinData->startAngle = 15;
			_beginthreadex(NULL, 0, SpiningCircleThread, spinData, 0, NULL);
			obj->value2++;
		}

		else if (obj->value2 == 53 && obj->time > 57650) //~
		{
			c_SpinData* spinData = (c_SpinData*)malloc(sizeof(c_SpinData));
			spinData->angle_dx = -3;	spinData->coolTime = 20; spinData->emissionCount = 9; spinData->startAngle = 30;
			_beginthreadex(NULL, 0, SpiningCircleThread, spinData, 0, NULL);
			
			obj->value1++;
			obj->value2 = 0;
		}
	}


	else if (obj->value1 == 4) //하이라이트
	{
		if (obj->value2 == 0 && obj->time > 60200) //미
		{
			EventMgr_AddObject(Object_InitFirework, 30, 15, 1500);
			_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
			bg_FlickStatement = true;
			for (int i = 0; i < 9; i++)
			{
				DrawCircleWithCenter(0, 0, 7, 0+ 40*i, 6, c_colorPalete[rand() % 6], 75, 12, 600, 2);
			}

			obj->value2++;
		}
	
		else if (obj->value2 == 1 && obj->time > 60900) //도- 솔
		{
			EventMgr_AddObject(Object_InitFirework, 30, 15, 1500);
			_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
			bg_FlickStatement = true;
			for (int i = 0; i < 9; i++)
			{
				DrawCircleWithCenter(0, 0, 9, 20 + 40 * i, -6, c_colorPalete[rand() % 6], 75, 18, 1200, 2);
			}
			obj->value2++;
		}

		else if (obj->value2 == 2 && obj->time > 61590) //미 (라솔미도)
		{
			EventMgr_AddObject(Object_InitFirework, 30, 15, 1500);
			_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
			bg_FlickStatement = true;
			for (int i = 0; i < 9; i++)
			{
				DrawCircleWithCenter(0, 0, 28, 40 + 40 * i, -3, c_colorPalete[rand() % 6], 50, 26, 1200, 2);
			}
			obj->value2++;
		}
	
		else if (obj->value2 == 3 && obj->time > 63940) //라
		{
			EventMgr_AddObject(Object_InitFirework, 30, 15, 1500);
			_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
			bg_FlickStatement = true;
			for (int i = 0; i < 9; i++)
			{
				DrawCircleWithCenter(0, 0, 14, 0 + 40 * i, 3, c_colorPalete[rand() % 6], 75, 12, 700, true);
			}
			obj->value2++;
		}

		else if (obj->value2 == 4 && obj->time > 64640) //미
		{
			EventMgr_AddObject(Object_InitFirework, 30, 15, 1500);
			_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
			bg_FlickStatement = true;
			for (int i = 0; i < 9; i++)
			{
				DrawCircleWithCenter(0, 0, 16, 20 + 40 * i, -3, c_colorPalete[rand() % 6], 75, 18, 650, true);
			}
			obj->value2++;
		}

		else if (obj->value2 == 5 && obj->time > 65360) //도 (레미도)
		{
			EventMgr_AddObject(Object_InitFirework, 30, 15, 1500);
			_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
			for (int i = 0; i < 9; i++)
			{
				DrawCircleWithCenter(0, 0, 16, 40 + 40 * i, -3, c_colorPalete[rand() % 6], 75, 32, 650, true);
			}
			bg_FlickStatement = true;
			obj->value2++;
		}
		
		////////////////////////////////////////////////////////////////////
		
		else if (obj->value2 == 6 && obj->time > 67670) //미
		{
			EventMgr_AddObject(Object_InitFirework, 30, 15, 1500);
			_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
			bg_FlickStatement = true;
			obj->value2++;
		}

		else if (obj->value2 == 7 && obj->time > 68370) //(도솔) 화면만
		{
			EventMgr_AddObject(Object_InitFirework, 30, 15, 1500);
			_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
			bg_FlickStatement = true;
			for (int i = 0; i < 9; i++)
			{
				DrawCircleWithCenter(0, 0, 9, 20 + 40 * i, -6, c_colorPalete[rand() % 6], 75, 18, 1200, 2);
			}
			obj->value2++;
		}

		else if (obj->value2 == 8 && obj->time > 69090) //미 (라솔미도)
		{
			EventMgr_AddObject(Object_InitFirework, 30, 15, 1500);
			_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
			bg_FlickStatement = true;
			for (int i = 0; i < 9; i++)
			{
				DrawCircleWithCenter(0, 0, 28, 40 + 40 * i, -3, c_colorPalete[rand() % 6], 50, 26, 1200, 2);
			}
			obj->value2++;
		}

		else if (obj->value2 == 9 && obj->time > 71400) //라
		{
			EventMgr_AddObject(Object_InitFirework, 30, 15, 1500);
			_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
			bg_FlickStatement = true;
			obj->value2++;
		}

		else if (obj->value2 == 10 && obj->time > 72140) //미 
		{
			EventMgr_AddObject(Object_InitFirework, 30, 15, 1500);
			_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
			bg_FlickStatement = true;
			for (int i = 0; i < 9; i++)
			{
				DrawCircleWithCenter(0, 0, 16, 20 + 40 * i, -3, c_colorPalete[rand() % 6], 75, 18, 650, true);
			}
			obj->value2++;
		}

		else if (obj->value2 == 11 && obj->time > 72850) //도
		{
			EventMgr_AddObject(Object_InitFirework, 30, 15, 1500);
			_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
			bg_FlickStatement = true;
			for (int i = 0; i < 9; i++)
			{
				DrawCircleWithCenter(0, 0, 35, 40 + 40 * i, -3, c_colorPalete[rand() % 6], 50, 26, 1200, true);
			}

			obj->value1++;
		}
	}

	else if (obj->value1 == 5 && obj->time > 75000) //아웃트로
	{
		obj->value1++;
		obj->time = 0;
		obj->fvalue1 = 1.f;
	}

	else if (obj->value1 == 6 && obj->time > 350 && obj->fvalue1 >= 0.05) //음악 줄이기
	{
		obj->fvalue1 -= 0.05f;
		obj->time -= 350;
		SoundMgr_AdjustVolume(obj->fvalue1);
		EventMgr_AddObject(Object_InitStarfall, rand() % 60, -4, 2000);
	}

	else if (obj->value1 == 6 && obj->fvalue1 < 0.05)
	{ 
		SoundMgr_StopSound();
		SoundMgr_AdjustVolume(1);
		// 게임끝
		EventMgr_ChangeScene(SCENE_CLEAR);
	}
}

void Object_RenderCascade(Object* obj) {
	/*
	char str[20];
	sprintf(str, "%llu", obj->time);
	RenderMgr_Draw(0, 0, str, WHITE, BLACK);
	*/
}

