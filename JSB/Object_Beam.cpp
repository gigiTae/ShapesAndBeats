#include "pch.h"
#include "TimgMgr.h"
#include "Object_Beam.h"
#include "RenderMgr.h"
#include "EventMgr.h"
#include "Object.h"

#define BeamLine "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式"

void Object_InitBeam(Object* obj)
{
	obj->time = 0;
	obj->Object_Update = ObjectdUpdateBeam;
	obj->Object_Render = Object_RenderBeam;
}

void ObjectdUpdateBeam(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	if (obj->time >= 150 && obj->value1 ==0)
	{
		obj->time -= 150;
		obj->y++;
		if (obj->y == 30)
			obj->value1 = 1;
	}
	else if (obj->time >= 30 && obj->value1 == 1)
	{
		obj->time -= 30;
		obj->y--;

		if (obj->y == -1)
			obj->value1 = 0;
	}

}

void Object_RenderBeam(Object* obj)
{
	if (obj->value1 == 0)
		RenderMgr_DrawC(0, obj->y, 60, BeamLine, GREEN, BLACK);
	else
		RenderMgr_DrawC(0, obj->y, 60, BeamLine, RED, BLACK);
}
