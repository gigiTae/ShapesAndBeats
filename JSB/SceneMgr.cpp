 #include "pch.h"
#include "SceneMgr.h"
#include "EventMgr.h"
#include "Scene.h"
#include "Scene_Main.h"
#include "Scene_Select.h"
#include "Scene_Higher.h"
#include "Scene_Cascade.h"
#include "Scene_GameOver.h"
#include "Scene_Sevcon.h"
#include "Scene_Tutorial.h"
#include "Scene_Clear.h"

Scene* SceneMgr_arrScene[SCNEN_TYPE_END]{}; // 모든 씬 목록
Scene* SceneMgr_curScene =nullptr;                   // 현재 씬

void SceneMgr_Init()
{
	// 씬 초기화 
	SceneMgr_arrScene[SCENE_MAIN] = (Scene*)malloc(sizeof(Scene));
	assert(SceneMgr_arrScene[SCENE_MAIN]);
	Scene_Main_Init(SceneMgr_arrScene[SCENE_MAIN]);

	SceneMgr_arrScene[SCENE_TUTORIAL] = (Scene*)malloc(sizeof(Scene));
	assert(SceneMgr_arrScene[SCENE_TUTORIAL]);
	Scene_Tutorial_Init(SceneMgr_arrScene[SCENE_TUTORIAL]);

	SceneMgr_arrScene[SCENE_SELECT] = (Scene*)malloc(sizeof(Scene));
	assert(SceneMgr_arrScene[SCENE_SELECT]);
	Scene_Select_Init(SceneMgr_arrScene[SCENE_SELECT]);

	SceneMgr_arrScene[SCENE_CASCADE] = (Scene*)malloc(sizeof(Scene));
	assert(SceneMgr_arrScene[SCENE_CASCADE]);
	Scene_Casacade_Init(SceneMgr_arrScene[SCENE_CASCADE]);

	SceneMgr_arrScene[SCENE_HiGHER] = (Scene*)malloc(sizeof(Scene));
	assert(SceneMgr_arrScene[SCENE_HiGHER]);
	Scene_Higher_Init(SceneMgr_arrScene[SCENE_HiGHER]);

	SceneMgr_arrScene[SCENE_SEVCON] = (Scene*)malloc(sizeof(Scene));
	assert(SceneMgr_arrScene[SCENE_SEVCON]);
	Scene_Sevcon_Init(SceneMgr_arrScene[SCENE_SEVCON]);

	SceneMgr_arrScene[SCENE_GAMEOVER] = (Scene*)malloc(sizeof(Scene));
	assert(SceneMgr_arrScene[SCENE_GAMEOVER]);
	Scene_GameOver_Init(SceneMgr_arrScene[SCENE_GAMEOVER]);

	SceneMgr_arrScene[SCENE_CLEAR] = (Scene*)malloc(sizeof(Scene));
	assert(SceneMgr_arrScene[SCENE_CLEAR]);
	Scene_Clear_Init(SceneMgr_arrScene[SCENE_CLEAR]);

    
	// 시작 씬 지정
	SceneMgr_curScene = SceneMgr_arrScene[SCENE_MAIN];
 	SceneMgr_curScene->Scene_Start();
}

void SceneMgr_Update()
{
	SceneMgr_curScene->Scene_Update();
}

void SceneMgr_Render()
{
	SceneMgr_curScene->Scene_Render();
}

// Scene을 변경할때 호출하는함수 *버그발생위험있음
void SceneMgr_Change(Scene* next)
{
	SceneMgr_curScene->Scene_Exit();
	
	SceneMgr_curScene = next;

	SceneMgr_curScene->Scene_Start();
}

void SceneMgr_Exit()
{
	// 현재씬 Exit
	SceneMgr_curScene->Scene_Exit();

	// 씬메모리해제
	for (int i = 0; i < SCNEN_TYPE_END; ++i)
	{
		if (SceneMgr_arrScene[i] != nullptr)
		{
			free(SceneMgr_arrScene[i]);
		}
	}

}

