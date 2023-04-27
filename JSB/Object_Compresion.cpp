#include "pch.h"
#include "Object_Compresion.h"
#include "TimgMgr.h"
#include "EventMgr.h"
#include "RenderMgr.h"
#include "Object.h"

void Object_InitCompresion(Object* obj)
{
	obj->name = "  ";
	obj->background = BLACK;
	obj->foreground = BLACK;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateCompresion;
	obj->Object_Render = Object_RenderCompresion;
}

void Object_UpdateCompresion(Object* obj)
{
	obj->time += TimeMgr_deltaTime;


	if (obj->time >= 100 && obj->y < 30)
	{
		if (obj->value1 == 0)
		{
			obj->value1++;
			EventMgr_AddObject(Object_InitCompresion, 0, obj->y + 2, 5000);
		}
		obj->x++;
		obj->time -= 50;
	}
}

void Object_RenderCompresion(Object* obj)
{
	RenderMgr_DrawC(0 + obj->x, obj->y, 2, "¢Æ   ", WHITE, YELLOW);
	RenderMgr_DrawC(58 - obj->x, obj->y+1, 2, "   ¢Æ", WHITE, YELLOW);
}
