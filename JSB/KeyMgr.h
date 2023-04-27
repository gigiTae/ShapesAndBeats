#pragma once

enum KEY_STATE
{
	NONE,
	TAP,
	HOLD,
	AWAY,
};

enum KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,

	A,
	S,
	D,
	SPACE,
	LAST,
};

typedef struct KeyInfo
{
	int  state; // 키의 상태값
	bool prevPush; // 이전 프레임에서 눌렸는지 여부
}KeyInfo;

extern KeyInfo keyInfo[LAST];

void KeyMgr_Init();
void KeyMgr_Update();