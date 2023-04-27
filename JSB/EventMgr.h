#pragma once

struct Object;

struct AddObjectStruct
{
	void (*function_init)(Object*);
	int x;
	int y;
	int destroyTime;
	int value1;
	int value2;
};

struct DestroyObjectStruct
{
	int arrIndex; // ����� �迭�� �ε���
	int createTime; // ���� �ð�
	int destroyTime; // ���� �ð�
};


void EventMgr_Init();
void EventMgr_Update();
void EventMgr_Exit();

/// <summary>
/// ������Ʈ �߰��Լ�
/// </summary>
/// <param name="function_init">�ʱ�ȭ�Լ�</param>
/// <param name="_x">x��ǥ</param>
/// <param name="_y">y��ǥ</param>
/// <param name="_destroyTime">1ms����,0�̸� ������������</param>
void EventMgr_AddObject(void (*function_init)(Object*), short _x, short _y, int _destroyTime);

/// <summary>
/// ������Ʈ �߰��Լ� + value1,2�� �߰��ؼ� ������Ʈ ������ �������ݴϴ�.
/// </summary>
/// <param name="function_init">�ʱ�ȭ�Լ�</param>
/// <param name="_x">x��ǥ</param>
/// <param name="_y">y��ǥ</param>
/// <param name="_destroyTime">1ms����,0�̸� ������������</param>
/// <param name="_value1">������Ʈ���� �ٸ��뵵�� ����ϴ� ��</param>
/// <param name="_value2">������Ʈ���� �ٸ��뵵�� ����ϴ� ��</param>
void EventMgr_AddObject_value(void (*function_init)(Object*), short _x, short _y, int _destroyTime, int _value1, int _value2);

void EventMgr_ChangeScene(int scene_number);