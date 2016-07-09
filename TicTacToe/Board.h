#pragma once
class Board: public RECT
{
public:
	Board(HWND hWnd);
	~Board();
	const static int CELL_SIZE = 100;
	BOOL GetCellRect(HWND hWnd, int index, RECT * pRect);
protected:
	int width, height;
};

