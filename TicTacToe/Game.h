#pragma once

class Game
{
public:
	const int CELL_SIZE = 100;
	Game();
	~Game();
	BOOL paint(HWND hWnd, HDC hdc);
protected:
	BOOL GetGameBoardRect(HWND hWnd, RECT * pRect);
	BOOL DrawManyLines(HWND hWnd, HDC hdc);
};

