#include "stdafx.h"
#include "Game.h"
#include "Board.h"

Game::Game()
{
}


Game::~Game()
{
}

BOOL Game::paint(HWND hWnd, HDC hdc)
{
	Board board = Board(hWnd);
	
	board.DrawPadding(hWnd, hdc);
	board.DrawBoard(hWnd, hdc);

	//for testing
	//board.DrawManyLines(hWnd, hdc);

	board.DrawBoardLines(hdc);

	return TRUE;
}