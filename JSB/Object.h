#pragma once

typedef struct Object
{
	int arrIndex; // 배열 인덱스
	// 위치
	short x;
	short y;
	int foreground; // 문자색
	int background; // 배경색
	unsigned long long time; 

	int value1;
	int value2;
	float fvalue1;
	float fvalue2;

	const char* name; // 출력문자

	// 함수 포인터를 이용해서 오브젝트마다 함수들을 구현해야함
	void (*Object_Update)(Object*);
	void (*Object_Render)(Object*);
}Object;

 