#pragma once

#include "pch.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "Object_Cascade.h"

void Object_InitNCSquare(Object* obj)
{
	obj->name = "¡á"; //* ¡Ü ¡Ý ¢Á ¢Â ¡á ¢Ã ¢Æ ¤±¥ª ¡¿ £« ¢´ ¥ï £ï
	obj->background = 1;
	obj->foreground = 1;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateNCSquare;
	obj->Object_Render = Object_RenderNCSquare;
}


void Object_UpdateNCSquare(Object* obj)
{


}


void Object_RenderNCSquare(Object* obj)
{
	RenderMgr_Draw(obj->x, obj->y, "*", DARK_GRAY, BLACK);
}