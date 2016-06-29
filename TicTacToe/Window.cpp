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