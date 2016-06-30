#pragma once
#include "Board.h"

class Game
{
public:
	Game();
	~Game();
	BOOL paint(HWND hWnd, HDC hdc);
protected:
	BOOL DrawManyLines(HWND hWnd, HDC hdc, Board rect);
	void DrawLine(HDC hdc, int x1, int y1, int x2, int y2);
	BOOL DrawBoardLines(HDC hdc);
};

