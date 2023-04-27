#include "pch.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "Object.h"
#include "CollisionMgr.h"
#include "Object_Player.h"
#include "SoundMgr.h"
void Scene_Defalut_Exit()
{
	SceneMgr_curScene->addIndex = 0;
	// 오브젝트들 메모리 해제
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		if (SceneMgr_curScene->objArr[i] != nullptr)
		{
			free(SceneMgr_curScene->objArr[i]);

			// 메모리를 해제하고 포인터는 nullptr를 가리킴
			SceneMgr_curScene->objArr[i] = nullptr;
		}
	}

	// 플레이어 메모리 해제
	if (SceneMgr_curScene->objPlayer != nullptr)
		free(SceneMgr_curScene->objPlayer);

	SoundMgr_StopSound();
}


void Scene_Default_Update()
{
	Scene* cur = SceneMgr_curScene; 
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		if (cur->objArr[i] != nullptr)
			cur->objArr[i]->Object_Update(cur->objArr[i]);
	}
}

void Scene_Default_Render()
{
	Scene* cur = SceneMgr_curScene;
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		if (cur->objArr[i] != nullptr)
			cur->objArr[i]->Object_Render(cur->objArr[i]);
	}

	Object* player = cur->objPlayer;
	if (player == nullptr)
		return;

	player->Object_Update(player);
	player->Object_Render(player);
	// 플레이어 충돌
	if (CollisionMgr_Arr[player->x][player->y] == ON_COLLISION)
		Object_HitPlayer();

}



int AddObject(void (*function_init)(Object*), short _x, short _y, int _value1, int _value2)
{
	// 현재 배열에 인덱스를 받아오고 배열에 빈공간을 찾는다.
	int index = SceneMgr_curScene->addIndex;
	while (true)
	{
		++SceneMgr_curScene->addIndex;
		if (SceneMgr_curScene->addIndex >= SCENE_OBJ_ARR_SIZE)
			SceneMgr_curScene->addIndex = 0;

		if(SceneMgr_curScene->objArr[SceneMgr_curScene->addIndex] == nullptr)
			break;
	}
	
	// 배열 공간 이상을 접근한 경우 => 이거 발생하면 배열의 크기를 늘리거나 최적화 코드로 다시 수정해야합니다
	assert(index != SCENE_OBJ_ARR_SIZE);

	// 씬의 배열에 동적으로 공간 할당
	SceneMgr_curScene->objArr[index] = (Object*)malloc(sizeof(Object));
	assert(SceneMgr_curScene->objArr[index]);

	// 전달받은 Init 함수를 이용해서 오브젝트 초기화
	function_init(SceneMgr_curScene->objArr[index]);
	
	// 자신이 Scene의 배열 몇번째에 위치
	SceneMgr_curScene->objArr[index]->arrIndex = index;

	// 오브젝트 위치 초기화
	SceneMgr_curScene->objArr[index]->x = _x;
	SceneMgr_curScene->objArr[index]->y = _y;

	SceneMgr_curScene->objArr[index]->value1 = _value1;
	SceneMgr_curScene->objArr[index]->value2 = _value2;

	return index;
}

void AddPlayerObject(void (*function_init)(Object*), short _x, short _y)
{
	Object* player = (Object*)malloc(sizeof(Object));
	assert(player);
	function_init(player);
	player->x = _x;
	player->y = _y;
	player->arrIndex = 0;
	SceneMgr_curScene->objPlayer = player;
}
