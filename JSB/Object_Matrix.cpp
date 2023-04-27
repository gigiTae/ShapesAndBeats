#include "pch.h"
#include "Object_Matrix.h"
#include "Object.h"
#include "RenderMgr.h"
#include "TimgMgr.h"

void Object_InitMatrix(Object* obj)
{
	obj->name = "  ";
	obj->background = BLACK;
	obj->foreground = WHITE;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateMatrix;
	obj->Object_Render = Object_RenderMatrix;
}

void Object_UpdateMatrix(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	if (obj->time >= 100)
	{
		++obj->y;
		obj->time -= 100;
		obj->value1 = rand() % 2;
		obj->value2 = rand() % 20;
	}

}

void Object_RenderMatrix(Object* obj)
{
	
	if (obj->value1)
		RenderMgr_DrawC(obj->x, obj->y - 20, 1, "0", DARK_GREEN, BLACK);
	else
		RenderMgr_DrawC(obj->x, obj->y - 20, 1, "1", DARK_GREEN, BLACK);
	for (int i = 1; i < 20; ++i)
	{
		if (obj->value2 % i ==0)
			RenderMgr_DrawC(obj->x, obj->y - i, 1, "1", GREEN, BLACK);
		else
			RenderMgr_DrawC(obj->x, obj->y - i, 1, "0", GREEN, BLACK);
	}

	if (obj->value1)
		RenderMgr_Draw(obj->x, obj->y, "1", WHITE, BLACK);
	else
		RenderMgr_Draw(obj->x, obj->y, "0", WHITE, BLACK);
}
