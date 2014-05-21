#include <windows.h>
#include <tchar.h>


//����� �Լ�����
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//winmain �Լ�����
INT WINAPI _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine,
	INT nCmdShow)
{
	/* 1. ����� */
	//long pointer constant t_string = const tchar * 
	LPCTSTR szClassName = _T("MyMainWindowClass");

	//������Ŭ����(Ȯ��) ��ü���� 
	WNDCLASSEX wcex;
	//��ü �ʱ�ȭ?
	::memset(&wcex, 0, sizeof(wcex));

	//��ü ���� �ʱ�ȭ
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

	/* 2. ������� */
	//��Ͽ� ������ ���
	if (!::RegisterClassEx(&wcex))
	{
		//���α׷� ����
		return 1;
	}
	//������ ���


	/* 3. ������ �������� */
	//�������ڵ� ����
	HWND hWnd = ::CreateWindowEx(0, szClassName, _T("My Win32"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 500,
		NULL, NULL, hInstance, NULL);

	//�������ڵ� ������ ������ ���
	if (hWnd == NULL)
	{
		//���α׷� ����
		return 2;
	}


	/* ���� �Լ����� ��Ȯ�� ������ �𸣰��� */
	//���ݱ��� ������ ���¸� �����ش�
	::ShowWindow(hWnd, nCmdShow);
	//������Ʈ
	::UpdateWindow(hWnd);



	/* 4. ���� �޽��� ���(?) */
	//�޽��� ����ü ����
	MSG msg;

	while (true)
	{
		//�޽����� �ִ� ���� ������(������ false�̹Ƿ� ���� ���� ���� x)
		if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			/* ���� �Լ����� ��Ȯ�� ������ �𸣰��� */
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);

		}
		//�����ư������ ���α׷� ����
		if (msg.message == WM_QUIT)
			break;

	}

	//I don't know what it is..
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//�޽����� ������?
	if (uMsg == WM_DESTROY)
	{
		::PostQuitMessage(0);
		//�Լ� Ż��
		return 0;
	}
	//����ڰ� ������ ������ ������ ������ ��������
	//�ý��ۿ��� �⺻���� ó�����شٴ� �Ͱ� ����� �ǹ�..
	//��Ȯ����..����
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}