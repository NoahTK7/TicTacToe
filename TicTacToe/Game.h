#pragma once

class Game
{
public:
	Game();
	~Game();
	BOOL paint(HWND hWnd, HDC hdc);
protected:
	BOOL DrawManyLines(HWND hWnd, HDC hdc, RECT rect);
};

