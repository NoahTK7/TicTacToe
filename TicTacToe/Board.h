#pragma once
class Board: public RECT
{
public:
	Board(HWND hWnd);
	~Board();
	const static int CELL_SIZE = 100;
	void DrawPadding(HWND hWnd, HDC hdc);
	void DrawBoard(HWND hWnd, HDC hdc);
	BOOL Board::DrawBoardLines(HDC hdc);
	void Board::DrawLine(HDC hdc, int x1, int y1, int x2, int y2);
	BOOL Board::DrawManyLines(HWND hWnd, HDC hdc);
protected:
	int width, height;
};

