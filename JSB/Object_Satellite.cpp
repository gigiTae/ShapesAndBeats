
#include "pch.h"
#include "Object_Satellite.h"
#include "RenderMgr.h"
#include "TimgMgr.h"
#include "EventMgr.h"
#include "Object.h"

void Object_InitSatellite(Object* obj)
{
	obj->foreground = WHITE;
	obj->time = 0;
	obj->Object_Update = Object_UpdateSatellite;
	obj->Object_Render = Object_RenderSatellite;
}

void Object_UpdateSatellite(Object* obj)
{
	obj->value2 += TimeMgr_deltaTime;
	obj->time += TimeMgr_deltaTime;	
	if (obj->value2 >= 100)
	{
		obj->x++;
		obj->value2 -= 100;
		obj->foreground = rand() % 14 + 1;
	}
}

void Object_RenderSatellite(Object* obj)
{
	RenderMgr_Draw(sin((double)obj->time/100)*5+obj->x, cos((double)obj->time/100)*5+obj->y, "○", obj->foreground, BLACK);
	RenderMgr_Draw(obj->x - 4, obj->y - 3, " А  А", YELLOW, BLACK);
	RenderMgr_Draw(obj->x - 4, obj->y - 2, "(*＾-＾)", YELLOW, BLACK);
	RenderMgr_Draw(obj->x - 5, obj->y - 1, "~~( _ _ )", YELLOW, BLACK);
	RenderMgr_Draw(obj->x - 5, obj->y,  "○〓〓〓〓〓〓○", YELLOW, BLACK);
}  
