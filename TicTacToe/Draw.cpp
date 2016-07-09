#include "stdafx.h"
#include "Draw.h"
#include "Board.h"


Draw::Draw(HWND hWnd, HDC hdc)
{
	window = hWnd;
	context = hdc;
}


Draw::~Draw()
{
}


void Draw::DrawPadding(Board * board)
{
	RECT padding;

	//top left corner
	padding.left = board->left - board->CELL_SIZE / 4;
	padding.top = board->top - board->CELL_SIZE / 4;

	//bottom right corner
	padding.right = board->right + board->CELL_SIZE / 4;
	padding.bottom = board->bottom + board->CELL_SIZE / 4;

	FillRect(context, &padding, (HBRUSH)GetStockObject(WHITE_BRUSH));
}

void Draw::DrawBoard(Board * board)
{
	FillRect(context, board, (HBRUSH)GetStockObject(WHITE_BRUSH));
	//Rectangle(hdc, this->left, this->top, this->right, this->bottom); solid outline
}

void Draw::DrawLine(int x1, int y1, int x2, int y2)
{
	MoveToEx(context, x1, y1, NULL);
	LineTo(context, x2, y2);
}

BOOL Draw::DrawBoardLines(Board * board)
{
	for (int i = 0; i < 4; ++i) // border
								//for (int i = 1; i < 3; ++i) // no border
	{
		//Vertical
		DrawLine(board->left + (board->CELL_SIZE * i), board->top, board->left + (board->CELL_SIZE * i), board->bottom);

		//Horizontal
		DrawLine(board->left, board->top + (board->CELL_SIZE * i), board->right, board->top + (board->CELL_SIZE * i));
	}

	return TRUE;
}

BOOL Draw::DrawManyLines(Board * board)
{
	int width = board->right - board->left;
	int height = board->bottom - board->top;

	for (int x = 0; x <= width; x += 5)
	{
		for (int y = 0; y <= height; y += 5)
		{
			MoveToEx(context, board->left, board->top, NULL);
			LineTo(context, board->left + x, board->top + y);
		}
	}

	return TRUE;

}