#include "pch.h"
#include "Object_BoxMonsterTear.h"
#include "TimgMgr.h"
#include "EventMgr.h"
#include "RenderMgr.h"
#include "Object.h"

void Object_InitBoxMonsterTear(Object* obj)
{
	obj->time = 0;
	obj->Object_Update = ObjectdUpdateBoxMonsterTear;
	obj->Object_Render = Object_RenderBoxMonsterTear;
}

void ObjectdUpdateBoxMonsterTear(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	if (obj->time >= 100)
	{
		obj->time -= 100;
		++obj->y;
		if (obj->value1 == 0)
		{
			obj->value1 = 1;
		}
		else
			obj->value1 = 0;
	}

}

void Object_RenderBoxMonsterTear(Object* obj)
{
	if (obj->value1 == 1)
		RenderMgr_DrawC(obj->x-1, obj->y, 3, "¡Ü¡Ü¡Ü", obj->value2, BLACK);
	else
		RenderMgr_DrawC(obj->x-1, obj->y, 3, "¡Ü¡Ü¡Ü", WHITE, BLACK);
}
