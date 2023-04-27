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
	int arrIndex; // 현재씬 배열의 인덱스
	int createTime; // 생성 시간
	int destroyTime; // 삭제 시간
};


void EventMgr_Init();
void EventMgr_Update();
void EventMgr_Exit();

/// <summary>
/// 오브젝트 추가함수
/// </summary>
/// <param name="function_init">초기화함수</param>
/// <param name="_x">x좌표</param>
/// <param name="_y">y좌표</param>
/// <param name="_destroyTime">1ms단위,0이면 삭제하지않음</param>
void EventMgr_AddObject(void (*function_init)(Object*), short _x, short _y, int _destroyTime);

/// <summary>
/// 오브젝트 추가함수 + value1,2를 추가해서 오브젝트 생성시 도움을줍니다.
/// </summary>
/// <param name="function_init">초기화함수</param>
/// <param name="_x">x좌표</param>
/// <param name="_y">y좌표</param>
/// <param name="_destroyTime">1ms단위,0이면 삭제하지않음</param>
/// <param name="_value1">오브젝트마다 다른용도로 사용하는 값</param>
/// <param name="_value2">오브젝트마다 다른용도로 사용하는 값</param>
void EventMgr_AddObject_value(void (*function_init)(Object*), short _x, short _y, int _destroyTime, int _value1, int _value2);

void EventMgr_ChangeScene(int scene_number);