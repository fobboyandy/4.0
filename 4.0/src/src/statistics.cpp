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

void statistics::update()
{
	total_seconds = (int)difftime(time(0), start_time);
	unproductive_seconds = p_timer();

	if (total_seconds != 0)//waits for a non zero denominator
		efficiency = ((total_seconds - unproductive_seconds) * 100) / total_seconds;
}


int statistics::get_efficiency() { return efficiency; };
int statistics::get_total_seconds() { return total_seconds; };
int statistics::get_unproductive_seconds() { return unproductive_seconds; };