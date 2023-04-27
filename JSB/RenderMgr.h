#pragma once

extern HANDLE RenderMgr_screen[2]; // 버퍼
extern bool RenderMgr_index;       // 현재 버퍼 인덱스

void RenderMgr_Init();

void RenderMgr_ClearScreen();
void RenderMgr_ChangeScreen();

void RenderMgr_Draw(short x, short y, const char* str, int foreground, int background);
void RenderMgr_DrawC(short x, short y, short collision_len,const char* str, int foreground, int background);