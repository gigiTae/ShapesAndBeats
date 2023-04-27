#include "pch.h"
#include "Object_Higher.h"
#include "Object.h"
#include "TimgMgr.h"
#include "SoundMgr.h"
#include "EventMgr.h"
#include "RenderMgr.h"
#include "Object_Matrix.h"
#include "Object_Line.h"
#include "Object_Compresion.h"
#include "Object_BoxMonster.h"
#include "Object_FlipBox.h"
#include "Object_Beam.h"
#include "Object_Spiral.h"
#include "Object_Santa.h"
#include "Object_Stem.h"
#include "Object_Satellite.h"
#include "Object_Cannon.h"

void Object_InitHigher(Object* obj)
{
	obj->name = "HIGHER";
	obj->background = BLACK;
	obj->foreground = WHITE;
	obj->fvalue1 = 1.f;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateHigher;
	obj->Object_Render = Object_RenderHigher;
}

/// <summary>
/// Hihger 메인 오브젝트로 음악, 패턴생성을 담당
/// value1 값과 시간순서에 따라서 순차적으로 오브젝트 추가
/// </summary>
/// <param name="obj"></param>
void Object_UpdateHigher(Object* obj)
{

	obj->time += TimeMgr_deltaTime;

	if (obj->value1 == 0)
	{
		obj->value1++;
		obj->time = 0;
		SoundMgr_PlaySound(HIGHER);
	}
	else if (obj->time >= 500 && obj->value1 == 1)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 55, 0, 3000);
	}
	else if (obj->time >= 750 && obj->value1 == 2)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 20, 0, 5000);
	}
	else if (obj->time >= 1000 && obj->value1 == 3)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 10, 0, 5000);
	}
	else if (obj->time >= 1500 && obj->value1 == 4)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 27, 0, 5000);
	}
	else if (obj->time >= 2250 && obj->value1 == 5)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 31, 0, 5000);
	}
	else if (obj->time >= 2500 && obj->value1 == 6)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 17, 0, 5000);
	}
	else if (obj->time >= 2750 && obj->value1 == 7)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 6, 0, 5000);
	}
	else if (obj->time >= 3000 && obj->value1 == 8)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 51, 0, 5000);
	}
	else if (obj->time >= 3250 && obj->value1 == 9)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 4, 0, 5000);
	}
	else if (obj->time >= 4250 && obj->value1 == 10)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 42, 0, 5000);
	}
	else if (obj->time >= 4500 && obj->value1 == 11)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 23, 0, 5000);
	}
	else if (obj->time >= 4750 && obj->value1 == 12)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 54, 0, 5000);
	}
	else if (obj->time >= 5000 && obj->value1 == 13)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 14, 0, 5000);
	}
	else if (obj->time >= 6000 && obj->value1 == 14)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 30, 0, 5000);
	}
	else if (obj->time >= 6000 && obj->value1 == 15)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 41, 0, 5000);
	}
	else if (obj->time >= 6250 && obj->value1 == 16)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 1, 0, 5000);
	}
	else if (obj->time >= 6500 && obj->value1 == 17)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 5, 0, 5000);
	}
	else if (obj->time >= 6750 && obj->value1 == 18)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 23, 0, 5000);
	}
	else if (obj->time >= 7000 && obj->value1 == 19)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 45, 0, 5000);
	}
	else if (obj->time >= 8000 && obj->value1 == 20)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 11, 0, 5000);
	}
	else if (obj->time >= 8250 && obj->value1 == 21)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 22, 0, 5000);
	}
	else if (obj->time >= 8500 && obj->value1 == 22)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 37, 0, 5000);
	}
	else if (obj->time >= 8750 && obj->value1 == 23)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 6, 0, 5000);
	}
	else if (obj->time >= 9000 && obj->value1 == 24)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitMatrix, 56, 0, 5000);
	}
	else if (obj->time >= 14710 && obj->value1 == 25)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 0, 0, 10000, 0, GREEN);
	}
	else if (obj->time >= 16700 && obj->value1 == 26)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 0, 0, 10000, 2, 12);
	}
	else if (obj->time >= 18600 && obj->value1 == 27)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 0, 30, 10000, 1, 3);
	}
	else if (obj->time >= 20400 && obj->value1 == 28)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 59, 0, 10000, 3, 13);
	}
	else if (obj->time >= 22350 && obj->value1 == 29)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 0, 0, 10000, 0, YELLOW);
	}
	else if (obj->time >= 24150 && obj->value1 == 30)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 0, 0, 10000, 0, 11);
	}
	else if (obj->time >= 25020 && obj->value1 == 31)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 0, 0, 10000, 2, YELLOW);
	}
	else if (obj->time >= 25980 && obj->value1 == 32)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 59, 0, 10000, 3, 5);
	}
	else if (obj->time >= 28000 && obj->value1 == 33)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 59, 0, 10000, 3, 4);
	}
	else if (obj->time >= 29640 && obj->value1 == 34)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 0, 0, 10000, 0, 2);
		EventMgr_AddObject_value(Object_InitLine, 0, 30, 10000, 1, 7);
	}
	else if (obj->time >= 31400 && obj->value1 == 35)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 0, 0, 10000, 2, 13);
		EventMgr_AddObject_value(Object_InitLine, 59, 0, 10000, 3, 3);
	}
	else if (obj->time >= 33350 && obj->value1 == 36 && obj->value2 == 0)
	{
		obj->value2++;
		EventMgr_AddObject_value(Object_InitLine, 0, 29, 10000, 1, DARK_RED);
	}
	else if (obj->time >= 35200 && obj->value1 == 36)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 0, 0, 10000, 0, 12);
	}
	else if (obj->time >= 37030 && obj->value1 == 37)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLine, 0, 0, 10000, 2, 14);
		EventMgr_AddObject_value(Object_InitLine, 0, 30, 10000, 1, 7);
	}
	else if (obj->time >= 40000 && obj->value1 == 38)
	{
		++obj->value1;
		EventMgr_AddObject(Object_InitBeam, 0, 0, 19000);
		for (int i = 0; i < 50; ++i)
			EventMgr_AddObject(Object_InitSpiral, 0, -i * 2, 20000);
	}
	else if (obj->time >= 60000 && obj->value1 == 39)
	{
		++obj->value1;

		EventMgr_AddObject_value(Object_InitStem, 0, 5, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitStem, 0, 15, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitStem, 0, 25, 2000, 0, 0);
	}
	else if (obj->time >= 61600 && obj->value1 == 40)
	{
		++obj->value1;

		EventMgr_AddObject_value(Object_InitStem, 15, 0, 2000, 0, 2);
		EventMgr_AddObject_value(Object_InitStem, 30, 0, 2000, 0, 2);
		EventMgr_AddObject_value(Object_InitStem, 45, 0, 2000, 0, 2);
	}
	else if (obj->time >= 63500 && obj->value1 == 41)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitStem, 59, 10, 2000, 0, 4);
		EventMgr_AddObject_value(Object_InitStem, 59, 20, 2000, 0, 4);
	}

	else if (obj->time >= 65200 && obj->value1 == 42)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitStem, 15, 0, 2000, 0, 2);
		EventMgr_AddObject_value(Object_InitStem, 30, 0, 2000, 0, 2);
		EventMgr_AddObject_value(Object_InitStem, 45, 0, 2000, 0, 2);
	}
	else if (obj->time >= 67000 && obj->value1 == 43)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitStem, 59, 10, 2000, 0, 4);
		EventMgr_AddObject_value(Object_InitStem, 59, 20, 2000, 0, 4);
		EventMgr_AddObject_value(Object_InitStem, 0, 5, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitStem, 0, 15, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitStem, 0, 25, 2000, 0, 0);
	}
	else if (obj->time >= 74620 && obj->value1 == 44)//800
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitCannon, 10, 29, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitCannon, 40, 0, 2000, 1, 0);
	}
	else if (obj->time >= 75720 && obj->value1 == 45) // 수정중
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitCannon, 40, 29, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitCannon, 10, 0, 2000, 1, 0);
	}
	else if (obj->time >= 76620 && obj->value1 == 46)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitCannon, 10, 29, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitCannon, 40, 0, 2000, 1, 0);
	}
	else if (obj->time >= 77420 && obj->value1 == 47)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitCannon, 40, 29, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitCannon, 10, 0, 2000, 1, 0);
	}
	else if (obj->time >= 78020 && obj->value1 == 48)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitCannon, 0, 15, 2000, 2, 0);
	}
	else if (obj->time >= 78500 && obj->value1 == 49)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitStem, 0, 0, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitStem, -2, 2, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitStem, -4, 4, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitStem, -6, 6, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitStem, -8, 8, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitStem, -10, 10, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitStem, -12, 12, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitStem, -14, 14, 2000, 0, 0);

		EventMgr_AddObject_value(Object_InitCannon, 59, 15, 2000, 2, 0);
	}
	else if (obj->time >= 80000 && obj->value1 == 50)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitCannon, 10, 29, 2000, 0, 0);
	}
	else if (obj->time >= 81000 && obj->value1 == 51)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitCannon, 20, 29, 2000, 0, 0);
	}
	else if (obj->time >= 82000 && obj->value1 == 52)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitCannon, 30, 29, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitCannon, 15, 0, 2000, 1, 0);

		EventMgr_AddObject_value(Object_InitStem, 59, 15, 2000, 0, 4);
		EventMgr_AddObject_value(Object_InitStem, 61, 17, 2000, 0, 4);
		EventMgr_AddObject_value(Object_InitStem, 63, 19, 2000, 0, 4);
		EventMgr_AddObject_value(Object_InitStem, 65, 21, 2000, 0, 4);
		EventMgr_AddObject_value(Object_InitStem, 67, 23, 2000, 0, 4);
		EventMgr_AddObject_value(Object_InitStem, 69, 25, 2000, 0, 4);
		EventMgr_AddObject_value(Object_InitStem, 71, 27, 2000, 0, 4);
	}
	else if (obj->time >= 83000 && obj->value1 == 53)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitCannon, 40, 29, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitCannon, 25, 0, 2000, 1, 0);
	}
	else if (obj->time >= 84000 && obj->value1 == 54)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitCannon, 35, 0, 2000, 1, 0);
		EventMgr_AddObject_value(Object_InitCannon, 50, 29, 2000, 0, 0);
	}
	else if (obj->time >= 86000 && obj->value1 == 54)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitCannon, 35, 0, 2000, 1, 0);
		EventMgr_AddObject_value(Object_InitCannon, 50, 29, 2000, 0, 0);
	}
	else if (obj->time >= 89000 && obj->value1 == 55)
	{
		++obj->value1;
		EventMgr_AddObject_value(Object_InitLine, 0, 0, 10000, 0, YELLOW);
		EventMgr_AddObject_value(Object_InitLine, 0, 29, 10000, 1, YELLOW);
		EventMgr_AddObject_value(Object_InitLine, 0, 0, 10000, 2, YELLOW);
		EventMgr_AddObject_value(Object_InitLine, 59, 0, 10000, 3, YELLOW);
	}
	else if(obj->time>= 93000 && obj->fvalue1 > 0.1f)
	{
		EventMgr_AddObject(Object_InitSatellite, 0, rand() % 25 + 5, 10000);
		obj->fvalue1 -= 0.1f;
		obj->time -= 1000;
		SoundMgr_AdjustVolume(obj->fvalue1);
	}
	else if(obj->time >= 94000)
	{
		SoundMgr_StopSound();
		SoundMgr_AdjustVolume(1);
		// 게임끝
		EventMgr_ChangeScene(SCENE_CLEAR);
	}
}

void Object_RenderHigher(Object* obj)
{
}


