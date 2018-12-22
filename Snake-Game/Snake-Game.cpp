#include "pch.h"
#include <iostream>

#include <windows.h>
#include <conio.h>
#include <time.h>
#include <thread>
#include <chrono>

enum
{
	ZERO,
	UP,
	DOWN,
	RIGHT,
	LEFT,
};

enum class KEYS_2
{
	ESC = 27,
	W = 87,
	w = 119,
	S = 83,
	s = 115,
	A = 65,
	a = 97,
	D = 68,
	d = 100
};

bool GameOver = false;

int Fruit_Map = 0;

int Number = 4;

int Letter = 2;

int Score = 0;

int Choice = 0;

void setcur(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Fruit(char(&arr)[15][30])
{
	if (Fruit_Map == 0)
	{
		int Fruit_X = 1 + rand() % (14 - 1);

		int Fruit_Y = 1 + rand() % (29 - 1);

		arr[Fruit_X][Fruit_Y] = 'F';

		Fruit_Map++;
	}
	else
	{

	}

}

void Check(char(&arr)[15][30], int L_Let, int L_Num)
{
	if (arr[L_Let][L_Num] == '+' || arr[L_Let][L_Num] == '#')
	{
		GameOver = true;
	}
	else if (arr[L_Let][L_Num] == 'F')
	{
		Score++;
		Fruit_Map--;
	}

	arr[L_Let][L_Num] = '+';
}

void AlwaysMove(char(&arr)[15][30])
{
	if (Choice == UP)
	{
		arr[Letter][Number] = ' ';
		Check(arr, Letter - 1, Number);
		Letter--;
		setcur(0, 0);
	}
	else if (Choice == DOWN)
	{
		arr[Letter][Number] = ' ';
		Check(arr, Letter + 1, Number);
		Letter++;
		setcur(0, 0);
	}
	else if (Choice == LEFT)
	{
		arr[Letter][Number] = ' ';
		Check(arr, Letter, Number - 1);
		Number--;
		setcur(0, 0);
	}
	else if (Choice == RIGHT)
	{
		arr[Letter][Number] = ' ';
		Check(arr, Letter, Number + 1);
		Number++;
		setcur(0, 0);
	}
	else if (Choice == ZERO)
	{
		setcur(0, 0);
	}
}

void arrPrint(char(&arr)[15][30])
{
	std::cout << std::endl;
	std::cout << "               ______________________________ " << std::endl;
	std::cout << "              |           - SNAKE -          |" << std::endl;
	std::cout << "              |______________________________|" << std::endl;
	for (int start = 0; start < 15; start++)
	{
		std::cout << "              |" << arr[start][0] << arr[start][1] << arr[start][2] << arr[start][3] << arr[start][4] << arr[start][5] << arr[start][6] << arr[start][7] << arr[start][8] << arr[start][9];
		std::cout << arr[start][10] << arr[start][11] << arr[start][12] << arr[start][13] << arr[start][14] << arr[start][15] << arr[start][16] << arr[start][17] << arr[start][18] << arr[start][19];
		std::cout << arr[start][20] << arr[start][21] << arr[start][22] << arr[start][23] << arr[start][24] << arr[start][25] << arr[start][26] << arr[start][27] << arr[start][28] << arr[start][29] << "| \n";
	}
	std::cout << "              |______________________________|" << std::endl;
	std::cout << "              |------------------------------|" << std::endl;
	std::cout << "              |   Score: " << Score;
	if (Score < 10)
	{
		std::cout << "                   |" << std::endl;
	}
	else if (Score > 9 && Score < 100)
	{
		std::cout << "                  |" << std::endl;
	}
	else if (Score > 99)
	{
		std::cout << "                 |" << std::endl;
	}

	std::cout << "              |------------------------------|" << std::endl;

	if (Choice == 0)
	{
		std::cout << "              |               W              |" << std::endl;
		std::cout << "              |            A  S  D           |" << std::endl;
	}
	else if (Choice == UP)
	{
		std::cout << "              |               ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "W";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "              |" << std::endl;
		std::cout << "              |            A  S  D           |" << std::endl;
	}
	else if (Choice == DOWN)
	{
		std::cout << "              |               W              |" << std::endl;
		std::cout << "              |            A  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "S";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "  D           |" << std::endl;
	}
	else if (Choice == LEFT)
	{
		std::cout << "              |               W              |" << std::endl;
		std::cout << "              |            ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "A";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "  S  D           |" << std::endl;
	}
	else if (Choice == RIGHT)
	{
		std::cout << "              |               W              |" << std::endl;
		std::cout << "              |            A  S  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "D";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "           |" << std::endl;
	}
	std::cout << "              |------------------------------|" << std::endl;
	std::cout << "              |______________________________|" << std::endl;
	std::cout << "                              ";
}

void Move(char(&arr)[15][30])
{
	if (_kbhit())
	{
		switch (static_cast<KEYS_2>(_getch()))
		{
		case KEYS_2::W:
			Choice = UP;
			break;

		case KEYS_2::w:
			Choice = UP;
			break;

		case KEYS_2::S:
			Choice = DOWN;
			break;

		case KEYS_2::s:
			Choice = DOWN;
			break;

		case KEYS_2::A:
			Choice = LEFT;
			break;

		case KEYS_2::a:
			Choice = LEFT;
			break;

		case KEYS_2::D:
			Choice = RIGHT;
			break;

		case KEYS_2::d:
			Choice = RIGHT;
			break;
		}
	}
}

int main()
{
	srand(time(NULL));

	const int Width = 30;
	const int Height = 15;

	char arr[Height][Width] = { 0 };

	for (int Arr_Height = 0; Arr_Height < 15; Arr_Height++)
	{
		arr[Arr_Height][0] = '#';
		arr[Arr_Height][29] = '#';
	}

	for (int Arr_Width = 1; Arr_Width < 30; Arr_Width++)
	{
		arr[0][Arr_Width] = '#';
		arr[14][Arr_Width] = '#';
	}

	arr[Letter][Number] = '+';

	arrPrint(arr);

	while (!GameOver)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(90));
		Fruit(arr);
		Move(arr);
		AlwaysMove(arr);
		arrPrint(arr);
	}
}