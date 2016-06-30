#include "stdafx.h"
#include "Board.h"
#include "Game.h"


Board::Board(HWND hWnd)
{
	RECT rc;
	if (GetClientRect(hWnd, &rc))
	{
		width = rc.right - rc.left;
		height = rc.bottom - rc.top;

		//top left corner
		left = (width - Game::CELL_SIZE * 3) / 2; //x
		top = (height - Game::CELL_SIZE * 3) / 2; //y

		//bottom right corner
		right = left + Game::CELL_SIZE * 3; //x
		bottom = top + Game::CELL_SIZE * 3; //y

	}
	else
	{
		//error?
	}

	/*left = pRect->left;
	right = pRect->right;
	top = pRect->top;
	bottom = pRect->bottom;
	width = right - left;
	height = bottom - top;*/
}


Board::~Board()
{
}

void Board::DrawPadding(HWND hWnd, HDC hdc)
{
	RECT padding;

	//top left corner
	padding.left = this->left - 25;
	padding.top = this->top - 25;

	//bottom right corner
	padding.right = this->right + 25;
	padding.bottom = this->bottom + 25;

	FillRect(hdc, &padding, (HBRUSH)GetStockObject(WHITE_BRUSH));
}

void Board::DrawBoard(HWND hWnd, HDC hdc)
{
	FillRect(hdc, this, (HBRUSH)GetStockObject(WHITE_BRUSH));
	//Rectangle(hdc, this->left, this->top, this->right, this->bottom);
}