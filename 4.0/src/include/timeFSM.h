#ifndef timefsm_h
#define timefsm_h

#include <time.h>
#include <windows.h>


class timeFSM 
{
	
public:
	//ctor
	timeFSM();
	void set_hwnd(HWND main); //updates the main_hwnd;
	//returns the total seconds procrastinated
	int operator()(void); //functor keeping track of states

private:
	HWND main_hwnd; //window of focus
	int offset;
	int total_time;
	time_t start_time;
	enum state
	{
		idle, //not procrastinating, keep resetting start time
		count, //procrastinating, don't reset start time
	};
	state state;
};

#endif