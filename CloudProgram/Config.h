#pragma once

//if on  unix, change to false 
#define USING_VISUAL_STUDIO true;

#if USING_VISUAL_STUDIO 

void SleepFunction(int milliseconds);
void ClearScreenFunction();

#else if 
void SleepFunction(int microseconds);
void ClearScreenFunction();

#endif

