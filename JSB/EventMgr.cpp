#include "pch.h"
#include "EventMgr.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "TimgMgr.h"

static AddObjectStruct* addArr[ADD_OBJECT_ARR_SIZE];
static DestroyObjectStruct* destroyArr[SCENE_OBJ_ARR_SIZE];
static int addIndex;
static int destroyIndex;
static int scene_number;

void EventMgr_Init()
{
	addIndex = 0;
	scene_number = -1;
	for (int i = 0; i < ADD_OBJECT_ARR_SIZE; ++i)
	{
		addArr[i] = nullptr;
	}

	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		destroyArr[i] = nullptr;
	}
}

void EventMgr_Update()
{
	// �߰��ϴ� ������Ʈ ����
	for (int i = 0; i < addIndex; ++i)
	{
		if(addArr[i] == nullptr) continue;

		int index =AddObject(addArr[i]->function_init, addArr[i]->x, addArr[i]->y
			, addArr[i]->value1, addArr[i]->value2);

		// ���� ������Ʈ�� �־���
		// destroyTime = 0 �̸� �������� �ʴ� ������Ʈ
		if (addArr[i]->destroyTime != 0)
		{
			DestroyObjectStruct* D_obj = (DestroyObjectStruct*)malloc(sizeof(DestroyObjectStruct));
			assert(D_obj);
			D_obj->arrIndex = index;
			D_obj->createTime = 0;
			D_obj->destroyTime = addArr[i]->destroyTime;
			destroyArr[destroyIndex] = D_obj;

			while (true)
			{
				++destroyIndex;
				// �迭������ �Ѿ ���
				if (destroyIndex >= SCENE_OBJ_ARR_SIZE)
					destroyIndex = 0;

				// ���� ������ ��
				if(destroyArr[destroyIndex] ==nullptr)
					break;
			}
		}

		free(addArr[i]);
		addArr[i] = nullptr;
	}
	addIndex = 0;

	// �����ϴ� ������Ʈ ����
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		if(destroyArr[i] == nullptr)
			continue;

		destroyArr[i]->createTime += (int)TimeMgr_deltaTime;

		// ������Ʈ ����
		if (destroyArr[i]->createTime >= destroyArr[i]->destroyTime)
		{
			free(SceneMgr_curScene->objArr[destroyArr[i]->arrIndex]);
			SceneMgr_curScene->objArr[destroyArr[i]->arrIndex] = nullptr;

			free(destroyArr[i]);
			destroyArr[i] = nullptr;
		}
	}

	if (scene_number != -1)
	{
		// �ٲٷ��� ���� ���°�� ���
		assert(scene_number < SCNEN_TYPE_END && scene_number > -1);
		EventMgr_Exit();
		SceneMgr_Change(SceneMgr_arrScene[scene_number]);
		scene_number = -1;
	}
	
}

void EventMgr_Exit()
{
	for (int i = 0; i < ADD_OBJECT_ARR_SIZE; ++i)
	{
		if (addArr[i] != nullptr)
		{
			free(addArr[i]);
			addArr[i] = nullptr;
		}
	}
	addIndex = 0;

	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		if (destroyArr[i] != nullptr)
			free(destroyArr[i]);
		destroyArr[i] = nullptr;
	}
}

void EventMgr_AddObject(void (*function_init)(Object*), short _x, short _y, int _destroyTime)
{
	AddObjectStruct* obj = ( AddObjectStruct*)malloc(sizeof(AddObjectStruct));
	assert(obj);
	obj->destroyTime = _destroyTime;
	obj->x = _x;
	obj->y = _y;
	obj->function_init = function_init;
	obj->value1 = 0;
	obj->value2 = 0;

	assert(addIndex < ADD_OBJECT_ARR_SIZE); //�������ӿ� 100�� ������Ʈ 100���̻� �߰��� ���
	addArr[addIndex++] = obj;
}

// Ư���� ���
void EventMgr_AddObject_value(void (*function_init)(Object*), short _x, short _y, int _destroyTime, int _value1, int _value2)
{
	AddObjectStruct* obj = (AddObjectStruct*)malloc(sizeof(AddObjectStruct));
	assert(obj);
	obj->destroyTime = _destroyTime;
	obj->x = _x;
	obj->y = _y;
	obj->function_init = function_init;

	obj->value1 = _value1;
	obj->value2 = _value2;

	assert(addIndex < ADD_OBJECT_ARR_SIZE); //�������ӿ� 100�� ������Ʈ 100���̻� �߰��� ���
	addArr[addIndex++] = obj;
}

void EventMgr_ChangeScene(int _scene_number)
{
	scene_number = _scene_number;
}
