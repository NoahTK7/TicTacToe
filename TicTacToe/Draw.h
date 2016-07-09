#pragma once
#include "Board.h"

class Draw
{
public:
	Draw(HWND hWnd, HDC hdc);
	~Draw();
	HWND window;
	HDC context;
	void DrawPadding(Board * board);
	void DrawBoard(Board * board);
	void DrawLine(int x1, int y1, int x2, int y2);
	BOOL DrawBoardLines(Board * board);
	BOOL DrawManyLines(Board * board);
};

