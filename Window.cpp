#include "Window.h"
#include "Define.h"
#include "Error.h"
#include "resource.h"

Window::Mode Window::_mode = Window::Mode::Window;
bool Window::_isActive = false;

void Window::MakeSettingWindow(Mode& mode) const
{
	DialogBox(GetModuleHandle(nullptr), TEXT("SETTING"), 0, (DLGPROC)SettingWindowProc);
	mode = _mode;
}

void Window::MakeMainWindow() const
{
	Error error;

	WNDCLASSEX windowClass =
	{
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW,
		MainWindowProc,
		0,
		0,
		GetModuleHandle(nullptr),
		LoadIcon(NULL, IDI_APPLICATION),
		LoadCursor(NULL, IDC_ARROW),
		NULL,
		NULL,
		Define::_mainWinClass,
		NULL
	};

	if (RegisterClassEx(&windowClass) == NULL) error.Issue("001");

	HWND windowHandle = CreateWindow(
		Define::_mainWinClass,
		Define::_mainWinTitle,
		Define::_mainWinStyle,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		Define::_mainWinWidth,
		Define::_mainWinHeight,
		NULL,
		NULL,
		GetModuleHandle(nullptr),
		NULL);
	
	if (windowHandle == NULL) error.Issue("002");

	RECT windowRect;
	RECT clientRect;

	if (GetWindowRect(windowHandle, &windowRect) == false) error.Issue("003");
	if(GetClientRect(windowHandle, &clientRect)==false) error.Issue("004");

	const int frameSize_x = (windowRect.right - windowRect.left) - (clientRect.right - clientRect.left);
	const int frameSize_y = (windowRect.bottom - windowRect.top) - (clientRect.bottom - clientRect.top);

	SetWindowPos(windowHandle, NULL, CW_USEDEFAULT, CW_USEDEFAULT, frameSize_x + Define::_mainWinWidth, frameSize_y + Define::_mainWinHeight, SWP_NOMOVE);

	ShowWindow(windowHandle, SW_SHOW);
	UpdateWindow(windowHandle);
}

LRESULT CALLBACK Window::SettingWindowProc(HWND windowHandle, UINT message_id, WPARAM wParam, LPARAM lParam)
{

	switch (message_id)
	{
	case WM_INITDIALOG:
		SendMessage(GetDlgItem(windowHandle, IDC_RADIOBUTTON101), BM_SETCHECK, BST_CHECKED, 0);
		return TRUE;
	case WM_CLOSE:
		EndDialog(windowHandle, TRUE);
		_mode = Mode::End;
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_RADIOBUTTON101:
			_mode = Mode::Window;
			return FALSE;
		case IDC_RADIOBUTTON102:
			_mode = Mode::FullScreen;
			return FALSE;
		case IDOK:
			EndDialog(windowHandle, TRUE);
			return TRUE;
		default:
			return FALSE;
		}
	default:
		return FALSE;
	}
	return TRUE;
}

LRESULT CALLBACK Window::MainWindowProc(HWND windowHandle, UINT message_id, WPARAM wParam, LPARAM lParam)
{
	
	switch (message_id)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_MOVE:
		_isActive = false;
		break;
	default:
		break;
	}
	return DefWindowProc(windowHandle, message_id, wParam, lParam);
}