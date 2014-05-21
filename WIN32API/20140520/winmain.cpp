#include <windows.h>
#include <tchar.h>

#define WINDOWXSIZE 500
#define WINDOWYSIZE 600

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

INT WINAPI _tWinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPTSTR lpCmdLine,
					 INT nCmdShow)
{
	LPCTSTR szClassName = _T("MyMainWindowClass");

	WNDCLASSEX wcex;

	::memset(&wcex, 0, sizeof(wcex));

	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_VREDRAW | CS_HREDRAW;
	wcex.lpfnWndProc = &WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szClassName;
	wcex.hIconSm = ::LoadIcon(NULL, IDI_APPLICATION);

	if (!::RegisterClassEx(&wcex))
	{
		return 1;
	}

	int cx = ::GetSystemMetrics(SM_CXSCREEN);
	int cy = ::GetSystemMetrics(SM_CYSCREEN);
	int zeroX = (cx - WINDOWXSIZE)/2;
	int zeroY = (cy - WINDOWYSIZE)/2;

	HWND hWnd = ::CreateWindowEx(0, szClassName, _T("Lee Juhyun"),
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
		zeroX, zeroY,
		WINDOWXSIZE, WINDOWYSIZE,
		NULL, NULL, hInstance, NULL);

	if (hWnd == NULL)
	{
		return 2;
	}

	::ShowWindow(hWnd, SW_NORMAL);
	::UpdateWindow(hWnd);

	MSG msg;

	while (true)
	{
		//if (::GetMessage(&msg, NULL, 0, 0))
		if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
		if (msg.message == WM_QUIT)
			break;
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY)
	{
		::PostQuitMessage(0);
		return 0;
	}

	return ::DefWindowProc(hWnd,uMsg,wParam,lParam);
}





	