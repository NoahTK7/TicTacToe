#pragma once
class Board: public RECT
{
public:
	Board(HWND hWnd);
	~Board();
	void DrawPadding(HWND hWnd, HDC hdc);
	void DrawBoard(HWND hWnd, HDC hdc);
protected:
	int width, height;
};

