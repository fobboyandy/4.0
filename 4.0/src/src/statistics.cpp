#include "statistics.h"

statistics::statistics() :efficiency(100), total_seconds(0), unproductive_seconds(0), start_time(time(0))
{
}

void statistics::init(HWND main_hwnd)
{
	efficiency = 100;
	total_seconds = 0;
	unproductive_seconds = 0;
	start_time = time(0);
	p_timer.set_hwnd(main_hwnd);
}

//void statistics::update()
//{
//	total_seconds = (int)difftime(time(0), start_time);
//	unproductive_seconds = p_timer();
//
//	if (total_seconds != 0)//waits for a non zero denominator
//		efficiency = ((total_seconds - unproductive_seconds) * 100) / total_seconds;
//}

int statistics::get_efficiency() { return efficiency; };
int statistics::get_total_seconds() { return total_seconds; };
int statistics::get_unproductive_seconds() { return unproductive_seconds; };

void statistics::analyze()
{
	//get window title
	//clear and create a list by breaking title into different word objects
	//have word return a weighted sum of weights of defining words
	//sum up summed weights and return float
	title_list.clear();
	wstring curr_word;
	TCHAR window_title[256];
	HWND curr_hwnd = GetForegroundWindow();
	GetWindowText(curr_hwnd, window_title, 256);
	for (size_t i = 0, j = 0; i < 256; i++)
	{
		if ((window_title[i] >= '0' && window_title[i] <= '9') || (window_title[i] >= 'a' && window_title[i] <= 'z') || (window_title[i] >= 'A' && window_title[i] <= 'Z'))
			curr_word.push_back(window_title[i]);
		else
		{
			title_list.push_back(word(global_dictionary, curr_word));
			curr_word.clear();
		}
	}
	//at this point title_list should be a list of words that make up the window's title
	
}