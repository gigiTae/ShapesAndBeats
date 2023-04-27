#include "pch.h"
#include "RenderMgr.h"
#include "CollisionMgr.h"

HANDLE RenderMgr_screen[2]{};
bool RenderMgr_index = false;

void RenderMgr_Init()
{
	// 화면 버퍼 2개 생성
	RenderMgr_screen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	RenderMgr_screen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서 설정
	CONSOLE_CURSOR_INFO cursor_info{ 0, };
	cursor_info.bVisible = false; // 커서를 보일지 말지 결정
	cursor_info.dwSize = 1;
	SetConsoleCursorInfo(RenderMgr_screen[0], &cursor_info);
	SetConsoleCursorInfo(RenderMgr_screen[1], &cursor_info);

	// 콘솔창 크기 설정
	COORD buffer_size = { SCREEN_WIDTH* SCREEN_ADJUST, SCREEN_LENGTH};
	SetConsoleScreenBufferSize(RenderMgr_screen[0], buffer_size);
	SetConsoleScreenBufferSize(RenderMgr_screen[1], buffer_size);
}

// 버퍼 지우기
void RenderMgr_ClearScreen()
{
	COORD coor = { 0,0 };
	DWORD dw;

	int color = (int)BLACK + (int)BLACK * 16;

	FillConsoleOutputCharacter(RenderMgr_screen[RenderMgr_index], ' ', SCREEN_WIDTH * SCREEN_LENGTH * SCREEN_ADJUST, coor, &dw);
	FillConsoleOutputAttribute(RenderMgr_screen[RenderMgr_index], color, SCREEN_WIDTH * SCREEN_LENGTH * SCREEN_ADJUST, coor, &dw);

	// 너무  느려지면 아래 방법 사용
	//CHAR_INFO buffer[SCREEN_WIDTH * SCREEN_LENGTH];
	//COORD coor = { 0, 0 };
	//SMALL_RECT rect = { 0, 0, SCREEN_WIDTH - 1, SCREEN_LENGTH - 1 };

	//for (int i = 0; i < SCREEN_WIDTH * SCREEN_LENGTH; i++)
	//{
	//	buffer[i].Char.AsciiChar = ' ';
	//	buffer[i].Attributes = color;
	//}

	//WriteConsoleOutput(RenderMgr_screen[RenderMgr_index], buffer, { SCREEN_WIDTH, SCREEN_LENGTH }, coor, &rect);
}

// 버퍼 바꾸기
void RenderMgr_ChangeScreen()
{
	SetConsoleActiveScreenBuffer(RenderMgr_screen[RenderMgr_index]);
	RenderMgr_index = !RenderMgr_index;
}

// 버퍼에 그리기
void RenderMgr_Draw(short x, short y, const char* str, int foreground, int background)
{
	// 화면밖으로 출력하는 경우
	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_LENGTH)
	{
		return;
	}

	COORD Cur = { (short)x * SCREEN_ADJUST, (short)y };

	DWORD dw;

	// 커서위치 이동
	SetConsoleCursorPosition(RenderMgr_screen[RenderMgr_index], Cur);

	// 컬러 변경
	int color = (int)foreground + (int)background * 16;
	SetConsoleTextAttribute(RenderMgr_screen[RenderMgr_index], color);

	WriteFile(RenderMgr_screen[RenderMgr_index], str, (DWORD)strlen(str), &dw, NULL);
}

void RenderMgr_DrawC(short x, short y, short collision_len, const char* str, int foreground, int background)
{
	// 화면밖으로 출력하는 경우
	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_LENGTH)
	{
		return;
	}

	// 충돌 체크
	for (int i = 0; i < collision_len; ++i)
	{
		CollisionMgr_Arr[x + i][y] = ON_COLLISION;
	}

	COORD Cur = { (short)x * SCREEN_ADJUST, (short)y };

	DWORD dw;

	// 커서위치 이동
	SetConsoleCursorPosition(RenderMgr_screen[RenderMgr_index], Cur);

	// 컬러 변경
	int color = (int)foreground + (int)background * 16;
	SetConsoleTextAttribute(RenderMgr_screen[RenderMgr_index], color);

	WriteFile(RenderMgr_screen[RenderMgr_index], str, (DWORD)strlen(str), &dw, NULL);
}

