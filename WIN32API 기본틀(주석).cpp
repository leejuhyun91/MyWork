#include <windows.h>
#include <tchar.h>


//사용자 함수선언
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//winmain 함수선언
INT WINAPI _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine,
	INT nCmdShow)
{
	/* 1. 선언부 */
	//long pointer constant t_string = const tchar * 
	LPCTSTR szClassName = _T("MyMainWindowClass");

	//윈도우클래스(확장) 객체선언 
	WNDCLASSEX wcex;
	//객체 초기화?
	::memset(&wcex, 0, sizeof(wcex));

	//객체 변수 초기화
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_VREDRAW | CS_HREDRAW;
	wcex.lpfnWndProc = &WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = ::LoadCursor(NULL, IDI_APPLICATION);
	wcex.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szClassName;
	wcex.hIconSm = ::LoadIcon(NULL, IDI_APPLICATION);

	/* 2. 등록절차 */
	//등록에 실패할 경우
	if (!::RegisterClassEx(&wcex))
	{
		//프로그램 종료
		return 1;
	}
	//성공할 경우


	/* 3. 윈도우 생성절차 */
	//윈도우핸들 생성
	HWND hWnd = ::CreateWindowEx(0, szClassName, _T("My Win32"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 500,
		NULL, NULL, hInstance, NULL);

	//윈도우핸들 생성에 실패할 경우
	if (hWnd == NULL)
	{
		//프로그램 종료
		return 2;
	}


	/* 다음 함수들의 정확한 개념을 모르겠음 */
	//지금까지 윈도우 상태를 보여준다
	::ShowWindow(hWnd, nCmdShow);
	//업데이트
	::UpdateWindow(hWnd);



	/* 4. 각종 메시지 출력(?) */
	//메시지 구조체 선언
	MSG msg;

	while (true)
	{
		//메시지가 있던 없던 리턴함(없으면 false이므로 다음 구문 실행 x)
		if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			/* 다음 함수들의 정확한 개념을 모르겠음 */
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);

		}
		//종료버튼누르면 프로그램 종료
		if (msg.message == WM_QUIT)
			break;

	}

	//I don't know what it is..
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//메시지가 없으면?
	if (uMsg == WM_DESTROY)
	{
		::PostQuitMessage(0);
		//함수 탈출
		return 0;
	}
	//사용자가 구현한 윈도우 절차를 제외한 나머지는
	//시스템에서 기본으로 처리해준다는 것과 비슷한 의미..
	//불확실함..ㅈㅅ
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}