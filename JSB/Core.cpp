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
	// ���ӽ���
	Core_gameRun = true;

	// �Ŵ��� �ʱ�ȭ ���� �߿���
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
	// �Ŵ��� ������Ʈ
	TimeMgr_Update();
	KeyMgr_Update();

	// ���� Ŭ����
	RenderMgr_ClearScreen();

	// ������Ʈ ������Ʈ
	SceneMgr_Update();

	// �浹�迭 �ʱ�ȭ
	CollisionMgr_Clear();

	// ������Ʈ ������
	SceneMgr_Render();

	// ������
	RenderMgr_ChangeScreen();

	// �� ����, ������Ʈ �߰�, ������ �Ѵ�.
	EventMgr_Update();
}

void Core_Exit()
{
	SoundMgr_Exit();
	SceneMgr_Exit();
	EventMgr_Exit();
}
