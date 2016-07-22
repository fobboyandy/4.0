#ifndef statistics_h
#define statistics_h
#include "timeFSM.h"
#include <time.h>
#include <string>
#include "word.h"
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::string;
using std::vector;


//used to store, manage, and calculate data
class statistics
{
public:
	statistics(); //ctor, load in saved dictionary data
	unordered_map<string, float> global_dictionary;
	/*
	init should be called before entering message loop to accurately initialize time reference
	*/
	void init(HWND main_hwnd); //main_hwnd used as center of attention
	void analyze(); //pass in window title and gives a decision of productive, unproductive, or undecided, this is the "update" function, it polls for window title every iteration
	int get_efficiency();
	int get_total_seconds();
	int get_unproductive_seconds();


private:
	int efficiency; //percentage of efficiency is wasted time / total time
	int total_seconds;
	int unproductive_seconds;
	time_t start_time;
	timeFSM p_timer;
	vector<word> title_list;
};

#endif