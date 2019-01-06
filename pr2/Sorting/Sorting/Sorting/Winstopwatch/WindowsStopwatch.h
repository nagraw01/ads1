#ifndef WINDOWS_STOPWATCH_H 
#define WINDOWS_STOPWATCH_H // // based on code from dr. fawcett: 
// http://www.lcs.syr.edu/faculty/fawcett/handouts/cse687/code/hirestimernativecpp/hirestimer.cpp 
// http://www.lcs.syr.edu/faculty/fawcett/handouts/cse687/code/hirestimernativecpp/hirestimer.h 
// 
#ifdef linux 
#elif defined __apple_cc__ 
#else
#include <windows.h>

class WindowsStopwatch {
public:
	WindowsStopwatch();
	void start();
	void stop();
	long getTime();
protected:
	__int64 a, b, f;
};

#endif

#endif

