#pragma once

#include <Windows.h>

class Window
{
public:
	explicit Window() = default;
	~Window() = default;
	enum class Mode
	{
		Window,
		FullScreen,
		End
	};
	void MakeSettingWindow(Mode& mode) const;
	void MakeMainWindow() const;
	inline bool isActive() const { return _isActive; }
	inline void SetActive() { _isActive = true; }
private:
	static LRESULT CALLBACK SettingWindowProc(HWND windowHandle, UINT message_id, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK MainWindowProc(HWND windowHandle, UINT message_id, WPARAM wParam, LPARAM lParam);
	static Mode _mode;
	static bool _isActive;
};

