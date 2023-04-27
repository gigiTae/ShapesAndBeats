#include "pch.h"
#include "RenderMgr.h"
#include "Object.h"
#include "Object_TutorialUI.h"
#include "TimgMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "EventMgr.h"
#include "KeyMgr.h"
#include "Object_Player.h"

extern bool isFireworkPlayed;
extern int logoY;
extern bool isBounced;
extern bool isFireThreadStarted;
extern bool isTapSpace;
extern bool showLogo;


void Object_InitTutorialUI(Object* player)
{
	player->time = 0;
	player->Object_Update = Object_UpdateTutorialUI;
	player->Object_Render = Object_RenderTutorialUI;
}

void Object_UpdateTutorialUI(Object* player)
{
	if (SceneMgr_curScene->objPlayer->x == 50 && SceneMgr_curScene->objPlayer->y == 15)
	{
		//메인 ui의 변수 초기화
		isFireworkPlayed = false;
		logoY = -19;
		isBounced = false;
		isFireThreadStarted = false;
		isTapSpace = false;
		showLogo = false;
		
		EventMgr_ChangeScene(MAINSCENE);
	}

	if (Player_Color < 16 && keyInfo[S].state == TAP) 
	{
		Player_Color++;
		EventMgr_ChangeScene(SCENE_TUTORIAL);
	}
	else if (Player_Color > 0 && keyInfo[D].state == TAP)
	{
		Player_Color--;
		EventMgr_ChangeScene(SCENE_TUTORIAL);
	}
}

void Object_RenderTutorialUI(Object* player)
{
	RenderMgr_Draw(5, 20, "이동 : → ← ↑ ↓ ", WHITE, BLACK);
	RenderMgr_Draw(5, 22, "대쉬 : Space ", WHITE, BLACK);

	if (keyInfo[SPACE].state == NONE)
		RenderMgr_Draw(38, 29, "Tip: 게임을 클리어하고 별똥별을 찾아보세요!", DARK_GRAY, BLACK);
	else
		RenderMgr_Draw(38, 29, "Tip: 게임을 클리어하고 별똥별을 찾아보세요!", YELLOW, BLACK);

	for (int i = 0; i < 30; ++i)
		RenderMgr_DrawC(20, i, 1, "◀", RED, BLACK);

	for (int i = 0; i < 30; ++i)
		RenderMgr_DrawC(30, i, 1, "◀", RED, BLACK);

		RenderMgr_Draw(50, 15, "EXIT", WHITE, BLACK);
}
