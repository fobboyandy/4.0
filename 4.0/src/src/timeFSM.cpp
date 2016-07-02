#include "timeFSM.h"
#include <windows.h>


timeFSM::timeFSM() : state(idle), offset(0), total_time(0) //intializes main_hwnd
{
}


void timeFSM::set_hwnd(HWND main)
{
	main_hwnd = main;
}

int timeFSM::operator()(void) //functor which keeps track of the states
{
	HWND curr_hwnd = GetForegroundWindow();
	if (state == idle)
	{
		if (curr_hwnd != main_hwnd)
		{
			//initialize the time 
			state = count; //move to next state
			start_time = time(0); //get current time
			total_time = offset + (int)difftime(time(0), start_time);
		}
		return total_time;
	}
	else
	{
		total_time = offset + (int)difftime(time(0), start_time);
		if (curr_hwnd == main_hwnd)
		{
			state = idle; //update state
			offset = total_time; //update offset
		}
		return total_time;
	}

}