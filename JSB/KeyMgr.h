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
	int  state; // Ű�� ���°�
	bool prevPush; // ���� �����ӿ��� ���ȴ��� ����
}KeyInfo;

extern KeyInfo keyInfo[LAST];

void KeyMgr_Init();
void KeyMgr_Update();