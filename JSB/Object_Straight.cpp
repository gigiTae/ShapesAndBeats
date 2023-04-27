#pragma once

#include "pch.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "EventMgr.h"

#include "Object_Cascade.h"

void Object_InitStraight(Object* obj)
{
	obj->name = "■"; //* ● ◎ ⊙ ◈ ■ ▣ ▒ ㅁⅹ × ＋ ¤ ο ｏ
	obj->background = 1;
	obj->foreground = 1;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateStraight;
	obj->Object_Render = Object_RenderStraight;
}
///머리 : 위치 변경됐을 때 한번 깜빡함, 작은거로
///생긴거 : 배경 2x2
///꼬리 : ■ 4개

#define moveSpeed obj->value1 //깜빡이는 시간
#define color obj->value2
#define flicker obj->background //깜빡임 상태, 1과 -1로 bool형식 표현.


void Object_UpdateStraight(Object* obj)
{
	obj->time += TimeMgr_deltaTime;

	if (obj->time >= moveSpeed)
	{
		obj->y--;
		obj->time -= moveSpeed;
	}
}


void Object_RenderStraight(Object* obj)
{
	if (flicker == 1)
	{
		RenderMgr_Draw(obj->x, obj->y, "■■", WHITE, WHITE); ///충돌로 바꾸기
		RenderMgr_Draw(obj->x, obj->y+1, "■■", WHITE, WHITE); ///충돌로 바꾸기
	}
	else
	{
		RenderMgr_Draw(obj->x, obj->y, "    ", SKYBLUE, BLACK); ///충돌로 바꾸기
		RenderMgr_Draw(obj->x, obj->y, "    ", SKYBLUE, BLACK); ///충돌로 바꾸기
	}
	flicker *= -1;

	RenderMgr_DrawC(obj->x, obj->y + 2, 2,"■■", DARK_SKYBLUE, BLACK); 
	RenderMgr_DrawC(obj->x, obj->y + 3, 2,"■■", DARK_SKYBLUE, BLACK); 
	RenderMgr_DrawC(obj->x, obj->y + 4, 2,"####", BLUE, BLACK); 
	RenderMgr_DrawC(obj->x, obj->y + 5, 2,"####", BLUE, BLACK); 
	RenderMgr_DrawC(obj->x, obj->y + 6, 2,"####", BLUE, BLACK); 
	RenderMgr_DrawC(obj->x, obj->y + 7, 2,"####", BLUE, BLACK); 
	RenderMgr_DrawC(obj->x, obj->y + 8, 2,"::::", DARK_BLUE, BLACK); 
	RenderMgr_DrawC(obj->x, obj->y + 9, 2,"::::", DARK_BLUE, BLACK); 
	RenderMgr_DrawC(obj->x, obj->y + 10, 2,"::::", DARK_BLUE, BLACK); 
	RenderMgr_DrawC(obj->x, obj->y + 11, 2,"::::", DARK_BLUE, BLACK); 
}