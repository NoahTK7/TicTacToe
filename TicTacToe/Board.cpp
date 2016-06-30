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
		left = (width - CELL_SIZE * 3) / 2; //x
		top = (height - CELL_SIZE * 3) / 2; //y

		//bottom right corner
		right = left + CELL_SIZE * 3; //x
		bottom = top + CELL_SIZE * 3; //y

	}
	else
	{
		//error?
	}
}


Board::~Board()
{
}

void Board::DrawPadding(HWND hWnd, HDC hdc)
{
	RECT padding;

	//top left corner
	padding.left = this->left - CELL_SIZE / 4;
	padding.top = this->top - CELL_SIZE / 4;

	//bottom right corner
	padding.right = this->right + CELL_SIZE / 4;
	padding.bottom = this->bottom + CELL_SIZE / 4;

	FillRect(hdc, &padding, (HBRUSH)GetStockObject(WHITE_BRUSH));
}

void Board::DrawBoard(HWND hWnd, HDC hdc)
{
	FillRect(hdc, this, (HBRUSH)GetStockObject(WHITE_BRUSH));
	//Rectangle(hdc, this->left, this->top, this->right, this->bottom); solid outline
}

void Board::DrawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

BOOL Board::DrawBoardLines(HDC hdc)
{
	//for (int i = 0; i < 4; ++i) closed box
	for (int i = 1; i < 3; ++i)
	{
		//Vertical
		DrawLine(hdc, this->left + (CELL_SIZE * i), this->top, this->left + (CELL_SIZE * i), this->bottom);

		//Horizontal
		DrawLine(hdc, this->left, this->top + (CELL_SIZE * i), this->right, this->top + (CELL_SIZE * i));
	}

	return TRUE;
}

BOOL Board::DrawManyLines(HWND hWnd, HDC hdc)
{
	int width = this->right - this->left;
	int height = this->bottom - this->top;

	for (int x = 0; x <= width; x += 5)
	{
		for (int y = 0; y <= height; y += 5)
		{
			MoveToEx(hdc, this->left, this->top, NULL);
			LineTo(hdc, this->left + x, this->top + y);
		}
	}

	return TRUE;

}