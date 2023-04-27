#pragma once


extern unsigned long long TimeMgr_curCount;
extern unsigned long long TimeMgr_prevCount;
extern unsigned long long TimeMgr_deltaTime;

void TimeMgr_Init();
void TimeMgr_Update();

