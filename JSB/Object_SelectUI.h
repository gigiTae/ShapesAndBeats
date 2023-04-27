#pragma once

struct Object;

void Object_InitSelectUI(Object* obj);
void Object_UpdateSelectUI(Object* obj);
void Object_RenderSelectUI(Object* obj);

void Draw1(int color, int arrow);
void Draw2(int color, int arrow);
void Draw3(int color, int arrow);
void Draw4(int color, int arrow);
void DrawRightBlank(int color, int arrow);
void DrawSlash(int stack, int arrow, int color);

extern int selectArrow;