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
	d = 100,
	Enter = 13
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

void Show_WASD()
{
	if (Choice == 0)
	{
		std::cout << "              |                W              |" << std::endl;
		std::cout << "              |             A  S  D           |" << std::endl;
	}
	else if (Choice == UP)
	{
		std::cout << "              |                ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "W";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "              |" << std::endl;
		std::cout << "              |             A  S  D           |" << std::endl;
	}
	else if (Choice == DOWN)
	{
		std::cout << "              |                W              |" << std::endl;
		std::cout << "              |             A  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "S";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "  D           |" << std::endl;
	}
	else if (Choice == LEFT)
	{
		std::cout << "              |                W              |" << std::endl;
		std::cout << "              |             ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "A";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "  S  D           |" << std::endl;
	}
	else if (Choice == RIGHT)
	{
		std::cout << "              |                W              |" << std::endl;
		std::cout << "              |             A  S  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "D";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "           |" << std::endl;
	}
	std::cout << "              |-------------------------------|" << std::endl;
}

void Show_Score()
{
	std::cout << "              |-------------------------------|" << std::endl;
	std::cout << "              |   Score: " << Score;
	if (Score < 10)
	{
		std::cout << "                    |" << std::endl;
	}
	else if (Score > 9 && Score < 100)
	{
		std::cout << "                   |" << std::endl;
	}
	else if (Score > 99)
	{
		std::cout << "                  |" << std::endl;
	}

	std::cout << "              |-------------------------------|" << std::endl;
}

int GameOverScreen()
{

	int GameOverChoice = 1;

GameOver_Sc:

	std::cout << std::endl;
	std::cout << "               _______________________________ " << std::endl;
	std::cout << "              |                               |" << std::endl;
	std::cout << "              |        - S  N  A  K  E -      |" << std::endl;
	std::cout << "              |_______________________________|" << std::endl;
	std::cout << "              |###############################|" << std::endl;
	std::cout << "              |#                             #|" << std::endl;
	std::cout << "              |#                             #|" << std::endl;
	std::cout << "              |#          GAME OVER          #|" << std::endl;
	std::cout << "              |#                             #|" << std::endl;
	std::cout << "              |#                             #|" << std::endl;
	std::cout << "              |#                             #|" << std::endl;
	if (GameOverChoice == 2)
	{
		std::cout << "              |#         Play Again          #|" << std::endl;
	}
	else if (GameOverChoice == 1)
	{
		std::cout << "              |#   - >   Play Again   < -    #|" << std::endl;
	}

	std::cout << "              |#                             #|" << std::endl;
	std::cout << "              |#                             #|" << std::endl;
	if (GameOverChoice == 1)
	{
		std::cout << "              |#            Exit             #|" << std::endl;
	}
	else if (GameOverChoice == 2)
	{
		std::cout << "              |#   - >      Exit       < -   #|" << std::endl;
	}

	std::cout << "              |#                             #|" << std::endl;
	std::cout << "              |#                             #|" << std::endl;
	std::cout << "              |#                             #|" << std::endl;
	std::cout << "              |###############################|" << std::endl;
	std::cout << "              |_______________________________|" << std::endl;
	Show_Score();

	Show_WASD();

	std::cout << "              |_______________________________|" << std::endl;
	std::cout << "                               ";

	while (true)
	{
		if (_kbhit())
		{
			switch (static_cast<KEYS_2>(_getch()))
			{
			case KEYS_2::W:
				GameOverChoice = 1;
				Choice = UP;
				setcur(0, 0);
				goto GameOver_Sc;
				break;

			case KEYS_2::w:
				GameOverChoice = 1;
				Choice = UP;
				setcur(0, 0);
				goto GameOver_Sc;
				break;

			case KEYS_2::S:
				GameOverChoice = 2;
				Choice = DOWN;
				setcur(0, 0);
				goto GameOver_Sc;
				break;

			case KEYS_2::s:
				GameOverChoice = 2;
				Choice = DOWN;
				setcur(0, 0);
				goto GameOver_Sc;
				break;

			case KEYS_2::Enter:
				if (GameOverChoice == 1)
				{
					return 1;
				}
				else if (GameOverChoice == 2)
				{
					return 0;
				}
				break;
			}
		}
	}
}

void Fruit(char(&arr)[15][16])
{
	if (Fruit_Map == 0)
	{
		int Fruit_X = 1 + rand() % (14 - 1);

		int Fruit_Y = 1 + rand() % (15 - 1);

		arr[Fruit_X][Fruit_Y] = 'F';

		Fruit_Map++;
	}
	else
	{

	}

}

void Check(char(&arr)[15][16], int L_Let, int L_Num)
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

void AlwaysMove(char(&arr)[15][16])
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

void arrPrint(char(&arr)[15][16])
{
	std::cout << std::endl;
	std::cout << "               _______________________________ " << std::endl;
	std::cout << "              |                               |" << std::endl;
	std::cout << "              |        - S  N  A  K  E -      |" << std::endl;
	std::cout << "              |_______________________________|" << std::endl;

	for (int start = 0; start < 15; start++)
	{
		std::cout << "              |" << arr[start][0] << " " << arr[start][1] << " " << arr[start][2] << " " << arr[start][3] << " " << arr[start][4] << " " << arr[start][5] << " " << arr[start][6] << " ";
		std::cout << arr[start][7] << " " << arr[start][8] << " " << arr[start][9] << " ";
		std::cout << arr[start][10] << " " << arr[start][11] << " " << arr[start][12] << " " << arr[start][13] << " " << arr[start][14] << " " << arr[start][15] << "| \n";
	}

	std::cout << "              |_______________________________|" << std::endl;

	Show_Score();

	Show_WASD();

	std::cout << "              |_______________________________|" << std::endl;
	std::cout << "                               ";
}

void Move(char(&arr)[15][16])
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

	const int Height = 15;
	const int Width = 16;

Start:

	char arr[Height][Width] = { 0 };

	for (int Arr_Height = 0; Arr_Height < 15; Arr_Height++)
	{
		arr[Arr_Height][0] = '#';
		arr[Arr_Height][15] = '#';
	}

	for (int Arr_Width = 1; Arr_Width < 16; Arr_Width++)
	{
		arr[0][Arr_Width] = '#';
		arr[14][Arr_Width] = '#';
	}

	arr[Letter][Number] = '+';

	arrPrint(arr);

	while (!GameOver)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(120));
		Fruit(arr);
		Move(arr);
		AlwaysMove(arr);
		arrPrint(arr);
	}

	setcur(0, 0);

	if (GameOverScreen() == 1)
	{
		Choice = ZERO;
		GameOver = false;
		Number = 4;
		Letter = 2;
		Fruit_Map = 0;
		Score = 0;
		system("CLS");
		goto Start;
	}
	else
	{
		return 0;
	}
}