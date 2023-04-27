#pragma once
#define _USE_MATH_DEFINES

#include "pch.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"

#include "Object_Firework.h"

void Object_InitFirework(Object* obj) {
	obj->name = "  ";
	obj->background = 0;
	obj->foreground = WHITE;
	obj->x = 30;
	obj->y = 30;
	obj->time = 0;
	obj->Object_Update = Object_UpdateFirework;
	obj->Object_Render = Object_RenderFirework;

}

#define diag obj->background
#define FIREWORK_UPDATE_TIME 50

void Object_UpdateFirework(Object* obj) {

	obj->time += TimeMgr_deltaTime;
	if (obj->time >= FIREWORK_UPDATE_TIME)
	{
		obj->value1++;
		diag = round(obj->value1 /sqrt(2));
		obj->time -= FIREWORK_UPDATE_TIME;
	}
}

void Object_RenderFirework(Object* obj) {

	RenderMgr_Draw(obj->x + obj->value1,	obj->y,					"*", WHITE, BLACK); //왼쪽
	RenderMgr_Draw(obj->x - obj->value1,	obj->y,					"*", WHITE, BLACK); //오른쪽
	RenderMgr_Draw(obj->x ,					obj->y +obj->value1,	"*", WHITE, BLACK); //위
	RenderMgr_Draw(obj->x,					obj->y -obj->value1,	"*", WHITE, BLACK); //아래

	RenderMgr_Draw(obj->x - diag,			obj->y + diag,			"*", WHITE, BLACK); //왼 위
	RenderMgr_Draw(obj->x - diag,			obj->y - diag,			"*", WHITE, BLACK); //왼 아래
	RenderMgr_Draw(obj->x + diag,			obj->y + diag,			"*", WHITE, BLACK); //오 위
	RenderMgr_Draw(obj->x + diag,			obj->y - diag,			"*", WHITE, BLACK); //오 아래
}