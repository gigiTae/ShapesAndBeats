#include "pch.h"
#include "Object_Santa.h"
#include "RenderMgr.h"
#include "TimgMgr.h"
#include "EventMgr.h"
#include "Object.h"
#include "Object_BoxMonsterTear.h"

void Object_InitSanta(Object* obj)
{
	obj->time = 0;
	obj->Object_Update = ObjectdUpdateSanta;
	obj->Object_Render = Object_RenderSanta;
}

void ObjectdUpdateSanta(Object* obj)
{
	obj->time += TimeMgr_deltaTime;

	if (obj->time >= 1000)
	{
		obj->time -= 1000;
		if (obj->value1 == 0)
		{
			obj->value1 = 1;
			EventMgr_AddObject_value(Object_InitBoxMonsterTear, obj->x + 3, obj->y + 4, 10000, 0, obj->value2);
		}
		else
			obj->value1 = 0;
	}

}

void Object_RenderSanta(Object* obj)
{
	//0
	RenderMgr_DrawC(obj->x, obj->y, 7, "              ", VIOLET, obj->value2);
	//1
	RenderMgr_DrawC(obj->x + 6, obj->y + 1, 1, "  ", VIOLET, obj->value2);
	RenderMgr_DrawC(obj->x,     obj->y + 1, 1, "  ", VIOLET, obj->value2);
	//2
	RenderMgr_DrawC(obj->x + 6, obj->y +2, 1, "  ", VIOLET, obj->value2);
	RenderMgr_DrawC(obj->x,     obj->y +2, 1, "  ", VIOLET, obj->value2);
	
	//´«
	RenderMgr_DrawC(obj->x + 2, obj->y + 2, 1, "  ", VIOLET, WHITE);
	RenderMgr_DrawC(obj->x + 4, obj->y + 2, 1, "  ", VIOLET, WHITE);
	// ÄÚ
	if (obj->value1 == 1)
		RenderMgr_DrawC(obj->x + 3, obj->y + 3, 1, "  ", VIOLET, WHITE);
	else
		RenderMgr_DrawC(obj->x + 3, obj->y + 3, 1, "  ", WHITE, obj->value2);
	//3
	RenderMgr_DrawC(obj->x + 6, obj->y + 3, 1, "  ", VIOLET, obj->value2);
	RenderMgr_DrawC(obj->x, obj->y + 3, 1, "  ", VIOLET, obj->value2);
	//4
	RenderMgr_DrawC(obj->x + 6, obj->y + 4, 1, "  ", VIOLET, obj->value2);
	RenderMgr_DrawC(obj->x, obj->y + 4, 1, "  ", VIOLET, obj->value2);
	//5
	RenderMgr_DrawC(obj->x,     obj->y+5, 7, "              ", VIOLET, obj->value2);
}
