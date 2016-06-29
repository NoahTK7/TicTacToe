#include "stdafx.h"
#include "Board.h"


Board::Board(HWND hWnd)
{
	RECT rc;
	if (GetClientRect(hWnd, &rc))
	{
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;

		left = (width - CELL_SIZE * 3) / 2;
		top = (height - CELL_SIZE * 3) / 2;

		right = left + CELL_SIZE * 3;
		bottom = top + CELL_SIZE * 3;

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