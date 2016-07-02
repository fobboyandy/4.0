#ifndef statistics_h
#define statistics_h
#include "timeFSM.h"
#include <time.h>

//used to store, manage, and calculate data
class statistics
{
public:
	statistics(); //ctor

	/*
	init should be called before entering message loop to accurately initialize time reference
	*/
	void init(HWND main_hwnd); //main_hwnd used as center of attention


	int get_efficiency();
	int get_total_seconds();
	int get_unproductive_seconds();
	void update();

private:
	int efficiency; //percentage of efficiency is wasted time / total time
	int total_seconds;
	int unproductive_seconds;
	time_t start_time;
	timeFSM p_timer;
};

#endif