#include "pch.h"
#include "Scene.h"
#include "Scene_Sevcon.h"
#include "Object_Player.h"
#include "SceneMgr.h"
#include "EventMgr.h"
#include "SoundMgr.h"
#include "Object_Snow.h"
#include "Object_Sevcon.h"

void Scene_Sevcon_Start()
{
	AddPlayerObject(Object_InitPlayer, 30, 15);
	
	EventMgr_AddObject(Object_InitSevcon, 0, 0, 0);

}

void Scene_Sevcon_Init(Scene* scene)
{
	scene->objPlayer = nullptr;
	scene->addIndex = 0;
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		scene->objArr[i] = nullptr;
	}

	scene->Scene_Start = Scene_Sevcon_Start;
	scene->Scene_Update = Scene_Default_Update;
	scene->Scene_Render = Scene_Default_Render;
	scene->Scene_Exit = Scene_Defalut_Exit;
}

