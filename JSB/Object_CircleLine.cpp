#include "pch.h"
#include "Object_CircleLine.h"
#include "RenderMgr.h"
#include "EventMgr.h"
#include "TimgMgr.h"
#include "Object.h"

void Object_InitCircleLine(Object* obj)
{
	obj->name = "  ";
	obj->background = BLACK;
	obj->foreground = VIOLET;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateCircleLine;
	obj->Object_Render = Object_RenderCircleLine;
}

void Object_UpdateCircleLine(Object* obj) 
{
	obj->time += TimeMgr_deltaTime;

	if (obj->time >= 10)
	{
		obj->time -= 10;
		if (obj->value1 == 0)
		{
			++obj->y;

			// 방향전환
			if (obj->y == 29 - obj->value2)
				obj->value1 = 1;
		}
		else if (obj->value1 == 1)
		{
			++obj->x;

			// 방향전환
			if (obj->x == 59 - obj->value2)
				obj->value1 = 2;
		}
		else if (obj->value1 == 2)
		{
			--obj->y;

			// 방향전환
			if (obj->y == obj->value2)
				obj->value1 = 3;
		}
		else
		{
			--obj->x;

			// 방향전환
			if (obj->x == 1 + obj->value2)
			{
				obj->value1 = 0;

				obj->value2++;
			}
		}
	}
}

void Object_RenderCircleLine(Object* obj)
{
	RenderMgr_DrawC(obj->x, obj->y, 1, "◎", obj->foreground, BLACK);
}