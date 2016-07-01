#pragma once
class Board: public RECT
{
public:
	Board(HWND hWnd);
	~Board();
	const static int CELL_SIZE = 100;
	void DrawPadding(HWND hWnd, HDC hdc);
	void DrawBoard(HWND hWnd, HDC hdc);
	BOOL DrawBoardLines(HDC hdc);
	void DrawLine(HDC hdc, int x1, int y1, int x2, int y2);
	BOOL DrawManyLines(HWND hWnd, HDC hdc);
	BOOL GetCellRect(HWND hWnd, int index, RECT * pRect);
protected:
	int width, height;
};

