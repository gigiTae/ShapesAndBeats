#include "pch.h"
#include "Object_ClearUI.h"
#include "RenderMgr.h"
#include "TimgMgr.h"
#include "EventMgr.h"
#include "Object.h"
#include "KeyMgr.h"
#include "SoundMgr.h"

extern bool isFireworkPlayed;
extern int logoY;
extern bool isBounced;
extern bool isFireThreadStarted;
extern bool isTapSpace;
extern bool showLogo;

void Object_InitClearUI(Object* obj)
{

	obj->foreground = YELLOW;
	obj->time = 0;
	obj->Object_Update = Object_UpdateClearUI;
	obj->Object_Render = Object_RenderClearUI;
}

void Object_UpdateClearUI(Object* obj)
{
	if (keyInfo[A].state == TAP)
	{
		//메인씬의 전역변수 초기화
		isFireworkPlayed = false;
		logoY = -19;
		isBounced = false;
		isFireThreadStarted = false;
		isTapSpace = false;
		showLogo = false;

		EventMgr_ChangeScene(MAINSCENE);
	}
		
	if (keyInfo[SPACE].state == TAP)
		SoundMgr_PlaySound(ENDING);
	else if (keyInfo[SPACE].state == AWAY)
		SoundMgr_StopSound();
}

void Object_RenderClearUI(Object* obj)
{



	if (keyInfo[SPACE].state == NONE)
	{

		RenderMgr_Draw(26, 22, "PRESS SPACEBAR", YELLOW, BLACK);
		RenderMgr_Draw(4, 6, "  ______   ________  ______    ______   ________         ______   __        ________   ______   _______  ", DARK_GRAY, BLACK);
		RenderMgr_Draw(4, 7, " /      \\ /        |/      \\  /      \\ /        |       /      \\ /  |      /        | /      \\ /       \\ ", DARK_GRAY, BLACK);
		RenderMgr_Draw(4, 8, "/$$$$$$  |$$$$$$$$//$$$$$$  |/$$$$$$  |$$$$$$$$/       /$$$$$$  |$$ |      $$$$$$$$/ /$$$$$$  |$$$$$$$  |", DARK_GRAY, BLACK);
		RenderMgr_Draw(4, 9, "$$ \\__$$/    $$ |  $$ |__$$ |$$ | _$$/ $$ |__          $$ |  $$/ $$ |      $$ |__    $$ |__$$ |$$ |__$$ |", DARK_GRAY, BLACK);
		RenderMgr_Draw(4, 10, "$$      \\    $$ |  $$    $$ |$$ |/    |$$    |         $$ |      $$ |      $$    |   $$    $$ |$$    $$< ", DARK_GRAY, BLACK);
		RenderMgr_Draw(4, 11, " $$$$$$  |   $$ |  $$$$$$$$ |$$ |$$$$ |$$$$$/          $$ |   __ $$ |      $$$$$/    $$$$$$$$ |$$$$$$$  |", DARK_GRAY, BLACK);
		RenderMgr_Draw(4, 12, "/  \\__$$ |   $$ |  $$ |  $$ |$$ \\__$$ |$$ |_____       $$ \\__/  |$$ |_____ $$ |_____ $$ |  $$ |$$ |  $$ |", DARK_GRAY, BLACK);
		RenderMgr_Draw(4, 13, "$$    $$/    $$ |  $$ |  $$ |$$    $$/ $$       |      $$    $$/ $$       |$$       |$$ |  $$ |$$ |  $$ |", DARK_GRAY, BLACK);
		RenderMgr_Draw(4, 14, " $$$$$$/     $$/   $$/   $$/  $$$$$$/  $$$$$$$$/        $$$$$$/  $$$$$$$$/ $$$$$$$$/ $$/   $$/ $$/   $$/ ", DARK_GRAY, BLACK);
	
		                              
		RenderMgr_Draw(0, 21, "　　　　　／＞　　フ", DARK_GRAY, BLACK);
		RenderMgr_Draw(0, 22, "　　　　| 　_　 _ l", DARK_GRAY, BLACK);
		RenderMgr_Draw(0, 23, " 　　　／` ミ＿Yノ", DARK_GRAY, BLACK);
		RenderMgr_Draw(0, 24, "　 　 /　 　|", DARK_GRAY, BLACK);
		RenderMgr_Draw(0, 25, "　　 /　 \\　\\", DARK_GRAY, BLACK);
		RenderMgr_Draw(0, 26, " 　 │　　|　|", DARK_GRAY, BLACK);
		RenderMgr_Draw(0, 27, "／￣|　　 |　|", DARK_GRAY, BLACK);
		RenderMgr_Draw(0, 28, "| (￣\\＿_\\_)__)", DARK_GRAY, BLACK);
		RenderMgr_Draw(0, 29, "＼二つ", DARK_GRAY, BLACK);

	}
	else
	{

		RenderMgr_Draw(26, 22, "PRESS SPACEBAR", DARK_GRAY, BLACK);
		RenderMgr_Draw(40, 28, "Thank you for playing! EXIT IS A", YELLOW, BLACK);
		RenderMgr_Draw(4, 6,  "  ______   ________  ______    ______   ________         ______   __        ________   ______   _______  ", obj->foreground, BLACK);
		RenderMgr_Draw(4, 7,  " /      \\ /        |/      \\  /      \\ /        |       /      \\ /  |      /        | /      \\ /       \\ ", obj->foreground, BLACK);
		RenderMgr_Draw(4, 8,  "/$$$$$$  |$$$$$$$$//$$$$$$  |/$$$$$$  |$$$$$$$$/       /$$$$$$  |$$ |      $$$$$$$$/ /$$$$$$  |$$$$$$$  |", obj->foreground, BLACK);
		RenderMgr_Draw(4, 9,  "$$ \\__$$/    $$ |  $$ |__$$ |$$ | _$$/ $$ |__          $$ |  $$/ $$ |      $$ |__    $$ |__$$ |$$ |__$$ |", obj->foreground, BLACK);
		RenderMgr_Draw(4, 10, "$$      \\    $$ |  $$    $$ |$$ |/    |$$    |         $$ |      $$ |      $$    |   $$    $$ |$$    $$< ", obj->foreground, BLACK);
		RenderMgr_Draw(4, 11, " $$$$$$  |   $$ |  $$$$$$$$ |$$ |$$$$ |$$$$$/          $$ |   __ $$ |      $$$$$/    $$$$$$$$ |$$$$$$$  |", obj->foreground, BLACK);
		RenderMgr_Draw(4, 12, "/  \\__$$ |   $$ |  $$ |  $$ |$$ \\__$$ |$$ |_____       $$ \\__/  |$$ |_____ $$ |_____ $$ |  $$ |$$ |  $$ |", obj->foreground, BLACK);
		RenderMgr_Draw(4, 13, "$$    $$/    $$ |  $$ |  $$ |$$    $$/ $$       |      $$    $$/ $$       |$$       |$$ |  $$ |$$ |  $$ |", obj->foreground, BLACK);
		RenderMgr_Draw(4, 14, " $$$$$$/     $$/   $$/   $$/  $$$$$$/  $$$$$$$$/        $$$$$$/  $$$$$$$$/ $$$$$$$$/ $$/   $$/ $$/   $$/ ", obj->foreground, BLACK);
	

		RenderMgr_Draw(0, 20, "　　　　 ／\\__/|　　", YELLOW, BLACK);
		RenderMgr_Draw(0, 21, "　　　　／　　   \\", YELLOW, BLACK);
		RenderMgr_Draw(0, 22, "　　　　| 　 ∂ ∂)", YELLOW, BLACK);
		RenderMgr_Draw(0, 23, " 　　　／` ミ__ㅅミ", YELLOW, BLACK);
		RenderMgr_Draw(0, 24, "　 　 /==　　  |", YELLOW, BLACK);
		RenderMgr_Draw(0, 25, "　　 /==       ", YELLOW, BLACK);
		RenderMgr_Draw(0, 26, " 　 │===   |　  \\", YELLOW, BLACK);
		RenderMgr_Draw(0, 27, "／￣|       \\ \\  \\", YELLOW, BLACK);
		RenderMgr_Draw(0, 28, "| (￣\\_______\\_)\\_)", YELLOW, BLACK);
		RenderMgr_Draw(0, 29, "＼二つ", YELLOW, BLACK);

	}





}				   
