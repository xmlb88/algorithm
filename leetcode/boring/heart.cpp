/************
   By Guhz
  2020.5.10
************/
#include <iostream>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <conio.h>
#define WB "color 70" //WB: White backgroud & Black foregroud
#define WR "color 7C" //WR: White backgroud & Red foregroud
#define unit "* "
#define ESC 27
#define posHeartX 50
#define posHeartY 5
/****************************************************************************************
Color List:

 0=Black  1=Blue 2=Green 3=Ocean blue 4=Red 5=Purple 6=Yellow 7=White 8=Grey 9=Light blue
 A=Light green B=Sky blue C=Light red D=Light purple E=Light yellow F=Bright white

****************************************************************************************/
enum
{
	row = 46,
	col = 47
};
bool Heart[row * col];

void init(void);
void goto_xy(int x, int y);
void illuminate(void); //TODO: Visually illuminate the process of calculating.
void show(void);	   //Show the heart shape as if a drop of red ink in the water.

int main(void)
{
	using std::cin;
	using std::cout;
	int key = 0;

	system(WB); //WB: White backgroud & Black foregroud
	init();
	illuminate();
	cin.get();
	system(WR); //White backgroud & Red foregroud

	while ((key = getch()) && (key != ESC)) //Press ESC to quit.
	{
		system("cls");
		show();
	}

	cout << "\nPress any key to continue.\n";
	cin.get(); //Let everythinig just stop here. Untill you press any key.
	return 0;
}

void init(void)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			Heart[i * col + j] = false;
}

void goto_xy(int x, int y) //定位光标位置到指定坐�?
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(hOut, pos);
}

void illuminate(void)
{
	using std::cout;
	double x, y, leftValue, rightValue;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			x = -1.15 + 0.05 * j;
			y = +1.25 - 0.05 * i;
			leftValue = x * x * y * y * y;
			rightValue = pow(x * x + y * y - 1, 3);

			if (leftValue >= rightValue) //Heart curve: x^2*y^3>=(x^2+y^2-1)^3
			{
				Heart[i * col + j] = true;
				goto_xy(0, 0);
				cout << "v positive " << leftValue << " >= " << rightValue;
				goto_xy(posHeartX + 2 * j, posHeartY + i);
				cout << "|";
			}
			else
			{
				Heart[i * col + j] = false;
				goto_xy(0, 0);
				cout << "x negative " << leftValue << " < " << rightValue;
				goto_xy(posHeartX + 2 * j, posHeartY + i);
				cout << "O";
			}
			Sleep(7);
		}
	}
}

void show(void)
{
	using std::cout;
	int fromWhere;
	int x, y;

	srand((unsigned int)clock()); //Let the random seed depends on time
	do
	{
		fromWhere = rand() % (row * col); //fromWhere: 0~row*col-1
	} while (Heart[fromWhere] == false);

	x = fromWhere / col;
	y = fromWhere % col;

	int Rx, Ry, Rmax;
	Rx = x > (row - 1 - x) ? x : (row - 1 - x);
	Ry = y > (col - 1 - y) ? y : (col - 1 - y);
	Rmax = (int)sqrt(Rx * Rx + Ry * Ry) + 1;

	for (int r = 1; r < Rmax; r++)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if ((((i - x) * (i - x) + (j - y) * (j - y)) < r * r) && Heart[i * col + j]) //In the circle && Be a part of the heart
				{
					goto_xy(posHeartX + 2 * j, posHeartY + i);
					cout << unit;
				}
			}
		}
		Sleep(20);
	}
}