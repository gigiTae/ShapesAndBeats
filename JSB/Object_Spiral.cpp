#include "pch.h"
#include "Object_Spiral.h"
#include "RenderMgr.h"
#include "EventMgr.h"
#include "TimgMgr.h"
#include "Object.h"



void Object_InitSpiral(Object* obj)
{
	obj->time = 0;
	obj->Object_Update = ObjectdUpdateSpiral;
	obj->Object_Render = Object_RenderSpiral;
}

// value1 0(+y) 1(+x) 2(-y) 3(-x) 

void ObjectdUpdateSpiral(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	
	if (obj->time >= 10)
	{
		obj->foreground = rand() % 14 + 1;
		obj->time -= 10;
		if (obj->value1 == 0)
		{
			++obj->y;

			// 방향전환
			if (obj->y == 29 -obj->value2)
				obj->value1 = 1;
		}
		else if (obj->value1 == 1)
		{
			++obj->x;

			// 방향전환
			if (obj->x == 59 -obj->value2)
				obj->value1 = 2;
		}
		else if (obj->value1 == 2 )
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
			if (obj->x == 1+obj->value2)
			{
				obj->value1 = 0;

				obj->value2++;
			}
		}
	}


}

void Object_RenderSpiral(Object* obj)
{
	RenderMgr_DrawC(obj->x, obj->y, 1, "♬", obj->foreground, BLACK);
}
