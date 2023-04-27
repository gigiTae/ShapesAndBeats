#pragma once
#define _USE_MATH_DEFINES

#include "pch.h"
#include "Object_Starfall.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"


void Object_InitStarfall(Object* obj) {
	obj->name = "  ";
	obj->background = RED;
	obj->foreground = WHITE;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateStarfall;
	obj->Object_Render = Object_RenderStarfall;
}

#define STARFALL_UPDATE_TIME 70


void Object_UpdateStarfall(Object* obj) {

	obj->time += TimeMgr_deltaTime;
	if (obj->time >= STARFALL_UPDATE_TIME)
	{
		obj->y++;
		obj->time -= STARFALL_UPDATE_TIME;
	}
}



void Object_RenderStarfall(Object* obj) {

	DrawStar(obj->x, obj->y);
}


void DrawStar(int x, int y) {

	RenderMgr_Draw(x, y, "  ", BLACK, BLACK);
	RenderMgr_Draw(x, y + 1, "''", 1, BLACK);
	RenderMgr_Draw(x, y + 2, "::", 9, BLACK);
	RenderMgr_Draw(x, y + 3, "**", 3, BLACK);
	RenderMgr_Draw(x, y + 4, "##", 11, BLACK);
	RenderMgr_Draw(x, y + 5, "бс", 7, BLACK);
}