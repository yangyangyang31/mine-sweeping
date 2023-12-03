#include "test1.h"

HBITMAP hB = NULL, hM = NULL, h0 = NULL, h1 = NULL, h2 = NULL, h3 = NULL, h4 = NULL, h5 = NULL, h6 = NULL, h7 = NULL, h8 = NULL, hr = NULL, hm = NULL,hpp=NULL;
HDC hdc = NULL, hBlank = NULL, hTempDc = NULL;
DWORD k;

void initlshow(char show[N][N])
{
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++)
			show[i][j] = 'B';
}

void initlmine(char mine[N][N])
{
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++)
			mine[i][j] = '?';
	int n =20;
	while (n)
	{
		int x = rand() % (N - 3) + 1, y = rand() % (N-3)+1;
		if (mine[x][y] == '?')
		{
			mine[x][y] = '#';
			n--;
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (mine[i][j] != '#')
			{
				int num = 0;
				for (int x = i - 1; x <= i + 1; x++)
				{
					for (int y = j - 1; y <= j + 1; y++)
						if (mine[x][y] == '#')
							num++;
				}
				mine[i][j] = '0' + num;
			}
		
		}
	}
}

//void display1(HWND hwnd,char show[N][N])
//{
//	PAINTSTRUCT ps;
//		HDC hdc, hBlank;
//		RECT rect;
//		::GetClientRect(hwnd, &rect);
//		hdc = ::BeginPaint(hwnd, &ps);
//		hBlank = ::CreateCompatibleDC(hdc);
//		for (int i = 1; i < N; i++)
//		{
//			for (int j = 1; j < N; j++)
//				switch (show[i][j])
//				{
//				case 'B':
//					::SelectObject(hBlank, hB);
//					BitBlt(hdc, rect.left + 25 * (j - 1), rect.top + 25 * (i-1), 25, 25, hBlank, 0, 0, SRCCOPY);
//					break;
//				case '0':
//					::SelectObject(hBlank, h0);
//					BitBlt(hdc, rect.left + 25 * (j - 1), rect.top + 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
//					break;
//				case '1':
//					::SelectObject(hBlank, h1);
//					BitBlt(hdc, rect.left + 25 * (j - 1), rect.top + 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
//					break;
//				case '2':
//					::SelectObject(hBlank, h2);
//					BitBlt(hdc, rect.left + 25 * (j - 1), rect.top + 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
//					break;
//				case '3':
//					::SelectObject(hBlank, h3);
//					BitBlt(hdc, rect.left + 25 * (j - 1), rect.top + 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
//					break;
//				case '4':
//					::SelectObject(hBlank, h4);
//					BitBlt(hdc, rect.left + 25 * (j - 1), rect.top + 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
//					break;
//				case '5':
//					::SelectObject(hBlank, h5);
//					BitBlt(hdc, rect.left + 25 * (j - 1), rect.top + 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
//					break;
//				case '6':
//					::SelectObject(hBlank, h6);
//					BitBlt(hdc, rect.left + 25 * (j - 1), rect.top + 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
//					break;
//				case '7':
//					::SelectObject(hBlank, h7);
//					BitBlt(hdc, rect.left + 25 * (j - 1), rect.top + 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
//					break;
//				case '8':
//					::SelectObject(hBlank, h8);
//					BitBlt(hdc, rect.left + 25 * (j - 1), rect.top + 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
//					break;
//				case '#':
//					::SelectObject(hBlank, hM);
//					BitBlt(hdc, rect.left + 25 * (j - 1), rect.top + 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
//					break;
//				}
//
//		}
//		::EndPaint(hwnd, &ps);
//}

void display2(HWND hwnd, char show[N][N])
{
	PatBlt(hTempDc, 0, 0, 390, 390, WHITENESS);
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
			switch (show[i][j])
			{
			case 'B':
				::SelectObject(hBlank, hB);
				BitBlt(hTempDc,  25 * (j - 1),  25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				 k = GetLastError();
				break;
			case '0':
				::SelectObject(hBlank, h0);
				BitBlt(hTempDc, 25 * (j - 1), 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				break;
			case '1':
				::SelectObject(hBlank, h1);
				BitBlt(hTempDc, 25 * (j - 1), 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				break;
			case '2':
				::SelectObject(hBlank, h2);
				BitBlt(hTempDc, 25 * (j - 1), 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				break;
			case '3':
				::SelectObject(hBlank, h3);
				BitBlt(hTempDc, 25 * (j - 1), 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				break;
			case '4':
				::SelectObject(hBlank, h4);
				BitBlt(hTempDc, 25 * (j - 1), 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				break;
			case '5':
				::SelectObject(hBlank, h5);
				BitBlt(hTempDc, 25 * (j - 1), 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				break;
			case '6':
				::SelectObject(hBlank, h6);
				BitBlt(hTempDc, 25 * (j - 1), 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				break;
			case '7':
				::SelectObject(hBlank, h7);
				BitBlt(hTempDc, 25 * (j - 1), 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				break;
			case '8':
				::SelectObject(hBlank, h8);
				BitBlt(hTempDc, 25 * (j - 1), 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				break;
			case '#':
				::SelectObject(hBlank, hM);
				BitBlt(hTempDc, 25 * (j - 1), 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				break;
			case 'r':
				::SelectObject(hBlank, hr);
				BitBlt(hTempDc, 25 * (j - 1), 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				break;
			case 'm':
				::SelectObject(hBlank, hm);
				BitBlt(hTempDc, 25 * (j - 1), 25 * (i - 1), 25, 25, hBlank, 0, 0, SRCCOPY);
				break;
			}
	}
}


void Spread(int i, int j, char mine[N][N], char show[N][N])
{
	if (i > 0 && i < N && j > 0 && j < N)             //·ÀÖ¹µÝ¹é·¶Î§Ôö´óºó£¬xy²»ÔÚÆåÅÌÄÚ
	{
		int num = mine[i][j]-'0';
		if (num == 0)
		{
			show[i][j] = '0';
			int x, y;
			for (x = i - 1; x <= i + 1; x++)
			{
				for (y = j - 1; y <= j + 1; y++)
				{
					if (show[x][y] == 'B')
						Spread(x, y, mine, show);
				}
			}
		}
		else
		{
			show[i][j] = '0' + num;
		}
	}
}

void red(char mine[N][N], int i, int j)
{
	mine[i][j] = 'r';
}

void findmine(int i, int j, char mine[N][N], char show[N][N], HWND hwnd,int &f)
{
	int win = 0;
	if (mine[i][j] == '#')
	{
		red(mine, i, j);
		f = 0;
		
	}
	else
	{
		if(show[i][j]=='B'||show[i][j]=='m')
		{
			Spread( i, j, mine, show);         //µÝ¹éÀ©É¢£»
			//display2(hwnd, show);
		}
	}

	for(int i=1;i<N-1;i++)
	{
		for (int j = 1; j <= N - 1; j++)
			if (show[i][j] == 'B'||show[i][j]=='m')
				win++;
	}
	
	if (win<=20)
	{
		f = 2;
	}
}
