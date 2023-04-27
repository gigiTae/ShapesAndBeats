#pragma once

struct Object;

void Object_InitStarfall(Object* obj);
void Object_UpdateStarfall(Object* obj);
void Object_RenderStarfall(Object* obj);

void DrawStar(int x, int y);