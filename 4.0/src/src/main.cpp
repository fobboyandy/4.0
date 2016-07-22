#include <windows.h>
#include "WWindow.h"
#include <tchar.h>
#include <time.h>
#include <string>
#include "statistics.h"

//namespace
using std::wstring;

//lock status of windows
#define LOCKED false
#define UNLOCKED true

bool status = UNLOCKED;

//time tracking
statistics main_stats;
int total_seconds;
wstring total_seconds_string;

int efficiency = 100;
wstring efficiency_string = std::to_wstring(0);
bool efficiency_invalidated = false;

//window string info
TCHAR wnd_title[256];
int previous_str_len = 256;

//window handles
HWND main_hwnd; /*main window*/
HWND prev_hwnd; /*used to avoid repetitive satisfying if statement*/

//macro winapi same as callback 
LRESULT CALLBACK myProcedure(
	_In_ HWND   hwnd,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
	)
{
	//main_stats.analyze();//update all stats
	total_seconds = main_stats.get_total_seconds();
	total_seconds_string = std::to_wstring(total_seconds);

	efficiency = main_stats.get_efficiency(); //gets the current procrastination time
	efficiency_string = std::to_wstring(efficiency);

	switch (uMsg)
	{
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	case WM_PAINT:
	{
		HDC hdc = GetDC(hwnd);

		TextOut(hdc, 50, 50, _T("Total time:"), 11);
		TextOut(hdc, 200, 50, total_seconds_string.c_str(), total_seconds_string.length());

		TextOut(hdc, 50, 100, _T("Efficiency:"), 11);
		if (efficiency < 100 && efficiency_invalidated == false)
		{
			efficiency_invalidated = true;
			InvalidateRect(main_hwnd, NULL, true);
		}
		TextOut(hdc, 200, 100, efficiency_string.c_str(), efficiency_string.length()); 
		

		//paintfunctions::time_TextOut(hdc, 200, 100, efficiency_string, efficiency);

		HWND active_hwnd = GetForegroundWindow(); // get handle of currently active window
		int current_str_len = GetWindowText(active_hwnd, wnd_title, 256); //repaint window if new string is shorter

		if (current_str_len < previous_str_len) //force repaint background
			InvalidateRect(hwnd, NULL, true);
		TextOut(hdc, 50, 0, wnd_title, current_str_len); //prints current active window

		previous_str_len = current_str_len; //update length of window name length

		if (status == LOCKED) //locked
			TextOut(hdc, 50, 150, _T("Lock Enabled"), 12);
		else
			TextOut(hdc, 50, 150, _T("Lock Disabled"), 13);

		ReleaseDC(hwnd, hdc);

	}break;
	case WM_MOVE:
	{
	}break;
	case WM_SIZE:
	{
	}break;
	case WM_RBUTTONDOWN:
	{
	}break;

	case WM_LBUTTONDOWN:
	{
		status = !status;
		InvalidateRect(hwnd, NULL, true);
	}break;
	}
	return 0;
}



///////////////////////////////////////////////////////////////////////
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
	)
{

	MSG message;//
	WWindow main(L"Timer", myProcedure, hInstance);
	if (main.register_class() == 0)
		return 12;
	if (main.create_window(L"Time") == 0)
		return 11;

	main.show_window();
	main_hwnd = main.get_handle(); //set main window
	prev_hwnd = main_hwnd;

	//p_timer.set_hwnd(main_hwnd); //sets the main_hwnd
	main_stats.init(main_hwnd);//intialize all statistics and handles before entering loop

	while (GetMessageW(&message, NULL, 0, 0) > 0) //main loop of the program, communicates with wndproc until end of program
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
		Sleep(5); //prevents high cpu usage
	}
	return (int)message.wParam;
}


