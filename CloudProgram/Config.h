#pragma once

//if on xCode, change to false
#define USING_VISUAL_STUDIO true;

#if USING_VISUAL_STUDIO 

void SleepFunction(int milliseconds);
void ClearScreenFunction();

#else if 
void SleepFunction(int milliseconds);
void ClearScreenFunction();

#endif

