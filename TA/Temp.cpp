#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPTSTR lpCmdLine,
					 INT nCmdShow)
{
	//스트링 
	LPCTSTR szClassName = _T("MyMainWindowClass");
	//윈도우클래스 객체선언;
	WNDCLASSEX wcex;

	//변수 초기화;
	::memset(&wcex, 0, sizeof(wcex));

	//클래스 멤버변수 초기화;
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

	//등록에 실패
	if(!::RegisterClassEx(&wcex))
	{
		return 1;
	}
	
	//등록성공하면 윈도우ex 생성
	HWND hWnd = ::CreateWindowEx(NULL, szClassName, _T("Lee's Win32"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 500, 
		NULL, NULL, hInstance, NULL);
	//윈도우핸들 생성 실패?할 경우, 프로그램 exit
	if(hWnd == NULL)
	{
		return 2;
	}

	//화면에 보이게
	::ShowWindow(hWnd, nCmdShow);
		
	//내용을 한번 업데이트
	::UpdateWindow(hWnd);

	//message structure
	MSG msg;

	while(true)
	{
		if(::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
		if(msg.message == WM_QUIT)
			break;
	}
	return msg.wParam;

}	
//메시지 구조체의 인자값을 받아 
//메시지에 대한 처리를 구현한 후,
//시스템에 기본적인 처리를 맡김(return)
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(uMsg == WM_DESTROY)
	{
		::PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

	//어떠한 메시지에 대한 기본처리를 해주는 함수.. 시스템에서 기본적으로 제공
