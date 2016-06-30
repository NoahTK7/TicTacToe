#pragma once

class Window
{
public:
	Window();
	~Window();
	void setMinSize(LPARAM lParam, int x, int y);
	int GetCellNumberFromPoint(HWND hWnd, int x, int y);
private:
};

