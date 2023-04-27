#include "pch.h"
#include "Player.h"
#include "Object.h"
#include "KeyMgr.h"
#include "RenderMgr.h"
#include "TimgMgr.h"

static int moveCoolTime = 50;
static bool moveAvailable = true;
static bool dashAvailable = true;
static bool flip = true;

unsigned DashCoolDown(void* arg) {
	dashAvailable = false;
	Sleep(200);
	moveCoolTime = 50;
	Sleep(600);
	dashAvailable = true;

	return 0;
}

unsigned MoveCoolDown(void* arg) {
	moveAvailable = false;
	Sleep(moveCoolTime);
	moveAvailable = true;

	return 0;
}

void Object_InitPlayer(Object* player)
{
	player->name = "dd";
	player->background = SKYBLUE;
	player->foreground = SKYBLUE;
	player->x = 10;
	player->y = 10;
	player->time = 0;
	player->Object_Update = Object_UpdatePlayer;
	player->Object_Render = Object_RenderPlayer;
}

void Object_UpdatePlayer(Object* player)
{
	player->time += TimeMgr_deltaTime;

	if (moveAvailable == true)
	{
		_beginthreadex(NULL, 0, MoveCoolDown, 0, 0, NULL);
		if (keyInfo[LEFT].state == HOLD)
		{
			--player->x;
		}
		if (keyInfo[RIGHT].state == HOLD)
		{
			++player->x;
		}
		if (keyInfo[UP].state == HOLD)
		{
			--player->y;

		}
		if (keyInfo[DOWN].state == HOLD)
		{
			++player->y;
		}

		if (keyInfo[SPACE].state == HOLD)
		{
			//대쉬
			///대쉬할때 팡 튀기는 이펙트가 있으면 좋겠다!
			if (dashAvailable == true)
			{
				_beginthreadex(NULL, 0, DashCoolDown, 0, 0, NULL);
				moveCoolTime = 1;
			}
		}
	}

}

void Object_RenderPlayer(Object* player)
{
	if (dashAvailable)
	{
		RenderMgr_Draw(player->x, player->y, player->name, player->foreground, player->background);
	}
	else
	{
		if (flip)
			RenderMgr_Draw(player->x, player->y, player->name, BLUE, BLUE);
		else
			RenderMgr_Draw(player->x, player->y, player->name, WHITE, WHITE);

		flip = !flip;
	}

}
