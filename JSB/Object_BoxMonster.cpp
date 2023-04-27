#include "pch.h"
#include "Object_BoxMonster.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "EventMgr.h"

void Object_InitBoxMonster(Object* obj)
{
	obj->name = "  ";
	obj->background = BLACK;
	obj->foreground = BLACK;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateBoxMonster;
	obj->Object_Render = Object_RenderBoxMonster;
}

void Object_UpdateBoxMonster(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	if (obj->time >= 250 )
	{
		++obj->x;
		obj->time -= 250;
		obj->foreground = rand() % 14 + 1;
	}


}

void Object_RenderBoxMonster(Object* obj)
{
	// 눈
	RenderMgr_Draw(obj->x, obj->y, "/ ------------------------\\              | ~~\\_____ / ~~\\__ |", obj->foreground, BLACK);
	RenderMgr_Draw(obj->x, obj->y + 1, "|      게임 클리어         |______________ \\______======    )-+", obj->foreground, BLACK);
	RenderMgr_Draw(obj->x, obj->y + 2, "|축                      하|                      ~~~|/~~    |", obj->foreground, BLACK);
	RenderMgr_Draw(obj->x, obj->y + 3, "\\------------------------ /                         ()", obj->foreground, BLACK);
}
