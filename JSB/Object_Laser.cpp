#include "pch.h"
#include "Object_Laser.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"

void Object_InitLaser(Object* obj)
{
	obj->name = "  ";
	obj->background = BLACK;
	obj->foreground = VIOLET;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateLaser;
	obj->Object_Render = Object_RenderLaser;
}

#define dir obj->value1

void Object_UpdateLaser(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	if (obj->time >= 1000)
	{
		++obj->y;
		obj->time -= 1000;
	}
}

void Object_RenderLaser(Object* obj)
{
	if (dir == 0) 
	{
		for (int i = 0; i < 30; i++)
		{
			RenderMgr_DrawC(obj->x, obj->y + i, 1, "бс", VIOLET, BLACK);
		}
	}
	else if (dir == 1) 
	{
		for (int i = 0; i < 60; i++) 
		{
			RenderMgr_DrawC(obj->x+i, obj->y, 1, "бс", VIOLET, BLACK);
		}
	}
}