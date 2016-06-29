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

	FillRect(hdc, &board, (HBRUSH)GetStockObject(WHITE_BRUSH));
	//Rectangle(hdc, board.left, board.top, board.right, board.bottom);

	//for fun
	DrawManyLines(hWnd, hdc, board);

	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, 100, 100);

	return TRUE;
}

//BOOL Game::GetGameBoardRect(HWND hWnd, RECT * pRect)
//{
//	RECT rc;
//	if (GetClientRect(hWnd, &rc))
//	{
//		int width = rc.right - rc.left;
//		int height = rc.bottom - rc.top;
//
//		pRect->left = (width - CELL_SIZE * 3) / 2;
//		pRect->top = (height - CELL_SIZE * 3) / 2;
//
//		pRect->right = pRect->left + CELL_SIZE * 3;
//		pRect->bottom = pRect->top + CELL_SIZE * 3;
//
//		return TRUE;
//	}
//
//	SetRectEmpty(pRect);
//	return FALSE;
//}

BOOL Game::DrawManyLines(HWND hWnd, HDC hdc, RECT rect)
{

	Board board = Board(hWnd);
	
	int width = board.right - board.left;
	int height = board.bottom - board.top;

	for (int x = 0; x <= width; x += 5)
	{
		for (int y = 0; y <= height; y += 5)
		{
			MoveToEx(hdc, board.left, board.top, NULL);
			LineTo(hdc, board.left + x, board.top + y);
		}
	}

	return TRUE;

}