#include "pch.h"
#include "Object_FlipBox.h"
#include "Object.h"
#include "RenderMgr.h"
#include "EventMgr.h"
#include "TimgMgr.h"


void Object_InitFlipBox(Object* obj)
{
	obj->time = 0;
	obj->Object_Update = ObjectdUpdateFlipBox;
	obj->Object_Render = Object_RenderFlipBox;
	obj->foreground = WHITE;
}

void ObjectdUpdateFlipBox(Object* obj)
{
	obj->time += TimeMgr_deltaTime;

	if (obj->time > 100)
	{
		obj->x++;
		obj->time -= 100;
		obj->foreground = rand() % 14 + 1;
	}

}

void Object_RenderFlipBox(Object* obj)
{
	RenderMgr_DrawC(obj->x - 2, obj->y,    5, "����������������", WHITE, BLACK);
	RenderMgr_DrawC(obj->x - 2, obj->y + 1,5, "��      ��", WHITE, BLACK);
	RenderMgr_DrawC(obj->x - 2, obj->y + 2,5, "��      ��", WHITE, BLACK);
	RenderMgr_DrawC(obj->x - 2, obj->y + 3,5, "��      ��", WHITE, BLACK);
	RenderMgr_DrawC(obj->x - 2, obj->y + 4,5, "����������������", WHITE, BLACK);

	RenderMgr_Draw(obj->x-1, obj->y+1,     "����������", obj->foreground, BLACK);
	RenderMgr_Draw(obj->x-1, obj->y + 2, "��   ��", obj->foreground, BLACK);
	RenderMgr_Draw(obj->x-1, obj->y + 3, "����������", obj->foreground, BLACK);

}
