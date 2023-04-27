#pragma once

#include "pch.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "SoundMgr.h"
#include "EventMgr.h"

#include "Object_Cascade.h"

void Object_InitBackgroundFlicker(Object* obj) 
{
	obj->background = BLACK;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateBackgroundFlicker;
	obj->Object_Render = Object_RenderBackgroundFlicker;
}


bool bg_FlickStatement = false;
#define bg_FlickTime 20


void Object_UpdateBackgroundFlicker(Object* obj) 
{

	if (bg_FlickStatement == true) 
	{
		obj->background = DARK_GRAY;
		obj->time += TimeMgr_deltaTime;
	}
	else
	{
		obj->background = BLACK;
	}

	if (obj->time > bg_FlickTime)
	{
		bg_FlickStatement = false;
		obj->time = 0;
	}
}


void Object_RenderBackgroundFlicker(Object* obj) 
{
	for (int i = 0; i < 30; i++)
	{
		RenderMgr_Draw(0, i, "                                                                                                                        ", WHITE, obj->background);
	}
}


