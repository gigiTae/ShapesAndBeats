#include "pch.h"
#include "Scene_Main.h"
#include "Object.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Object_MainUI.h"
#include "SoundMgr.h"
#include "SoundMgr.h"
#include "EventMgr.h"



void Scene_Main_Start()
{
	// =========���⿡ ������Ʈ�� �߰�=============
	EventMgr_AddObject_value(Object_InitMainUI, 0, 0, 0, 0, 0);
}


void Scene_Main_Init(Scene* scene)
{
	scene->objPlayer = nullptr;
	scene->addIndex = 0;
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		scene->objArr[i] = nullptr;
	}

	scene->Scene_Start = Scene_Main_Start;
	scene->Scene_Update = Scene_Default_Update;
	scene->Scene_Render = Scene_Default_Render;
	scene->Scene_Exit = Scene_Main_Exit;
} 

void Scene_Main_Exit()
{
	SoundMgr_StopSound();

	SceneMgr_curScene->addIndex = 0;
	// ������Ʈ�� �޸� ����
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		if (SceneMgr_curScene->objArr[i] != nullptr)
		{
			free(SceneMgr_curScene->objArr[i]);

			// �޸𸮸� �����ϰ� �����ʹ� nullptr�� ����Ŵ
			SceneMgr_curScene->objArr[i] = nullptr;
		}
	}
}
