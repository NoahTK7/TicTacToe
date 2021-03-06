// TicTacToe.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "TicTacToe.h"
#include "Game.h"
#include "Window.h"
#include "Board.h"
#include "Draw.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TICTACTOE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TICTACTOE));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TICTACTOE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
//  wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.hbrBackground  = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TICTACTOE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//

Game game;
Window window;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC ghdc = GetDC(hWnd);

	switch (message)
    {
	case WM_CREATE:
		{
		}
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_LBUTTONDOWN:
		{
			int xPos = GET_X_LPARAM(lParam);
			int yPos = GET_Y_LPARAM(lParam);

			int index = window.GetCellIndex(hWnd, xPos, yPos);

			if (ghdc != NULL)
			{
				/*
				Debug index

				WCHAR temp[100];
				wsprintf(temp, L"Index = %d", index);
				TextOut(hdc, xPos, yPos, temp, lstrlen(temp));
				*/

				if (index != -1) {
					//game class for logic
					game.OnCellClicked(index);

					RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);					
				}

			}
		}
		break;
	case WM_MOUSEMOVE:
		{
			//if (ghdc != NULL)
			//{
			//	RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_ERASENOW | RDW_INVALIDATE);
			//
			//	POINT point;
			//	GetCursorPos(&point);
			//	ScreenToClient(hWnd, &point);

			//	Draw drawer(hWnd, ghdc); //temp
			//	drawer.DrawCrosshair(&point);		
			//}
		}
		break;

	//TODO
	//
	//	Reduce flickering, dont repaint entire window, background
	//
	// moved to  Draw::DrawBackground
	//case WM_ERASEBKGND:
	//	{
	//		//return 1;
	//		/*if (ghdc != NULL)
	//		{
	//			RECT rc;
	//			GetClientRect(hWnd, &rc);
	//			FillRect(ghdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
	//		}*/
	//	}
	//	break;
	case WM_GETMINMAXINFO:
		{
			window.setMinSize(lParam, Board::CELL_SIZE*5, Board::CELL_SIZE*5);
		}
		break;
    case WM_PAINT:
        {
			HDC          hdcMem;
			HBITMAP      hbmMem;
			HANDLE       hOld;

            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			
			//Draw drawer(hWnd, hdc);
			//game.paint(hWnd, hdc, drawer);

			RECT rect;
			int width;
			int height;

			if (GetWindowRect(hWnd, &rect))
			{
				width = rect.right - rect.left;
				height = rect.bottom - rect.top;
			}

			hdcMem = CreateCompatibleDC(hdc);
			hbmMem = CreateCompatibleBitmap(hdc, width, height);

			hOld = SelectObject(hdcMem, hbmMem);

			// Draw into hdcMem here
			Draw drawer(hWnd, hdcMem);
			game.paint(hWnd, hdcMem, drawer);

			// Transfer the off-screen DC to the screen
			BitBlt(hdc, 0, 0, width, height, hdcMem, 0, 0, SRCCOPY);

			// Free-up the off-screen DC
			SelectObject(hdcMem, hOld);
			DeleteObject(hbmMem);
			DeleteDC(hdcMem);			

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
	ReleaseDC(hWnd, ghdc);
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

