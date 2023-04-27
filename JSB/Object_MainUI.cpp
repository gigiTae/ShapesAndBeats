#include "pch.h"
#include "Object.h"
#include "RenderMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Core.h"
#include "SoundMgr.h"
#include "TimgMgr.h"
#include "SoundMgr.h"
#include "EventMgr.h"

#include "Object_MainUI.h"
#include "Object_Starfall.h"
#include "Object_Firework.h"
#include "Function_WindowBounce.h"


static int selectUI = 0; // 0 ���� ����  1Ʃ�丮�� 2 ���� ����
static bool musicStart = false;
unsigned tick = 0;

//�Ʒ� ������������ �ٽ� ���� ������ ���ƿ��� �� �ʱ�ȭ�ؾ� �� ���̵�
bool isFireworkPlayed = false;
int logoY = -19;
bool isBounced = false;
bool isFireThreadStarted = false;
bool isTapSpace = false;
bool showLogo = false;

void Object_InitMainUI(Object* obj)
{
	musicStart = true;
	obj->name = "��";
	obj->background = BLACK;
	obj->foreground = BLUE;
	obj->x = 10;
	obj->y = 0;
	obj->time = 0;
	obj->Object_Update = Object_UpdateMainUI;
	obj->Object_Render = Object_RenderMainUI;
}

#define MAIN_UPDATE_TIME 100
void Object_UpdateMainUI(Object* obj)
{
	obj->time += TimeMgr_deltaTime;
	tick++; 

	//���ǰ���
	if (obj->time < 1000 && musicStart)
	{
		obj->time = 0;
		musicStart = false;
		SoundMgr_PlaySound(INTRO);
	}

	if (obj->time > 4000 && !musicStart)
	{
		musicStart = true;
		SoundMgr_PlaySound(MAINSCENE);
	}
	

	//��
	if (obj->time > 500 && obj->time < 3300) 
	{
		if (tick % 40 == 0) EventMgr_AddObject(Object_InitStarfall, rand() % 60, (rand() % 15) - 10, 600);
	}

	//���ڿ� ���� �Ҳ� �ݺ�
	if (!isFireThreadStarted && obj->time > 4650)
	{
		isFireThreadStarted = true;
		_beginthreadex(NULL, 0, FireworkRepeat, 0, 0, NULL);
	}

	if (obj->time > 3980)
	{
		showLogo = true; //�ΰ� ���̱�
		if (logoY < 2 && tick % 7 == 0) logoY++; //�ΰ� ������
	}

	//�Ҳ� �ѰŹ��� ������
	if (!isFireworkPlayed && obj->time > 4200 )
	{
		isFireworkPlayed = true;
		for (int i = 0; i < 10; i++)
		{
			EventMgr_AddObject(Object_InitFirework, rand() % 40 + 10, rand() % 10 + 10, 600);
		}
	}

	//ȭ�� �� �ϱ�
	if (!isBounced && obj->time > 4150)
	{
		isBounced = true;
		_beginthreadex(NULL, 0, WindowBounce, 0, 0, NULL);
	}

	//�� �̵� ���� Ű �Է�
	if (showLogo == true)
	{
		if (keyInfo[UP].state == TAP)
		{
			SoundMgr_PlayEffect(CLICK1);
			selectUI--;
			if (selectUI == -1)
				selectUI = 0;
		}

		if (keyInfo[DOWN].state == TAP)
		{
			SoundMgr_PlayEffect(CLICK1);
			selectUI++;
			if (selectUI == 3)
				selectUI = 2;
		}

		if (keyInfo[SPACE].state == TAP && selectUI == 0)
		{
			isTapSpace = true;
			SoundMgr_PlayEffect(CLICK2);
			// SceneMgr���� ScnenChange �� ��û
			EventMgr_ChangeScene(SCENE_SELECT);
		}
		if (keyInfo[SPACE].state == TAP && selectUI == 1)
		{
			isTapSpace = true;
			SoundMgr_PlayEffect(CLICK2);
			// SceneMgr���� ScnenChange �� ��û
			EventMgr_ChangeScene(SCENE_TUTORIAL);
		}
		if (keyInfo[SPACE].state == TAP && selectUI == 2)
		{
			SoundMgr_PlayEffect(CLICK2);
			// ���� ����
			Core_gameRun = false;
		}
	}
}

void Object_RenderMainUI(Object* obj)
{

	if (showLogo == true)
	{
		RenderMgr_Draw(0, logoY,	"                ::::::::      :::    :::         :::        :::::::::     ::::::::::     :::::::: ", SKYBLUE, BLACK);
		RenderMgr_Draw(0, logoY+1,	"              :+:    :+:     :+:    :+:       :+: :+:      :+:    :+:    :+:           :+:    :+: ", SKYBLUE, BLACK);
		RenderMgr_Draw(0, logoY+2,	"             +:+            +:+    +:+      +:+   +:+     +:+    +:+    +:+           +:+", SKYBLUE, BLACK);
		RenderMgr_Draw(0, logoY+3,	"            +#++:++#++     +#++:++#++     +#++:++#++:    +#++:++#+     +#++:++#      +#++:++#++   ", SKYBLUE, BLACK);
		RenderMgr_Draw(0, logoY+4,	"                  +#+     +#+    +#+     +#+     +#+    +#+           +#+                  +#+", SKYBLUE, BLACK);
		RenderMgr_Draw(0, logoY+5,	"          #+#    #+#     #+#    #+#     #+#     #+#    #+#           #+#           #+#    #+#", SKYBLUE, BLACK);
		RenderMgr_Draw(0, logoY+6,	"          ########      ###    ###     ###     ###    ###           ##########     ########", SKYBLUE, BLACK);

		RenderMgr_Draw(0, logoY+9, "                        :::::::             :::::::::      ::::::::::        :::    :::::::::::    :::::::: ", DARK_SKYBLUE, BLACK);
		RenderMgr_Draw(0, logoY+10, "                      :+:   :+:            :+:    :+:     :+:             :+: :+:      :+:       :+:    :+:", DARK_SKYBLUE, BLACK);
		RenderMgr_Draw(0, logoY+11, "                      +:+ +:+             +:+    +:+     +:+            +:+   +:+     +:+       +:+         ", DARK_SKYBLUE, BLACK);
		RenderMgr_Draw(0, logoY+12, "                      +#++:  ++#         +#++:++#+      +#++:++#      +#++:++#++:    +#+       +#++:++#++", DARK_SKYBLUE, BLACK);
		RenderMgr_Draw(0, logoY+13, "                    +#+ +#+#+#          +#+    +#+     +#+           +#+     +#+    +#+              +#+", DARK_SKYBLUE, BLACK);
		RenderMgr_Draw(0, logoY+14, "                  #+#   #+#+           #+#    #+#     #+#           #+#     #+#    #+#       #+#    #+#", DARK_SKYBLUE, BLACK);
		RenderMgr_Draw(0, logoY+15, "                  ##########          #########      ##########    ###     ###    ###        ########", DARK_SKYBLUE, BLACK);

		RenderMgr_Draw(1, 28, "���� : �� �� �� �� Space", DARK_GRAY, BLACK);

		RenderMgr_Draw(40, 23, "���� ����", WHITE, BLACK);
		RenderMgr_Draw(40, 25, "���� ���۹��", WHITE, BLACK);
		RenderMgr_Draw(40, 27, "���� ����", WHITE, BLACK);

		if (selectUI==0)
		{
			RenderMgr_Draw(38, 23, "��", WHITE, BLACK);
		}
		else if(selectUI == 1)
		{
			RenderMgr_Draw(38, 25, "��", WHITE, BLACK);
		}
		else
			RenderMgr_Draw(38, 27, "��", WHITE, BLACK);
	}

}

// �ð����� ��� �Ҳ��� �������� �����带 ����
unsigned FireworkRepeat(void* arg) {
	while (true)
	{
		EventMgr_AddObject(Object_InitFirework, rand() % 60, rand() % 30, 650);
		Sleep(960);

		if (isTapSpace) break;
	}
	return 0;
}