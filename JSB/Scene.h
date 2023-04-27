#pragma once

struct Object;

typedef struct Scene
{
	Object* objArr[SCENE_OBJ_ARR_SIZE]; // Scene�� �����ϴ� ������Ʈ
	Object* objPlayer;
	int addIndex;         // ������ �߰��ϴ� �ε���

	void (*Scene_Start)(); // �� ���۽� ȣ��
	void (*Scene_Exit)();  // �� ������ ȣ��
	void (*Scene_Update)(); // �� ������Ʈ
	void (*Scene_Render)(); // �� ������

}Scene;

void Scene_Defalut_Exit();
void Scene_Default_Update();
void Scene_Default_Render();

/// <summary>
/// private �Լ� ���X
/// </summary>
/// <param name="function_init"></param>
/// <param name="_x"></param>
/// <param name="_y"></param>
/// <param name="_value1"></param>
/// <param name="_value2"></param>
/// <returns></returns>
int AddObject(void (*function_init)(Object*), short _x, short _y, int _value1, int _value2);
void AddPlayerObject(void (*function_init)(Object*), short _x, short _y);
