#pragma once
#include "pch.h"

//콘솔 화면 위치를 변경시키는 스레드
unsigned WindowBounce(void* arg) {
	HWND consoleWindow = GetConsoleWindow();
	RECT consoleRect;
	GetWindowRect(consoleWindow, &consoleRect);
	int consoleX = consoleRect.left;
	int consoleY = consoleRect.top;

	for (int i = 0; i <= 21; i += 3)
	{
		consoleY++;
		SetWindowPos(consoleWindow, 0, consoleX, consoleY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		Sleep(1);
	}


	for (int i = 0; i <= 21; i += 3)
	{
		consoleY--;
		SetWindowPos(consoleWindow, 0, consoleX, consoleY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		Sleep(1);
	}

	return 0;
}