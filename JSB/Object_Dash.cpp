
#include "pch.h"
#include "Object_Dash.h"
#include "Object.h"
#include "Object_Player.h"
#include "RenderMgr.h"
#include "TimgMgr.h"

void Object_InitDash(Object* obj)
{
	obj->name = "  ";
	obj->background = Player_Color;
	obj->foreground = Player_Color;
	obj->x = 30;
	obj->y = 15;
	obj->time = 0;
	obj->Object_Update = Object_UpdateDash;
	obj->Object_Render = Object_RenderDash;
}

void Object_UpdateDash(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
}

void Object_RenderDash(Object* obj)
{
	if (obj->time < 100)
	{
		RenderMgr_Draw(obj->x - 1, obj->y - 1, "����������", WHITE, BLACK);
		RenderMgr_Draw(obj->x - 1, obj->y,     "��   ��", WHITE, BLACK);
		RenderMgr_Draw(obj->x - 1, obj->y + 1, "����������", WHITE, BLACK);
	}
	else
	{
		RenderMgr_Draw(obj->x - 2, obj->y - 2, "������������������", obj->foreground, BLACK);
		RenderMgr_Draw(obj->x - 2, obj->y -1,  "��       ��", obj->foreground, BLACK);
		RenderMgr_Draw(obj->x - 2, obj->y,     "��       ��", obj->foreground, BLACK);
		RenderMgr_Draw(obj->x - 2, obj->y + 1, "��       ��", obj->foreground, BLACK);
		RenderMgr_Draw(obj->x - 2, obj->y + 2, "������������������", obj->foreground, BLACK);
	}
}

