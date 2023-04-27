#include "Object_Sevcon.h"
#include "pch.h"
#include "Object.h"
#include "TimgMgr.h"
#include "SoundMgr.h"
#include "EventMgr.h"
#include "Object_Laser.h"
#include "Object_Snow.h"
#include "Object_JustCircle.h"
#include "Object_CircleLine.h"
#include "Object_Cascade.h"
#include "SoundMgr.h"

void Object_InitSevcon(Object* obj)
{
	obj->name = "SEVCON";
	obj->background = BLACK;
	obj->foreground = VIOLET;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateSevcon;
	obj->Object_Render = Object_RenderSevcon;
}

void Object_UpdateSevcon(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	if (obj->value1 == 0)
	{
		obj->value1++;
		SoundMgr_PlaySound(SEVCON);
	}
	else if (obj->value1 == 1 && obj->time >= 1000)
	{
		obj->value1++;
		EventMgr_AddObject(Object_InitJustCircle, 30, 15, 29000);
	}
	else if (obj->value1 == 2 && obj->time >= 1500) {
		obj->value1++;
		EventMgr_AddObject_value(Object_InitSnow, 33, 18, 0, 2, 0);
	}
	else if (obj->value1 == 3 && obj->time >= 2500) {
		obj->value1++;
		EventMgr_AddObject_value(Object_InitSnow, 25, 13, 0, 0, 0);	
	}
	else if (obj->value1 == 4 && obj->time >= 3500) {
		obj->value1++;
		EventMgr_AddObject_value(Object_InitSnow, 23, 15, 0, 5, 0);
	}

	else if (obj->value1 == 5 && obj->time >= 4500)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitSnow, 33, 18, 0, 7, 0);
	}

	else if (obj->value1 == 6 && obj->time >= 8500) 
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitSnow, 31, 10, 0, 2, 0);
		EventMgr_AddObject_value(Object_InitSnow, 35, 11, 0, 2, 0);
	}

	else if (obj->value1 == 7 && obj->time >= 9500)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitSnow, 27, 11, 0, 0, 0);
		EventMgr_AddObject_value(Object_InitSnow, 24, 13, 0, 0, 0);
	}
	else if (obj->value1 == 8 && obj->time >= 10000) {
		obj->value1++;
		EventMgr_AddObject_value(Object_InitSnow, 22, 14, 0, 5, 0);
		EventMgr_AddObject_value(Object_InitSnow, 25, 17, 0, 5, 0);
	}
	else if (obj->value1 == 9 && obj->time >= 11500) {
		obj->value1++;
		EventMgr_AddObject_value(Object_InitSnow, 35, 16, 0, 7, 0);
		EventMgr_AddObject_value(Object_InitSnow, 32, 19, 0, 7, 0);
	}
	else if (obj->value1 == 10 && obj->time >= 12000) {
		obj->value1++;
		EventMgr_AddObject_value(Object_InitSnow, 27, 17, 2000, 2, 0);
		EventMgr_AddObject_value(Object_InitSnow, 42, 12, 2000, 5, 0);
		
	}
	else if (obj->value1 == 11 && obj->time >= 13000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitSnow, 37, 22, 2000, 0, 0);
		EventMgr_AddObject_value(Object_InitSnow, 32, 10, 2000, 7, 0);
	}

	else if (obj->value1 == 12 && obj->time >= 14000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitSnow, 25, 17, 1500, 2, 0);
		EventMgr_AddObject_value(Object_InitSnow, 37, 12, 1500, 5, 0);
	}

	else if (obj->value1 == 13 && obj->time >= 15000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitSnow, 32, 22, 1500, 0, 0);
		EventMgr_AddObject_value(Object_InitSnow, 27, 10, 1500, 7, 0);
	}
	else if (obj->value1 == 14 && obj->time >= 16000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 15 && obj->time >= 17000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 4, 0, 1000, 0, 0);;
	}
	else if (obj->value1 == 16 && obj->time >= 18000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 8, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 17 && obj->time >= 19000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 12, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 18 && obj->time >= 20000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 16, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 19 && obj->time >= 21000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 20, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 20 && obj->time >= 22000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 24, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 21 && obj->time >= 23000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 28, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 22 && obj->time >= 24000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 0, 1000, 1, 0);
	}
	else if (obj->value1 == 23 && obj->time >= 25000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 3, 1000, 1, 0);
	}
	else if (obj->value1 == 24 && obj->time >= 26000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 6, 1000, 1, 0);
	}
	else if (obj->value1 == 25 && obj->time >= 27000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 9, 1000, 1, 0);
	}
	else if (obj->value1 == 26 && obj->time >= 28000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 12, 1000, 1, 0);
	}
	else if (obj->value1 == 27 && obj->time >= 29000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 15, 1000, 1, 0);
	}
	else if (obj->value1 == 28 && obj->time >= 30000)
	{
		obj->value1++;
		for (int i = 0; i < 50; i++)
		{
			EventMgr_AddObject(Object_InitCircleLine, 0, -i * 2, 20000);
		}
	}
	else if (obj->value1 == 29 && obj->time >= 44000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 20, 0, 1000, 0, 0);
		EventMgr_AddObject_value(Object_InitLaser, 40, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 30 && obj->time >= 45000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 25, 0, 1000, 0, 0);
		EventMgr_AddObject_value(Object_InitLaser, 35, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 31 && obj->time >= 46000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 5, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 25, 1000, 1, 0);
	}
	else if (obj->value1 == 32 && obj->time >= 47000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 10, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 20, 1000, 1, 0);
	}
	else if (obj->value1 == 33 && obj->time >= 48000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 5, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 10, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 15, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 20, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 25, 1000, 1, 0);
	}
	else if (obj->value1 == 34 && obj->time >= 49000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 11, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 13, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 15, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 17, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 19, 1000, 1, 0);;
	}
	else if (obj->value1 == 35 && obj->time >= 50000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 1, 0, 1000, 0, 0);
		EventMgr_AddObject_value(Object_InitLaser, 3, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 36 && obj->time >= 51000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 5, 0, 1000, 0, 0);
		EventMgr_AddObject_value(Object_InitLaser, 7, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 37 && obj->time >= 52000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 9, 0, 1000, 0, 0);
		EventMgr_AddObject_value(Object_InitLaser, 11, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 38 && obj->time >= 53000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 13, 0, 1000, 0, 0);
		EventMgr_AddObject_value(Object_InitLaser, 15, 0, 1000, 0, 0);
	}
	else if (obj->value1 == 39 && obj->time >= 54000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 2, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 4, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 6, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 8, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 10, 1000, 1, 0);
	}
	else if (obj->value1 == 40 && obj->time >= 55000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 0, 28, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 26, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 24, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 22, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 20, 1000, 1, 0);
	}
	else if (obj->value1 == 41 && obj->time >= 56000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 25, 0, 1000, 0, 0);
		EventMgr_AddObject_value(Object_InitLaser, 35, 0, 1000, 0, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 13, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 15, 1000, 1, 0);
	}
	else if (obj->value1 == 42 && obj->time >= 57000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 27, 0, 1000, 0, 0);
		EventMgr_AddObject_value(Object_InitLaser, 32, 0, 1000, 0, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 13, 1000, 1, 0);
		EventMgr_AddObject_value(Object_InitLaser, 0, 15, 1000, 1, 0);
	}
	else if (obj->value1 == 43 && obj->time >= 59000)
	{
		obj->value1++;
		for (int i = 0; i < 50; i++)
		{
			EventMgr_AddObject(Object_InitCircleLine, 0, -i * 2, 20000);
		}
	}
	else if (obj->value1 == 44 && obj->time >= 60000)
	{
		obj->value1++;
		_beginthreadex(NULL, 0, RainDispensorThread, NULL, 0, NULL);
	}
	else if (obj->value1 == 45 && obj->time >= 79000)
	{
		obj->value1++;
		EventMgr_AddObject_value(Object_InitLaser, 30, 0, 1000, 0, 0);
		EventMgr_AddObject_value(Object_InitLaser, 32, 0, 1000, 0, 0);
		obj->time = 0;
		obj->fvalue1 = 1.f;
	}
	else if (obj->value1==46 && obj->time >= 500 && obj->fvalue1 > 0.1)
	{
		obj->fvalue1 -= 0.1f;
		obj->time -= 500;
		SoundMgr_AdjustVolume(obj->fvalue1);
	}
	else if (obj->value1 == 46 && obj->fvalue1 < 0.1)
	{
		SoundMgr_StopSound();
		SoundMgr_AdjustVolume(1);
		// °ÔÀÓ³¡
		EventMgr_ChangeScene(SCENE_CLEAR);
	}
}

void Object_RenderSevcon(Object* obj)
{

}