#include "stdafx.h"
#include "Game.h"

Game::Game()
{
}


Game::~Game()
{
}

BOOL Game::paint(HWND hWnd, HDC hdc)
{
	RECT rc;

	if (GetGameBoardRect(hWnd, &rc))
	{
		//FillRect(hdc, &rc, (HBRUSH)GetStockObject(WHITE_BRUSH));
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}
	else {
		//throw error
		return FALSE;
	}

	//for fun
	DrawManyLines(hWnd, hdc);

	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, 100, 100);

	return TRUE;
}

BOOL Game::GetGameBoardRect(HWND hWnd, RECT * pRect)
{
	RECT rc;
	if (GetClientRect(hWnd, &rc))
	{
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;

		pRect->left = (width - CELL_SIZE * 3) / 2;
		pRect->top = (height - CELL_SIZE * 3) / 2;

		pRect->right = pRect->left + CELL_SIZE * 3;
		pRect->bottom = pRect->top + CELL_SIZE * 3;

		return TRUE;
	}

	SetRectEmpty(pRect);
	return FALSE;
}

BOOL Game::DrawManyLines(HWND hWnd, HDC hdc)
{

	RECT rc;
	if (GetClientRect(hWnd, &rc))
	{
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;

		for (int x = 0; x < width; x += 10)
		{
			for (int y = 0; y < height; y += 10)
			{
				MoveToEx(hdc, 0, 0, NULL);
				LineTo(hdc, x, y);
			}
		}

		return TRUE;
	}

	return FALSE;

}