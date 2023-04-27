#include "pch.h"
#include "KeyMgr.h"

KeyInfo keyInfo[LAST]{};

int g_arrVK[LAST] =
{
	VK_LEFT,//LEFT,
	VK_RIGHT,//RIGHT,
	VK_UP,//UP,
	VK_DOWN,//DOWN,

	'A',
	'S',
	'D',
	VK_SPACE,//SPACE,
	//LAST,
};

void KeyMgr_Init()
{
	for (int i = 0; i < LAST; ++i)
	{
 		keyInfo[i].prevPush = false;
		keyInfo[i].state = NONE;
	}
}

void KeyMgr_Update()
{
	for (int i = 0; i < LAST; ++i)
	{
		// 키를 누름
		if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
		{
			// 이전에도 누름
			if (keyInfo[i].prevPush)
			{
				keyInfo[i].state = HOLD;
			} 
			else
			{
				keyInfo[i].state = TAP;
			}
			keyInfo[i].prevPush = true;
		}
		// 키가 안눌려 있다.
		else
		{
			// 이전에도 눌려 있었다
			if (keyInfo[i].prevPush)
			{
				keyInfo[i].state = AWAY;
			}
			else
			{
				keyInfo[i].state = NONE;
			}
			keyInfo[i].prevPush = false;
		}

	}
}
