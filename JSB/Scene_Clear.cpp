#include "pch.h"
#include "Scene_Clear.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventMgr.h"
#include "Object_ClearUI.h"
#include "Object_ShootingStar.h"

void Scene_Clear_Start()
{
	for (int i = 0; i < 7; ++i)
		EventMgr_AddObject(Object_InitShootingStar, i * 5, rand() % 5 - 10, 0);

	
	EventMgr_AddObject(Object_InitClearUI, 0, 0, 0);
}

void Scene_Clear_Init(Scene* scene)
{
	scene->objPlayer = nullptr;
	scene->addIndex = 0;
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		scene->objArr[i] = nullptr;
	}

	scene->Scene_Start = Scene_Clear_Start;
	scene->Scene_Update = Scene_Default_Update;
	scene->Scene_Render = Scene_Default_Render;
	scene->Scene_Exit = Scene_Defalut_Exit;
}
