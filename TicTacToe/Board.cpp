#include "stdafx.h"
#include "Board.h"
#include "Game.h"


Board::Board(HWND hWnd)
{
	//GetGameBoardRect
	RECT rc;
	if (GetClientRect(hWnd, &rc))
	{
		width = rc.right - rc.left;
		height = rc.bottom - rc.top;

		//top left corner
		left = (width - CELL_SIZE * 3) / 2; //x
		top = (height - CELL_SIZE * 3) / 2; //y

		//bottom right corner
		right = left + CELL_SIZE * 3; //x
		bottom = top + CELL_SIZE * 3; //y

	}
	else
	{
		//TODO: error?
	}
}


Board::~Board()
{
}

//Static?
BOOL Board::GetCellRect(HWND hWnd, int index, RECT * pRect)
{
	SetRectEmpty(pRect);
	if (index < 0 || index > 8) 
		return FALSE;

	int x = index % 3; // colum
	int y = index / 3; // row

	pRect->left = this->left + (x * CELL_SIZE) + 1;
	pRect->top = this->top + (y * CELL_SIZE) + 1;

	pRect->right = pRect->left + CELL_SIZE - 1;
	pRect->bottom = pRect->top + CELL_SIZE - 1;

	return TRUE;
}