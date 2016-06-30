#include "stdafx.h"
#include "Window.h"
#include "Game.h"


Window::Window()
{
}


Window::~Window()
{
}

void Window::setMinSize(LPARAM lParam, int x, int y)
{
	MINMAXINFO * pMinMax = (MINMAXINFO*)lParam;
	pMinMax->ptMinTrackSize.x = x;
	pMinMax->ptMinTrackSize.y = y;
}

int Window::GetCellNumberFromPoint(HWND hWnd, int x, int y)
{
	POINT pt = {x, y};
	Board board = Board(hWnd);
	if (PtInRect(&board, pt)) {
		//inside game board

		//normalize (relative to rectangle)
		x = pt.x - board.left;
		y = pt.y - board.top;

		int column = x / board.CELL_SIZE;
		int row = y / board.CELL_SIZE;

		//index 0-8
		return column + row * 3;
	}

	return -1;
}