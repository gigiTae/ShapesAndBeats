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
	// 추가하는 오브젝트 관리
	for (int i = 0; i < addIndex; ++i)
	{
		if(addArr[i] == nullptr) continue;

		int index =AddObject(addArr[i]->function_init, addArr[i]->x, addArr[i]->y
			, addArr[i]->value1, addArr[i]->value2);

		// 삭제 오브젝트에 넣어줌
		// destroyTime = 0 이면 삭제하지 않는 오브젝트
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
				// 배열공간을 넘어간 경우
				if (destroyIndex >= SCENE_OBJ_ARR_SIZE)
					destroyIndex = 0;

				// 다음 공간에 들어감
				if(destroyArr[destroyIndex] ==nullptr)
					break;
			}
		}

		free(addArr[i]);
		addArr[i] = nullptr;
	}
	addIndex = 0;

	// 삭제하는 오브젝트 관리
	for (int i = 0; i < SCENE_OBJ_ARR_SIZE; ++i)
	{
		if(destroyArr[i] == nullptr)
			continue;

		destroyArr[i]->createTime += (int)TimeMgr_deltaTime;

		// 오브젝트 삭제
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
		// 바꾸려는 씬이 없는경우 경고
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

	assert(addIndex < ADD_OBJECT_ARR_SIZE); //한프레임에 100개 오브젝트 100개이상 추가한 경우
	addArr[addIndex++] = obj;
}

// 특수한 경우
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

	assert(addIndex < ADD_OBJECT_ARR_SIZE); //한프레임에 100개 오브젝트 100개이상 추가한 경우
	addArr[addIndex++] = obj;
}

void EventMgr_ChangeScene(int _scene_number)
{
	scene_number = _scene_number;
}
