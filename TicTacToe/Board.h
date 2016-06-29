#pragma once
class Board: public RECT
{
public:
	Board(HWND hWnd);
	const static int CELL_SIZE = 100;
	~Board();
protected:
	int width, height;
};

