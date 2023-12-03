#include "resource.h"
#include "test1.h"

char show[N][N], mine[N][N];
int f = 1,a;
RECT rect;

LRESULT WINAPI WindowProc(HWND hwnd, UINT umsg, WPARAM wParam, LPARAM lParam)
{
	switch (umsg)
	{
	case WM_CREATE:
		initlshow(show);
		initlmine(mine);
		
		//k = GetLastError();
		break;
	case WM_CLOSE:
		::PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
	{
		int x = LOWORD(lParam),y = HIWORD(lParam);
		int j = (x) / 25+1, i = (y) / 25+1;
		findmine(i, j, mine, show,hwnd,f);
		InvalidateRect(hwnd, &rect, false);
		break;
	}
	case WM_RBUTTONDOWN:
	{
		int x = LOWORD(lParam), y = HIWORD(lParam);
		int j = (x) / 25 + 1, i = (y) / 25 + 1;
		if(show[i][j] == 'B')
			show[i][j] = 'm';
		else if(show[i][j] == 'm')
			show[i][j] = 'B';
		int win2 = 0;
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j <= N - 1; j++)
				if (show[i][j] == 'm'&&mine[i][j]=='#')
					win2++;
		}
		if (win2 == 20)
			f = 2;
		InvalidateRect(hwnd, &rect, false);
		break;
	}
	case WM_PAINT:
	{
		GetClientRect(hwnd, &rect);
		PAINTSTRUCT ps;
		HDC dc;
		dc = ::BeginPaint(hwnd, &ps);
		if(f==1)
		{
			display2(hwnd, show);
			BitBlt(dc, 0, 0, 390, 390, hTempDc, 0, 0, SRCCOPY);
		}
		else if (f == 2)
		{
			display2(hwnd, mine);
			BitBlt(dc, 0, 0, 390, 390, hTempDc, 0, 0, SRCCOPY);
			a=MessageBox(hwnd, "游戏胜利,要再来一次吗", "666666", MB_YESNO);
			switch (a)
			{
			case IDYES:
				initlshow(show);
				initlmine(mine);
				f = 1;
				display2(hwnd, show);
				BitBlt(dc, 0, 0, 390, 390, hTempDc, 0, 0, SRCCOPY);
				break;
			case IDNO:
				::PostQuitMessage(0);
				break;
			}
		}
		else if (f == 0)
		{
			display2(hwnd, mine);
			BitBlt(dc, 0, 0, 390, 390, hTempDc, 0, 0, SRCCOPY);
			a=MessageBox(hwnd, "你被炸死了，要再来一次吗", "fwfwfwfw", MB_YESNO);
			switch (a)
			{
			case IDYES:
				initlshow(show);
				initlmine(mine);
				f = 1;
				display2(hwnd, show);
				BitBlt(dc, 0, 0, 390, 390, hTempDc, 0, 0, SRCCOPY);
				break;
			case IDNO:
				::PostQuitMessage(0);
				break;
			}
		}
		
		::EndPaint(hwnd, &ps);
		break;
	}
	default:
		return DefWindowProc(hwnd, umsg, wParam, lParam);
		break;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE ProhInstance, LPSTR cmd, int nshow)
{
	//设计窗口
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = ::CreateSolidBrush(RGB(255, 255, 255));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = "hello";
	wc.lpszMenuName = NULL;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	srand((unsigned int)time(NULL));

	hB = (HBITMAP)::LoadImageA(NULL, "blank1.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);
	hM = (HBITMAP)::LoadImageA(NULL, "mine.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);
	h0 = (HBITMAP)::LoadImageA(NULL, "0.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);
	h1 = (HBITMAP)::LoadImageA(NULL, "1.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);
	h2 = (HBITMAP)::LoadImageA(NULL, "2.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);
	h3 = (HBITMAP)::LoadImageA(NULL, "3.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);
	h4 = (HBITMAP)::LoadImageA(NULL, "4.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);
	h5 = (HBITMAP)::LoadImageA(NULL, "5.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);
	h6 = (HBITMAP)::LoadImageA(NULL, "6.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);
	h7 = (HBITMAP)::LoadImageA(NULL, "7.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);
	h8 = (HBITMAP)::LoadImageA(NULL, "8.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);
	hr = (HBITMAP)::LoadImageA(NULL, "blood.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);
	hm = (HBITMAP)::LoadImageA(NULL, "flag.bmp", IMAGE_BITMAP, 25, 25, LR_LOADFROMFILE);




	//注册窗口
	::RegisterClass(&wc);

	//创建窗口
	HWND hwnd = ::CreateWindow("hello", "扫雷", WS_OVERLAPPEDWINDOW, 500, 200, (N-2) * 25 + 15, (N-2) * 25 + 15, NULL, NULL, hInstance, NULL);
	hdc = ::GetDC(hwnd);
	hBlank = ::CreateCompatibleDC(hdc);
	hTempDc = ::CreateCompatibleDC(hdc);

	hpp = (HBITMAP)::CreateCompatibleBitmap(hdc, 390, 390);
	::SelectObject(hTempDc, hpp);

	//显示与更新
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}