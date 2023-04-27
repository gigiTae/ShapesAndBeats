#include "pch.h"
#include "Object_Player.h"
#include "Object.h"
#include "SoundMgr.h"
#include "TimgMgr.h"
#include "KeyMgr.h"
#include "RenderMgr.h"
#include "EventMgr.h"
#include "Object_Dash.h"
#include "Object_Dead.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "SoundMgr.h"
#include "Object_TutorialUI.h"

#define PLAYER_MAXHP 2
#define DASH_COOLTIME 500 //1��
#define DASH_TIME 300
#define MOVE_SPEED 100
#define DASH_SPEED 25


int Player_Color = SKYBLUE;

static int playerState = PLAYER_DEAFULT;
static int playerHP = PLAYER_MAXHP;
static int dashTime = 0;

static bool moveAvailable = true;

void Object_InitPlayer(Object* player)
{
	// �÷��̾� ���� �ʱ�ȭ
	moveAvailable = true;
	playerState = PLAYER_MOVE;
	playerHP = PLAYER_MAXHP;
	dashTime = DASH_COOLTIME;

	player->name = "  "; 
	player->background = Player_Color;
	player->foreground = Player_Color;
	player->x = 30;
	player->y = 15;
	player->time = 0;
	player->Object_Update = Object_UpdatePlayer;
	player->Object_Render = Object_RenderPlayer;
}

void Object_UpdatePlayer(Object* player)
{
	dashTime += (int)TimeMgr_deltaTime;
	player->time += TimeMgr_deltaTime;

	if (playerState == PLAYER_MOVE)
	{
		if (dashTime >= DASH_COOLTIME)		dashTime = DASH_COOLTIME;

		// �뽬
		if (keyInfo[SPACE].state == TAP && dashTime == DASH_COOLTIME)
		{
			EventMgr_AddObject(Object_InitDash, player->x, player->y, 200);
			playerState = PLAYER_DASH;
			dashTime = 0;
		}
		else if(keyInfo[A].state ==TAP) // �����ڸ��
		{
			playerState = PLAYER_GOD;
		}
		
		/// �÷��̾� �̵�
		if (player->time >= MOVE_SPEED)
		{
			if (keyInfo[LEFT].state == HOLD && player->x > 0)
			{
				--player->x;
			}
			if (keyInfo[RIGHT].state == HOLD &&player->x < SCREEN_WIDTH-1)
			{
				++player->x;
			}
			if (keyInfo[UP].state == HOLD && player->y > 0)
			{
				--player->y;
			}
			if (keyInfo[DOWN].state == HOLD && player->y < SCREEN_LENGTH-1)
			{
				++player->y;
			}
			player->time -= MOVE_SPEED;
		}
		
	}
	else if (playerState == PLAYER_DASH) /// �뽬
	{
		if (dashTime >= DASH_TIME) playerState = PLAYER_MOVE;

		if (player->time >= DASH_SPEED)
		{
			if (keyInfo[LEFT].state == HOLD && player->x > 0)
			{
				--player->x;
			}
			if (keyInfo[RIGHT].state == HOLD && player->x < SCREEN_WIDTH - 1)
			{
				++player->x;
			}
			if (keyInfo[UP].state == HOLD && player->y > 0)
			{
				--player->y;
			}
			if (keyInfo[DOWN].state == HOLD && player->y < SCREEN_LENGTH - 1)
			{
				++player->y;
			}
			player->time -= DASH_SPEED;
		}

	}
	else if (playerState == PLAYER_HIT) /// �ǰ�
	{
		if (dashTime >= DASH_COOLTIME) /// �����ð��� �뽬��Ÿ�Ӱ� ����
		{
			playerState = PLAYER_MOVE;
			dashTime = DASH_COOLTIME;
		}

		if (player->time >= MOVE_SPEED)
		{
			if (keyInfo[LEFT].state == HOLD && player->x > 0)
			{
				--player->x;
			}
			if (keyInfo[RIGHT].state == HOLD && player->x < SCREEN_WIDTH - 1)
			{
				++player->x;
			}
			if (keyInfo[UP].state == HOLD && player->y > 0)
			{
				--player->y;
			}
			if (keyInfo[DOWN].state == HOLD && player->y < SCREEN_LENGTH - 1)
			{
				++player->y;
			}
			player->time -= MOVE_SPEED;
		}
	}
	else if (playerState == PLAYER_DEAD) // �Է¹��� ����
	{
		// 2���Ŀ� ���ӿ��� ������
		if (player->value1 == 1)
			EventMgr_ChangeScene(SCENE_TUTORIAL);

		if (player->time >= 2000 )
			EventMgr_ChangeScene(SCENE_GAMEOVER);
	}
	else if (playerState == PLAYER_GOD) // �������
	{
		if (keyInfo[A].state == TAP)
			playerState = PLAYER_MOVE;

		if (player->time >= DASH_SPEED)
		{
			if (keyInfo[LEFT].state == HOLD && player->x > 0)
			{
				--player->x;
			}
			if (keyInfo[RIGHT].state == HOLD && player->x < SCREEN_WIDTH - 1)
			{
				++player->x;
			}
			if (keyInfo[UP].state == HOLD && player->y > 0)
			{
				--player->y;
			}
			if (keyInfo[DOWN].state == HOLD && player->y < SCREEN_LENGTH - 1)
			{
				++player->y;
			}
			player->time -= DASH_SPEED;
		}
	}
}


void Object_RenderPlayer(Object* player)
{
	if (playerState == PLAYER_MOVE)
	{
		RenderMgr_Draw(player->x, player->y, "��", WHITE, player->foreground);
	}
	else if (playerState == PLAYER_DASH)
	{
		RenderMgr_Draw(player->x, player->y, "��", player->foreground, BLACK);
	}
	else if (playerState == PLAYER_DEAD)
	{
		RenderMgr_Draw(player->x, player->y, "��", BLACK, DARK_GRAY );
	}
	else if (playerState == PLAYER_GOD)
	{
		RenderMgr_Draw(player->x, player->y, "��", WHITE, YELLOW);
	}
	else if (playerState == PLAYER_HIT)
	{
		int state = rand() % 2;
		if (state == 0)
			RenderMgr_Draw(player->x, player->y, "��", WHITE, player->foreground);
		else
			RenderMgr_Draw(player->x, player->y, "��", player->foreground, WHITE);
	}

}

void Object_HitPlayer()
{
	if (playerState != PLAYER_MOVE ) // ���������� ��� 
		return;
	if (playerHP > 0) // ü���� �������
	{
		SoundMgr_PlayEffect(HIT);
		playerHP--;
		playerState = PLAYER_HIT;
		dashTime = 0;
		return;
	}
	else // ü���� ���� ���
	{
		playerState = PLAYER_DEAD;
		Object* player = SceneMgr_curScene->objPlayer;
		assert(player);
		// �÷��̾� ��� �ִϸ��̼�
		EventMgr_AddObject(Object_InitDead, player->x, player->y, 500);
		SoundMgr_StopSound();
		SoundMgr_PlayEffect(DIE);
		player->time = 0;
	}
}

