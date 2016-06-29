#include "stdafx.h"
#include "Board.h"
#include "Game.h"


Board::Board(HWND hWnd)
{
	RECT rc;
	if (GetClientRect(hWnd, &rc))
	{
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;

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