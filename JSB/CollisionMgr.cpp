#include "pch.h"
#include "CollisionMgr.h"

bool CollisionMgr_Arr[SCREEN_WIDTH][SCREEN_LENGTH]{};

void CollisionMgr_Init()
{
	for (int x = 0; x < SCREEN_WIDTH; ++x)
	{
		for (int y = 0; y < SCREEN_LENGTH; ++y)
		{
			CollisionMgr_Arr[x][y] = NONE_COLLISION;
		}
	}
}

void CollisionMgr_Clear()
{
	for (int x = 0; x < SCREEN_WIDTH; ++x)
	{
		for (int y = 0; y < SCREEN_LENGTH; ++y)
		{
			CollisionMgr_Arr[x][y] = NONE_COLLISION;
		}
	}
}

