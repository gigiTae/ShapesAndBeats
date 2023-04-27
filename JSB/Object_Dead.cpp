
#include "pch.h"
#include "Object.h"
#include "Object_Dead.h"
#include "TimgMgr.h"
#include "RenderMgr.h"

void Object_InitDead(Object* obj)
{
	obj->name = "  ";
	obj->background = SKYBLUE;
	obj->foreground = SKYBLUE;
	obj->x = 30;
	obj->y = 15;
	obj->time = 0;
	obj->Object_Update = Object_UpdateDead;
	obj->Object_Render = Object_RenderDead;
}

void Object_UpdateDead(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
}

void Object_RenderDead(Object* obj)
{
	if (obj->time < 100)
	{
		RenderMgr_Draw(obj->x - 1, obj->y - 1, "忙式式式忖", GRAY, BLACK);
		RenderMgr_Draw(obj->x - 1, obj->y,     "弛   弛", GRAY, BLACK);
		RenderMgr_Draw(obj->x - 1, obj->y + 1, "戌式式式戎", GRAY, BLACK);
	}
	else
	{
		RenderMgr_Draw(obj->x - 2, obj->y - 2, "忙式式式式式式式忖", DARK_GRAY, BLACK);
		RenderMgr_Draw(obj->x - 2, obj->y - 1, "弛       弛", DARK_GRAY, BLACK);
		RenderMgr_Draw(obj->x - 2, obj->y,     "弛       弛", DARK_GRAY, BLACK);
		RenderMgr_Draw(obj->x - 2, obj->y + 1, "弛       弛", DARK_GRAY, BLACK);
		RenderMgr_Draw(obj->x - 2, obj->y + 2, "戌式式式式式式式戎", DARK_GRAY, BLACK);
	}
}
