#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPTSTR lpCmdLine,
					 INT nCmdShow)
{
	//��Ʈ�� 
	LPCTSTR szClassName = _T("MyMainWindowClass");
	//������Ŭ���� ��ü����;
	WNDCLASSEX wcex;

	//���� �ʱ�ȭ;
	::memset(&wcex, 0, sizeof(wcex));

	//Ŭ���� ������� �ʱ�ȭ;
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

	//��Ͽ� ����
	if(!::RegisterClassEx(&wcex))
	{
		return 1;
	}
	
	//��ϼ����ϸ� ������ex ����
	HWND hWnd = ::CreateWindowEx(NULL, szClassName, _T("Lee's Win32"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 500, 
		NULL, NULL, hInstance, NULL);
	//�������ڵ� ���� ����?�� ���, ���α׷� exit
	if(hWnd == NULL)
	{
		return 2;
	}

	//ȭ�鿡 ���̰�
	::ShowWindow(hWnd, nCmdShow);
		
	//������ �ѹ� ������Ʈ
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
//�޽��� ����ü�� ���ڰ��� �޾� 
//�޽����� ���� ó���� ������ ��,
//�ý��ۿ� �⺻���� ó���� �ñ�(return)
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(uMsg == WM_DESTROY)
	{
		::PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

	//��� �޽����� ���� �⺻ó���� ���ִ� �Լ�.. �ý��ۿ��� �⺻������ ����
