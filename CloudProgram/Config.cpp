#pragma once

#include "Config.h"

#if USING_VISUAL_STUDIO 
#include <Windows.h>

void SleepFunction(int milliseconds){
	Sleep(milliseconds);
}

void ClearScreenFunction() {
	system("CLS");
}

#else  
#include <stdlib.h>
#include <unistd.h>
void SleepFunction(int microseconds) { 
	microseconds * 1000;
	usleep(microseconds);
}

void ClearScreenFunction() {
	system("clear");
}

#endif

