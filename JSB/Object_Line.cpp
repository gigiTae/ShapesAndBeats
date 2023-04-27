#include "pch.h"
#include "Object_Line.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"

void Object_InitLine(Object* obj)
{
	obj->name = "  ";
	obj->background = BLACK;
	obj->foreground = WHITE;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateLine;
	obj->Object_Render = Object_RenderLine;
}

void Object_UpdateLine(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	if (obj->time >= 100)
	{
		if (obj->value1 == 0)
			++obj->y;
		else if (obj->value1 == 1)
			--obj->y;
		else if (obj->value1 == 2)
			++obj->x;
		else
			--obj->x;
		obj->time -= 100;
	}
}

void Object_RenderLine(Object* obj)
{
	if (obj->value1 <= 1)
		RenderMgr_DrawC(obj->x, obj->y, 60, "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式", obj->value2, BLACK);
	else
	{
		for (int i = 0; i < 30; ++i)
			RenderMgr_DrawC(obj->x, i, 1, "弛", obj->value2, BLACK);
	}
}

