#include "pch.h"
#include "TimgMgr.h"


unsigned long long TimeMgr_curCount = 0;
unsigned long long TimeMgr_prevCount = 0;
unsigned long long TimeMgr_deltaTime = 0;

void TimeMgr_Init()
{
	// √ ±‚»≠
	TimeMgr_curCount = TimeMgr_prevCount = GetTickCount64();
	srand(time(NULL));
}
void TimeMgr_Update()
{
	TimeMgr_prevCount = TimeMgr_curCount;
	TimeMgr_curCount = GetTickCount64();
	TimeMgr_deltaTime = TimeMgr_curCount - TimeMgr_prevCount;
}
