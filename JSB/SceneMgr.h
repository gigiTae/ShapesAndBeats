#pragma once

struct Scene;

extern Scene* SceneMgr_arrScene[SCNEN_TYPE_END]; // 모든 씬 목록
extern Scene* SceneMgr_curScene;

void SceneMgr_Init();
void SceneMgr_Update();
void SceneMgr_Render();

// 씬 체인지
void SceneMgr_Change(Scene* next); 
void SceneMgr_Exit();