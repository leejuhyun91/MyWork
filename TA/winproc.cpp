#include "windefine.h"
#include <time.h>
//#define NUM rand()%256
#define COLOR_RED rand()%256
#define COLOR_GREEN rand()%256
#define COLOR_BLUE rand()%256

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(uMsg == WM_DESTROY)
	{
		::PostQuitMessage(0);
		return 0;
	}
	else if(uMsg == WM_PAINT)
	{
		PAINTSTRUCT ps;
		HDC hdc = ::BeginPaint(hWnd, &ps);

		RECT rc;
		::GetClientRect(hWnd, &rc);

		//�̰� �����ϴ� âũ�� ���������⸦ ������...
		//srand(unsigned(time(NULL)));

		HBRUSH hBrush = ::CreateSolidBrush(RGB(COLOR_RED, COLOR_GREEN, COLOR_BLUE));
		//�ٽ� �������.. maybe..������ �귯�������� �����ص� ��, �������ν�
		HBRUSH hOldBrush = (HBRUSH)::SelectObject(hdc, hBrush);

		HPEN hPen = ::CreatePen(PS_SOLID, 5, RGB(COLOR_RED, COLOR_GREEN, COLOR_BLUE));
		HPEN hOldPen = (HPEN)::SelectObject(hdc, hPen);

		::Rectangle(hdc, rc.left + 10, rc.top + 10,
			rc.right - 10, rc.bottom - 10);

		::SelectObject(hdc, hOldPen);
		::DeleteObject(hPen);

		::SelectObject(hdc, hOldBrush);
		::DeleteObject(hBrush);

		//�� �׸���
		//::Ellipse(hdc, rc.left + 10, rc.top + 10,
		//	rc.right - 10, rc.bottom - 10);
		
		//�۾��ڽ� ����ȭ
		//::SetBkMode(hdc, TRANSPARENT);
		
		//�۾����� (�׸��� ���� �� ���, ������ ����!)
		//::DrawText(hdc, _T("�������K�K�����K��"), -1,
		//	&rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


		::EndPaint(hWnd, &ps);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}