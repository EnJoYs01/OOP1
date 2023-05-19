#include <windows.h>
#include"pch.h"
#include "PointLate.h"
#include"FigureLate.h"
#include"FigureEarly.h"

HDC hdc;

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_TIMER:
	{
		InvalidateRect(hwnd, NULL, true);
		break;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd, &ps);

		//FigureLate myFigureLate(100, 100, 70, 30);
		//myFigureLate.Show();
		//myFigureLate.MoveTo(300, 100);

		FigureEarly myFigureEarly(100, 100, 70, 30);
		//myFigureEarly.Show();
		myFigureEarly.MoveTo(300, 100);

		EndPaint(hwnd, &ps);
		break;
	}
	case WM_CREATE:
	{
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(EXIT_SUCCESS);
		break;
	}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}



int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ PWSTR czCmdLine, _In_ int nCmdShow)
{
	HWND hwnd{};
	MSG msg{};

	WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wc.hCursor = LoadCursor(nullptr, IDI_APPLICATION);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = L"MyAppClass ";
	wc.lpszMenuName = nullptr;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&wc))
	{
		return EXIT_FAILURE;
	}

	hwnd = CreateWindow(wc.lpszClassName, L"Player", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 600, 400, nullptr, nullptr, nullptr, nullptr);
	if (hwnd == INVALID_HANDLE_VALUE)
	{
		return EXIT_FAILURE;
	}

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return static_cast<int>(msg.wParam);
}
