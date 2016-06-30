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

	//for fun
	//DrawManyLines(hWnd, hdc, board);

	DrawBoardLines(hdc, board);

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

BOOL Game::DrawManyLines(HWND hWnd, HDC hdc, Board rect)
{
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	for (int x = 0; x <= width; x += 5)
	{
		for (int y = 0; y <= height; y += 5)
		{
			MoveToEx(hdc, rect.left, rect.top, NULL);
			LineTo(hdc, rect.left + x, rect.top + y);
		}
	}

	return TRUE;

}

void Game::DrawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

BOOL Game::DrawBoardLines(HDC hdc, Board board)
{
	//for (int i = 0; i < 4; ++i) closed box
	for (int i = 1; i < 3; ++i)
	{
		//Vertical
		DrawLine(hdc, board.left + (CELL_SIZE * i), board.top, board.left + (CELL_SIZE * i), board.bottom);

		//Horizontal
		DrawLine(hdc, board.left, board.top + (CELL_SIZE * i), board.right, board.top + (CELL_SIZE * i));
	}

	return TRUE;
}