#include "pch.h"
#include "Object_SelectUI.h"
#include "Object.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "EventMgr.h"



void Object_InitSelectUI(Object* obj)
{
	obj->name = "  ";
	obj->background = BLACK;
	obj->foreground = WHITE;
	obj->x = 0;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateSelectUI;
	obj->Object_Render = Object_RenderSelectUI;
}

static int prevSelectArrow = 0;		//이전에 선택했던 스테이지
int selectArrow = 1;				//지금 어느 스테이지를 강조할지
static int stack = rand() % 8;		//팡팡쏘는거 최대 몇개까지 그릴지
static int currentStack = 0;		//지금 그려진 갯수
static int stackChange = 0;			//스택 변경까지 남은 시간
static int colorPalete[12] = { 4,12,6,14,10,2,11,3,9,1,5,13 };
static int colorPlaeteIndex = 0;

#define STACK_SHOW_COOL 15

//Exit을 눌렀을 때, 메인에 있는 전역변수를 초기화시켜줌.
extern bool isFireworkPlayed;
extern int logoY;
extern bool isBounced;
extern bool isFireThreadStarted;
extern bool isTapSpace;
extern bool showLogo;




void Object_UpdateSelectUI(Object* obj) 
{
	//스테이지(씬) 선택 관련
	if (prevSelectArrow != selectArrow)
	{
		SoundMgr_StopSound();
		if (selectArrow == 1)		SoundMgr_PlaySound(PV_CASCCADE);
		if (selectArrow == 2)		SoundMgr_PlaySound(PV_SEVCON);
		if (selectArrow == 3)		SoundMgr_PlaySound(PV_HIGHER);

		prevSelectArrow = selectArrow;
	}

	if (keyInfo[UP].state == TAP && selectArrow > 1)
	{
		selectArrow--;
		SoundMgr_PlayEffect(CLICK1);
	}

	if (keyInfo[DOWN].state == TAP && selectArrow < 4)
	{
		selectArrow++;
		SoundMgr_PlayEffect(CLICK1);
	}

	if (keyInfo[SPACE].state == TAP)
	{
		SoundMgr_StopSound();
		SoundMgr_PlayEffect(CLICK2);
		if (selectArrow == 1)		EventMgr_ChangeScene(SCENE_CASCADE);
		if (selectArrow == 2)		EventMgr_ChangeScene(SCENE_SEVCON);
		if (selectArrow == 3)		EventMgr_ChangeScene(SCENE_HiGHER);
		if (selectArrow == 4) 
		{
			//메인 씬의 전역변수 초기화
			isFireworkPlayed = false;
			logoY = -19;
			isBounced = false;
			isFireThreadStarted = false;
			isTapSpace = false;
			showLogo = false;

			EventMgr_ChangeScene(SCENE_MAIN);
		}
	}


	// 팡팡쏘는 이팩트 관련
	obj->time += TimeMgr_deltaTime;
	if (obj->time >= STACK_SHOW_COOL)
	{
		//currentStack의 크기를 stack의 크기에 맞게 1씩 증감시킨다
		if (currentStack < stack) currentStack++;
		if (currentStack > stack) currentStack--;
		
		//하나씩 증가시키며 일정 횟수가 넘어가면 stack의 크기를 변경시킨다.
		stackChange++;

		//랜덤으로 stack의 크기를 정해준다
		if (stackChange == 8)
		{
			stackChange = 0;
			stack = rand() % 8;
		} 

		if (stackChange % 4 == 0)
		{
			if (colorPlaeteIndex + 1 == 12) colorPlaeteIndex = 0;
			else colorPlaeteIndex++;
		}

		obj->time -= STACK_SHOW_COOL;
	}
}



void Object_RenderSelectUI(Object* obj) {

	RenderMgr_Draw(61, 7, "", WHITE, BLACK);
	RenderMgr_Draw(61, 8, "", WHITE, BLACK);
	RenderMgr_Draw(61, 9, "", WHITE, BLACK);
	RenderMgr_Draw(61, 10, "", WHITE, BLACK);
	RenderMgr_Draw(61, 11, "", WHITE, BLACK);
	RenderMgr_Draw(61, 12, "", WHITE, BLACK);

	if (selectArrow == 1)
	{
		DrawRightBlank(colorPalete[colorPlaeteIndex], 1);
		Draw1(colorPalete[colorPlaeteIndex], 1);
		Draw2(WHITE, 1);
		Draw3(WHITE, 1);
		Draw4(WHITE, 1);
	}

	if (selectArrow == 2)
	{
		DrawRightBlank(colorPalete[colorPlaeteIndex], 2);
		Draw1(WHITE, 2);
		Draw2(colorPalete[colorPlaeteIndex], 2);
		Draw3(WHITE, 2);
		Draw4(WHITE, 2);
	}

	if (selectArrow == 3)
	{
		DrawRightBlank(colorPalete[colorPlaeteIndex], 3);
		Draw1(WHITE, 3);
		Draw2(WHITE, 3);
		Draw3(colorPalete[colorPlaeteIndex], 3);
		Draw4(WHITE, 3);
	}

	if (selectArrow == 4)
	{
		DrawRightBlank(BLUE, 4);
		Draw1(WHITE, 4);
		Draw2(WHITE, 4);
		Draw3(WHITE, 4);
		Draw4(BLUE, 4);
	}

	int slashColorIndex = colorPlaeteIndex + 1;
	for (int i = 1; i <= currentStack; i++)
	{
		slashColorIndex = slashColorIndex % 12;
		DrawSlash(i, selectArrow, colorPalete[slashColorIndex]);
		slashColorIndex++;
	}
}


void Draw1(int color, int arrow) {
	int x = 31;
	if (arrow == 1) x -= 5;

	RenderMgr_Draw(x, 1,	"     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", color, BLACK);
	RenderMgr_Draw(x, 2,	"    / /   _____                     __                    ", color, BLACK);
	RenderMgr_Draw(x, 3,	"   / /   / ___/__ ____ _______ ____/ /__                  ", color, BLACK);
	RenderMgr_Draw(x, 4,	"  / /   / /__/ _ `(_-</ __/ _ `/ _  / -_)                 ", color, BLACK);
	RenderMgr_Draw(x, 5,	" / /    \\___/\\_,_/___/\\__/\\_,_/\\_,_/\\__/            ", color, BLACK);
	RenderMgr_Draw(x, 6,	"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", color, BLACK);
}

void Draw2(int color, int arrow) {
	int x = 31;
	if (arrow == 2) x -= 5;

	RenderMgr_Draw(x, 7,	"     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", color, BLACK);
	RenderMgr_Draw(x, 8,	"    / /   ____                                            ", color, BLACK);
	RenderMgr_Draw(x, 9,	"   / /   / __/__ _  _________  ___                        ", color, BLACK);
	RenderMgr_Draw(x, 10,	"  / /   _\\ \\/ -_) |/ / __/ _ \\/ _ \\                   ", color, BLACK);
	RenderMgr_Draw(x, 11,	" / /   /___/\\__/|___/\\__/\\___/_//_/                    ", color, BLACK);
	RenderMgr_Draw(x, 12,	"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", color, BLACK);
}

void Draw3(int color, int arrow) {
	int x = 31;
	if (arrow == 3) x -= 5;

	RenderMgr_Draw(x, 13,	"     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", color, BLACK);
	RenderMgr_Draw(x, 14,	"    / /   __ _____________ _________                      ", color, BLACK);
	RenderMgr_Draw(x, 15,	"   / /   / // /  _/ ___/ // / __/ _ \\                    ", color, BLACK);
	RenderMgr_Draw(x, 16,	"  / /   / _  // // (_ / _  / _// , _/                     ", color, BLACK);
	RenderMgr_Draw(x, 17,	" / /   /_//_/___/\\___/_//_/___/_/|_|                     ", color, BLACK);
	RenderMgr_Draw(x, 18,	"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", color, BLACK);
}


void Draw4(int color, int arrow) {
	int x = 44;
	if (arrow == 4) x -= 5;

	RenderMgr_Draw(x, 19, "    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━", color, BLACK);
	RenderMgr_Draw(x, 20, "   / /   .---..-..-..-..---.    ", color, BLACK);
	RenderMgr_Draw(x, 21, "  / /    | |-  >  < | |`| |'    ", color, BLACK);
	RenderMgr_Draw(x, 22, " / /     `---''-'`-``-' `-'     ", color, BLACK);
	RenderMgr_Draw(x, 23, "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", color, BLACK);
}

void DrawRightBlank(int color, int arrow) {
	int y = 1 + (arrow - 1) * 6;

	if (arrow == 4)
	{
		RenderMgr_Draw(55, y,	"━━━━━━━━━", color, BLACK);
		RenderMgr_Draw(55, y+1,	"         ", color, BLACK);
		RenderMgr_Draw(55, y+2,	"         ", color, BLACK);
		RenderMgr_Draw(55, y+3,	"         ", color, BLACK);
		RenderMgr_Draw(55, y+4,	"━━━━━━━━━", color, BLACK);
	}
	else
	{
		RenderMgr_Draw(55, y,		"━━━━━━━━━", color, BLACK);
		RenderMgr_Draw(55, y + 1,	"         ", color, BLACK);
		RenderMgr_Draw(55, y + 2,	"         ", color, BLACK);
		RenderMgr_Draw(55, y + 3,	"         ", color, BLACK);
		RenderMgr_Draw(55, y + 4,	"         ", color, BLACK);
		RenderMgr_Draw(55, y + 5,	"━━━━━━━━━", color, BLACK);
	}
}


void DrawSlash(int stack, int arrow, int color) {
	if (arrow == 4) return;
	
	//int color = rand() % 14 + 1;
	//if (isLeft == true) color = WHITE;

	int y = 1 + (arrow - 1) * 6;
	int x = 23 - (stack-1) * 2;

	RenderMgr_Draw(x+2, y,		"  ━━━━", color, BLACK);
	RenderMgr_Draw(x+2, y + 1,	" / /", color, BLACK);
	RenderMgr_Draw(x+1, y + 2,	"  / /", color, BLACK);
	RenderMgr_Draw(x+1, y + 3,	" / /", color, BLACK);
	RenderMgr_Draw(x, y + 4,	"  / /", color, BLACK);
	RenderMgr_Draw(x, y + 5,	" ━━━━", color, BLACK);
}
