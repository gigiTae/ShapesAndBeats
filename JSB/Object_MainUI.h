#pragma once


struct Object;

void Object_InitMainUI(Object* obj);
void Object_UpdateMainUI(Object* obj);
void Object_RenderMainUI(Object* obj);

unsigned WindowBounce(void* arg);
unsigned FireworkRepeat(void* arg);