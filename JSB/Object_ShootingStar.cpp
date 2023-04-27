
#include "pch.h"
#include "Object_ShootingStar.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "EventMgr.h"
#include "KeyMgr.h"

void Object_InitShootingStar(Object* obj)
{
	obj->foreground = YELLOW;
	obj->time = 0;
	obj->Object_Update = Object_UpdateShootingStar;
	obj->Object_Render = Object_RenderShootingStar;
}

void Object_UpdateShootingStar(Object* obj)
{

	obj->time += TimeMgr_deltaTime;
	if (obj->time >= 50)
	{
		obj->time -= 50;

		obj->x++;
		obj->y++;
	}

	if (obj->x > 60 || obj->y > 30)
	{
		obj->foreground = rand() % 100;
		obj->x = rand() % 75 - 20;
		obj->y = rand() % 5 - 5;
	}
}

void Object_RenderShootingStar(Object* obj)
{


	if (keyInfo[SPACE].state != NONE)
	{
		if (obj->foreground < 97)
			RenderMgr_Draw(obj->x, obj->y, "¡Ù", YELLOW, BLACK);
		else
		{  
			RenderMgr_Draw(obj->x - 3, obj->y - 3, "*", YELLOW, BLACK);
			RenderMgr_Draw(obj->x - 2, obj->y - 2, "*", YELLOW, BLACK);
			RenderMgr_Draw(obj->x-1, obj->y-1, "*", YELLOW, BLACK);
			RenderMgr_Draw(obj->x, obj->y, "¡Ú", YELLOW, BLACK);
		}
	}
}

