#pragma once
#include <Windows.h>
#include <time.h>
#define  N  17

extern HBITMAP hB, hM, h0, h1, h2, h3, h4, h5, h6, h7, h8, hr, hm,hpp;
extern 	HDC hdc, hBlank, hTempDc;

void initlshow(char show[N][N]);

void initlmine(char mine[N][N]);

void display1(HWND hwnd, char show[N][N]);
void display2(HWND hwnd,  char show[N][N]);

void findmine(int i,int j,char mine[N][N],char show[N][N],HWND hwnd,int &f);

void Spread(int i, int j, char mine[N][N], char show[N][N]);

void red(char mine[N][N], int i, int j);
