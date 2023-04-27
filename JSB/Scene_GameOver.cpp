#include "pch.h"
#include "Scene_GameOver.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventMgr.h"
#include "Object_GameOverUI.h"

void Scene_GameOver_Start()
{
	EventMgr_AddObject_value(Object_InitGameOverUI, 0, 0, 0,7,8);
}

void Scene_GameOver_Init(Scene* scene)
{

	scene->objPlayer = nullptr;
	scene->addIndex = 0;
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		scene->objArr[i] = nullptr;
	}

	scene->Scene_Start = Scene_GameOver_Start;
	scene->Scene_Update = Scene_Default_Update;
	scene->Scene_Render = Scene_Default_Render;
	scene->Scene_Exit = Scene_Defalut_Exit;
}
