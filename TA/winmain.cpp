#include "windefine.h"


INT WINAPI _tWinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPTSTR lpCndLine,
					 INT nCmdShow)
{
	LPCTSTR szClassName = _T("MyMainWindowClass");

	WNDCLASSEX wcex;

	::memset(&wcex, 0, sizeof(wcex));

	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_VREDRAW | CS_HREDRAW;
	wcex.lpfnWndProc = &WndProc;
	wcex.cbClsExtra = NULL;
	wcex.cbWndExtra = NULL;
	wcex.hInstance = hInstance;
	wcex.hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = ::LoadCursor(NULL, IDI_APPLICATION);
	wcex.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szClassName;
	wcex.hIconSm = ::LoadIcon(NULL, IDI_APPLICATION);

	if(!::RegisterClassEx(&wcex))
	{
		return 1;
	}

	int width = 500;
	int height = 500;

	int cx = ::GetSystemMetrics(SM_CXSCREEN);
	int cy = ::GetSystemMetrics(SM_CYSCREEN);

	int zeroX = (cx - width)/2;
	int zeroY = (cy - height)/2;

	HWND hWnd = ::CreateWindowEx(NULL, szClassName, _T("My Win32"),
		WS_OVERLAPPEDWINDOW,
		zeroX, zeroY,
		width, height,
		NULL, NULL, hInstance, NULL);

	if(hWnd == NULL)
	{
		return 2;
	}

	::ShowWindow(hWnd, nCmdShow);
	::UpdateWindow(hWnd);

	MSG msg;

	while (true)
	{
		if(::PeekMessage(&msg,NULL, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);

		}
		if(msg.message == WM_QUIT)
			break;
	}

	return msg.wParam;
}

