#pragma once

//if on  unix, change to false 
#define USING_WINDOWS true;

#if USING_WINDOWS

void SleepFunction(int milliseconds);
void ClearScreenFunction();

#else if 
void SleepFunction(int microseconds);
void ClearScreenFunction();

#endif

