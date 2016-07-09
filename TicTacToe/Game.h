#pragma once
#include "Board.h"

class Game
{
public:
	Game();
	~Game();
	BOOL paint(HWND hWnd, HDC hdc);
	int playerTurn = 1;
	BOOL ReserveCell(int index);
	int gameBoard[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
protected:
};

