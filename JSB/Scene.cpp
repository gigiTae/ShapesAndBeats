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

	// �÷��̾� �޸� ����
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
	// �÷��̾� �浹
	if (CollisionMgr_Arr[player->x][player->y] == ON_COLLISION)
		Object_HitPlayer();

}



int AddObject(void (*function_init)(Object*), short _x, short _y, int _value1, int _value2)
{
	// ���� �迭�� �ε����� �޾ƿ��� �迭�� ������� ã�´�.
	int index = SceneMgr_curScene->addIndex;
	while (true)
	{
		++SceneMgr_curScene->addIndex;
		if (SceneMgr_curScene->addIndex >= SCENE_OBJ_ARR_SIZE)
			SceneMgr_curScene->addIndex = 0;

		if(SceneMgr_curScene->objArr[SceneMgr_curScene->addIndex] == nullptr)
			break;
	}
	
	// �迭 ���� �̻��� ������ ��� => �̰� �߻��ϸ� �迭�� ũ�⸦ �ø��ų� ����ȭ �ڵ�� �ٽ� �����ؾ��մϴ�
	assert(index != SCENE_OBJ_ARR_SIZE);

	// ���� �迭�� �������� ���� �Ҵ�
	SceneMgr_curScene->objArr[index] = (Object*)malloc(sizeof(Object));
	assert(SceneMgr_curScene->objArr[index]);

	// ���޹��� Init �Լ��� �̿��ؼ� ������Ʈ �ʱ�ȭ
	function_init(SceneMgr_curScene->objArr[index]);
	
	// �ڽ��� Scene�� �迭 ���°�� ��ġ
	SceneMgr_curScene->objArr[index]->arrIndex = index;

	// ������Ʈ ��ġ �ʱ�ȭ
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
