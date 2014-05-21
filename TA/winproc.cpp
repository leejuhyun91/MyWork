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

		//이걸 적용하니 창크기 조절빠르기를 못따라감...
		//srand(unsigned(time(NULL)));

		HBRUSH hBrush = ::CreateSolidBrush(RGB(COLOR_RED, COLOR_GREEN, COLOR_BLUE));
		//다시 설명듣자.. maybe..기존의 브러쉬색깔을 저장해둔 후, 지움으로써
		HBRUSH hOldBrush = (HBRUSH)::SelectObject(hdc, hBrush);

		HPEN hPen = ::CreatePen(PS_SOLID, 5, RGB(COLOR_RED, COLOR_GREEN, COLOR_BLUE));
		HPEN hOldPen = (HPEN)::SelectObject(hdc, hPen);

		::Rectangle(hdc, rc.left + 10, rc.top + 10,
			rc.right - 10, rc.bottom - 10);

		::SelectObject(hdc, hOldPen);
		::DeleteObject(hPen);

		::SelectObject(hdc, hOldBrush);
		::DeleteObject(hBrush);

		//원 그리기
		//::Ellipse(hdc, rc.left + 10, rc.top + 10,
		//	rc.right - 10, rc.bottom - 10);
		
		//글씨박스 투명화
		//::SetBkMode(hdc, TRANSPARENT);
		
		//글씨쓰기 (그림과 같이 쓸 경우, 순서에 유의!)
		//::DrawText(hdc, _T("으하하핳핳하하핳하"), -1,
		//	&rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


		::EndPaint(hWnd, &ps);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}