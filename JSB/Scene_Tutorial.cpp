#include "pch.h"
#include "Scene_Tutorial.h"
#include "Scene.h"
#include "Player.h"
#include "SoundMgr.h"
#include "EventMgr.h"
#include "SceneMgr.h"
#include "Object.h"
#include "Scene.h"
#include "Object_TutorialUI.h"

void Scene_Tutorial_Start()
{
	AddPlayerObject(Object_InitPlayer, 10, 15);

	EventMgr_AddObject(Object_InitTutorialUI, 0, 0, 0);
	SceneMgr_curScene->objPlayer->value1 = 1;
	SoundMgr_PlaySound(TUTORIAL);
}

void Scene_Tutorial_Init(Scene* scene)
{
	scene->objPlayer = nullptr;
	scene->addIndex = 0;
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		scene->objArr[i] = nullptr;
	}
	scene->Scene_Start = Scene_Tutorial_Start;
	scene->Scene_Update = Scene_Default_Update;
	scene->Scene_Render = Scene_Default_Render;
	scene->Scene_Exit = Scene_Defalut_Exit;
}
