#pragma once

#include "Config.h"


#if USING_VISUAL_STUDIO 
#include <Windows.h>

void SleepFunction(int milliseconds){
	Sleep(milliseconds);
}

void ClearFunction() {
	system("CLS");
}

#else if 

#include <stdlib.h>

void SleepFunction(int milliseconds) { 
	milliseconds * 1000;
	usleep(milliseconds);
}

void ClearFunction() {
	system("clear");
}

#endif

