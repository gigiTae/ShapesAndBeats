#include "pch.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "Object_JustCircle.h"

void Object_InitJustCircle(Object* obj)
{
	obj->name = "¡Ü";
	obj->foreground = VIOLET;
	obj->time = 0;
	obj->Object_Update = Object_UpdateJustCircle;
	obj->Object_Render = Object_RenderJustCircle;
}

void Object_UpdateJustCircle(Object* obj)
{
	obj->value2 += TimeMgr_deltaTime;
	obj->time += TimeMgr_deltaTime;
	if (obj->value2 >= 1000)
	{ 
		 obj->value2 -= 1000;
	}
}

void Object_RenderJustCircle(Object* obj)
{
	RenderMgr_DrawC(sin((double)obj->time / 500) * 7 + obj->x, cos((double)obj->time / 500) * 7 + obj->y, 1, "¡Ü", obj->foreground, BLACK);
}