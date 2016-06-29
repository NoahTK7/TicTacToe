#pragma once
class Board: public RECT
{
public:
	Board(HWND hWnd);
	~Board();
protected:
	int width, height;
};

