#ifndef WWindow_h
#define WWindow_h

#include <windows.h>

class WWindow
{
public:
	WWindow(LPCTSTR class_name, WNDPROC process_name, HINSTANCE instance_handle);
	~WWindow();
	ATOM register_class();
	HWND create_window(LPCTSTR window_name);
	HWND get_handle();
	void show_window();
	void hide_window();

protected:

private:
	WNDCLASSEX wcex;
	HWND window_handle;
};

#endif
