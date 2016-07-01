#pragma once

class Window
{
public:
	Window();
	~Window();
	void setMinSize(LPARAM lParam, int x, int y);
	int GetCellIndex(HWND hWnd, int x, int y);
private:
};

