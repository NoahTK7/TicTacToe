#pragma once
#include "Board.h"
#include "Draw.h"

class Game
{
public:
	Game();
	~Game();
	BOOL paint(HWND hWnd, HDC hdc, Draw drawer);
	int playerTurn = 1;
	BOOL ReserveCell(int index);
	BOOL OnCellClicked(int index);
	int gameBoard[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
protected:
};

