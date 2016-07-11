#include "stdafx.h"
#include "Draw.h"
#include "Board.h"


Draw::Draw(HWND hWnd, HDC hdc)
{
	window = hWnd;
	context = hdc;

	HBRblue = CreateSolidBrush(RGB(0, 0, 255));
	HBRred = CreateSolidBrush(RGB(255, 0, 0));
}


Draw::~Draw()
{
	DeleteObject(HBRblue);
	DeleteObject(HBRred);
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

BOOL Draw::DrawCrosshair(LPPOINT point)
{
	RECT rc;
	POINT pt = { point->x, point->y };
	if (GetClientRect(window, &rc))
	{
		if (PtInRect(&rc, pt)) {
			DrawLine(rc.left, pt.y, rc.right, pt.y);
			DrawLine(pt.x, rc.top, pt.x, rc.bottom);
		}
	}
	return TRUE;
}

BOOL Draw::DrawCells(int * gb)
{
	for (int i = 0; i < 9; ++i) {
		
		//debug gameboard array
		WCHAR temp[100];
		wsprintf(temp, L"Index = %d", gb[i]);
		TextOut(context, i*100, 0, temp, lstrlen(temp));

		if (gb[i] != 0) {

			Board board(window);
			RECT cell;

			board.GetCellRect(window, i, &cell);

			HBRUSH HBRreds = CreateSolidBrush(RGB(255, 0, 0));
			FillRect(context, &cell, (gb[i] == 2) ? HBRreds : HBRblue);
			DeleteObject(HBRred);
		}

	}
	
	return TRUE;
}

//void Draw::CreateBrushes() {
//	HBRblue = CreateSolidBrush(RGB(0, 0, 255));
//	HBRred = CreateSolidBrush(RGB(255, 0, 0));
//}
//
//void Draw::DestroyBrushes() {
//	DeleteObject(HBRblue);
//	DeleteObject(HBRred);
//}