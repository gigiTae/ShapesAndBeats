#include "pch.h"
#include "Scene_Select.h"
#include "Object.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Object_SelectUI.h"


void Scene_Select_Start()
{
	AddObject(Object_InitSelectUI, 0, 0, 0, 0);
}

void Scene_Select_Init(Scene* scene)
{
	scene->objPlayer = nullptr;
	scene->addIndex = 0;
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		scene->objArr[i] = nullptr;
	}

	scene->Scene_Start = Scene_Select_Start;
	scene->Scene_Update = Scene_Default_Update;
	scene->Scene_Render = Scene_Default_Render;
	scene->Scene_Exit = Scene_Defalut_Exit;
}
