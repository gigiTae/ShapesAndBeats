#pragma once

struct Object;

typedef struct Scene
{
	Object* objArr[SCENE_OBJ_ARR_SIZE]; // Scene이 관리하는 오브젝트
	Object* objPlayer;
	int addIndex;         // 다음에 추가하는 인덱스

	void (*Scene_Start)(); // 씬 시작시 호출
	void (*Scene_Exit)();  // 씬 나갈때 호출
	void (*Scene_Update)(); // 씬 업데이트
	void (*Scene_Render)(); // 씬 렌더링

}Scene;

void Scene_Defalut_Exit();
void Scene_Default_Update();
void Scene_Default_Render();

/// <summary>
/// private 함수 사용X
/// </summary>
/// <param name="function_init"></param>
/// <param name="_x"></param>
/// <param name="_y"></param>
/// <param name="_value1"></param>
/// <param name="_value2"></param>
/// <returns></returns>
int AddObject(void (*function_init)(Object*), short _x, short _y, int _value1, int _value2);
void AddPlayerObject(void (*function_init)(Object*), short _x, short _y);
