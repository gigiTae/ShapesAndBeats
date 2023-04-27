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
		// Ű�� ����
		if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
		{
			// �������� ����
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
		// Ű�� �ȴ��� �ִ�.
		else
		{
			// �������� ���� �־���
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
