#include "pch.h"
#include "Object_Stem.h"
#include "RenderMgr.h"
#include "TimgMgr.h"
#include "Object.h"
#include "EventMgr.h"

void Object_InitStem(Object* obj)
{
	obj->time = 0;
	obj->background = YELLOW;
	obj->Object_Update = Object_UpdateStem;
	obj->Object_Render = Object_RenderStem;
}

void Object_UpdateStem(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	if (obj->time >= 50)
	{
		// right
		if (obj->value1 == 0 && obj->value2 == 0 && obj->x <60)
		{
			EventMgr_AddObject_value(Object_InitStem, obj->x + 1, obj->y + 1, 2000, 1, 0);
			obj->value2++;
		}
		else if (obj->value1 == 1 && obj->value2 == 0 && obj->x <60)
		{
			EventMgr_AddObject_value(Object_InitStem, obj->x + 1, obj->y - 1, 2000,0,0);
			obj->value2++;
		}
		// down
		else if (obj->value1 == 0 && obj->value2 == 2 && obj->y < 30)
		{
			EventMgr_AddObject_value(Object_InitStem, obj->x + 1, obj->y + 1, 2000, 1, 2);
			obj->value2++;
		}
		else if (obj->value1 == 1 && obj->value2 == 2 && obj->y < 30)
		{
			EventMgr_AddObject_value(Object_InitStem, obj->x - 1, obj->y + 1, 2000, 0, 2);
			obj->value2++;
		}
		// left
		else if (obj->value1 == 0 && obj->value2 == 4 && obj->x > 0)
		{
			EventMgr_AddObject_value(Object_InitStem, obj->x - 1, obj->y + 1, 2000, 1, 4);
			obj->value2++;
		}
		else if (obj->value1 == 1 && obj->value2 == 4 && obj->x > 0)
		{
			EventMgr_AddObject_value(Object_InitStem, obj->x - 1, obj->y - 1, 2000, 0, 4);
			obj->value2++;
		}

		// up
		else if (obj->value1 == 0 && obj->value2 == 6 && obj->y >0)
		{
			EventMgr_AddObject_value(Object_InitStem, obj->x + 1, obj->y - 1, 2000, 1, 6);
			obj->value2++;
		}
		else if (obj->value1 == 1 && obj->value2 == 6 && obj->y < 30)
		{
			EventMgr_AddObject_value(Object_InitStem, obj->x - 1, obj->y - 1, 2000, 0, 6);
			obj->value2++;
		}
	}
}

void Object_RenderStem(Object* obj)
{
	if (obj->time <= 100)
		RenderMgr_DrawC(obj->x, obj->y, 1, "  ", WHITE, WHITE);
	else if(obj->time <= 1900)
		RenderMgr_DrawC(obj->x, obj->y, 1, "  ", WHITE, obj->background);
	else
		RenderMgr_DrawC(obj->x, obj->y, 1, "¢Æ¢Æ", WHITE, obj->background);
}
