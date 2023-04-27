
#include "pch.h"
#include "Object_GameOverUI.h"
#include "RenderMgr.h"
#include "TimgMgr.h"
#include "Object.h"
#include "KeyMgr.h"
#include "EventMgr.h"
#include "SoundMgr.h"
#include "Object_SelectUI.h"

#define speed obj->value


void Object_InitGameOverUI(Object* obj)
{
	obj->name = "  ";
	obj->background = SKYBLUE;
	obj->foreground = SKYBLUE;
	obj->x = 30;
	obj->y = 15;
	obj->time = 0;
	obj->Object_Update = Object_UpdateGameOverUI;
	obj->Object_Render = Object_RenderGameOverUI;
}

void Object_UpdateGameOverUI(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	if (obj->time >=100 && obj->value1 != 0)
	{
		obj->value1 -= 1;
		obj->time -= 100;
	}
	else if(obj->value1 == 0 && obj->time < 100)
	{
		obj->value2 = WHITE;
		obj->x = 18;
	}
	else if (obj->value1 == 0)
	{
		obj->value2 = RED;
		if (keyInfo[LEFT].state == TAP)
		{
			SoundMgr_PlayEffect(CLICK1);
			obj->x = 18;
		}
		if (keyInfo[RIGHT].state == TAP)
		{
			SoundMgr_PlayEffect(CLICK1);
			obj->x = 38;
		}
		if (keyInfo[SPACE].state == TAP && obj->x == 18)
		{
			SoundMgr_PlayEffect(CLICK2);
			if (selectArrow == 1)		EventMgr_ChangeScene(SCENE_CASCADE);
			if (selectArrow == 2)		EventMgr_ChangeScene(SCENE_SEVCON);
			if (selectArrow == 3)		EventMgr_ChangeScene(SCENE_HiGHER);

		}
		if (keyInfo[SPACE].state == TAP && obj->x == 38)
		{
			SoundMgr_PlayEffect(CLICK2);
			EventMgr_ChangeScene(SCENE_SELECT);
		}
		
	}
}

void Object_RenderGameOverUI(Object* obj)
{
	RenderMgr_Draw(7 + obj->value1, 6, "  ______    ______   __       __  ________         ______   __     __  ________  _______ ",obj->value2, BLACK);
	RenderMgr_Draw(7 - obj->value1, 7, " /      \\  /      \\ /  \\     /  |/        |       /      \\ /  |   /  |/        |/       \\ ", obj->value2, BLACK);
	RenderMgr_Draw(7 + obj->value1, 8, "/$$$$$$  |/$$$$$$  |$$  \\   /$$ |$$$$$$$$/       /$$$$$$  |$$ |   $$ |$$$$$$$$/ $$$$$$$  |", obj->value2, BLACK);
	RenderMgr_Draw(7 - obj->value1, 9, "$$ | _$$/ $$ |__$$ |$$$  \\ /$$$ |$$ |__          $$ |  $$ |$$ |   $$ |$$ |__    $$ |__$$ |", obj->value2, BLACK);
	RenderMgr_Draw(7 + obj->value1, 10, "$$ |/    |$$    $$ |$$$$  /$$$$ |$$    |         $$ |  $$ |$$  \\ /$$/ $$    |   $$    $$< ", obj->value2, BLACK);
	RenderMgr_Draw(7 - obj->value1, 11, "$$ |$$$$ |$$$$$$$$ |$$ $$ $$/$$ |$$$$$/          $$ |  $$ | $$  /$$/  $$$$$/    $$$$$$$  |", obj->value2, BLACK);
	RenderMgr_Draw(7 + obj->value1, 12, "$$ \\__$$ |$$ |  $$ |$$ |$$$/ $$ |$$ |_____       $$ \\__$$ |  $$ $$/   $$ |_____ $$ |  $$ |", obj->value2, BLACK);
	RenderMgr_Draw(7 - obj->value1, 13, "$$    $$/ $$ |  $$ |$$ | $/  $$ |$$       |      $$    $$/    $$$/    $$       |$$ |  $$ |", obj->value2, BLACK);
	RenderMgr_Draw(7 + obj->value1, 14, " $$$$$$/  $$/   $$/ $$/      $$/ $$$$$$$$/        $$$$$$/      $/     $$$$$$$$/ $$/   $$/ ", obj->value2, BLACK);

	if (obj->value2 == RED)
	{
		RenderMgr_Draw(obj->x, 20, "¢º", WHITE, BLACK);
		if (obj->x == 18)
		{
			RenderMgr_Draw(20, 20, "RETRY", WHITE, BLACK);
			RenderMgr_Draw(40, 20, "EXIT", DARK_GRAY, BLACK);
		}
		else
		{
			RenderMgr_Draw(20, 20, "RETRY", DARK_GRAY, BLACK);
			RenderMgr_Draw(40, 20, "EXIT", WHITE, BLACK);
		}
	}
}

