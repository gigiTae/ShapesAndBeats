#pragma once

struct Object;

extern int Player_Color;

void Object_InitPlayer(Object* player);
void Object_UpdatePlayer(Object* player);
void Object_RenderPlayer(Object* player);
void Object_HitPlayer();
