#include "pch.h"
#include "Object_Snow.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "Object.h"
#include "EventMgr.h"

void Object_InitSnow(Object* obj)
{
	obj->name = "  ";
	obj->background = BLACK;
	obj->foreground = WHITE;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateSnow;
	obj->Object_Render = Object_RenderSnow;
}

#define dir obj->value1
#define col obj->value2

enum Direct
{
	LEFTUP,
	UP,
	RIGHTUP,
	LEFT,
	RIGHT,
	LEFTDOWN,
	DOWN,
	RIGHTDOWN
};

void Object_UpdateSnow(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	if (obj->time >= 500)
	{
		obj->time -= 500;
		if (dir == LEFTUP) // 0
		{
			obj->y--;
			obj->x--;
		}
		else if (dir == UP) // 1
		{
			obj->y--;
		}
		else if (dir == RIGHTUP) // 2
		{
			obj->x++;
			obj->y--;
		}
		else if (dir == LEFT) // 3
		{
			obj->x--;
		}
		else if (dir == RIGHT) // 4
		{
			obj->x++;
		}
		else if (dir == LEFTDOWN) // 5
		{
			obj->x--;
			obj->y++;
		}
		else if (dir == DOWN) // 6
		{
			obj->y++;
		}
		else if (dir == RIGHTDOWN) // 7
		{
			obj->x++;
			obj->y++;
		}
	}
}

void Object_RenderSnow(Object* obj)
{
	if (col == 0) 
	{
		RenderMgr_DrawC(obj->x, obj->y, 1, "¡Ü", VIOLET, BLACK);
	}
	else if (col == 1) 
	{
		RenderMgr_DrawC(obj->x, obj->y, 1, "¡Ü", RED, BLACK);
	}
}
