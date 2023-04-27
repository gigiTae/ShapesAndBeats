#include "pch.h"
#include "Core.h"

int main()
{

	Core_Init();

	while(Core_gameRun)
	{
 		Core_Progress();
	}

	Core_Exit();

	return 0;
} 
