#pragma once

struct Scene;

extern Scene* SceneMgr_arrScene[SCNEN_TYPE_END]; // ��� �� ���
extern Scene* SceneMgr_curScene;

void SceneMgr_Init();
void SceneMgr_Update();
void SceneMgr_Render();

// �� ü����
void SceneMgr_Change(Scene* next); 
void SceneMgr_Exit();