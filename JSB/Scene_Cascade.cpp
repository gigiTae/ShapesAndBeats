#include "pch.h"
#include "Scene_Cascade.h"
#include "Scene.h"
#include "Object.h"
#include "SoundMgr.h"
#include "Object_Player.h"
#include "SceneMgr.h"
#include "EventMgr.h"
#include "Object_Cascade.h"

void Scene_Casacade_Start()
{
	AddPlayerObject(Object_InitPlayer, 30, 15);
	EventMgr_AddObject(Object_InitCascade, 0, 0, 0);
}

void Scene_Casacade_Init(Scene* scene)
{
	scene->objPlayer = nullptr;
	scene->addIndex = 0;
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		scene->objArr[i] = nullptr;
	}

	scene->Scene_Start = Scene_Casacade_Start;
	scene->Scene_Update = Scene_Default_Update;
	scene->Scene_Render = Scene_Default_Render;
	scene->Scene_Exit = Scene_Defalut_Exit;
}

