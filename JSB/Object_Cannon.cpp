#include "pch.h"
#include "Object_Cannon.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "EventMgr.h"
#include "Object.h"



void Object_InitCannon(Object* obj)
{
	obj->time = 0;
	obj->Object_Update = ObjectdUpdateCannon;
	obj->Object_Render = Object_RenderCannon;
	obj->fvalue1 = 0;
}

void ObjectdUpdateCannon(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	if (obj->time >= 250 && obj->fvalue1 < 1.9f)
	{
		obj->time -= 250;
		obj->fvalue1 += 1.f;
		if (obj->value1 == 0) // up
		{
			--obj->y;
		}
		else if (obj->value1 == 1) //down
		{
			++obj->y;
		}
		else if (obj->value1 == 2) // left
		{
			--obj->x;
		}
		else if (obj->value1 == 3) //right
		{
			++obj->x;
		}
	}
	else if (obj->time >= 100)
	{
		obj->time -= 100;
		obj->value2++;
		obj->fvalue1 += 1.f;
	}


}

void Object_RenderCannon(Object* obj)
{
	if (obj->fvalue1 < 0.9f)
		RenderMgr_DrawC(obj->x, obj->y, 1, "¡Û", YELLOW, WHITE);
	else if (obj->fvalue1 < 1.1f)
	{
		RenderMgr_DrawC(obj->x, obj->y, 1, "¡Û", YELLOW, BLACK);
	}
	else if (obj->fvalue1 < 2.1f)
	{
		RenderMgr_DrawC(obj->x, obj->y, 1, "¡Ü", WHITE, YELLOW);
	}
	else 
	{
		if (obj->value1 == 0) // up
		{
			RenderMgr_DrawC(obj->x - obj->value2, obj->y - obj->value2, 1, "¡Ü", YELLOW, BLACK);
			RenderMgr_DrawC(obj->x, obj->y-obj->value2, 1, "¡Ü", YELLOW, BLACK);
			RenderMgr_DrawC(obj->x + obj->value2, obj->y - obj->value2, 1, "¡Ü", YELLOW, BLACK);
		}
		else if (obj->value1 == 1) //down
		{
			RenderMgr_DrawC(obj->x + obj->value2, obj->y + obj->value2, 1, "¡Ü", YELLOW, BLACK);
			RenderMgr_DrawC(obj->x, obj->y + obj->value2, 1, "¡Ü", YELLOW, BLACK);
			RenderMgr_DrawC(obj->x - obj->value2, obj->y + obj->value2, 1, "¡Ü", YELLOW, BLACK);
		}
		else if (obj->value1 == 2) // left
		{
			RenderMgr_DrawC(obj->x - obj->value2, obj->y - obj->value2, 1, "¡Ü", YELLOW, BLACK);
			RenderMgr_DrawC(obj->x-obj->value2, obj->y, 1, "¡Ü", YELLOW, BLACK);
			RenderMgr_DrawC(obj->x - obj->value2, obj->y + obj->value2, 1, "¡Ü", YELLOW, BLACK);
		}
		else if (obj->value1 == 3) //right
		{
			RenderMgr_DrawC(obj->x + obj->value2, obj->y + obj->value2, 1, "¡Ü", YELLOW, BLACK);
			RenderMgr_DrawC(obj->x +obj->value2, obj->y, 1, "¡Ü", YELLOW, BLACK);
			RenderMgr_DrawC(obj->x + obj->value2, obj->y - obj->value2, 1, "¡Ü", YELLOW, BLACK);
		}
		
	}
}
