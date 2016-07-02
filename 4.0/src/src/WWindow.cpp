#include "WWindow.h"

WWindow::WWindow(LPCTSTR class_name, WNDPROC process_name, HINSTANCE instance_handle)
{
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_VREDRAW | CS_HREDRAW;
	wcex.lpfnWndProc = process_name;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = class_name;
	wcex.hInstance = instance_handle;
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
}

WWindow::~WWindow()
{

}

ATOM WWindow::register_class()
{
	return RegisterClassEx(&wcex);
}

HWND WWindow::create_window(LPCTSTR window_name)
{
	window_handle = CreateWindow(wcex.lpszClassName,
		window_name,
		WS_OVERLAPPED | WS_SYSMENU,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		300,
		300,
		NULL,
		NULL,
		wcex.hInstance,
		NULL);
	return window_handle;
}

HWND WWindow::get_handle()
{
	return window_handle;
}

void WWindow::show_window()
{
	ShowWindow(window_handle, SW_SHOWNORMAL);
	UpdateWindow(window_handle);
}

void WWindow::hide_window()
{
	ShowWindow(window_handle, SW_HIDE);
	UpdateWindow(window_handle);
}


