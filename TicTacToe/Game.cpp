#include "stdafx.h"
#include "Game.h"
#include "Board.h"
#include "Draw.h"

Game::Game()
{
}


Game::~Game()
{
}

BOOL Game::paint(HWND hWnd, HDC hdc)
{
	Board board(hWnd);
	Draw drawer(hWnd, hdc);
	
	drawer.DrawPadding(&board);
	drawer.DrawBoard(&board);

	//for testing
	//board.DrawManyLines(&board);

	drawer.DrawBoardLines(&board);

	return TRUE;
}

BOOL Game::ReserveCell(int index)
{
	if (gameBoard[index] == 1) {
		return FALSE;
	}
	else {
		gameBoard[index] = 1;
		return TRUE;
	}
}