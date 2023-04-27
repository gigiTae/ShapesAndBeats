#include "pch.h"
#include "Core.h"
#include "KeyMgr.h"
#include "TimgMgr.h"
#include "RenderMgr.h"
#include "SceneMgr.h"
#include "CollisionMgr.h"
#include "SoundMgr.h"
#include "PathMgr.h"
#include "EventMgr.h"

bool Core_gameRun = false;

void Core_Init()
{
	// 게임시작
	Core_gameRun = true;

	// 매니져 초기화 순서 중요함
	PathMgr_Init();
	KeyMgr_Init();
	TimeMgr_Init();
	RenderMgr_Init();
	SoundMgr_Init();
	EventMgr_Init();


	SceneMgr_Init();
	CollisionMgr_Init();
}

void Core_Progress()
{
	// 매니져 업데이트
	TimeMgr_Update();
	KeyMgr_Update();

	// 버퍼 클리어
	RenderMgr_ClearScreen();

	// 오브젝트 업데이트
	SceneMgr_Update();

	// 충돌배열 초기화
	CollisionMgr_Clear();

	// 오브젝트 랜더링
	SceneMgr_Render();

	// 랜더링
	RenderMgr_ChangeScreen();

	// 씬 변경, 오브젝트 추가, 삭제를 한다.
	EventMgr_Update();
}

void Core_Exit()
{
	SoundMgr_Exit();
	SceneMgr_Exit();
	EventMgr_Exit();
}
