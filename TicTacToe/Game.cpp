#include "stdafx.h"
#include "Game.h"
#include "Board.h"

Game::Game()
{
}


Game::~Game()
{
}

BOOL Game::paint(HWND hWnd, HDC hdc, Draw drawer)
{
	Board board(hWnd);
	
	drawer.DrawPadding(&board);
	drawer.DrawBoard(&board);

	//for testing
	//board.DrawManyLines(&board);

	drawer.DrawBoardLines(&board);

	drawer.DrawCells(gameBoard);

	return TRUE;
}

BOOL Game::ReserveCell(int index)
{
	if (gameBoard[index] != 0) {
		return FALSE;
	}
	else {
		gameBoard[index] = playerTurn;
		return TRUE;
	}
}

BOOL Game::OnCellClicked(int index)
{
	if (ReserveCell(index)) {
		playerTurn = (playerTurn == 2) ? 1 : 2;
	}
	
	return TRUE;
}