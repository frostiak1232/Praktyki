#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <Windows.h>
#include <string>


using namespace std;
#pragma comment( lib, "winmm" )//playsound

HANDLE hOut;
int szer = 19;
int zyz = 0;//do testu czy wylosowane
int wys = 13;
int wylosowana=0;
int pozycja[16];
int inplay[16];
int iks, kiz;
int pola1[32][55];
int rollamount = 3;
int i;
int dlugosc;
string bot1, bot2, bot3;
int ruch=0;
int wyjety;
int loop=0;
char znak = 178;
int c = 0;
int tymczasowa;
int tak1, tak2, tak4, tak3, tak5;
char tab[13][19];

void duzo();

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void zyze()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* sprawdza liczbe wierszyw buforze */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* wypelnia bufor spacjami */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* wypelnia bufor aktualnymi kolorami */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* przesuwa kursor */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void przejscie(int ktr) 
{
	ClearScreen();
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	gotoxy(1, 1);
	for(int i = 0; i < 19; i++)
	{
		cout << znak;
	}
	for (int i = 2; i < 13; i++)
	{
		gotoxy(1, i);
		cout << znak;
		for (int z = 0; z <17 ; z++)
		{
			cout << " ";
		}
		cout << znak;
	}
	gotoxy(1, 13);
	for (int i = 0; i < 19; i++)
	{
		cout << znak;
	}
	gotoxy(6, 7);
	if (ktr == 1)
	{
		cout << "BOT " << bot1;
	}
	if (ktr == 2)
	{
		cout << "BOT " << bot2;
	}
	if (ktr == 3)
	{
		cout << "BOT " << bot3;
	}
	if (ktr == 4)
	{
		cout << "YOUR TURN";
	}
}

void wyswietl()
{
	ClearScreen();
	//system("cls");
	for (i = 0; i < wys; i++)
	{
		gotoxy(1, i + 1);
		for (c = 0; c < szer; c++)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			if (tab[i][c] == '1')
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			if (tab[i][c] == '2')
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			if (tab[i][c] == '3')
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			if (tab[i][c] == '4')
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			if (tab[i][c] == 'b')
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			if (tab[i][c] == ' ')
			{
				SetConsoleTextAttribute(hOut, 60);
			}
			if (tab[i][c] == 'g')
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			if (tab[i][c] == 'y')
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			cout << tab[i][c];
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
		cout << endl;
	}
}

void wielkoscf(int foncik)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = foncik;
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}

void rozmiarokna()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 220, 100, 880, 500, TRUE); // pozycja x/y  szer/wys
}

void uspij(double czas)
{
	Sleep(czas * 1000);
}

void opening(double czas)
{
	for (int i = 0; i < 47; i++)
	{
		gotoxy(i, 0);
		cout << "@";
		uspij(czas);
	}
	for (int d = 1; d < 15; d++)
	{
		gotoxy(46, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 46; i >= 0; i--)
	{
		gotoxy(i, 14);
		cout << "@";
		uspij(czas);
	}
	for (int d = 14; d > 0; d--)
	{
		gotoxy(0, d);
		cout << "@";
		uspij(czas);
	}
	gotoxy(19, 6);
	cout << "CHINCZYK";
	uspij(1);
	gotoxy(13, 7);
	cout << "PRESS SPACE TO START";
}

void menu()
{
	for (int i = 0; i < 47; i++)
	{
		gotoxy(i, 0);
		cout << "@";
	}
	for (int d = 1; d < 15; d++)
	{
		gotoxy(46, d);
		cout << "@";
	}
	for (int i = 46; i >= 0; i--)
	{
		gotoxy(i, 14);
		cout << "@";
	}
	for (int d = 14; d > 0; d--)
	{
		gotoxy(0, d);
		cout << "@";
	}
	gotoxy(10, 5);
	cout << "DO YOU WANT TO PLAY AGAIN?";
	uspij(1);
	gotoxy(13, 7);
	cout << "YES[y]";
	gotoxy(27, 7);
	cout << "NO[n]";
}

void wygrana(double czas)
{
	for (int i = 0; i < 47; i++)
	{
		gotoxy(i, 0);
		cout << "@";
		uspij(czas);
	}
	for (int d = 1; d < 15; d++)
	{
		gotoxy(46, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 46; i >= 0; i--)
	{
		gotoxy(i, 14);
		cout << "@";
		uspij(czas);
	}
	for (int d = 14; d > 0; d--)
	{
		gotoxy(0, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 1; i < 46; i++)
	{
		gotoxy(i, 1);
		cout << "@";
		uspij(czas);
	}
	for (int d = 2; d < 14; d++)
	{
		gotoxy(45, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 45; i >= 1; i--)
	{
		gotoxy(i, 13);
		cout << "@";
		uspij(czas);
	}
	for (int d = 13; d > 1; d--)
	{
		gotoxy(1, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 2; i < 45; i++)
	{
		gotoxy(i, 2);
		cout << "@";
		uspij(czas);
	}
	for (int d = 3; d < 13; d++)
	{
		gotoxy(44, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 44; i >= 2; i--)
	{
		gotoxy(i, 12);
		cout << "@";
		uspij(czas);
	}
	for (int d = 12; d > 2; d--)
	{
		gotoxy(2, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 3; i < 44; i++)
	{
		gotoxy(i, 3);
		cout << "@";
		uspij(czas);
	}
	for (int d = 4; d < 12; d++)
	{
		gotoxy(43, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 43; i >= 3; i--)
	{
		gotoxy(i, 11);
		cout << "@";
		uspij(czas);
	}
	for (int d = 11; d > 3; d--)
	{
		gotoxy(3, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 4; i < 43; i++)
	{
		gotoxy(i, 4);
		cout << "@";
		uspij(czas);
	}
	for (int d = 5; d < 11; d++)
	{
		gotoxy(42, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 42; i >= 4; i--)
	{
		gotoxy(i, 10);
		cout << "@";
		uspij(czas);
	}
	for (int d = 10; d > 4; d--)
	{
		gotoxy(4, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 5; i < 42; i++)
	{
		gotoxy(i, 5);
		cout << "@";
		uspij(czas);
	}
	for (int d = 6; d < 10; d++)
	{
		gotoxy(41, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 41; i >= 5; i--)
	{
		gotoxy(i, 9);
		cout << "@";
		uspij(czas);
	}
	for (int d = 9; d > 5; d--)
	{
		gotoxy(5, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 6; i < 41; i++)
	{
		gotoxy(i, 6);
		cout << "@";
		uspij(czas);
	}
	for (int d = 7; d < 9; d++)
	{
		gotoxy(40, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 40; i >= 6; i--)
	{
		gotoxy(i, 8);
		cout << "@";
		uspij(czas);
	}
	for (int d = 8; d > 6; d--)
	{
		gotoxy(6, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 7; i < 40; i++)
	{
		gotoxy(i, 7);
		cout << "@";
		uspij(czas);
	}
	//
	for (int i = 1; i < 46; i++)
	{
		gotoxy(i, 1);
		cout << " ";
		uspij(czas);
	}
	for (int d = 2; d < 14; d++)
	{
		gotoxy(45, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 45; i >= 1; i--)
	{
		gotoxy(i, 13);
		cout << " ";
		uspij(czas);
	}
	for (int d = 13; d > 1; d--)
	{
		gotoxy(1, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 2; i < 45; i++)
	{
		gotoxy(i, 2);
		cout << " ";
		uspij(czas);
	}
	for (int d = 3; d < 13; d++)
	{
		gotoxy(44, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 44; i >= 2; i--)
	{
		gotoxy(i, 12);
		cout << " ";
		uspij(czas);
	}
	for (int d = 12; d > 2; d--)
	{
		gotoxy(2, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 3; i < 44; i++)
	{
		gotoxy(i, 3);
		cout << " ";
		uspij(czas);
	}
	for (int d = 4; d < 12; d++)
	{
		gotoxy(43, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 43; i >= 3; i--)
	{
		gotoxy(i, 11);
		cout << " ";
		uspij(czas);
	}
	for (int d = 11; d > 3; d--)
	{
		gotoxy(3, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 4; i < 43; i++)
	{
		gotoxy(i, 4);
		cout << " ";
		uspij(czas);
	}
	for (int d = 5; d < 11; d++)
	{
		gotoxy(42, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 42; i >= 4; i--)
	{
		gotoxy(i, 10);
		cout << " ";
		uspij(czas);
	}
	for (int d = 10; d > 4; d--)
	{
		gotoxy(4, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 5; i < 42; i++)
	{
		gotoxy(i, 5);
		cout << " ";
		uspij(czas);
	}
	for (int d = 6; d < 10; d++)
	{
		gotoxy(41, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 41; i >= 5; i--)
	{
		gotoxy(i, 9);
		cout << " ";
		uspij(czas);
	}
	for (int d = 9; d > 5; d--)
	{
		gotoxy(5, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 6; i < 41; i++)
	{
		gotoxy(i, 6);
		cout << " ";
		uspij(czas);
	}
	for (int d = 7; d < 9; d++)
	{
		gotoxy(40, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 40; i >= 6; i--)
	{
		gotoxy(i, 8);
		cout << " ";
		uspij(czas);
	}
	for (int d = 8; d > 6; d--)
	{
		gotoxy(6, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 7; i < 40; i++)
	{
		gotoxy(i, 7);
		cout << " ";
		uspij(czas);
	}
	gotoxy(15, 6);
	cout << "CONGRATULATIONS!";
	uspij(1);
	gotoxy(19, 7);
	cout << "YOU WON";
}

void przegrana(double czas)
{
	for (int i = 0; i < 47; i++)
	{
		gotoxy(i, 0);
		cout << "@";
		uspij(czas);
	}
	for (int d = 1; d < 15; d++)
	{
		gotoxy(46, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 46; i >= 0; i--)
	{
		gotoxy(i, 14);
		cout << "@";
		uspij(czas);
	}
	for (int d = 14; d > 0; d--)
	{
		gotoxy(0, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 1; i < 46; i++)
	{
		gotoxy(i, 1);
		cout << "@";
		uspij(czas);
	}
	for (int d = 2; d < 14; d++)
	{
		gotoxy(45, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 45; i >= 1; i--)
	{
		gotoxy(i, 13);
		cout << "@";
		uspij(czas);
	}
	for (int d = 13; d > 1; d--)
	{
		gotoxy(1, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 2; i < 45; i++)
	{
		gotoxy(i, 2);
		cout << "@";
		uspij(czas);
	}
	for (int d = 3; d < 13; d++)
	{
		gotoxy(44, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 44; i >= 2; i--)
	{
		gotoxy(i, 12);
		cout << "@";
		uspij(czas);
	}
	for (int d = 12; d > 2; d--)
	{
		gotoxy(2, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 3; i < 44; i++)
	{
		gotoxy(i, 3);
		cout << "@";
		uspij(czas);
	}
	for (int d = 4; d < 12; d++)
	{
		gotoxy(43, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 43; i >= 3; i--)
	{
		gotoxy(i, 11);
		cout << "@";
		uspij(czas);
	}
	for (int d = 11; d > 3; d--)
	{
		gotoxy(3, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 4; i < 43; i++)
	{
		gotoxy(i, 4);
		cout << "@";
		uspij(czas);
	}
	for (int d = 5; d < 11; d++)
	{
		gotoxy(42, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 42; i >= 4; i--)
	{
		gotoxy(i, 10);
		cout << "@";
		uspij(czas);
	}
	for (int d = 10; d > 4; d--)
	{
		gotoxy(4, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 5; i < 42; i++)
	{
		gotoxy(i, 5);
		cout << "@";
		uspij(czas);
	}
	for (int d = 6; d < 10; d++)
	{
		gotoxy(41, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 41; i >= 5; i--)
	{
		gotoxy(i, 9);
		cout << "@";
		uspij(czas);
	}
	for (int d = 9; d > 5; d--)
	{
		gotoxy(5, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 6; i < 41; i++)
	{
		gotoxy(i, 6);
		cout << "@";
		uspij(czas);
	}
	for (int d = 7; d < 9; d++)
	{
		gotoxy(40, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 40; i >= 6; i--)
	{
		gotoxy(i, 8);
		cout << "@";
		uspij(czas);
	}
	for (int d = 8; d > 6; d--)
	{
		gotoxy(6, d);
		cout << "@";
		uspij(czas);
	}
	for (int i = 7; i < 40; i++)
	{
		gotoxy(i, 7);
		cout << "@";
		uspij(czas);
	}
	//
	for (int i = 1; i < 46; i++)
	{
		gotoxy(i, 1);
		cout << " ";
		uspij(czas);
	}
	for (int d = 2; d < 14; d++)
	{
		gotoxy(45, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 45; i >= 1; i--)
	{
		gotoxy(i, 13);
		cout << " ";
		uspij(czas);
	}
	for (int d = 13; d > 1; d--)
	{
		gotoxy(1, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 2; i < 45; i++)
	{
		gotoxy(i, 2);
		cout << " ";
		uspij(czas);
	}
	for (int d = 3; d < 13; d++)
	{
		gotoxy(44, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 44; i >= 2; i--)
	{
		gotoxy(i, 12);
		cout << " ";
		uspij(czas);
	}
	for (int d = 12; d > 2; d--)
	{
		gotoxy(2, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 3; i < 44; i++)
	{
		gotoxy(i, 3);
		cout << " ";
		uspij(czas);
	}
	for (int d = 4; d < 12; d++)
	{
		gotoxy(43, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 43; i >= 3; i--)
	{
		gotoxy(i, 11);
		cout << " ";
		uspij(czas);
	}
	for (int d = 11; d > 3; d--)
	{
		gotoxy(3, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 4; i < 43; i++)
	{
		gotoxy(i, 4);
		cout << " ";
		uspij(czas);
	}
	for (int d = 5; d < 11; d++)
	{
		gotoxy(42, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 42; i >= 4; i--)
	{
		gotoxy(i, 10);
		cout << " ";
		uspij(czas);
	}
	for (int d = 10; d > 4; d--)
	{
		gotoxy(4, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 5; i < 42; i++)
	{
		gotoxy(i, 5);
		cout << " ";
		uspij(czas);
	}
	for (int d = 6; d < 10; d++)
	{
		gotoxy(41, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 41; i >= 5; i--)
	{
		gotoxy(i, 9);
		cout << " ";
		uspij(czas);
	}
	for (int d = 9; d > 5; d--)
	{
		gotoxy(5, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 6; i < 41; i++)
	{
		gotoxy(i, 6);
		cout << " ";
		uspij(czas);
	}
	for (int d = 7; d < 9; d++)
	{
		gotoxy(40, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 40; i >= 6; i--)
	{
		gotoxy(i, 8);
		cout << " ";
		uspij(czas);
	}
	for (int d = 8; d > 6; d--)
	{
		gotoxy(6, d);
		cout << " ";
		uspij(czas);
	}
	for (int i = 7; i < 40; i++)
	{
		gotoxy(i, 7);
		cout << " ";
		uspij(czas);
	}
	gotoxy(17, 6);
	cout << "UNFORTUNATELY";
	uspij(1);
	gotoxy(19, 7);
	cout << "YOU LOST!";
}

void przemiesc1()
{
	if (tab[pola1[0][pozycja[0] + wylosowana]][pola1[1][pozycja[0] + wylosowana]] == 'b')
	{
		if (pozycja[0] + wylosowana -13 == pozycja[4] || pozycja[0] + wylosowana - 13 + 52 == pozycja[5])
		{
			tab[1][16] = 'b';
			inplay[4] = 0;
			pozycja[4] = -1;
		}
		if (pozycja[0] + wylosowana -13 == pozycja[5] || pozycja[0] + wylosowana - 13 + 52 == pozycja[6])
		{
			tab[1][17] = 'b';
			inplay[5] = 0;
			pozycja[5] = -1;
		}
		if (pozycja[0] + wylosowana -13 == pozycja[6] || pozycja[0] + wylosowana - 13 + 52 == pozycja[7])
		{
			tab[2][16] = 'b';
			inplay[6] = 0;
			pozycja[6] = -1;
		}
		if (pozycja[0] + wylosowana -13 == pozycja[7] || pozycja[0] + wylosowana - 13 + 52 == pozycja[8])
		{
			tab[2][17] = 'b';
			inplay[7] = 0;
			pozycja[7] = -1;
		}
	}
	if (tab[pola1[0][pozycja[0] + wylosowana]][pola1[1][pozycja[0] + wylosowana]] == 'g')
	{
		if (pozycja[0] + wylosowana - 26 == pozycja[8] || pozycja[0] + wylosowana - 26 + 52 == pozycja[8])
		{
			tab[10][16] = 'g';
			inplay[8] = 0;
			pozycja[8] = -1;
		}
		if (pozycja[0] + wylosowana - 26 == pozycja[9] || pozycja[0] + wylosowana - 26 + 52 == pozycja[9])
		{
			tab[10][17] = 'g';
			inplay[9] = 0;
			pozycja[9] = -1;
		}
		if (pozycja[0] + wylosowana - 26 == pozycja[10] || pozycja[0] + wylosowana - 26 + 52 == pozycja[10])
		{
			tab[11][16] = 'g';
			inplay[10] = 0;
			pozycja[10] = -1;
		}
		if (pozycja[0] + wylosowana - 26 == pozycja[11] || pozycja[0] + wylosowana - 26 + 52 == pozycja[11])
		{
			tab[11][17] = 'g';
			inplay[11] = 0;
			pozycja[11] = -1;
		}
	}
	if (tab[pola1[0][pozycja[0] + wylosowana]][pola1[1][pozycja[0] + wylosowana]] == 'y')
	{
		if (pozycja[0] + wylosowana - 39 == pozycja[12] || pozycja[0] + wylosowana - 39 + 52 == pozycja[12])
		{
			tab[10][1] = 'y';
			inplay[12] = 0;
			pozycja[12] = -1;
		}
		if (pozycja[0] + wylosowana -39 == pozycja[13] || pozycja[0] + wylosowana - 39 + 52 == pozycja[13])
		{
			tab[10][2] = 'y';
			inplay[13] = 0;
			pozycja[13] = -1;
		}
		if (pozycja[0] + wylosowana -39 == pozycja[14] || pozycja[0] + wylosowana - 39 + 52 == pozycja[14])
		{
			tab[11][1] = 'y';
			inplay[14] = 0;
			pozycja[14] = -1;
		}
		if (pozycja[0] + wylosowana -39 == pozycja[15] || pozycja[0] + wylosowana - 39 + 52 == pozycja[15])
		{
			tab[11][2] = 'y';
			inplay[15] = 0;
			pozycja[15] = -1;
		}
	}
	tab[pola1[0][pozycja[0] + wylosowana]][pola1[1][pozycja[0] + wylosowana]] = '1';
	tab[pola1[0][pozycja[0]]][pola1[1][pozycja[0]]] = ' ';
	pozycja[0] += wylosowana;
}

bool test1()
{
	if (pozycja[0] + wylosowana < 55)
	{
		if (tab[pola1[0][pozycja[0] + wylosowana]][pola1[1][pozycja[0] + wylosowana]] == '1')
		{
			return false;
		}
		if (tab[pola1[0][pozycja[0] + wylosowana]][pola1[1][pozycja[0] + wylosowana]] == '2')
		{
			return false;
		}
		if (tab[pola1[0][pozycja[0] + wylosowana]][pola1[1][pozycja[0] + wylosowana]] == '3')
		{
			return false;
		}
		if (tab[pola1[0][pozycja[0] + wylosowana]][pola1[1][pozycja[0] + wylosowana]] == '4')
		{
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void przemiesc2()
{
	if (tab[pola1[2][pozycja[1] + wylosowana]][pola1[3][pozycja[1] + wylosowana]] == 'b')
	{
		if (pozycja[1] + wylosowana - 13 == pozycja[4] || pozycja[1] + wylosowana - 13 + 52 == pozycja[4])
		{
			tab[1][16] = 'b';
			inplay[4] = 0;
			pozycja[4] = -1;
		}
		if (pozycja[1] + wylosowana -13 == pozycja[5] || pozycja[1] + wylosowana - 13 + 52 == pozycja[5])
		{
			tab[1][17] = 'b';
			inplay[5] = 0;
			pozycja[5] = -1;
		}
		if (pozycja[1] + wylosowana -13 == pozycja[6] || pozycja[1] + wylosowana - 13 + 52 == pozycja[6])
		{
			tab[2][16] = 'b';
			inplay[6] = 0;
			pozycja[6] = -1;
		}
		if (pozycja[1] + wylosowana -13 == pozycja[7] || pozycja[1] + wylosowana - 13 + 52 == pozycja[7])
		{
			tab[2][17] = 'b';
			inplay[7] = 0;
			pozycja[7] = -1;
		}
	}
	if (tab[pola1[2][pozycja[1] + wylosowana]][pola1[3][pozycja[1] + wylosowana]] == 'g')
	{
		if (pozycja[1] + wylosowana - 26 == pozycja[8] || pozycja[1] + wylosowana - 26 + 52 == pozycja[8])
		{
			tab[10][16] = 'g';
			inplay[8] = 0;
			pozycja[8] = -1;
		}
		if (pozycja[1] + wylosowana - 26 == pozycja[9] || pozycja[1] + wylosowana - 26 + 52 == pozycja[9])
		{
			tab[10][17] = 'g';
			inplay[9] = 0;
			pozycja[9] = -1;
		}
		if (pozycja[1] + wylosowana - 26 == pozycja[10] || pozycja[1] + wylosowana - 26 + 52 == pozycja[10])
		{
			tab[11][16] = 'g';
			inplay[10] = 0;
			pozycja[10] = -1;
		}
		if (pozycja[1] + wylosowana - 26 == pozycja[11] || pozycja[1] + wylosowana - 26 + 52 == pozycja[11])
		{
			tab[11][17] = 'g';
			inplay[11] = 0;
			pozycja[11] = -1;
		}
	}
	if (tab[pola1[2][pozycja[1] + wylosowana]][pola1[3][pozycja[1] + wylosowana]] == 'y')
	{
		if (pozycja[1] + wylosowana -39 == pozycja[12] || pozycja[1] + wylosowana - 39 + 52 == pozycja[12])
		{
			tab[10][1] = 'y';
			inplay[12] = 0;
			pozycja[12] = -1;
		}
		if (pozycja[1] + wylosowana -39 == pozycja[13] || pozycja[1] + wylosowana - 39 + 52 == pozycja[13])
		{
			tab[10][2] = 'y';
			inplay[13] = 0;
			pozycja[13] = -1;
		}
		if (pozycja[1] + wylosowana -39 == pozycja[14] || pozycja[1] + wylosowana - 39 + 52 == pozycja[14])
		{
			tab[11][1] = 'y';
			inplay[14] = 0;
			pozycja[14] = -1;
		}
		if (pozycja[1] + wylosowana -39 == pozycja[15] || pozycja[1] + wylosowana - 39 + 52 == pozycja[15])
		{
			tab[11][2] = 'y';
			inplay[15] = 0;
			pozycja[15] = -1;
		}
	}
	tab[pola1[2][pozycja[1] + wylosowana]][pola1[3][pozycja[1] + wylosowana]] = '2';
	tab[pola1[2][pozycja[1]]][pola1[3][pozycja[1]]] = ' ';
	pozycja[1] += wylosowana;
}

bool test2()
{
	if (pozycja[1] + wylosowana < 55)
	{
		if (tab[pola1[2][pozycja[1] + wylosowana]][pola1[3][pozycja[1] + wylosowana]] == '1')
		{
			return false;
		}
		if (tab[pola1[2][pozycja[1] + wylosowana]][pola1[3][pozycja[1] + wylosowana]] == '2')
		{
			return false;
		}
		if (tab[pola1[2][pozycja[1] + wylosowana]][pola1[3][pozycja[1] + wylosowana]] == '3')
		{
			return false;
		}
		if (tab[pola1[2][pozycja[1] + wylosowana]][pola1[3][pozycja[1] + wylosowana]] == '4')
		{
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void przemiesc3()
{
	if (tab[pola1[4][pozycja[2] + wylosowana]][pola1[5][pozycja[2] + wylosowana]] == 'b')
	{
		if (pozycja[2] + wylosowana -13 == pozycja[4] || pozycja[2] + wylosowana - 13 + 52 == pozycja[4])
		{
			tab[1][16] = 'b';
			inplay[4] = 0;
			pozycja[4] = -1;
		}
		if (pozycja[2] + wylosowana -13 == pozycja[5] || pozycja[2] + wylosowana - 13 + 52 == pozycja[5])
		{
			tab[1][17] = 'b';
			inplay[5] = 0;
			pozycja[5] = -1;
		}
		if (pozycja[2] + wylosowana -13 == pozycja[6] || pozycja[2] + wylosowana - 13 + 52 == pozycja[6])
		{
			tab[2][16] = 'b';
			inplay[6] = 0;
			pozycja[6] = -1;
		}
		if (pozycja[2] + wylosowana -13 == pozycja[7] || pozycja[2] + wylosowana - 13 + 52 == pozycja[7])
		{
			tab[2][17] = 'b';
			inplay[7] = 0;
			pozycja[7] = -1;
		}
	}
	if (tab[pola1[4][pozycja[2] + wylosowana]][pola1[5][pozycja[2] + wylosowana]] == 'g')
	{
		if (pozycja[2] + wylosowana - 26 == pozycja[8] || pozycja[2] + wylosowana - 26 + 52 == pozycja[8])
		{
			tab[10][16] = 'g';
			inplay[8] = 0;
			pozycja[8] = -1;
		}
		if (pozycja[2] + wylosowana - 26 == pozycja[9] || pozycja[2] + wylosowana - 26 + 52 == pozycja[9])
		{
			tab[10][17] = 'g';
			inplay[9] = 0;
			pozycja[9] = -1;
		}
		if (pozycja[2] + wylosowana - 26 == pozycja[10] || pozycja[2] + wylosowana - 26 + 52 == pozycja[10])
		{
			tab[11][16] = 'g';
			inplay[10] = 0;
			pozycja[10] = -1;
		}
		if (pozycja[2] + wylosowana - 26 == pozycja[11] || pozycja[2] + wylosowana - 26 + 52 == pozycja[11])
		{
			tab[11][17] = 'g';
			inplay[11] = 0;
			pozycja[11] = -1;
		}
	}
	if (tab[pola1[4][pozycja[2] + wylosowana]][pola1[5][pozycja[2] + wylosowana]] == 'y')
	{
		if (pozycja[2] + wylosowana -39 == pozycja[12] || pozycja[2] + wylosowana - 39 + 52 == pozycja[12])
		{
			tab[10][1] = 'y';
			inplay[12] = 0;
			pozycja[12] = -1;
		}
		if (pozycja[2] + wylosowana -39 == pozycja[13] || pozycja[2] + wylosowana - 39 + 52 == pozycja[13])
		{
			tab[10][2] = 'y';
			inplay[13] = 0;
			pozycja[13] = -1;
		}
		if (pozycja[2] + wylosowana -39 == pozycja[14] || pozycja[2] + wylosowana - 39 + 52 == pozycja[14])
		{
			tab[11][1] = 'y';
			inplay[14] = 0;
			pozycja[14] = -1;
		}
		if (pozycja[2] + wylosowana -39 == pozycja[15] || pozycja[2] + wylosowana - 39 + 52 == pozycja[15])
		{
			tab[11][2] = 'y';
			inplay[15] = 0;
			pozycja[15] = -1;
		}
	}
	tab[pola1[4][pozycja[2] + wylosowana]][pola1[5][pozycja[2] + wylosowana]] = '3';
	tab[pola1[4][pozycja[2]]][pola1[5][pozycja[2]]] = ' ';
	pozycja[2] += wylosowana;
}

bool test3()
{
	if (pozycja[2] + wylosowana < 55)
	{
		if (tab[pola1[4][pozycja[2] + wylosowana]][pola1[5][pozycja[2] + wylosowana]] == '1')
		{
			return false;
		}
		if (tab[pola1[4][pozycja[2] + wylosowana]][pola1[5][pozycja[2] + wylosowana]] == '2')
		{
			return false;
		}
		if (tab[pola1[4][pozycja[2] + wylosowana]][pola1[5][pozycja[2] + wylosowana]] == '3')
		{
			return false;
		}
		if (tab[pola1[4][pozycja[2] + wylosowana]][pola1[5][pozycja[2] + wylosowana]] == '4')
		{
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void przemiesc4()
{
	if (tab[pola1[6][pozycja[3] + wylosowana]][pola1[7][pozycja[3] + wylosowana]] == 'b')
	{
		if (pozycja[3] + wylosowana -13 == pozycja[4] || pozycja[3] + wylosowana - 13 + 52 == pozycja[4])
		{
			tab[1][16] = 'b';
			inplay[4] = 0;
			pozycja[4] = -1;
		}
		if (pozycja[3] + wylosowana -13 == pozycja[5] || pozycja[3] + wylosowana - 13 + 52 == pozycja[5])
		{
			tab[1][17] = 'b';
			inplay[5] = 0;
			pozycja[5] = -1;
		}
		if (pozycja[3] + wylosowana -13 == pozycja[6] || pozycja[3] + wylosowana - 13 + 52 == pozycja[6])
		{
			tab[2][16] = 'b';
			inplay[6] = 0;
			pozycja[6] = -1;
		}
		if (pozycja[3] + wylosowana -13 == pozycja[7] || pozycja[3] + wylosowana - 13 + 52 == pozycja[7])
		{
			tab[2][17] = 'b';
			inplay[7] = 0;
			pozycja[7] = -1;
		}
	}
	if (tab[pola1[6][pozycja[3] + wylosowana]][pola1[7][pozycja[3] + wylosowana]] == 'g')
	{
		if (pozycja[3] + wylosowana - 26 == pozycja[8] || pozycja[3] + wylosowana - 26 + 52 == pozycja[8])
		{
			tab[10][16] = 'g';
			inplay[8] = 0;
			pozycja[8] = -1;
		}
		if (pozycja[3] + wylosowana - 26 == pozycja[9] || pozycja[3] + wylosowana - 26 + 52 == pozycja[9])
		{
			tab[10][17] = 'g';
			inplay[9] = 0;
			pozycja[9] = -1;
		}
		if (pozycja[3] + wylosowana - 26 == pozycja[10] || pozycja[3] + wylosowana - 26 + 52 == pozycja[10])
		{
			tab[11][16] = 'g';
			inplay[10] = 0;
			pozycja[10] = -1;
		}
		if (pozycja[3] + wylosowana - 26 == pozycja[11] || pozycja[3] + wylosowana - 26 + 52 == pozycja[11])
		{
			tab[11][17] = 'g';
			inplay[11] = 0;
			pozycja[11] = -1;
		}
	}
	if (tab[pola1[6][pozycja[3] + wylosowana]][pola1[7][pozycja[3] + wylosowana]] == 'y')
	{
		if (pozycja[3] + wylosowana -39 == pozycja[12] || pozycja[3] + wylosowana - 39 + 52 == pozycja[12])
		{
			tab[10][1] = 'y';
			inplay[12] = 0;
			pozycja[12] = -1;
		}
		if (pozycja[3] + wylosowana -39 == pozycja[13] || pozycja[3] + wylosowana - 39 + 52 == pozycja[13])
		{
			tab[10][2] = 'y';
			inplay[13] = 0;
			pozycja[13] = -1;
		}
		if (pozycja[3] + wylosowana -39 == pozycja[14] || pozycja[3] + wylosowana - 39 + 52 == pozycja[14])
		{
			tab[11][1] = 'y';
			inplay[14] = 0;
			pozycja[14] = -1;
		}
		if (pozycja[3] + wylosowana -39 == pozycja[15] || pozycja[3] + wylosowana - 39 + 52 == pozycja[15])
		{
			tab[11][2] = 'y';
			inplay[15] = 0;
			pozycja[15] = -1;
		}
	}
	tab[pola1[6][pozycja[3] + wylosowana]][pola1[7][pozycja[3] + wylosowana]] = '4';
	tab[pola1[6][pozycja[3]]][pola1[7][pozycja[3]]] = ' ';
	pozycja[3] += wylosowana;
}

bool test4()
{
	if (pozycja[3] + wylosowana < 55)
	{
		if (tab[pola1[6][pozycja[3] + wylosowana]][pola1[7][pozycja[3] + wylosowana]] == '1')
		{
			return false;
		}
		if (tab[pola1[6][pozycja[3] + wylosowana]][pola1[7][pozycja[3] + wylosowana]] == '2')
		{
			return false;
		}
		if (tab[pola1[6][pozycja[3] + wylosowana]][pola1[7][pozycja[3] + wylosowana]] == '3')
		{
			return false;
		}
		if (tab[pola1[6][pozycja[3] + wylosowana]][pola1[7][pozycja[3] + wylosowana]] == '4')
		{
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool test5()
{
	if ((tab[4][1] != '1') && (tab[4][1] != '2') && (tab[4][1] != '3') && (tab[4][1] != '4') )
	{
		if ((inplay[0] == 0) || (inplay[1] == 0) || (inplay[2] == 0) || (inplay[3] == 0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void przemiescbot1(int pionek)
{
	if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == '1' ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == '2' ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == '3' ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == '4')
	{
		if (pozycja[pionek]+wylosowana == (pozycja[0] - 13) || pozycja[pionek] + wylosowana == (pozycja[0] - 13 + 52))
		{
			tab[1][1] = '1';
			inplay[0] = 0;
			pozycja[0] = -1;
		}

		if (pozycja[pionek] + wylosowana == pozycja[1] - 13 || pozycja[pionek] + wylosowana == pozycja[1] - 13 + 52)
		{
			tab[1][2] = '2';
			inplay[1] = 0;
			pozycja[1] = -1;
		}
		if (pozycja[pionek] + wylosowana == pozycja[2] - 13 || pozycja[pionek] + wylosowana == pozycja[2] - 13 + 52)
		{
			tab[2][1] = '3';
			inplay[2] = 0;
			pozycja[2] = -1;
		}
		if (pozycja[pionek] + wylosowana == pozycja[3] - 13 || pozycja[pionek] + wylosowana == pozycja[3] - 13 + 52)
		{
			tab[2][2] = '4';
			inplay[3] = 0;
			pozycja[3] = -1;
		}
	}
	if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == 'g')
	{
		if (pozycja[pionek] + wylosowana -13 == pozycja[8] || pozycja[pionek] + wylosowana - 13 + 52 == pozycja[8])
		{
			tab[10][16] = 'g';
			inplay[8] = 0;
			pozycja[8] = -1;
		}
		if (pozycja[pionek] + wylosowana -13 == pozycja[9] || pozycja[pionek] + wylosowana - 13 + 52 == pozycja[9])
		{
			tab[10][17] = 'g';
			inplay[9] = 0;
			pozycja[9] = -1;
		}
		if (pozycja[pionek] + wylosowana -13 == pozycja[10] || pozycja[pionek] + wylosowana - 13 + 52 == pozycja[10])
		{
			tab[11][16] = 'g';
			inplay[10] = 0;
			pozycja[10] = -1;
		}
		if (pozycja[pionek] + wylosowana -13 == pozycja[11] || pozycja[pionek] + wylosowana - 13 + 52 == pozycja[11])
		{
			tab[11][17] = 'g';
			inplay[11] = 0;
			pozycja[11] = -1;
		}
	}
	if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == 'y')
	{
		if (pozycja[pionek] + wylosowana - 26 == pozycja[12] || pozycja[pionek] + wylosowana - 26 + 52 == pozycja[12])
		{
			tab[10][1] = 'y';
			inplay[12] = 0;
			pozycja[12] = -1;
		}
		if (pozycja[pionek] + wylosowana - 26 == pozycja[13] || pozycja[pionek] + wylosowana - 26 + 52 == pozycja[13])
		{
			tab[10][2] = 'y';
			inplay[13] = 0;
			pozycja[13] = -1;
		}
		if (pozycja[pionek] + wylosowana - 26 == pozycja[14] || pozycja[pionek] + wylosowana - 26 + 52 == pozycja[14])
		{
			tab[11][1] = 'y';
			inplay[14] = 0;
			pozycja[14] = -1;
		}
		if (pozycja[pionek] + wylosowana - 26 == pozycja[15] || pozycja[pionek] + wylosowana - 26 + 52 == pozycja[15])
		{
			tab[11][2] = 'y';
			inplay[15] = 0;
			pozycja[15] = -1;
		}
	}
	tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] = 'b';
	tab[pola1[pionek*2][pozycja[pionek]]][pola1[(pionek * 2) + 1][pozycja[pionek]]] = ' ';
	pozycja[pionek] += wylosowana;
}

void przemiescbot2(int pionek)
{
	if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == '1' ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == '2' ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == '3' ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == '4')
	{
		if (pozycja[pionek] + wylosowana + 26 == pozycja[0] || pozycja[pionek] + wylosowana + 26 - 52 == pozycja[0])
		{
			tab[1][1] = '1';
			inplay[0] = 0;
			pozycja[0] = -1;
		}
		if (pozycja[pionek] + wylosowana + 26 == pozycja[1] || pozycja[pionek] + wylosowana + 26 - 52 == pozycja[1])
		{
			tab[1][2] = '2';
			inplay[1] = 0;
			pozycja[1] = -1;
		}
		if (pozycja[pionek] + wylosowana + 26 == pozycja[2] || pozycja[pionek] + wylosowana + 26 - 52 == pozycja[2])
		{
			tab[2][1] = '3';
			inplay[2] = 0;
			pozycja[2] = -1;
		}
		if (pozycja[pionek] + wylosowana + 26 == pozycja[3] || pozycja[pionek] + wylosowana + 26 - 52 == pozycja[3])
		{
			tab[2][2] = '4';
			inplay[3] = 0;
			pozycja[3] = -1;
		}
	}
	if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == 'b')
	{
		if (pozycja[pionek] + wylosowana +13 == pozycja[4] || pozycja[pionek] + wylosowana + 13 -52 == pozycja[4])
		{
			tab[1][16] = 'b';
			inplay[4] = 0;
			pozycja[4] = -1;
		}
		if (pozycja[pionek] + wylosowana +13 == pozycja[5] || pozycja[pionek] + wylosowana + 13 - 52 == pozycja[5])
		{
			tab[1][17] = 'b';
			inplay[5] = 0;
			pozycja[5] = -1;
		}
		if (pozycja[pionek] + wylosowana +13 == pozycja[6] || pozycja[pionek] + wylosowana + 13 - 52 == pozycja[6])
		{
			tab[2][16] = 'b';
			inplay[6] = 0;
			pozycja[6] = -1;
		}
		if (pozycja[pionek] + wylosowana +13 == pozycja[7] || pozycja[pionek] + wylosowana + 13 - 52 == pozycja[7])
		{
			tab[2][17] = 'b';
			inplay[7] = 0;
			pozycja[7] = -1;
		}
	}
	if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == 'y')
	{
		if (pozycja[pionek] + wylosowana -13 == pozycja[12] || pozycja[pionek] + wylosowana - 13 + 52 == pozycja[12])
		{
			tab[10][1] = 'y';
			inplay[12] = 0;
			pozycja[12] = -1;
		}
		if (pozycja[pionek] + wylosowana -13 == pozycja[13] || pozycja[pionek] + wylosowana - 13 + 52 == pozycja[13])
		{
			tab[10][2] = 'y';
			inplay[13] = 0;
			pozycja[13] = -1;
		}
		if (pozycja[pionek] + wylosowana -13 == pozycja[14] || pozycja[pionek] + wylosowana - 13 + 52 == pozycja[14])
		{
			tab[11][1] = 'y';
			inplay[14] = 0;
			pozycja[14] = -1;
		}
		if (pozycja[pionek] + wylosowana -13 == pozycja[15] || pozycja[pionek] + wylosowana - 13 + 52 == pozycja[15])
		{
			tab[11][2] = 'y';
			inplay[15] = 0;
			pozycja[15] = -1;
		}
	}
	tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] = 'g';
	tab[pola1[pionek * 2][pozycja[pionek]]][pola1[(pionek * 2) + 1][pozycja[pionek]]] = ' ';
	pozycja[pionek] += wylosowana;
}

void przemiescbot3(int pionek)
{
	if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == '1' ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == '2' ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == '3' ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == '4')
	{
		if (pozycja[pionek] + wylosowana -13 == pozycja[0] || pozycja[pionek] + wylosowana - 13 + 52 == pozycja[0])
		{
			tab[1][1] = '1';
			inplay[0] = 0;
			pozycja[0] = -1;
		}
		if (pozycja[pionek] + wylosowana -13 == pozycja[1] || pozycja[pionek] + wylosowana - 13 + 52 == pozycja[1])
		{
			tab[1][2] = '2';
			inplay[1] = 0;
			pozycja[1] = -1;
		}
		if (pozycja[pionek] + wylosowana -13 == pozycja[2] || pozycja[pionek] + wylosowana - 13 + 52 == pozycja[2])
		{
			tab[2][1] = '3';
			inplay[2] = 0;
			pozycja[2] = -1;
		}
		if (pozycja[pionek] + wylosowana -13 == pozycja[3] || pozycja[pionek] + wylosowana - 13 + 52 == pozycja[3])
		{
			tab[2][2] = '4';
			inplay[3] = 0;
			pozycja[3] = -1;
		}
	}
	if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == 'b')
	{
		if (pozycja[pionek] + wylosowana - 26 == pozycja[4] || pozycja[pionek] + wylosowana - 26 + 52 == pozycja[4])
		{
			tab[1][16] = 'b';
			inplay[4] = 0;
			pozycja[4] = -1;
		}
		if (pozycja[pionek] + wylosowana - 26 == pozycja[5] || pozycja[pionek] + wylosowana - 26 + 52 == pozycja[5])
		{
			tab[1][17] = 'b';
			inplay[5] = 0;
			pozycja[5] = -1;
		}
		if (pozycja[pionek] + wylosowana - 26 == pozycja[6] || pozycja[pionek] + wylosowana - 26 + 52 == pozycja[6])
		{
			tab[2][16] = 'b';
			inplay[6] = 0;
			pozycja[6] = -1;
		}
		if (pozycja[pionek] + wylosowana - 26 == pozycja[7] || pozycja[pionek] + wylosowana - 26 + 52 == pozycja[7])
		{
			tab[2][17] = 'b';
			inplay[7] = 0;
			pozycja[7] = -1;
		}
	}
	if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == 'g')
	{
		if (pozycja[pionek] + wylosowana - 39 == pozycja[8] || pozycja[pionek] + wylosowana - 39 +52 == pozycja[8])
		{
			tab[10][16] = 'g';
			inplay[8] = 0;
			pozycja[8] = -1;
		}
		if (pozycja[pionek] + wylosowana - 39 == pozycja[9] || pozycja[pionek] + wylosowana - 39 + 52 == pozycja[9])
		{
			tab[10][17] = 'g';
			inplay[9] = 0;
			pozycja[9] = -1;
		}
		if (pozycja[pionek] + wylosowana - 39 == pozycja[10] || pozycja[pionek] + wylosowana - 39 + 52 == pozycja[10])
		{
			tab[11][16] = 'g';
			inplay[10] = 0;
			pozycja[10] = -1;
		}
		if (pozycja[pionek] + wylosowana - 39 == pozycja[11] || pozycja[pionek] + wylosowana - 39 + 52 == pozycja[11])
		{
			tab[11][17] = 'g';
			inplay[11] = 0;
			pozycja[11] = -1;
		}
	}
	tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] = 'y';
	tab[pola1[pionek * 2][pozycja[pionek]]][pola1[(pionek * 2) + 1][pozycja[pionek]]] = ' ';
	pozycja[pionek] += wylosowana;
}

bool botbije1(int pionek)
{
	if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('1') ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('2') ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('3') ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('4') ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('g') ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('y'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool botbije2(int pionek)
{
	if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('1') ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('2') || 
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('3') || 
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('4') || 
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('b') || 
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('y'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool botbije3(int pionek)
{
	if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('1') ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('2') ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('3') ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('4') ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('b') ||
		tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == ('g'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool botwyjscie1()
{
	if (tab[1][11] != 'b')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool botwyjscie2()
{
	if (tab[8][17] != 'g')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool botwyjscie3()
{
	if (tab[11][7] != 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool bottest1(int pionek)
{
	if ((pozycja[pionek] + wylosowana) < 55)
	{
		if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == 'b')
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool bottest2(int pionek)
{
	if (pozycja[pionek] + wylosowana < 55)
	{
		if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == 'g')
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool bottest3(int pionek)
{
	if (pozycja[pionek] + wylosowana < 55)
	{
		if (tab[pola1[pionek * 2][pozycja[pionek] + wylosowana]][pola1[(pionek * 2) + 1][pozycja[pionek] + wylosowana]] == 'y')
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

int losuj()
{
	return rand() % 6 + 1;
}

void czyr()
{
	tymczasowa = 1;
	while (tymczasowa != 0)
	{
		switch (_getch())
		{
		case 114:
			wylosowana = losuj();
			gotoxy(21, iks);
			cout << "Rolled: " << wylosowana << endl;
			uspij(1);
			tymczasowa = 0;
			break;
		}
	}
}

void roll3()
{
	rollamount = 3;
	while (rollamount != 0)
	{
		wyswietl();
		gotoxy(21, 2);
		cout << "0 pawns in play";
		gotoxy(21, 3);
		cout << "Press R to roll";
		gotoxy(21, 4);
		cout << "Rolls left: " << rollamount << endl;
		iks = 5;
		czyr();
		rollamount--;
		if (wylosowana == 6)
		{
			break;
		}
	}
}

void wyjmij()
{
	if (pozycja[4] == 39)
	{
		tab[1][16] = 'b';
		inplay[4] = 0;
		pozycja[4] = -1;
	}
	if (pozycja[5] == 39)
	{
		tab[1][17] = 'b';
		inplay[5] = 0;
		pozycja[5] = -1;
	}
	if (pozycja[6] == 39)
	{
		tab[2][16] = 'b';
		inplay[6] = 0;
		pozycja[6] = -1;
	}
	if (pozycja[7] == 39)
	{
		tab[2][17] = 'b';
		inplay[7] = 0;
		pozycja[7] = -1;
	}
	if (pozycja[8] == 26)
	{
		tab[10][16] = 'g';
		inplay[8] = 0;
		pozycja[8] = -1;
	}
	if (pozycja[9] == 26)
	{
		tab[10][17] = 'g';
		inplay[9] = 0;
		pozycja[9] = -1;
	}
	if (pozycja[10] == 26)
	{
		tab[11][16] = 'g';
		inplay[10] = 0;
		pozycja[10] = -1;
	}
	if (pozycja[11] == 26)
	{
		tab[11][17] = 'g';
		inplay[11] = 0;
		pozycja[11] = -1;
	}
	if (pozycja[12] == 13)
	{
		tab[10][1] = 'y';
		inplay[12] = 0;
		pozycja[12] = -1;
	}
	if (pozycja[13] == 13)
	{
		tab[10][2] = 'y';
		inplay[13] = 0;
		pozycja[13] = -1;
	}
	if (pozycja[14] == 13)
	{
		tab[11][1] = 'y';
		inplay[14] = 0;
		pozycja[14] = -1;
	}
	if (pozycja[15] == 13)
	{
		tab[11][2] = 'y';
		inplay[15] = 0;
		pozycja[15] = -1;
	}
	if (tab[1][1] == '1')
	{
		tab[4][1] = '1';
		tab[1][1] = ' ';
		wyswietl();
		inplay[0] = 1;
		pozycja[0] = 0;
	}
	else {

		if (tab[1][2] == '2')
		{
			tab[4][1] = '2';
			tab[1][2] = ' ';
			wyswietl();
			inplay[1] = 1;
			pozycja[1] = 0;
		}
		else {
			if (tab[2][1] == '3')
			{
				tab[4][1] = '3';
				tab[2][1] = ' ';
				wyswietl();
				inplay[2] = 1;
				pozycja[2] = 0;
			}
			else {
				if (tab[2][2] == '4')
				{
					tab[4][1] = '4';
					tab[2][2] = ' ';
					wyswietl();
					inplay[3] = 1;
					pozycja[3] = 0;
				}
			}
		}
	}
	
	
}

void wyjmij2()
{
	if (pozycja[8] == 39)
	{
		tab[10][16] = 'g';
		inplay[8] = 0;
		pozycja[8] = -1;
	}
	if (pozycja[9] == 39)
	{
		tab[10][17] = 'g';
		inplay[9] = 0;
		pozycja[9] = -1;
	}
	if (pozycja[10] == 39)
	{
		tab[11][16] = 'g';
		inplay[10] = 0;
		pozycja[10] = -1;
	}
	if (pozycja[11] == 39)
	{
		tab[11][17] = 'g';
		inplay[11] = 0;
		pozycja[11] = -1;
	}
	if (pozycja[12] == 26)
	{
		tab[10][1] = 'y';
		inplay[12] = 0;
		pozycja[12] = -1;
	}
	if (pozycja[13] == 26)
	{
		tab[10][2] = 'y';
		inplay[13] = 0;
		pozycja[13] = -1;
	}
	if (pozycja[14] == 26)
	{
		tab[11][1] = 'y';
		inplay[14] = 0;
		pozycja[14] = -1;
	}
	if (pozycja[15] == 26)
	{
		tab[11][2] = 'y';
		inplay[15] = 0;
		pozycja[15] = -1;
	}
	if (pozycja[0] == 13)
	{
		tab[1][1] = '1';
		inplay[0] = 0;
		pozycja[0] = -1;
	}
	if (pozycja[1] == 13)
	{
		tab[1][2] = '2';
		inplay[1] = 0;
		pozycja[1] = -1;
	}
	if (pozycja[2] == 13)
	{
		tab[2][1] = '3';
		inplay[2] = 0;
		pozycja[2] = -1;
	}
	if (pozycja[3] == 13)
	{
		tab[2][2] = '4';
		inplay[3] = 0;
		pozycja[3] = -1;
	}
	if (tab[1][16] == 'b')
	{
		tab[1][11] = 'b';
		tab[1][16] = ' ';
		wyjety = 1;
		inplay[4] = 1;
		pozycja[4] = 0;
		wyswietl();
	}
	else {

		if (tab[1][17] == 'b')
		{
			tab[1][11] = 'b';
			tab[1][17] = ' ';
			wyjety = 2;
			inplay[5] = 1;
			pozycja[5] = 0;
			wyswietl();
		}
		else {
			if (tab[2][16] == 'b')
			{
				tab[1][11] = 'b';
				tab[2][16] = ' ';
				wyjety = 3;
				inplay[6] = 1;
				pozycja[6] = 0;
				wyswietl();
			}
			else {
				if (tab[2][17] == 'b')
				{
					tab[1][11] = 'b';
					tab[2][17] = ' ';
					wyjety = 4;
					inplay[7] = 1;
					pozycja[7] = 0;
					wyswietl();
				}
				else {
					cout << endl << "error 2";
				}
			}
		}
	}


}

void wyjmij3()
{
	if (pozycja[12] == 39)
	{
		tab[10][1] = 'y';
		inplay[12] = 0;
		pozycja[12] = -1;
	}
	if (pozycja[13] == 39)
	{
		tab[10][2] = 'y';
		inplay[13] = 0;
		pozycja[13] = -1;
	}
	if (pozycja[14] == 39)
	{
		tab[11][1] = 'y';
		inplay[14] = 0;
		pozycja[14] = -1;
	}
	if (pozycja[15] == 39)
	{
		tab[11][2] = 'y';
		inplay[15] = 0;
		pozycja[15] = -1;
	}
	if (pozycja[0] == 26)
	{
		tab[1][1] = '1';
		inplay[0] = 0;
		pozycja[0] = -1;
	}
	if (pozycja[1] == 26)
	{
		tab[1][2] = '2';
		inplay[1] = 0;
		pozycja[1] = -1;
	}
	if (pozycja[2] == 26)
	{
		tab[2][1] = '3';
		inplay[2] = 0;
		pozycja[2] = -1;
	}
	if (pozycja[3] == 26)
	{
		tab[2][2] = '4';
		inplay[3] = 0;
		pozycja[3] = -1;
	}
	if (pozycja[4] == 13)
	{
		tab[1][16] = 'b';
		inplay[4] = 0;
		pozycja[4] = -1;
	}
	if (pozycja[5] == 13)
	{
		tab[1][17] = 'b';
		inplay[5] = 0;
		pozycja[5] = -1;
	}
	if (pozycja[6] == 13)
	{
		tab[2][16] = 'b';
		inplay[6] = 0;
		pozycja[6] = -1;
	}
	if (pozycja[7] == 13)
	{
		tab[2][17] = 'b';
		inplay[7] = 0;
		pozycja[7] = -1;
	}
	if (tab[10][16] == 'g')
	{
		tab[8][17] = 'g';
		tab[10][16] = ' ';
		wyjety = 1;
		wyswietl();
		inplay[8] = 1;
		pozycja[8] = 0;
	}
	else {

		if (tab[10][17] == 'g')
		{
			tab[8][17] = 'g';
			tab[10][17] = ' ';
			wyjety = 2;
			wyswietl();
			inplay[9] = 1;
			pozycja[9] = 0;
		}
		else {
			if (tab[11][16] == 'g')
			{
				tab[8][17] = 'g';
				tab[11][16] = ' ';
				wyjety = 3;
				wyswietl();
				inplay[10] = 1;
				pozycja[10] = 0;
			}
			else {
				if (tab[11][17] == 'g')
				{
					tab[8][17] = 'g';
					tab[11][17] = ' ';
					wyjety = 4;
					wyswietl();
					inplay[11] = 1;
					pozycja[11] = 0;
				}
			}
		}
	}


}

void wyjmij4()
{
	if (pozycja[0] == 39)
	{
		tab[1][1] = '1';
		inplay[0] = 0;
		pozycja[0] = -1;
	}
	if (pozycja[1] == 39)
	{
		tab[1][2] = '2';
		inplay[1] = 0;
		pozycja[1] = -1;
	}
	if (pozycja[2] == 39)
	{
		tab[2][1] = '3';
		inplay[2] = 0;
		pozycja[2] = -1;
	}
	if (pozycja[3] == 39)
	{
		tab[2][2] = '4';
		inplay[3] = 0;
		pozycja[3] = -1;
	}
	if (pozycja[4] == 26)
	{
		tab[1][16] = 'b';
		inplay[4] = 0;
		pozycja[4] = -1;
	}
	if (pozycja[5] == 26)
	{
		tab[1][17] = 'b';
		inplay[5] = 0;
		pozycja[5] = -1;
	}
	if (pozycja[6] == 26)
	{
		tab[2][16] = 'b';
		inplay[6] = 0;
		pozycja[6] = -1;
	}
	if (pozycja[7] == 26)
	{
		tab[2][17] = 'b';
		inplay[7] = 0;
		pozycja[7] = -1;
	}
	if (pozycja[8] == 13)
	{
		tab[10][16] = 'g';
		inplay[8] = 0;
		pozycja[8] = -1;
	}
	if (pozycja[9] == 13)
	{
		tab[10][17] = 'g';
		inplay[9] = 0;
		pozycja[9] = -1;
	}
	if (pozycja[10] == 13)
	{
		tab[11][16] = 'g';
		inplay[10] = 0;
		pozycja[10] = -1;
	}
	if (pozycja[11] == 13)
	{
		tab[11][17] = 'g';
		inplay[11] = 0;
		pozycja[11] = -1;
	}
	if (tab[10][1] == 'y')
	{
		tab[11][7] = 'y';
		tab[10][1] = ' ';
		wyjety = 1;
		wyswietl();
		inplay[12] = 1;
		pozycja[12] = 0;
	}
	else {

		if (tab[10][2] == 'y')
		{
			tab[11][7] = 'y';
			tab[10][2] = ' ';
			wyjety = 2;
			wyswietl();
			inplay[13] = 1;
			pozycja[13] = 0;
		}
		else {
			if (tab[11][1] == 'y')
			{
				tab[11][7] = 'y';
				tab[11][1] = ' ';
				wyjety = 3;
				wyswietl();
				inplay[14] = 1;
				pozycja[14] = 0;
			}
			else {
				if (tab[11][2] == 'y')
				{
					tab[11][7] = 'y';
					tab[11][2] = ' ';
					wyjety = 4;
					wyswietl();
					inplay[15] = 1;
					pozycja[15] = 0;
				}
			}
		}
	}


}

void start()
{
	while (loop != 1)
	{
		switch (_getch())
		{
		case 32:
			wyswietl();
			loop = 1;
			break;
		}
	}
}

void botmultiroll(string imie)
{
	rollamount = 3;
	while (rollamount != 0)
	{
		wyswietl();
		gotoxy(21, 2);
		cout << imie << " has 0 pawns in play	";
		gotoxy(21, 3);
		cout << "Rolls left: " << rollamount;
		wylosowana=losuj();
		gotoxy(21, 4);
		cout << imie << " rolled " << wylosowana;
		uspij(1.5);
		rollamount--;
		if (wylosowana == 6)
		{
			break;
		}
	}
}

void roll() {
	wyswietl();
	gotoxy(21, 2);
	cout << "Press R to roll" << endl;
	iks = 3;
	czyr();
}

void taby0()
{
	for (int i = 0; i < 16; i++)
	{
		pozycja[i] = -1;
	}
	for (int w = 0; w < 16; w++)
	{
		inplay[w] = 0;
	}
}

int main() {
	srand(time(0));
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	startuj:
	duzo();
	wielkoscf(30);
	rozmiarokna();
	//PlaySound(TEXT("soundtrack.wav"), NULL, SND_FILENAME | SND_ASYNC);--soundtrack mial 800mb
	c = 0;
	string linia;
	fstream plik;
	plik.open("plansza.txt");
	if (plik.good() == true)
	{

		while (!plik.eof())
		{
			getline(plik, linia);
			dlugosc = linia.length() - 1;
			for (i = 0; i <= dlugosc; i++)
			{
				tab[c][i] = linia[i];
				if (tab[c][i] == '@') tab[c][i] = 178;
			}
			c++;
		}
		plik.close();
	}
	else
	{
		cout << "Nie mozna uruchomic pliku!" << endl;
	}
	plik.close();
	bot1 = "Darek";
	bot2 = "Marek";
	bot3 = "Janek";
	//----------------------------------------------------------
	opening(0.05);
	zyze();
	taby0();
	start();
	while ((tab[6][2] == ' ' || tab[6][3] == ' ' || tab[6][4] == ' ' || tab[6][5] == ' ') &&
		(tab[6][13] == ' ' || tab[6][14] == ' ' || tab[6][15] == ' ' || tab[6][16] == ' ') &&
		(tab[2][9] == ' ' || tab[3][9] == ' ' || tab[4][9] == ' ' || tab[5][9] == ' ') &&
		(tab[7][9] == ' ' || tab[8][9] == ' ' || tab[9][9] == ' ' || tab[10][9] == ' '))
	{
		if ((inplay[0] == 0) && (inplay[1] == 0) && (inplay[2] == 0) && (inplay[3] == 0))
		{
			roll3();
			if (wylosowana == 6)
			{
				wyjmij();
				roll();
				przemiesc1();
				uspij(1);
				wyswietl();
			}
		}
		else
		{
			kiz = 1;
			roll();
			tak1 = 0;
			tak2 = 0;
			tak3 = 0;
			tak4 = 0;
			tak5 = 0;
			if (inplay[0] == 1)
			{
				if (test1() == true)
				{
					kiz++;
					gotoxy(21, kiz);
					cout << "1.Move pawn No.1" << endl;
					tak1 = 1;
				}

			}
			if (inplay[1] == 1)
			{
				if (test2() == true)
				{
					kiz++;
					gotoxy(21, kiz);
					cout << "2.Move pawn No.2" << endl;
					tak2 = 1;
				}

			}
			if (inplay[2] == 1)
			{
				if (test3() == true)
				{
					kiz++;
					gotoxy(21, kiz);
					cout << "3.Move pawn No.3" << endl;
					tak3 = 1;
				}

			}
			if (inplay[3] == 1)
			{
				if (test4() == true)
				{
					kiz++;
					gotoxy(21, kiz);
					cout << "4.Move pawn No.4" << endl;
					tak4 = 1;
				}

			}
			if (wylosowana == 6)
			{
				if (test5() == true)
				{
					kiz++;
					gotoxy(21, kiz);
					cout << "5.Take out new pawn" << endl;
					tak5 = 1;
				}
			}
			kiz++;
			gotoxy(21, kiz);
			cout << "Q.Surrender" << endl;
			if ((tak5 == 0) && (tak4 == 0) && (tak3 == 0) && (tak2 == 0) && (tak1 == 0))
			{
				kiz++;
				gotoxy(21, kiz);
				cout << "S.Skip(Its not possible to";
				kiz++;
				gotoxy(21, kiz);
				cout << "make a move with this roll)";
			}
			tymczasowa = 3;
			while (tymczasowa != 0)
			{
				switch (_getch())
				{
				case 49:
					if (tak1 == 0)
					{
						break;
					}
					przemiesc1();
					wyswietl();
					uspij(0.5);
					tymczasowa = 0;
					break;
				case 50:
					if (tak2 == 0)
					{
						break;
					}
					przemiesc2();
					wyswietl();
					uspij(0.5);
					tymczasowa = 0;
					break;
				case 51:
					if (tak3 == 0)
					{
						break;
					}
					przemiesc3();
					wyswietl();
					uspij(0.5);
					tymczasowa = 0;
					break;
				case 52:
					if (tak4 == 0)
					{
						break;
					}
					przemiesc4();
					wyswietl();
					uspij(0.5);
					tymczasowa = 0;
					break;
				case 53:
					if (tak5 == 0)
					{
						break;
					}
					wyjmij();
					wyswietl();
					uspij(0.5);
					tymczasowa = 0;
					break;
				case 113:
					przegrana(0.01);
					uspij(4);
					ClearScreen();
					menu();
					while (1)
					{
						switch (_getch())
						{
						case 'y':
							ClearScreen();
							goto startuj;
							break;
						case 'n':
							return 0;
							break;
						}
					}
					break;
				case 115:
					if ((tak5 == 0) && (tak4 == 0) && (tak3 == 0) && (tak2 == 0) && (tak1 == 0))
					{
						tymczasowa = 0;
						uspij(0.5);
					}
					break;
				case 'M':
					//cheatwin
					tab[6][2] = '1';
					tab[6][3] = '2';
					tab[6][4] = '3';
					tab[6][5] = '4';
					tymczasowa = 0;
					break;
				case 'N':
					//cheatlose
					tab[6][13] = 'g';
					tab[6][14] = 'g';
					tab[6][15] = 'g';
					tab[6][16] = 'g';
					tymczasowa = 0;
					break;
				}
			}
		}
		while (wylosowana == 6)
		{
			kiz = 1;
			roll();
			tak1 = 0;
			tak2 = 0;
			tak3 = 0;
			tak4 = 0;
			tak5 = 0;
			if (inplay[0] == 1)
			{
				if (test1() == true)
				{
					kiz++;
					gotoxy(21, kiz);
					cout << "1.Move pawn No.1" << endl;
					tak1 = 1;
				}

			}
			if (inplay[1] == 1)
			{
				if (test2() == true)
				{
					kiz++;
					gotoxy(21, kiz);
					cout << "2.Move pawn No.2" << endl;
					tak2 = 1;
				}

			}
			if (inplay[2] == 1)
			{
				if (test3() == true)
				{
					kiz++;
					gotoxy(21, kiz);
					cout << "3.Move pawn No.3" << endl;
					tak3 = 1;
				}

			}
			if (inplay[3] == 1)
			{
				if (test4() == true)
				{
					kiz++;
					gotoxy(21, kiz);
					cout << "4.Move pawn No.4" << endl;
					tak4 = 1;
				}

			}
			if (wylosowana == 6)
			{
				if (test5() == true)
				{
					kiz++;
					gotoxy(21, kiz);
					cout << "5.Take out new pawn" << endl;
					tak5 = 1;
				}
			}
			kiz++;
			gotoxy(21, kiz);
			cout << "Q.Surrender" << endl;
			if ((tak5 == 0) && (tak4 == 0) && (tak3 == 0) && (tak2 == 0) && (tak1 == 0))
			{
				kiz++;
				gotoxy(21, kiz);
				cout << "S.Skip(Its not possible to";
				kiz++;
				gotoxy(21, kiz);
				cout << "make a move with this roll)";
			}
			tymczasowa = 3;
			while (tymczasowa != 0)
			{
				switch (_getch())
				{
				case 49:
					if (tak1 == 0)
					{
						break;
					}
					przemiesc1();
					wyswietl();
					uspij(0.5);
					tymczasowa = 0;
					break;
				case 50:
					if (tak2 == 0)
					{
						break;
					}
					przemiesc2();
					wyswietl();
					uspij(0.5);
					tymczasowa = 0;
					break;
				case 51:
					if (tak3 == 0)
					{
						break;
					}
					przemiesc3();
					wyswietl();
					uspij(0.5);
					tymczasowa = 0;
					break;
				case 52:
					if (tak4 == 0)
					{
						break;
					}
					przemiesc4();
					wyswietl();
					uspij(0.5);
					tymczasowa = 0;
					break;
				case 53:
					if (tak5 == 0)
					{
						break;
					}
					wyjmij();
					wyswietl();
					uspij(0.5);
					tymczasowa = 0;
					break;
				case 113:
					przegrana(0.01);
					uspij(4);
					ClearScreen();
					menu();
					while (1)
					{
						switch (_getch())
						{
						case 'y':
							ClearScreen();
							goto startuj;
							break;
						case 'n':
							return 0;
							break;
						}
					}
					break;
				case 115:
					if ((tak5 == 0) && (tak4 == 0) && (tak3 == 0) && (tak2 == 0) && (tak1 == 0))
					{
						tymczasowa = 0;
						uspij(0.5);
					}
					break;
				case 'M':
					//cheatwin
					tab[6][2] = '1';
					tab[6][3] = '2';
					tab[6][4] = '3';
					tab[6][5] = '4';
					tymczasowa = 0;
					break;
				case 'N':
					//cheatlose
					tab[6][13] = 'g';
					tab[6][14] = 'g';
					tab[6][15] = 'g';
					tab[6][16] = 'g';
					tymczasowa = 0;
					break;
				}
			}
		}
		wylosowana = 0;
		ruch = 0;
		wyjety = 0;
		//-----------------------------bot1
		uspij(0.5);
		if (tab[6][2] != ' ' && tab[6][3] != ' ' && tab[6][4] != ' ' && tab[6][5] != ' ') break;
		if (tab[6][13] != ' ' && tab[6][14] != ' ' && tab[6][15] != ' ' && tab[6][16] != ' ') break;
		przejscie(1);
		uspij(1);
		//grafika bot1
		if (inplay[4] == 0 && inplay[5] == 0 && inplay[6] == 0 && inplay[7] == 0)
		{
			botmultiroll(bot1);
			if (wylosowana == 6)
			{
				wyjmij2();
				wylosowana = losuj();
				wyswietl();
				gotoxy(21, 2);
				cout << bot1 << " rolled " << wylosowana;
				uspij(1);
				przemiescbot1(4);
				uspij(1);
				wyswietl();
				if (wylosowana == 6)
				{
					goto kotwica;
				}
			}
		}
		else
		{
		kotwica:
			ruch = 0;
			wylosowana = losuj();
			wyswietl();
			gotoxy(21, 2);
			cout << bot1 << " rolled " << wylosowana;
			uspij(1);
			if (wylosowana == 6)
			{
				while (wylosowana == 6)
				{
					ruch = 0;
					if (inplay[4] == 0 || inplay[5] == 0 || inplay[6] == 0 || inplay[7] == 0)
					{
						if (botwyjscie1() == true)
						{
							wyswietl();
							gotoxy(21, 2);
							cout << bot1 << " is taking out a pawn" << endl;
							uspij(1);
							wyjmij2();
							wylosowana = losuj();
							gotoxy(21, 2);
							cout << bot1 << " rolled " << wylosowana;
							uspij(1);
							if (bottest1(4) == true && wyjety == 1)
							{
								przemiescbot1(4);
								wyswietl();
								uspij(1.5);
								ruch = 1;
							}
							if (bottest1(5) == true && wyjety == 2)
							{
								przemiescbot1(5);
								wyswietl();
								uspij(1.5);
								ruch = 1;
							}
							if (bottest1(6) == true && wyjety == 3)
							{
								przemiescbot1(6);
								wyswietl();
								uspij(1.5);
								ruch = 1;
							}
							if (bottest1(7) == true && wyjety == 4)
							{
								przemiescbot1(7);
								wyswietl();
								uspij(1.5);
								ruch = 1;
							}
							if (ruch != 1)
							{
								if (botbije1(4) == true && bottest1(4) == true && inplay[4] == 1)ruch = 2;
								if (botbije1(5) == true && bottest1(5) == true && inplay[5] == 1)ruch = 3;
								if (botbije1(6) == true && bottest1(6) == true && inplay[6] == 1)ruch = 4;
								if (botbije1(7) == true && bottest1(7) == true && inplay[7] == 1)ruch = 5;
								switch (ruch)
								{
								case 2:
									przemiescbot1(4);
									wyswietl();
									uspij(1.5);
									break;
								case 3:
									przemiescbot1(5);
									wyswietl();
									uspij(1.5);
									break;
								case 4:
									przemiescbot1(6);
									wyswietl();
									uspij(1.5);
									break;
								case 5:
									przemiescbot1(7);
									wyswietl();
									uspij(1.5);
									break;
								}
							}
							if (ruch == 0)
							{
								if (bottest1(4) == true && inplay[4] == 1)
								{
									ruch = 6;
								}
								if (bottest1(5) == true && inplay[5] == 1)
								{
									ruch = 7;
								}
								if (bottest1(6) == true && inplay[6] == 1)
								{
									ruch = 8;
								}
								if (bottest1(7) == true && inplay[7] == 1)
								{
									ruch = 9;
								}
								switch (ruch)
								{
								case 6:
									przemiescbot1(4);
									wyswietl();
									uspij(1.5);
									break;
								case 7:
									przemiescbot1(5);
									wyswietl();
									uspij(1.5);
									break;
								case 8:
									przemiescbot1(6);
									wyswietl();
									uspij(1.5);
									break;
								case 9:
									przemiescbot1(7);
									wyswietl();
									uspij(1.5);
									break;
								}
							}
						}
						else
						{
							wylosowana = 0;
						}
					}
					else
					{
						if (botbije1(4) == true && inplay[4] == 1 && bottest1(4) == true)
						{
							ruch = 2;
						}
						if (botbije1(5) == true && inplay[5] == 1 && bottest1(5) == true)
						{
							ruch = 3;
						}
						if (botbije1(6) == true && inplay[6] == 1 && bottest1(6) == true)
						{
							ruch = 4;
						}
						if (botbije1(7) == true && inplay[7] == 1 && bottest1(7) == true)
						{
							ruch = 5;
						}
						switch (ruch)
						{
						case 2:
							przemiescbot1(4);
							wyswietl();
							uspij(1.5);
							break;
						case 3:
							przemiescbot1(5);
							wyswietl();
							uspij(1.5);
							break;
						case 4:
							przemiescbot1(6);
							wyswietl();
							uspij(1.5);
							break;
						case 5:
							przemiescbot1(7);
							wyswietl();
							uspij(1.5);
							break;
						}
						if (ruch == 0)
						{
							if (bottest1(4) == true && inplay[4] == 1)
							{
								ruch = 6;
							}
							if (bottest1(5) == true && inplay[5] == 1)
							{
								ruch = 7;
							}
							if (bottest1(6) == true && inplay[6] == 1)
							{
								ruch = 8;
							}
							if (bottest1(7) == true && inplay[7] == 1)
							{
								ruch = 9;
							}
							switch (ruch)
							{
							case 6:
								przemiescbot1(4);
								wyswietl();
								uspij(1.5);
								break;
							case 7:
								przemiescbot1(5);
								wyswietl();
								uspij(1.5);
								break;
							case 8:
								przemiescbot1(6);
								wyswietl();
								uspij(1.5);
								break;
							case 9:
								przemiescbot1(7);
								wyswietl();
								uspij(1.5);
								break;
							}
						}
						goto kotwica;
					}
				}
			}
			else
			{
				if (botbije1(4) == true && inplay[4] == 1 && bottest1(4) == true)
				{
					ruch = 10;
				}
				if (botbije1(5) == true && inplay[5] == 1 && bottest1(5) == true)
				{
					ruch = 11;
				}
				if (botbije1(6) == true && inplay[6] == 1 && bottest1(6) == true)
				{
					ruch = 12;
				}
				if (botbije1(7) == true && inplay[7] == 1 && bottest1(7) == true)
				{
					ruch = 13;
				}
				switch (ruch)
				{
				case 10:
					przemiescbot1(4);
					wyswietl();
					uspij(1.5);
					break;
				case 11:
					przemiescbot1(5);
					wyswietl();
					uspij(1.5);
					break;
				case 12:
					przemiescbot1(6);
					wyswietl();
					uspij(1.5);
					break;
				case 13:
					przemiescbot1(7);
					wyswietl();
					uspij(1.5);
					break;
				}

				if (ruch == 0)
				{
					if (bottest1(4) == true && inplay[4] == 1)
					{
						ruch = 14;
					}
					if (bottest1(5) == true && inplay[5] == 1)
					{
						ruch = 15;
					}
					if (bottest1(6) == true && inplay[6] == 1)
					{
						ruch = 16;
					}
					if (bottest1(7) == true && inplay[7] == 1)
					{
						ruch = 17;
					}
					switch (ruch)
					{
					case 14:
						przemiescbot1(4);
						wyswietl();
						uspij(1.5);
						break;
					case 15:
						przemiescbot1(5);
						wyswietl();
						uspij(1.5);
						break;
					case 16:
						przemiescbot1(6);
						wyswietl();
						uspij(1.5);
						break;
					case 17:
						przemiescbot1(7);
						wyswietl();
						uspij(1.5);
						break;
					}
				}
			}
		}
		//-----------------------------bot2
		uspij(0.5);
		if (tab[2][9] != ' ' && tab[3][9] != ' ' && tab[4][9] != ' ' && tab[5][9] != ' ') break;
		przejscie(2);
		uspij(1);
		//grafika bot2
		ruch = 0;
		wyjety = 0;
		wylosowana = 0;
		if (inplay[8] == 0 && inplay[9] == 0 && inplay[10] == 0 && inplay[11] == 0)
		{
			botmultiroll(bot2);
			if (wylosowana == 6)
			{
				wyjmij3();
				wylosowana = losuj();
				wyswietl();
				gotoxy(21, 2);
				cout << bot2 << " rolled " << wylosowana;
				uspij(1);
				przemiescbot2(8);
				uspij(1);
				wyswietl();
				if (wylosowana == 6)
				{
					goto kotwica2;
				}
			}
		}
		else
		{
		kotwica2:
			ruch = 0;
			wylosowana = losuj();
			wyswietl();
			gotoxy(21, 2);
			cout << bot2 << " rolled " << wylosowana;
			uspij(1);
			if (wylosowana == 6)
			{
				while (wylosowana == 6)
				{
					ruch = 0;
					if (inplay[8] == 0 || inplay[9] == 0 || inplay[10] == 0 || inplay[11] == 0)
					{
						if (botwyjscie2() == true)
						{
							wyswietl();
							gotoxy(21, 2);
							cout << bot2 << " is taking out a pawn" << endl;
							uspij(1);
							wyjmij3();
							wylosowana = losuj();
							gotoxy(21, 2);
							cout << bot2 << " rolled " << wylosowana;
							uspij(1);
							if (bottest2(8) == true && wyjety == 1)
							{
								przemiescbot2(8);
								wyswietl();
								uspij(1.5);
								ruch = 1;
							}
							if (bottest2(9) == true && wyjety == 2)
							{
								przemiescbot2(9);
								wyswietl();
								uspij(1.5);
								ruch = 1;
							}
							if (bottest2(10) == true && wyjety == 3)
							{
								przemiescbot2(10);
								wyswietl();
								uspij(1.5);
								ruch = 1;
							}
							if (bottest2(11) == true && wyjety == 4)
							{
								przemiescbot2(11);
								wyswietl();
								uspij(1.5);
								ruch = 1;
							}
							if (ruch != 1)
							{
								if (botbije2(8) == true && bottest2(8) == true && inplay[8] == 1)ruch = 2;
								if (botbije2(9) == true && bottest2(9) == true && inplay[9] == 1)ruch = 3;
								if (botbije2(10) == true && bottest2(10) == true && inplay[10] == 1)ruch = 4;
								if (botbije2(11) == true && bottest2(11) == true && inplay[11] == 1)ruch = 5;
								switch (ruch)
								{
								case 2:
									przemiescbot2(8);
									wyswietl();
									uspij(1.5);
									break;
								case 3:
									przemiescbot2(9);
									wyswietl();
									uspij(1.5);
									break;
								case 4:
									przemiescbot2(10);
									wyswietl();
									uspij(1.5);
									break;
								case 5:
									przemiescbot2(11);
									wyswietl();
									uspij(1.5);
									break;
								}
							}
							if (ruch == 0)
							{
								if (bottest2(8) == true && inplay[8] == 1)
								{
									ruch = 6;
								}
								if (bottest2(9) == true && inplay[9] == 1)
								{
									ruch = 7;
								}
								if (bottest2(10) == true && inplay[10] == 1)
								{
									ruch = 8;
								}
								if (bottest2(11) == true && inplay[11] == 1)
								{
									ruch = 9;
								}
								switch (ruch)
								{
								case 6:
									przemiescbot2(8);
									wyswietl();
									uspij(1.5);
									break;
								case 7:
									przemiescbot2(9);
									wyswietl();
									uspij(1.5);
									break;
								case 8:
									przemiescbot2(10);
									wyswietl();
									uspij(1.5);
									break;
								case 9:
									przemiescbot2(11);
									wyswietl();
									uspij(1.5);
									break;
								}
							}
						}
						else
						{
							wylosowana = 0;
						}
					}
					else
					{
						if (botbije2(8) == true && inplay[8] == 1 && bottest2(8) == true)
						{
							ruch = 2;
						}
						if (botbije2(9) == true && inplay[9] == 1 && bottest2(9) == true)
						{
							ruch = 3;
						}
						if (botbije2(10) == true && inplay[10] == 1 && bottest2(10) == true)
						{
							ruch = 4;
						}
						if (botbije2(11) == true && inplay[11] == 1 && bottest2(11) == true)
						{
							ruch = 5;
						}
						switch (ruch)
						{
						case 2:
							przemiescbot2(8);
							wyswietl();
							uspij(1.5);
							break;
						case 3:
							przemiescbot2(9);
							wyswietl();
							uspij(1.5);
							break;
						case 4:
							przemiescbot2(10);
							wyswietl();
							uspij(1.5);
							break;
						case 5:
							przemiescbot2(11);
							wyswietl();
							uspij(1.5);
							break;
						}
						if (ruch == 0)
						{
							if (bottest2(8) == true && inplay[8] == 1)
							{
								ruch = 6;
							}
							if (bottest2(9) == true && inplay[9] == 1)
							{
								ruch = 7;
							}
							if (bottest2(10) == true && inplay[10] == 1)
							{
								ruch = 8;
							}
							if (bottest2(11) == true && inplay[11] == 1)
							{
								ruch = 9;
							}
							switch (ruch)
							{
							case 6:
								przemiescbot2(8);
								wyswietl();
								uspij(1.5);
								break;
							case 7:
								przemiescbot2(9);
								wyswietl();
								uspij(1.5);
								break;
							case 8:
								przemiescbot2(10);
								wyswietl();
								uspij(1.5);
								break;
							case 9:
								przemiescbot2(11);
								wyswietl();
								uspij(1.5);
								break;
							}
						}
						goto kotwica2;
					}
				}
			}
			else
			{
				if (botbije2(8) == true && inplay[8] == 1 && bottest2(8) == true)
				{
					ruch = 10;
				}
				if (botbije2(9) == true && inplay[9] == 1 && bottest2(9) == true)
				{
					ruch = 11;
				}
				if (botbije2(10) == true && inplay[10] == 1 && bottest2(10) == true)
				{
					ruch = 12;
				}
				if (botbije2(11) == true && inplay[11] == 1 && bottest2(11) == true)
				{
					ruch = 13;
				}
				switch (ruch)
				{
				case 10:
					przemiescbot2(8);
					wyswietl();
					uspij(1.5);
					break;
				case 11:
					przemiescbot2(9);
					wyswietl();
					uspij(1.5);
					break;
				case 12:
					przemiescbot2(10);
					wyswietl();
					uspij(1.5);
					break;
				case 13:
					przemiescbot2(11);
					wyswietl();
					uspij(1.5);
					break;
				}

				if (ruch == 0)
				{
					if (bottest2(8) == true && inplay[8] == 1)
					{
						ruch = 14;
					}
					if (bottest2(9) == true && inplay[9] == 1)
					{
						ruch = 15;
					}
					if (bottest2(10) == true && inplay[10] == 1)
					{
						ruch = 16;
					}
					if (bottest2(11) == true && inplay[11] == 1)
					{
						ruch = 17;
					}
					switch (ruch)
					{
					case 14:
						przemiescbot2(8);
						wyswietl();
						uspij(1.5);
						break;
					case 15:
						przemiescbot2(9);
						wyswietl();
						uspij(1.5);
						break;
					case 16:
						przemiescbot2(10);
						wyswietl();
						uspij(1.5);
						break;
					case 17:
						przemiescbot2(11);
						wyswietl();
						uspij(1.5);
						break;
					}
				}
			}
		}
		//-----------------------------bot3
		uspij(0.5);
		if (tab[6][13] != ' ' && tab[6][14] != ' ' && tab[6][15] != ' ' && tab[6][16] != ' ') break;
		przejscie(3);
		uspij(1);
		//grafika bot3
		ruch = 0;
		wyjety = 0;
		wylosowana = 0;
		if (inplay[12] == 0 && inplay[13] == 0 && inplay[14] == 0 && inplay[15] == 0)
		{
			botmultiroll(bot3);
			if (wylosowana == 6)
			{
				wyjmij4();
				wylosowana = losuj();
				wyswietl();
				gotoxy(21, 2);
				cout << bot3 << " rolled " << wylosowana;
				uspij(1);
				przemiescbot3(12);
				uspij(1);
				wyswietl();
				if (wylosowana == 6)
				{
					goto kotwica3;
				}
			}
		}
		else
		{
		kotwica3:
			ruch = 0;
			wylosowana = losuj();
			wyswietl();
			gotoxy(21, 2);
			cout << bot3 << " rolled " << wylosowana;
			uspij(1);
			if (wylosowana == 6)
			{
				while (wylosowana == 6)
				{
					ruch = 0;
					if (inplay[12] == 0 || inplay[13] == 0 || inplay[14] == 0 || inplay[15] == 0)
					{
						if (botwyjscie3() == true)
						{
							wyswietl();
							gotoxy(21, 2);
							cout << bot3 << " is taking out a pawn" << endl;
							uspij(1);
							wyjmij4();
							wylosowana = losuj();
							gotoxy(21, 2);
							cout << bot3 << " rolled " << wylosowana;
							uspij(1);
							if (bottest3(12) == true && wyjety == 1)
							{
								przemiescbot3(12);
								wyswietl();
								uspij(1.5);
								ruch = 1;
							}
							if (bottest3(13) == true && wyjety == 2)
							{
								przemiescbot3(13);
								wyswietl();
								uspij(1.5);
								ruch = 1;
							}
							if (bottest3(14) == true && wyjety == 3)
							{
								przemiescbot3(14);
								wyswietl();
								uspij(1.5);
								ruch = 1;
							}
							if (bottest3(15) == true && wyjety == 4)
							{
								przemiescbot3(15);
								wyswietl();
								uspij(1.5);
								ruch = 1;
							}
							if (ruch != 1)
							{
								if (botbije3(12) == true && bottest3(12) == true && inplay[12] == 1)ruch = 2;
								if (botbije3(13) == true && bottest3(13) == true && inplay[13] == 1)ruch = 3;
								if (botbije3(14) == true && bottest3(14) == true && inplay[14] == 1)ruch = 4;
								if (botbije3(15) == true && bottest3(15) == true && inplay[15] == 1)ruch = 5;
								switch (ruch)
								{
								case 2:
									przemiescbot3(12);
									wyswietl();
									uspij(1.5);
									break;
								case 3:
									przemiescbot3(13);
									wyswietl();
									uspij(1.5);
									break;
								case 4:
									przemiescbot3(14);
									wyswietl();
									uspij(1.5);
									break;
								case 5:
									przemiescbot3(15);
									wyswietl();
									uspij(1.5);
									break;
								}
							}
							if (ruch == 0)
							{
								if (bottest3(12) == true && inplay[12] == 1)
								{
									ruch = 6;
								}
								if (bottest3(13) == true && inplay[13] == 1)
								{
									ruch = 7;
								}
								if (bottest3(14) == true && inplay[14] == 1)
								{
									ruch = 8;
								}
								if (bottest3(15) == true && inplay[15] == 1)
								{
									ruch = 9;
								}
								switch (ruch)
								{
								case 6:
									przemiescbot3(12);
									wyswietl();
									uspij(1.5);
									break;
								case 7:
									przemiescbot3(13);
									wyswietl();
									uspij(1.5);
									break;
								case 8:
									przemiescbot3(14);
									wyswietl();
									uspij(1.5);
									break;
								case 9:
									przemiescbot3(15);
									wyswietl();
									uspij(1.5);
									break;
								}
							}
						}
						else
						{
							wylosowana = 0;
						}
					}
					else
					{
						if (botbije3(12) == true && inplay[12] == 1 && bottest3(12) == true)
						{
							ruch = 2;
						}
						if (botbije3(13) == true && inplay[13] == 1 && bottest3(13) == true)
						{
							ruch = 3;
						}
						if (botbije3(14) == true && inplay[14] == 1 && bottest3(14) == true)
						{
							ruch = 4;
						}
						if (botbije3(15) == true && inplay[15] == 1 && bottest3(15) == true)
						{
							ruch = 5;
						}
						switch (ruch)
						{
						case 2:
							przemiescbot3(12);
							wyswietl();
							uspij(1.5);
							break;
						case 3:
							przemiescbot3(13);
							wyswietl();
							uspij(1.5);
							break;
						case 4:
							przemiescbot3(14);
							wyswietl();
							uspij(1.5);
							break;
						case 5:
							przemiescbot3(15);
							wyswietl();
							uspij(1.5);
							break;
						}
						if (ruch == 0)
						{
							if (bottest3(12) == true && inplay[12] == 1)
							{
								ruch = 6;
							}
							if (bottest3(13) == true && inplay[13] == 1)
							{
								ruch = 7;
							}
							if (bottest3(14) == true && inplay[14] == 1)
							{
								ruch = 8;
							}
							if (bottest3(15) == true && inplay[15] == 1)
							{
								ruch = 9;
							}
							switch (ruch)
							{
							case 6:
								przemiescbot3(12);
								wyswietl();
								uspij(1.5);
								break;
							case 7:
								przemiescbot3(13);
								wyswietl();
								uspij(1.5);
								break;
							case 8:
								przemiescbot3(14);
								wyswietl();
								uspij(1.5);
								break;
							case 9:
								przemiescbot3(15);
								wyswietl();
								uspij(1.5);
								break;
							}
						}
						goto kotwica3;
					}
				}
			}
			else
			{
				if (botbije3(12) == true && inplay[12] == 1 && bottest3(12) == true)
				{
					ruch = 10;
				}
				if (botbije3(13) == true && inplay[13] == 1 && bottest3(13) == true)
				{
					ruch = 11;
				}
				if (botbije3(14) == true && inplay[14] == 1 && bottest3(14) == true)
				{
					ruch = 12;
				}
				if (botbije3(15) == true && inplay[15] == 1 && bottest3(15) == true)
				{
					ruch = 13;
				}
				switch (ruch)
				{
				case 10:
					przemiescbot3(12);
					wyswietl();
					uspij(1.5);
					break;
				case 11:
					przemiescbot3(13);
					wyswietl();
					uspij(1.5);
					break;
				case 12:
					przemiescbot3(14);
					wyswietl();
					uspij(1.5);
					break;
				case 13:
					przemiescbot3(15);
					wyswietl();
					uspij(1.5);
					break;
				}

				if (ruch == 0)
				{
					if (bottest3(12) == true && inplay[12] == 1)
					{
						ruch = 14;
					}
					if (bottest3(13) == true && inplay[13] == 1)
					{
						ruch = 15;
					}
					if (bottest3(14) == true && inplay[14] == 1)
					{
						ruch = 16;
					}
					if (bottest3(15) == true && inplay[15] == 1)
					{
						ruch = 17;
					}
					switch (ruch)
					{
					case 14:
						przemiescbot3(12);
						wyswietl();
						uspij(1.5);
						break;
					case 15:
						przemiescbot3(13);
						wyswietl();
						uspij(1.5);
						break;
					case 16:
						przemiescbot3(14);
						wyswietl();
						uspij(1.5);
						break;
					case 17:
						przemiescbot3(15);
						wyswietl();
						uspij(1.5);
						break;
					}
				}
			}
		}
		//twoj ruch
		uspij(0.5);
		if (tab[7][9] != ' ' && tab[8][9] != ' ' && tab[9][9] != ' ' && tab[10][9] != ' ') break;
		przejscie(4);
		uspij(1);
	}
	uspij(1.5);
	if (tab[6][2] != ' ' && tab[6][3] != ' ' && tab[6][4] != ' ' && tab[6][5] != ' ')
	{
		wygrana(0.01);
	}
	else
	{
		przegrana(0.01);
	}
	uspij(4);
	ClearScreen();
	menu();
	while (1)
	{
		switch (_getch())
		{
		case 'y':
			ClearScreen();
			goto startuj;
			break;
		case 'n':
			return 0;
			break;
		}
	}
	system("pause");
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	return 0;
}

void duzo()
{
	pola1[0][0] = 4;
	pola1[0][1] = 4;
	pola1[0][2] = 4;
	pola1[0][3] = 4;
	pola1[0][4] = 4;
	pola1[0][5] = 4;
	pola1[0][6] = 4;
	pola1[0][7] = 3;
	pola1[0][8] = 2;
	pola1[0][9] = 1;
	pola1[0][10] = 1;
	pola1[0][11] = 1;
	pola1[0][12] = 1;
	pola1[0][13] = 1;
	pola1[0][14] = 2;
	pola1[0][15] = 3;
	pola1[0][16] = 4;
	pola1[0][17] = 4;
	pola1[0][18] = 4;
	pola1[0][19] = 4;
	pola1[0][20] = 4;
	pola1[0][21] = 4;
	pola1[0][22] = 4;
	pola1[0][23] = 5;
	pola1[0][24] = 6;
	pola1[0][25] = 7;
	pola1[0][26] = 8;
	pola1[0][27] = 8;
	pola1[0][28] = 8;
	pola1[0][29] = 8;
	pola1[0][30] = 8;
	pola1[0][31] = 8;
	pola1[0][32] = 8;
	pola1[0][33] = 9;
	pola1[0][34] = 10;
	pola1[0][35] = 11;
	pola1[0][36] = 11;
	pola1[0][37] = 11;
	pola1[0][38] = 11;
	pola1[0][39] = 11;
	pola1[0][40] = 10;
	pola1[0][41] = 9;
	pola1[0][42] = 8;
	pola1[0][43] = 8;
	pola1[0][44] = 8;
	pola1[0][45] = 8;
	pola1[0][46] = 8;
	pola1[0][47] = 8;
	pola1[0][48] = 8;
	pola1[0][49] = 7;
	pola1[0][50] = 6;
	pola1[0][51] = 6;
	pola1[0][52] = 6;
	pola1[0][53] = 6;
	pola1[0][54] = 6;

	pola1[1][0] = 1;
	pola1[1][1] = 2;
	pola1[1][2] = 3;
	pola1[1][3] = 4;
	pola1[1][4] = 5;
	pola1[1][5] = 6;
	pola1[1][6] = 7;
	pola1[1][7] = 7;
	pola1[1][8] = 7;
	pola1[1][9] = 7;
	pola1[1][10] = 8;
	pola1[1][11] = 9;
	pola1[1][12] = 10;
	pola1[1][13] = 11;
	pola1[1][14] = 11;
	pola1[1][15] = 11;
	pola1[1][16] = 11;
	pola1[1][17] = 12;
	pola1[1][18] = 13;
	pola1[1][19] = 14;
	pola1[1][20] = 15;
	pola1[1][21] = 16;
	pola1[1][22] = 17;
	pola1[1][23] = 17;
	pola1[1][24] = 17;
	pola1[1][25] = 17;
	pola1[1][26] = 17;
	pola1[1][27] = 16;
	pola1[1][28] = 15;
	pola1[1][29] = 14;
	pola1[1][30] = 13;
	pola1[1][31] = 12;
	pola1[1][32] = 11;
	pola1[1][33] = 11;
	pola1[1][34] = 11;
	pola1[1][35] = 11;
	pola1[1][36] = 10;
	pola1[1][37] = 9;
	pola1[1][38] = 8;
	pola1[1][39] = 7;
	pola1[1][40] = 7;
	pola1[1][41] = 7;
	pola1[1][42] = 7;
	pola1[1][43] = 6;
	pola1[1][44] = 5;
	pola1[1][45] = 4;
	pola1[1][46] = 3;
	pola1[1][47] = 2;
	pola1[1][48] = 1;
	pola1[1][49] = 1;
	pola1[1][50] = 1;
	pola1[1][51] = 2;
	pola1[1][52] = 3;
	pola1[1][53] = 4;
	pola1[1][54] = 5;

	pola1[2][0] = 4;
	pola1[2][1] = 4;
	pola1[2][2] = 4;
	pola1[2][3] = 4;
	pola1[2][4] = 4;
	pola1[2][5] = 4;
	pola1[2][6] = 4;
	pola1[2][7] = 3;
	pola1[2][8] = 2;
	pola1[2][9] = 1;
	pola1[2][10] = 1;
	pola1[2][11] = 1;
	pola1[2][12] = 1;
	pola1[2][13] = 1;
	pola1[2][14] = 2;
	pola1[2][15] = 3;
	pola1[2][16] = 4;
	pola1[2][17] = 4;
	pola1[2][18] = 4;
	pola1[2][19] = 4;
	pola1[2][20] = 4;
	pola1[2][21] = 4;
	pola1[2][22] = 4;
	pola1[2][23] = 5;
	pola1[2][24] = 6;
	pola1[2][25] = 7;
	pola1[2][26] = 8;
	pola1[2][27] = 8;
	pola1[2][28] = 8;
	pola1[2][29] = 8;
	pola1[2][30] = 8;
	pola1[2][31] = 8;
	pola1[2][32] = 8;
	pola1[2][33] = 9;
	pola1[2][34] = 10;
	pola1[2][35] = 11;
	pola1[2][36] = 11;
	pola1[2][37] = 11;
	pola1[2][38] = 11;
	pola1[2][39] = 11;
	pola1[2][40] = 10;
	pola1[2][41] = 9;
	pola1[2][42] = 8;
	pola1[2][43] = 8;
	pola1[2][44] = 8;
	pola1[2][45] = 8;
	pola1[2][46] = 8;
	pola1[2][47] = 8;
	pola1[2][48] = 8;
	pola1[2][49] = 7;
	pola1[2][50] = 6;
	pola1[2][51] = 6;
	pola1[2][52] = 6;
	pola1[2][53] = 6;
	pola1[2][54] = 6;

	pola1[3][0] = 1;
	pola1[3][1] = 2;
	pola1[3][2] = 3;
	pola1[3][3] = 4;
	pola1[3][4] = 5;
	pola1[3][5] = 6;
	pola1[3][6] = 7;
	pola1[3][7] = 7;
	pola1[3][8] = 7;
	pola1[3][9] = 7;
	pola1[3][10] = 8;
	pola1[3][11] = 9;
	pola1[3][12] = 10;
	pola1[3][13] = 11;
	pola1[3][14] = 11;
	pola1[3][15] = 11;
	pola1[3][16] = 11;
	pola1[3][17] = 12;
	pola1[3][18] = 13;
	pola1[3][19] = 14;
	pola1[3][20] = 15;
	pola1[3][21] = 16;
	pola1[3][22] = 17;
	pola1[3][23] = 17;
	pola1[3][24] = 17;
	pola1[3][25] = 17;
	pola1[3][26] = 17;
	pola1[3][27] = 16;
	pola1[3][28] = 15;
	pola1[3][29] = 14;
	pola1[3][30] = 13;
	pola1[3][31] = 12;
	pola1[3][32] = 11;
	pola1[3][33] = 11;
	pola1[3][34] = 11;
	pola1[3][35] = 11;
	pola1[3][36] = 10;
	pola1[3][37] = 9;
	pola1[3][38] = 8;
	pola1[3][39] = 7;
	pola1[3][40] = 7;
	pola1[3][41] = 7;
	pola1[3][42] = 7;
	pola1[3][43] = 6;
	pola1[3][44] = 5;
	pola1[3][45] = 4;
	pola1[3][46] = 3;
	pola1[3][47] = 2;
	pola1[3][48] = 1;
	pola1[3][49] = 1;
	pola1[3][50] = 1;
	pola1[3][51] = 2;
	pola1[3][52] = 3;
	pola1[3][53] = 4;
	pola1[3][54] = 5;

	pola1[4][0] = 4;
	pola1[4][1] = 4;
	pola1[4][2] = 4;
	pola1[4][3] = 4;
	pola1[4][4] = 4;
	pola1[4][5] = 4;
	pola1[4][6] = 4;
	pola1[4][7] = 3;
	pola1[4][8] = 2;
	pola1[4][9] = 1;
	pola1[4][10] = 1;
	pola1[4][11] = 1;
	pola1[4][12] = 1;
	pola1[4][13] = 1;
	pola1[4][14] = 2;
	pola1[4][15] = 3;
	pola1[4][16] = 4;
	pola1[4][17] = 4;
	pola1[4][18] = 4;
	pola1[4][19] = 4;
	pola1[4][20] = 4;
	pola1[4][21] = 4;
	pola1[4][22] = 4;
	pola1[4][23] = 5;
	pola1[4][24] = 6;
	pola1[4][25] = 7;
	pola1[4][26] = 8;
	pola1[4][27] = 8;
	pola1[4][28] = 8;
	pola1[4][29] = 8;
	pola1[4][30] = 8;
	pola1[4][31] = 8;
	pola1[4][32] = 8;
	pola1[4][33] = 9;
	pola1[4][34] = 10;
	pola1[4][35] = 11;
	pola1[4][36] = 11;
	pola1[4][37] = 11;
	pola1[4][38] = 11;
	pola1[4][39] = 11;
	pola1[4][40] = 10;
	pola1[4][41] = 9;
	pola1[4][42] = 8;
	pola1[4][43] = 8;
	pola1[4][44] = 8;
	pola1[4][45] = 8;
	pola1[4][46] = 8;
	pola1[4][47] = 8;
	pola1[4][48] = 8;
	pola1[4][49] = 7;
	pola1[4][50] = 6;
	pola1[4][51] = 6;
	pola1[4][52] = 6;
	pola1[4][53] = 6;
	pola1[4][54] = 6;

	pola1[5][0] = 1;
	pola1[5][1] = 2;
	pola1[5][2] = 3;
	pola1[5][3] = 4;
	pola1[5][4] = 5;
	pola1[5][5] = 6;
	pola1[5][6] = 7;
	pola1[5][7] = 7;
	pola1[5][8] = 7;
	pola1[5][9] = 7;
	pola1[5][10] = 8;
	pola1[5][11] = 9;
	pola1[5][12] = 10;
	pola1[5][13] = 11;
	pola1[5][14] = 11;
	pola1[5][15] = 11;
	pola1[5][16] = 11;
	pola1[5][17] = 12;
	pola1[5][18] = 13;
	pola1[5][19] = 14;
	pola1[5][20] = 15;
	pola1[5][21] = 16;
	pola1[5][22] = 17;
	pola1[5][23] = 17;
	pola1[5][24] = 17;
	pola1[5][25] = 17;
	pola1[5][26] = 17;
	pola1[5][27] = 16;
	pola1[5][28] = 15;
	pola1[5][29] = 14;
	pola1[5][30] = 13;
	pola1[5][31] = 12;
	pola1[5][32] = 11;
	pola1[5][33] = 11;
	pola1[5][34] = 11;
	pola1[5][35] = 11;
	pola1[5][36] = 10;
	pola1[5][37] = 9;
	pola1[5][38] = 8;
	pola1[5][39] = 7;
	pola1[5][40] = 7;
	pola1[5][41] = 7;
	pola1[5][42] = 7;
	pola1[5][43] = 6;
	pola1[5][44] = 5;
	pola1[5][45] = 4;
	pola1[5][46] = 3;
	pola1[5][47] = 2;
	pola1[5][48] = 1;
	pola1[5][49] = 1;
	pola1[5][50] = 1;
	pola1[5][51] = 2;
	pola1[5][52] = 3;
	pola1[5][53] = 4;
	pola1[5][54] = 5;

	pola1[6][0] = 4;
	pola1[6][1] = 4;
	pola1[6][2] = 4;
	pola1[6][3] = 4;
	pola1[6][4] = 4;
	pola1[6][5] = 4;
	pola1[6][6] = 4;
	pola1[6][7] = 3;
	pola1[6][8] = 2;
	pola1[6][9] = 1;
	pola1[6][10] = 1;
	pola1[6][11] = 1;
	pola1[6][12] = 1;
	pola1[6][13] = 1;
	pola1[6][14] = 2;
	pola1[6][15] = 3;
	pola1[6][16] = 4;
	pola1[6][17] = 4;
	pola1[6][18] = 4;
	pola1[6][19] = 4;
	pola1[6][20] = 4;
	pola1[6][21] = 4;
	pola1[6][22] = 4;
	pola1[6][23] = 5;
	pola1[6][24] = 6;
	pola1[6][25] = 7;
	pola1[6][26] = 8;
	pola1[6][27] = 8;
	pola1[6][28] = 8;
	pola1[6][29] = 8;
	pola1[6][30] = 8;
	pola1[6][31] = 8;
	pola1[6][32] = 8;
	pola1[6][33] = 9;
	pola1[6][34] = 10;
	pola1[6][35] = 11;
	pola1[6][36] = 11;
	pola1[6][37] = 11;
	pola1[6][38] = 11;
	pola1[6][39] = 11;
	pola1[6][40] = 10;
	pola1[6][41] = 9;
	pola1[6][42] = 8;
	pola1[6][43] = 8;
	pola1[6][44] = 8;
	pola1[6][45] = 8;
	pola1[6][46] = 8;
	pola1[6][47] = 8;
	pola1[6][48] = 8;
	pola1[6][49] = 7;
	pola1[6][50] = 6;
	pola1[6][51] = 6;
	pola1[6][52] = 6;
	pola1[6][53] = 6;
	pola1[6][54] = 6;

	pola1[7][0] = 1;
	pola1[7][1] = 2;
	pola1[7][2] = 3;
	pola1[7][3] = 4;
	pola1[7][4] = 5;
	pola1[7][5] = 6;
	pola1[7][6] = 7;
	pola1[7][7] = 7;
	pola1[7][8] = 7;
	pola1[7][9] = 7;
	pola1[7][10] = 8;
	pola1[7][11] = 9;
	pola1[7][12] = 10;
	pola1[7][13] = 11;
	pola1[7][14] = 11;
	pola1[7][15] = 11;
	pola1[7][16] = 11;
	pola1[7][17] = 12;
	pola1[7][18] = 13;
	pola1[7][19] = 14;
	pola1[7][20] = 15;
	pola1[7][21] = 16;
	pola1[7][22] = 17;
	pola1[7][23] = 17;
	pola1[7][24] = 17;
	pola1[7][25] = 17;
	pola1[7][26] = 17;
	pola1[7][27] = 16;
	pola1[7][28] = 15;
	pola1[7][29] = 14;
	pola1[7][30] = 13;
	pola1[7][31] = 12;
	pola1[7][32] = 11;
	pola1[7][33] = 11;
	pola1[7][34] = 11;
	pola1[7][35] = 11;
	pola1[7][36] = 10;
	pola1[7][37] = 9;
	pola1[7][38] = 8;
	pola1[7][39] = 7;
	pola1[7][40] = 7;
	pola1[7][41] = 7;
	pola1[7][42] = 7;
	pola1[7][43] = 6;
	pola1[7][44] = 5;
	pola1[7][45] = 4;
	pola1[7][46] = 3;
	pola1[7][47] = 2;
	pola1[7][48] = 1;
	pola1[7][49] = 1;
	pola1[7][50] = 1;
	pola1[7][51] = 2;
	pola1[7][52] = 3;
	pola1[7][53] = 4;
	pola1[7][54] = 5;

	pola1[8][0] = 1;
	pola1[8][1] = 2;
	pola1[8][2] = 3;
	pola1[8][3] = 4;
	pola1[8][4] = 4;
	pola1[8][5] = 4;
	pola1[8][6] = 4;
	pola1[8][7] = 4;
	pola1[8][8] = 4;
	pola1[8][9] = 4;
	pola1[8][10] = 5;
	pola1[8][11] = 6;
	pola1[8][12] = 7;
	pola1[8][13] = 8;
	pola1[8][14] = 8;
	pola1[8][15] = 8;
	pola1[8][16] = 8;
	pola1[8][17] = 8;
	pola1[8][18] = 8;
	pola1[8][19] = 8;
	pola1[8][20] = 9;
	pola1[8][21] = 10;
	pola1[8][22] = 11;
	pola1[8][23] = 11;
	pola1[8][24] = 11;
	pola1[8][25] = 11;
	pola1[8][26] = 11;
	pola1[8][27] = 10;
	pola1[8][28] = 9;
	pola1[8][29] = 8;
	pola1[8][30] = 8;
	pola1[8][31] = 8;
	pola1[8][32] = 8;
	pola1[8][33] = 8;
	pola1[8][34] = 8;
	pola1[8][35] = 8;
	pola1[8][36] = 7;
	pola1[8][37] = 6;
	pola1[8][38] = 5;
	pola1[8][39] = 4;
	pola1[8][40] = 4;
	pola1[8][41] = 4;
	pola1[8][42] = 4;
	pola1[8][43] = 4;
	pola1[8][44] = 4;
	pola1[8][45] = 4;
	pola1[8][46] = 3;
	pola1[8][47] = 2;
	pola1[8][48] = 1;
	pola1[8][49] = 1;
	pola1[8][50] = 1;
	pola1[8][51] = 2;
	pola1[8][52] = 3;
	pola1[8][53] = 4;
	pola1[8][54] = 5;

	pola1[9][0] = 11;
	pola1[9][1] = 11;
	pola1[9][2] = 11;
	pola1[9][3] = 11;
	pola1[9][4] = 12;
	pola1[9][5] = 13;
	pola1[9][6] = 14;
	pola1[9][7] = 15;
	pola1[9][8] = 16;
	pola1[9][9] = 17;
	pola1[9][10] = 17;
	pola1[9][11] = 17;
	pola1[9][12] = 17;
	pola1[9][13] = 17;
	pola1[9][14] = 16;
	pola1[9][15] = 15;
	pola1[9][16] = 14;
	pola1[9][17] = 13;
	pola1[9][18] = 12;
	pola1[9][19] = 11;
	pola1[9][20] = 11;
	pola1[9][21] = 11;
	pola1[9][22] = 11;
	pola1[9][23] = 10;
	pola1[9][24] = 9;
	pola1[9][25] = 8;
	pola1[9][26] = 7;
	pola1[9][27] = 7;
	pola1[9][28] = 7;
	pola1[9][29] = 7;
	pola1[9][30] = 6;
	pola1[9][31] = 5;
	pola1[9][32] = 4;
	pola1[9][33] = 3;
	pola1[9][34] = 2;
	pola1[9][35] = 1;
	pola1[9][36] = 1;
	pola1[9][37] = 1;
	pola1[9][38] = 1;
	pola1[9][39] = 1;
	pola1[9][40] = 2;
	pola1[9][41] = 3;
	pola1[9][42] = 4;
	pola1[9][43] = 5;
	pola1[9][44] = 6;
	pola1[9][45] = 7;
	pola1[9][46] = 7;
	pola1[9][47] = 7;
	pola1[9][48] = 7;
	pola1[9][49] = 8;
	pola1[9][50] = 9;
	pola1[9][51] = 9;
	pola1[9][52] = 9;
	pola1[9][53] = 9;
	pola1[9][54] = 9;

	pola1[10][0] = 1;
	pola1[10][1] = 2;
	pola1[10][2] = 3;
	pola1[10][3] = 4;
	pola1[10][4] = 4;
	pola1[10][5] = 4;
	pola1[10][6] = 4;
	pola1[10][7] = 4;
	pola1[10][8] = 4;
	pola1[10][9] = 4;
	pola1[10][10] = 5;
	pola1[10][11] = 6;
	pola1[10][12] = 7;
	pola1[10][13] = 8;
	pola1[10][14] = 8;
	pola1[10][15] = 8;
	pola1[10][16] = 8;
	pola1[10][17] = 8;
	pola1[10][18] = 8;
	pola1[10][19] = 8;
	pola1[10][20] = 9;
	pola1[10][21] = 10;
	pola1[10][22] = 11;
	pola1[10][23] = 11;
	pola1[10][24] = 11;
	pola1[10][25] = 11;
	pola1[10][26] = 11;
	pola1[10][27] = 10;
	pola1[10][28] = 9;
	pola1[10][29] = 8;
	pola1[10][30] = 8;
	pola1[10][31] = 8;
	pola1[10][32] = 8;
	pola1[10][33] = 8;
	pola1[10][34] = 8;
	pola1[10][35] = 8;
	pola1[10][36] = 7;
	pola1[10][37] = 6;
	pola1[10][38] = 5;
	pola1[10][39] = 4;
	pola1[10][40] = 4;
	pola1[10][41] = 4;
	pola1[10][42] = 4;
	pola1[10][43] = 4;
	pola1[10][44] = 4;
	pola1[10][45] = 4;
	pola1[10][46] = 3;
	pola1[10][47] = 2;
	pola1[10][48] = 1;
	pola1[10][49] = 1;
	pola1[10][50] = 1;
	pola1[10][51] = 2;
	pola1[10][52] = 3;
	pola1[10][53] = 4;
	pola1[10][54] = 5;

	pola1[11][0] = 11;
	pola1[11][1] = 11;
	pola1[11][2] = 11;
	pola1[11][3] = 11;
	pola1[11][4] = 12;
	pola1[11][5] = 13;
	pola1[11][6] = 14;
	pola1[11][7] = 15;
	pola1[11][8] = 16;
	pola1[11][9] = 17;
	pola1[11][10] = 17;
	pola1[11][11] = 17;
	pola1[11][12] = 17;
	pola1[11][13] = 17;
	pola1[11][14] = 16;
	pola1[11][15] = 15;
	pola1[11][16] = 14;
	pola1[11][17] = 13;
	pola1[11][18] = 12;
	pola1[11][19] = 11;
	pola1[11][20] = 11;
	pola1[11][21] = 11;
	pola1[11][22] = 11;
	pola1[11][23] = 10;
	pola1[11][24] = 9;
	pola1[11][25] = 8;
	pola1[11][26] = 7;
	pola1[11][27] = 7;
	pola1[11][28] = 7;
	pola1[11][29] = 7;
	pola1[11][30] = 6;
	pola1[11][31] = 5;
	pola1[11][32] = 4;
	pola1[11][33] = 3;
	pola1[11][34] = 2;
	pola1[11][35] = 1;
	pola1[11][36] = 1;
	pola1[11][37] = 1;
	pola1[11][38] = 1;
	pola1[11][39] = 1;
	pola1[11][40] = 2;
	pola1[11][41] = 3;
	pola1[11][42] = 4;
	pola1[11][43] = 5;
	pola1[11][44] = 6;
	pola1[11][45] = 7;
	pola1[11][46] = 7;
	pola1[11][47] = 7;
	pola1[11][48] = 7;
	pola1[11][49] = 8;
	pola1[11][50] = 9;
	pola1[11][51] = 9;
	pola1[11][52] = 9;
	pola1[11][53] = 9;
	pola1[11][54] = 9;

	pola1[12][0] = 1;
	pola1[12][1] = 2;
	pola1[12][2] = 3;
	pola1[12][3] = 4;
	pola1[12][4] = 4;
	pola1[12][5] = 4;
	pola1[12][6] = 4;
	pola1[12][7] = 4;
	pola1[12][8] = 4;
	pola1[12][9] = 4;
	pola1[12][10] = 5;
	pola1[12][11] = 6;
	pola1[12][12] = 7;
	pola1[12][13] = 8;
	pola1[12][14] = 8;
	pola1[12][15] = 8;
	pola1[12][16] = 8;
	pola1[12][17] = 8;
	pola1[12][18] = 8;
	pola1[12][19] = 8;
	pola1[12][20] = 9;
	pola1[12][21] = 10;
	pola1[12][22] = 11;
	pola1[12][23] = 11;
	pola1[12][24] = 11;
	pola1[12][25] = 11;
	pola1[12][26] = 11;
	pola1[12][27] = 10;
	pola1[12][28] = 9;
	pola1[12][29] = 8;
	pola1[12][30] = 8;
	pola1[12][31] = 8;
	pola1[12][32] = 8;
	pola1[12][33] = 8;
	pola1[12][34] = 8;
	pola1[12][35] = 8;
	pola1[12][36] = 7;
	pola1[12][37] = 6;
	pola1[12][38] = 5;
	pola1[12][39] = 4;
	pola1[12][40] = 4;
	pola1[12][41] = 4;
	pola1[12][42] = 4;
	pola1[12][43] = 4;
	pola1[12][44] = 4;
	pola1[12][45] = 4;
	pola1[12][46] = 3;
	pola1[12][47] = 2;
	pola1[12][48] = 1;
	pola1[12][49] = 1;
	pola1[12][50] = 1;
	pola1[12][51] = 2;
	pola1[12][52] = 3;
	pola1[12][53] = 4;
	pola1[12][54] = 5;

	pola1[13][0] = 11;
	pola1[13][1] = 11;
	pola1[13][2] = 11;
	pola1[13][3] = 11;
	pola1[13][4] = 12;
	pola1[13][5] = 13;
	pola1[13][6] = 14;
	pola1[13][7] = 15;
	pola1[13][8] = 16;
	pola1[13][9] = 17;
	pola1[13][10] = 17;
	pola1[13][11] = 17;
	pola1[13][12] = 17;
	pola1[13][13] = 17;
	pola1[13][14] = 16;
	pola1[13][15] = 15;
	pola1[13][16] = 14;
	pola1[13][17] = 13;
	pola1[13][18] = 12;
	pola1[13][19] = 11;
	pola1[13][20] = 11;
	pola1[13][21] = 11;
	pola1[13][22] = 11;
	pola1[13][23] = 10;
	pola1[13][24] = 9;
	pola1[13][25] = 8;
	pola1[13][26] = 7;
	pola1[13][27] = 7;
	pola1[13][28] = 7;
	pola1[13][29] = 7;
	pola1[13][30] = 6;
	pola1[13][31] = 5;
	pola1[13][32] = 4;
	pola1[13][33] = 3;
	pola1[13][34] = 2;
	pola1[13][35] = 1;
	pola1[13][36] = 1;
	pola1[13][37] = 1;
	pola1[13][38] = 1;
	pola1[13][39] = 1;
	pola1[13][40] = 2;
	pola1[13][41] = 3;
	pola1[13][42] = 4;
	pola1[13][43] = 5;
	pola1[13][44] = 6;
	pola1[13][45] = 7;
	pola1[13][46] = 7;
	pola1[13][47] = 7;
	pola1[13][48] = 7;
	pola1[13][49] = 8;
	pola1[13][50] = 9;
	pola1[13][51] = 9;
	pola1[13][52] = 9;
	pola1[13][53] = 9;
	pola1[13][54] = 9;

	pola1[14][0] = 1;
	pola1[14][1] = 2;
	pola1[14][2] = 3;
	pola1[14][3] = 4;
	pola1[14][4] = 4;
	pola1[14][5] = 4;
	pola1[14][6] = 4;
	pola1[14][7] = 4;
	pola1[14][8] = 4;
	pola1[14][9] = 4;
	pola1[14][10] = 5;
	pola1[14][11] = 6;
	pola1[14][12] = 7;
	pola1[14][13] = 8;
	pola1[14][14] = 8;
	pola1[14][15] = 8;
	pola1[14][16] = 8;
	pola1[14][17] = 8;
	pola1[14][18] = 8;
	pola1[14][19] = 8;
	pola1[14][20] = 9;
	pola1[14][21] = 10;
	pola1[14][22] = 11;
	pola1[14][23] = 11;
	pola1[14][24] = 11;
	pola1[14][25] = 11;
	pola1[14][26] = 11;
	pola1[14][27] = 10;
	pola1[14][28] = 9;
	pola1[14][29] = 8;
	pola1[14][30] = 8;
	pola1[14][31] = 8;
	pola1[14][32] = 8;
	pola1[14][33] = 8;
	pola1[14][34] = 8;
	pola1[14][35] = 8;
	pola1[14][36] = 7;
	pola1[14][37] = 6;
	pola1[14][38] = 5;
	pola1[14][39] = 4;
	pola1[14][40] = 4;
	pola1[14][41] = 4;
	pola1[14][42] = 4;
	pola1[14][43] = 4;
	pola1[14][44] = 4;
	pola1[14][45] = 4;
	pola1[14][46] = 3;
	pola1[14][47] = 2;
	pola1[14][48] = 1;
	pola1[14][49] = 1;
	pola1[14][50] = 1;
	pola1[14][51] = 2;
	pola1[14][52] = 3;
	pola1[14][53] = 4;
	pola1[14][54] = 5;

	pola1[15][0] = 11;
	pola1[15][1] = 11;
	pola1[15][2] = 11;
	pola1[15][3] = 11;
	pola1[15][4] = 12;
	pola1[15][5] = 13;
	pola1[15][6] = 14;
	pola1[15][7] = 15;
	pola1[15][8] = 16;
	pola1[15][9] = 17;
	pola1[15][10] = 17;
	pola1[15][11] = 17;
	pola1[15][12] = 17;
	pola1[15][13] = 17;
	pola1[15][14] = 16;
	pola1[15][15] = 15;
	pola1[15][16] = 14;
	pola1[15][17] = 13;
	pola1[15][18] = 12;
	pola1[15][19] = 11;
	pola1[15][20] = 11;
	pola1[15][21] = 11;
	pola1[15][22] = 11;
	pola1[15][23] = 10;
	pola1[15][24] = 9;
	pola1[15][25] = 8;
	pola1[15][26] = 7;
	pola1[15][27] = 7;
	pola1[15][28] = 7;
	pola1[15][29] = 7;
	pola1[15][30] = 6;
	pola1[15][31] = 5;
	pola1[15][32] = 4;
	pola1[15][33] = 3;
	pola1[15][34] = 2;
	pola1[15][35] = 1;
	pola1[15][36] = 1;
	pola1[15][37] = 1;
	pola1[15][38] = 1;
	pola1[15][39] = 1;
	pola1[15][40] = 2;
	pola1[15][41] = 3;
	pola1[15][42] = 4;
	pola1[15][43] = 5;
	pola1[15][44] = 6;
	pola1[15][45] = 7;
	pola1[15][46] = 7;
	pola1[15][47] = 7;
	pola1[15][48] = 7;
	pola1[15][49] = 8;
	pola1[15][50] = 9;
	pola1[15][51] = 9;
	pola1[15][52] = 9;
	pola1[15][53] = 9;
	pola1[15][54] = 9;

	pola1[16][0] = 8;
	pola1[16][1] = 8;
	pola1[16][2] = 8;
	pola1[16][3] = 8;
	pola1[16][4] = 8;
	pola1[16][5] = 8;
	pola1[16][6] = 8;
	pola1[16][7] = 9;
	pola1[16][8] = 10;
	pola1[16][9] = 11;
	pola1[16][10] = 11;
	pola1[16][11] = 11;
	pola1[16][12] = 11;
	pola1[16][13] = 11;
	pola1[16][14] = 10;
	pola1[16][15] = 9;
	pola1[16][16] = 8;
	pola1[16][17] = 8;
	pola1[16][18] = 8;
	pola1[16][19] = 8;
	pola1[16][20] = 8;
	pola1[16][21] = 8;
	pola1[16][22] = 8;
	pola1[16][23] = 7;
	pola1[16][24] = 6;
	pola1[16][25] = 5;
	pola1[16][26] = 4;
	pola1[16][27] = 4;
	pola1[16][28] = 4;
	pola1[16][29] = 4;
	pola1[16][30] = 4;
	pola1[16][31] = 4;
	pola1[16][32] = 4;
	pola1[16][33] = 3;
	pola1[16][34] = 2;
	pola1[16][35] = 1;
	pola1[16][36] = 1;
	pola1[16][37] = 1;
	pola1[16][38] = 1;
	pola1[16][39] = 1;
	pola1[16][40] = 2;
	pola1[16][41] = 3;
	pola1[16][42] = 4;
	pola1[16][43] = 4;
	pola1[16][44] = 4;
	pola1[16][45] = 4;
	pola1[16][46] = 4;
	pola1[16][47] = 4;
	pola1[16][48] = 4;
	pola1[16][49] = 5;
	pola1[16][50] = 6;
	pola1[16][51] = 6;
	pola1[16][52] = 6;
	pola1[16][53] = 6;
	pola1[16][54] = 6;

	pola1[17][0] = 17;
	pola1[17][1] = 16;
	pola1[17][2] = 15;
	pola1[17][3] = 14;
	pola1[17][4] = 13;
	pola1[17][5] = 12;
	pola1[17][6] = 11;
	pola1[17][7] = 11;
	pola1[17][8] = 11;
	pola1[17][9] = 11;
	pola1[17][10] = 10;
	pola1[17][11] = 9;
	pola1[17][12] = 8;
	pola1[17][13] = 7;
	pola1[17][14] = 7;
	pola1[17][15] = 7;
	pola1[17][16] = 7;
	pola1[17][17] = 6;
	pola1[17][18] = 5;
	pola1[17][19] = 4;
	pola1[17][20] = 3;
	pola1[17][21] = 2;
	pola1[17][22] = 1;
	pola1[17][23] = 1;
	pola1[17][24] = 1;
	pola1[17][25] = 1;
	pola1[17][26] = 1;
	pola1[17][27] = 2;
	pola1[17][28] = 3;
	pola1[17][29] = 4;
	pola1[17][30] = 5;
	pola1[17][31] = 6;
	pola1[17][32] = 7;
	pola1[17][33] = 7;
	pola1[17][34] = 7;
	pola1[17][35] = 7;
	pola1[17][36] = 8;
	pola1[17][37] = 9;
	pola1[17][38] = 10;
	pola1[17][39] = 11;
	pola1[17][40] = 11;
	pola1[17][41] = 11;
	pola1[17][42] = 11;
	pola1[17][43] = 12;
	pola1[17][44] = 13;
	pola1[17][45] = 14;
	pola1[17][46] = 15;
	pola1[17][47] = 16;
	pola1[17][48] = 17;
	pola1[17][49] = 17;
	pola1[17][50] = 17;
	pola1[17][51] = 16;
	pola1[17][52] = 15;
	pola1[17][53] = 14;
	pola1[17][54] = 13;

	pola1[18][0] = 8;
	pola1[18][1] = 8;
	pola1[18][2] = 8;
	pola1[18][3] = 8;
	pola1[18][4] = 8;
	pola1[18][5] = 8;
	pola1[18][6] = 8;
	pola1[18][7] = 9;
	pola1[18][8] = 10;
	pola1[18][9] = 11;
	pola1[18][10] = 11;
	pola1[18][11] = 11;
	pola1[18][12] = 11;
	pola1[18][13] = 11;
	pola1[18][14] = 10;
	pola1[18][15] = 9;
	pola1[18][16] = 8;
	pola1[18][17] = 8;
	pola1[18][18] = 8;
	pola1[18][19] = 8;
	pola1[18][20] = 8;
	pola1[18][21] = 8;
	pola1[18][22] = 8;
	pola1[18][23] = 7;
	pola1[18][24] = 6;
	pola1[18][25] = 5;
	pola1[18][26] = 4;
	pola1[18][27] = 4;
	pola1[18][28] = 4;
	pola1[18][29] = 4;
	pola1[18][30] = 4;
	pola1[18][31] = 4;
	pola1[18][32] = 4;
	pola1[18][33] = 3;
	pola1[18][34] = 2;
	pola1[18][35] = 1;
	pola1[18][36] = 1;
	pola1[18][37] = 1;
	pola1[18][38] = 1;
	pola1[18][39] = 1;
	pola1[18][40] = 2;
	pola1[18][41] = 3;
	pola1[18][42] = 4;
	pola1[18][43] = 4;
	pola1[18][44] = 4;
	pola1[18][45] = 4;
	pola1[18][46] = 4;
	pola1[18][47] = 4;
	pola1[18][48] = 4;
	pola1[18][49] = 5;
	pola1[18][50] = 6;
	pola1[18][51] = 6;
	pola1[18][52] = 6;
	pola1[18][53] = 6;
	pola1[18][54] = 6;

	pola1[19][0] = 17;
	pola1[19][1] = 16;
	pola1[19][2] = 15;
	pola1[19][3] = 14;
	pola1[19][4] = 13;
	pola1[19][5] = 12;
	pola1[19][6] = 11;
	pola1[19][7] = 11;
	pola1[19][8] = 11;
	pola1[19][9] = 11;
	pola1[19][10] = 10;
	pola1[19][11] = 9;
	pola1[19][12] = 8;
	pola1[19][13] = 7;
	pola1[19][14] = 7;
	pola1[19][15] = 7;
	pola1[19][16] = 7;
	pola1[19][17] = 6;
	pola1[19][18] = 5;
	pola1[19][19] = 4;
	pola1[19][20] = 3;
	pola1[19][21] = 2;
	pola1[19][22] = 1;
	pola1[19][23] = 1;
	pola1[19][24] = 1;
	pola1[19][25] = 1;
	pola1[19][26] = 1;
	pola1[19][27] = 2;
	pola1[19][28] = 3;
	pola1[19][29] = 4;
	pola1[19][30] = 5;
	pola1[19][31] = 6;
	pola1[19][32] = 7;
	pola1[19][33] = 7;
	pola1[19][34] = 7;
	pola1[19][35] = 7;
	pola1[19][36] = 8;
	pola1[19][37] = 9;
	pola1[19][38] = 10;
	pola1[19][39] = 11;
	pola1[19][40] = 11;
	pola1[19][41] = 11;
	pola1[19][42] = 11;
	pola1[19][43] = 12;
	pola1[19][44] = 13;
	pola1[19][45] = 14;
	pola1[19][46] = 15;
	pola1[19][47] = 16;
	pola1[19][48] = 17;
	pola1[19][49] = 17;
	pola1[19][50] = 17;
	pola1[19][51] = 16;
	pola1[19][52] = 15;
	pola1[19][53] = 14;
	pola1[19][54] = 13;

	pola1[20][0] = 8;
	pola1[20][1] = 8;
	pola1[20][2] = 8;
	pola1[20][3] = 8;
	pola1[20][4] = 8;
	pola1[20][5] = 8;
	pola1[20][6] = 8;
	pola1[20][7] = 9;
	pola1[20][8] = 10;
	pola1[20][9] = 11;
	pola1[20][10] = 11;
	pola1[20][11] = 11;
	pola1[20][12] = 11;
	pola1[20][13] = 11;
	pola1[20][14] = 10;
	pola1[20][15] = 9;
	pola1[20][16] = 8;
	pola1[20][17] = 8;
	pola1[20][18] = 8;
	pola1[20][19] = 8;
	pola1[20][20] = 8;
	pola1[20][21] = 8;
	pola1[20][22] = 8;
	pola1[20][23] = 7;
	pola1[20][24] = 6;
	pola1[20][25] = 5;
	pola1[20][26] = 4;
	pola1[20][27] = 4;
	pola1[20][28] = 4;
	pola1[20][29] = 4;
	pola1[20][30] = 4;
	pola1[20][31] = 4;
	pola1[20][32] = 4;
	pola1[20][33] = 3;
	pola1[20][34] = 2;
	pola1[20][35] = 1;
	pola1[20][36] = 1;
	pola1[20][37] = 1;
	pola1[20][38] = 1;
	pola1[20][39] = 1;
	pola1[20][40] = 2;
	pola1[20][41] = 3;
	pola1[20][42] = 4;
	pola1[20][43] = 4;
	pola1[20][44] = 4;
	pola1[20][45] = 4;
	pola1[20][46] = 4;
	pola1[20][47] = 4;
	pola1[20][48] = 4;
	pola1[20][49] = 5;
	pola1[20][50] = 6;
	pola1[20][51] = 6;
	pola1[20][52] = 6;
	pola1[20][53] = 6;
	pola1[20][54] = 6;

	pola1[21][0] = 17;
	pola1[21][1] = 16;
	pola1[21][2] = 15;
	pola1[21][3] = 14;
	pola1[21][4] = 13;
	pola1[21][5] = 12;
	pola1[21][6] = 11;
	pola1[21][7] = 11;
	pola1[21][8] = 11;
	pola1[21][9] = 11;
	pola1[21][10] = 10;
	pola1[21][11] = 9;
	pola1[21][12] = 8;
	pola1[21][13] = 7;
	pola1[21][14] = 7;
	pola1[21][15] = 7;
	pola1[21][16] = 7;
	pola1[21][17] = 6;
	pola1[21][18] = 5;
	pola1[21][19] = 4;
	pola1[21][20] = 3;
	pola1[21][21] = 2;
	pola1[21][22] = 1;
	pola1[21][23] = 1;
	pola1[21][24] = 1;
	pola1[21][25] = 1;
	pola1[21][26] = 1;
	pola1[21][27] = 2;
	pola1[21][28] = 3;
	pola1[21][29] = 4;
	pola1[21][30] = 5;
	pola1[21][31] = 6;
	pola1[21][32] = 7;
	pola1[21][33] = 7;
	pola1[21][34] = 7;
	pola1[21][35] = 7;
	pola1[21][36] = 8;
	pola1[21][37] = 9;
	pola1[21][38] = 10;
	pola1[21][39] = 11;
	pola1[21][40] = 11;
	pola1[21][41] = 11;
	pola1[21][42] = 11;
	pola1[21][43] = 12;
	pola1[21][44] = 13;
	pola1[21][45] = 14;
	pola1[21][46] = 15;
	pola1[21][47] = 16;
	pola1[21][48] = 17;
	pola1[21][49] = 17;
	pola1[21][50] = 17;
	pola1[21][51] = 16;
	pola1[21][52] = 15;
	pola1[21][53] = 14;
	pola1[21][54] = 13;

	pola1[22][0] = 11;
	pola1[22][1] = 10;
	pola1[22][2] = 9;
	pola1[22][3] = 8;
	pola1[22][4] = 8;
	pola1[22][5] = 8;
	pola1[22][6] = 8;
	pola1[22][7] = 8;
	pola1[22][8] = 8;
	pola1[22][9] = 8;
	pola1[22][10] = 7;
	pola1[22][11] = 6;
	pola1[22][12] = 5;
	pola1[22][13] = 4;
	pola1[22][14] = 4;
	pola1[22][15] = 4;
	pola1[22][16] = 4;
	pola1[22][17] = 4;
	pola1[22][18] = 4;
	pola1[22][19] = 4;
	pola1[22][20] = 3;
	pola1[22][21] = 2;
	pola1[22][22] = 1;
	pola1[22][23] = 1;
	pola1[22][24] = 1;
	pola1[22][25] = 1;
	pola1[22][26] = 1;
	pola1[22][27] = 2;
	pola1[22][28] = 3;
	pola1[22][29] = 4;
	pola1[22][30] = 4;
	pola1[22][31] = 4;
	pola1[22][32] = 4;
	pola1[22][33] = 4;
	pola1[22][34] = 4;
	pola1[22][35] = 4;
	pola1[22][36] = 5;
	pola1[22][37] = 6;
	pola1[22][38] = 7;
	pola1[22][39] = 8;
	pola1[22][40] = 8;
	pola1[22][41] = 8;
	pola1[22][42] = 8;
	pola1[22][43] = 8;
	pola1[22][44] = 8;
	pola1[22][45] = 8;
	pola1[22][46] = 9;
	pola1[22][47] = 10;
	pola1[22][48] = 11;
	pola1[22][49] = 11;
	pola1[22][50] = 11;
	pola1[22][51] = 10;
	pola1[22][52] = 9;
	pola1[22][53] = 8;
	pola1[22][54] = 7;

	pola1[23][0] = 7;
	pola1[23][1] = 7;
	pola1[23][2] = 7;
	pola1[23][3] = 7;
	pola1[23][4] = 6;
	pola1[23][5] = 5;
	pola1[23][6] = 4;
	pola1[23][7] = 3;
	pola1[23][8] = 2;
	pola1[23][9] = 1;
	pola1[23][10] = 1;
	pola1[23][11] = 1;
	pola1[23][12] = 1;
	pola1[23][13] = 1;
	pola1[23][14] = 2;
	pola1[23][15] = 3;
	pola1[23][16] = 4;
	pola1[23][17] = 5;
	pola1[23][18] = 6;
	pola1[23][19] = 7;
	pola1[23][20] = 7;
	pola1[23][21] = 7;
	pola1[23][22] = 7;
	pola1[23][23] = 8;
	pola1[23][24] = 9;
	pola1[23][25] = 10;
	pola1[23][26] = 11;
	pola1[23][27] = 11;
	pola1[23][28] = 11;
	pola1[23][29] = 11;
	pola1[23][30] = 12;
	pola1[23][31] = 13;
	pola1[23][32] = 14;
	pola1[23][33] = 15;
	pola1[23][34] = 16;
	pola1[23][35] = 17;
	pola1[23][36] = 17;
	pola1[23][37] = 17;
	pola1[23][38] = 17;
	pola1[23][39] = 17;
	pola1[23][40] = 16;
	pola1[23][41] = 15;
	pola1[23][42] = 14;
	pola1[23][43] = 13;
	pola1[23][44] = 12;
	pola1[23][45] = 11;
	pola1[23][46] = 11;
	pola1[23][47] = 11;
	pola1[23][48] = 11;
	pola1[23][49] = 10;
	pola1[23][50] = 9;
	pola1[23][51] = 9;
	pola1[23][52] = 9;
	pola1[23][53] = 9;
	pola1[23][54] = 9;

	pola1[24][0] = 11;
	pola1[24][1] = 10;
	pola1[24][2] = 9;
	pola1[24][3] = 8;
	pola1[24][4] = 8;
	pola1[24][5] = 8;
	pola1[24][6] = 8;
	pola1[24][7] = 8;
	pola1[24][8] = 8;
	pola1[24][9] = 8;
	pola1[24][10] = 7;
	pola1[24][11] = 6;
	pola1[24][12] = 5;
	pola1[24][13] = 4;
	pola1[24][14] = 4;
	pola1[24][15] = 4;
	pola1[24][16] = 4;
	pola1[24][17] = 4;
	pola1[24][18] = 4;
	pola1[24][19] = 4;
	pola1[24][20] = 3;
	pola1[24][21] = 2;
	pola1[24][22] = 1;
	pola1[24][23] = 1;
	pola1[24][24] = 1;
	pola1[24][25] = 1;
	pola1[24][26] = 1;
	pola1[24][27] = 2;
	pola1[24][28] = 3;
	pola1[24][29] = 4;
	pola1[24][30] = 4;
	pola1[24][31] = 4;
	pola1[24][32] = 4;
	pola1[24][33] = 4;
	pola1[24][34] = 4;
	pola1[24][35] = 4;
	pola1[24][36] = 5;
	pola1[24][37] = 6;
	pola1[24][38] = 7;
	pola1[24][39] = 8;
	pola1[24][40] = 8;
	pola1[24][41] = 8;
	pola1[24][42] = 8;
	pola1[24][43] = 8;
	pola1[24][44] = 8;
	pola1[24][45] = 8;
	pola1[24][46] = 9;
	pola1[24][47] = 10;
	pola1[24][48] = 11;
	pola1[24][49] = 11;
	pola1[24][50] = 11;
	pola1[24][51] = 10;
	pola1[24][52] = 9;
	pola1[24][53] = 8;
	pola1[24][54] = 7;

	pola1[25][0] = 7;
	pola1[25][1] = 7;
	pola1[25][2] = 7;
	pola1[25][3] = 7;
	pola1[25][4] = 6;
	pola1[25][5] = 5;
	pola1[25][6] = 4;
	pola1[25][7] = 3;
	pola1[25][8] = 2;
	pola1[25][9] = 1;
	pola1[25][10] = 1;
	pola1[25][11] = 1;
	pola1[25][12] = 1;
	pola1[25][13] = 1;
	pola1[25][14] = 2;
	pola1[25][15] = 3;
	pola1[25][16] = 4;
	pola1[25][17] = 5;
	pola1[25][18] = 6;
	pola1[25][19] = 7;
	pola1[25][20] = 7;
	pola1[25][21] = 7;
	pola1[25][22] = 7;
	pola1[25][23] = 8;
	pola1[25][24] = 9;
	pola1[25][25] = 10;
	pola1[25][26] = 11;
	pola1[25][27] = 11;
	pola1[25][28] = 11;
	pola1[25][29] = 11;
	pola1[25][30] = 12;
	pola1[25][31] = 13;
	pola1[25][32] = 14;
	pola1[25][33] = 15;
	pola1[25][34] = 16;
	pola1[25][35] = 17;
	pola1[25][36] = 17;
	pola1[25][37] = 17;
	pola1[25][38] = 17;
	pola1[25][39] = 17;
	pola1[25][40] = 16;
	pola1[25][41] = 15;
	pola1[25][42] = 14;
	pola1[25][43] = 13;
	pola1[25][44] = 12;
	pola1[25][45] = 11;
	pola1[25][46] = 11;
	pola1[25][47] = 11;
	pola1[25][48] = 11;
	pola1[25][49] = 10;
	pola1[25][50] = 9;
	pola1[25][51] = 9;
	pola1[25][52] = 9;
	pola1[25][53] = 9;
	pola1[25][54] = 9;

	pola1[26][0] = 11;
	pola1[26][1] = 10;
	pola1[26][2] = 9;
	pola1[26][3] = 8;
	pola1[26][4] = 8;
	pola1[26][5] = 8;
	pola1[26][6] = 8;
	pola1[26][7] = 8;
	pola1[26][8] = 8;
	pola1[26][9] = 8;
	pola1[26][10] = 7;
	pola1[26][11] = 6;
	pola1[26][12] = 5;
	pola1[26][13] = 4;
	pola1[26][14] = 4;
	pola1[26][15] = 4;
	pola1[26][16] = 4;
	pola1[26][17] = 4;
	pola1[26][18] = 4;
	pola1[26][19] = 4;
	pola1[26][20] = 3;
	pola1[26][21] = 2;
	pola1[26][22] = 1;
	pola1[26][23] = 1;
	pola1[26][24] = 1;
	pola1[26][25] = 1;
	pola1[26][26] = 1;
	pola1[26][27] = 2;
	pola1[26][28] = 3;
	pola1[26][29] = 4;
	pola1[26][30] = 4;
	pola1[26][31] = 4;
	pola1[26][32] = 4;
	pola1[26][33] = 4;
	pola1[26][34] = 4;
	pola1[26][35] = 4;
	pola1[26][36] = 5;
	pola1[26][37] = 6;
	pola1[26][38] = 7;
	pola1[26][39] = 8;
	pola1[26][40] = 8;
	pola1[26][41] = 8;
	pola1[26][42] = 8;
	pola1[26][43] = 8;
	pola1[26][44] = 8;
	pola1[26][45] = 8;
	pola1[26][46] = 9;
	pola1[26][47] = 10;
	pola1[26][48] = 11;
	pola1[26][49] = 11;
	pola1[26][50] = 11;
	pola1[26][51] = 10;
	pola1[26][52] = 9;
	pola1[26][53] = 8;
	pola1[26][54] = 7;

	pola1[27][0] = 7;
	pola1[27][1] = 7;
	pola1[27][2] = 7;
	pola1[27][3] = 7;
	pola1[27][4] = 6;
	pola1[27][5] = 5;
	pola1[27][6] = 4;
	pola1[27][7] = 3;
	pola1[27][8] = 2;
	pola1[27][9] = 1;
	pola1[27][10] = 1;
	pola1[27][11] = 1;
	pola1[27][12] = 1;
	pola1[27][13] = 1;
	pola1[27][14] = 2;
	pola1[27][15] = 3;
	pola1[27][16] = 4;
	pola1[27][17] = 5;
	pola1[27][18] = 6;
	pola1[27][19] = 7;
	pola1[27][20] = 7;
	pola1[27][21] = 7;
	pola1[27][22] = 7;
	pola1[27][23] = 8;
	pola1[27][24] = 9;
	pola1[27][25] = 10;
	pola1[27][26] = 11;
	pola1[27][27] = 11;
	pola1[27][28] = 11;
	pola1[27][29] = 11;
	pola1[27][30] = 12;
	pola1[27][31] = 13;
	pola1[27][32] = 14;
	pola1[27][33] = 15;
	pola1[27][34] = 16;
	pola1[27][35] = 17;
	pola1[27][36] = 17;
	pola1[27][37] = 17;
	pola1[27][38] = 17;
	pola1[27][39] = 17;
	pola1[27][40] = 16;
	pola1[27][41] = 15;
	pola1[27][42] = 14;
	pola1[27][43] = 13;
	pola1[27][44] = 12;
	pola1[27][45] = 11;
	pola1[27][46] = 11;
	pola1[27][47] = 11;
	pola1[27][48] = 11;
	pola1[27][49] = 10;
	pola1[27][50] = 9;
	pola1[27][51] = 9;
	pola1[27][52] = 9;
	pola1[27][53] = 9;
	pola1[27][54] = 9;

	pola1[28][0] = 11;
	pola1[28][1] = 10;
	pola1[28][2] = 9;
	pola1[28][3] = 8;
	pola1[28][4] = 8;
	pola1[28][5] = 8;
	pola1[28][6] = 8;
	pola1[28][7] = 8;
	pola1[28][8] = 8;
	pola1[28][9] = 8;
	pola1[28][10] = 7;
	pola1[28][11] = 6;
	pola1[28][12] = 5;
	pola1[28][13] = 4;
	pola1[28][14] = 4;
	pola1[28][15] = 4;
	pola1[28][16] = 4;
	pola1[28][17] = 4;
	pola1[28][18] = 4;
	pola1[28][19] = 4;
	pola1[28][20] = 3;
	pola1[28][21] = 2;
	pola1[28][22] = 1;
	pola1[28][23] = 1;
	pola1[28][24] = 1;
	pola1[28][25] = 1;
	pola1[28][26] = 1;
	pola1[28][27] = 2;
	pola1[28][28] = 3;
	pola1[28][29] = 4;
	pola1[28][30] = 4;
	pola1[28][31] = 4;
	pola1[28][32] = 4;
	pola1[28][33] = 4;
	pola1[28][34] = 4;
	pola1[28][35] = 4;
	pola1[28][36] = 5;
	pola1[28][37] = 6;
	pola1[28][38] = 7;
	pola1[28][39] = 8;
	pola1[28][40] = 8;
	pola1[28][41] = 8;
	pola1[28][42] = 8;
	pola1[28][43] = 8;
	pola1[28][44] = 8;
	pola1[28][45] = 8;
	pola1[28][46] = 9;
	pola1[28][47] = 10;
	pola1[28][48] = 11;
	pola1[28][49] = 11;
	pola1[28][50] = 11;
	pola1[28][51] = 10;
	pola1[28][52] = 9;
	pola1[28][53] = 8;
	pola1[28][54] = 7;

	pola1[29][0] = 7;
	pola1[29][1] = 7;
	pola1[29][2] = 7;
	pola1[29][3] = 7;
	pola1[29][4] = 6;
	pola1[29][5] = 5;
	pola1[29][6] = 4;
	pola1[29][7] = 3;
	pola1[29][8] = 2;
	pola1[29][9] = 1;
	pola1[29][10] = 1;
	pola1[29][11] = 1;
	pola1[29][12] = 1;
	pola1[29][13] = 1;
	pola1[29][14] = 2;
	pola1[29][15] = 3;
	pola1[29][16] = 4;
	pola1[29][17] = 5;
	pola1[29][18] = 6;
	pola1[29][19] = 7;
	pola1[29][20] = 7;
	pola1[29][21] = 7;
	pola1[29][22] = 7;
	pola1[29][23] = 8;
	pola1[29][24] = 9;
	pola1[29][25] = 10;
	pola1[29][26] = 11;
	pola1[29][27] = 11;
	pola1[29][28] = 11;
	pola1[29][29] = 11;
	pola1[29][30] = 12;
	pola1[29][31] = 13;
	pola1[29][32] = 14;
	pola1[29][33] = 15;
	pola1[29][34] = 16;
	pola1[29][35] = 17;
	pola1[29][36] = 17;
	pola1[29][37] = 17;
	pola1[29][38] = 17;
	pola1[29][39] = 17;
	pola1[29][40] = 16;
	pola1[29][41] = 15;
	pola1[29][42] = 14;
	pola1[29][43] = 13;
	pola1[29][44] = 12;
	pola1[29][45] = 11;
	pola1[29][46] = 11;
	pola1[29][47] = 11;
	pola1[29][48] = 11;
	pola1[29][49] = 10;
	pola1[29][50] = 9;
	pola1[29][51] = 9;
	pola1[29][52] = 9;
	pola1[29][53] = 9;
	pola1[29][54] = 9;

	pola1[30][0] = 11;
	pola1[30][1] = 10;
	pola1[30][2] = 9;
	pola1[30][3] = 8;
	pola1[30][4] = 8;
	pola1[30][5] = 8;
	pola1[30][6] = 8;
	pola1[30][7] = 8;
	pola1[30][8] = 8;
	pola1[30][9] = 8;
	pola1[30][10] = 7;
	pola1[30][11] = 6;
	pola1[30][12] = 5;
	pola1[30][13] = 4;
	pola1[30][14] = 4;
	pola1[30][15] = 4;
	pola1[30][16] = 4;
	pola1[30][17] = 4;
	pola1[30][18] = 4;
	pola1[30][19] = 4;
	pola1[30][20] = 3;
	pola1[30][21] = 2;
	pola1[30][22] = 1;
	pola1[30][23] = 1;
	pola1[30][24] = 1;
	pola1[30][25] = 1;
	pola1[30][26] = 1;
	pola1[30][27] = 2;
	pola1[30][28] = 3;
	pola1[30][29] = 4;
	pola1[30][30] = 4;
	pola1[30][31] = 4;
	pola1[30][32] = 4;
	pola1[30][33] = 4;
	pola1[30][34] = 4;
	pola1[30][35] = 4;
	pola1[30][36] = 5;
	pola1[30][37] = 6;
	pola1[30][38] = 7;
	pola1[30][39] = 8;
	pola1[30][40] = 8;
	pola1[30][41] = 8;
	pola1[30][42] = 8;
	pola1[30][43] = 8;
	pola1[30][44] = 8;
	pola1[30][45] = 8;
	pola1[30][46] = 9;
	pola1[30][47] = 10;
	pola1[30][48] = 11;
	pola1[30][49] = 11;
	pola1[30][50] = 11;
	pola1[30][51] = 10;
	pola1[30][52] = 9;
	pola1[30][53] = 8;
	pola1[30][54] = 7;

	pola1[31][0] = 7;
	pola1[31][1] = 7;
	pola1[31][2] = 7;
	pola1[31][3] = 7;
	pola1[31][4] = 6;
	pola1[31][5] = 5;
	pola1[31][6] = 4;
	pola1[31][7] = 3;
	pola1[31][8] = 2;
	pola1[31][9] = 1;
	pola1[31][10] = 1;
	pola1[31][11] = 1;
	pola1[31][12] = 1;
	pola1[31][13] = 1;
	pola1[31][14] = 2;
	pola1[31][15] = 3;
	pola1[31][16] = 4;
	pola1[31][17] = 5;
	pola1[31][18] = 6;
	pola1[31][19] = 7;
	pola1[31][20] = 7;
	pola1[31][21] = 7;
	pola1[31][22] = 7;
	pola1[31][23] = 8;
	pola1[31][24] = 9;
	pola1[31][25] = 10;
	pola1[31][26] = 11;
	pola1[31][27] = 11;
	pola1[31][28] = 11;
	pola1[31][29] = 11;
	pola1[31][30] = 12;
	pola1[31][31] = 13;
	pola1[31][32] = 14;
	pola1[31][33] = 15;
	pola1[31][34] = 16;
	pola1[31][35] = 17;
	pola1[31][36] = 17;
	pola1[31][37] = 17;
	pola1[31][38] = 17;
	pola1[31][39] = 17;
	pola1[31][40] = 16;
	pola1[31][41] = 15;
	pola1[31][42] = 14;
	pola1[31][43] = 13;
	pola1[31][44] = 12;
	pola1[31][45] = 11;
	pola1[31][46] = 11;
	pola1[31][47] = 11;
	pola1[31][48] = 11;
	pola1[31][49] = 10;
	pola1[31][50] = 9;
	pola1[31][51] = 9;
	pola1[31][52] = 9;
	pola1[31][53] = 9;
	pola1[31][54] = 9;
}