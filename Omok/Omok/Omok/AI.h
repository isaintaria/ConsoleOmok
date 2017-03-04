#pragma once
#include "Globar.h"

int myBoard[BOARD_X][BOARD_Y] = { BoardType::Empty };

BoardType Player = BoardType::White;
BoardType Enemy = BoardType::Black;

void Recursive(int &x, int &y)
{
	int randX = rand() % BOARD_X;
	int randY = rand() % BOARD_Y;

	if (myBoard[randX][randX] == BoardType::Empty)
	{
		x = randX;
		y = randY;
	}
	else
	{
		Recursive(x, y);
	}
}

void Attack(int *x, int *y)
{
	for (int ux = 0; ux < BOARD_X; ux++)
	{
		for (int uy = 0; uy < BOARD_Y; uy++)
		{
			if (myBoard[ux][uy] == Enemy && myBoard[ux][uy + 1] == Enemy && myBoard[ux][uy + 2] == Enemy)
			{
				if (myBoard[ux][uy + 3] == BoardType::Empty)
				{
					if (myBoard[ux][uy - 1] == BoardType::Empty)
					{
						*x = ux;
						*y = uy - 1;

						myBoard[ux][uy] = Player;
						return;
					}

					*x = ux;
					*y = uy + 3;

					myBoard[ux][uy] = Player;
					return;
				}
			}
		}
	}

	int _x = 0;
	int _y = 0;

	Recursive(_x, _y);

	*x = _x;
	*y = _y;

	myBoard[_x][_y] = Player;
}

void Defence(int x, int y)
{
	if (BoardType::White == Player)
	{
		myBoard[x][y] = BoardType::Black;
	}
	else
	{
		myBoard[x][y] = BoardType::White;
	}
}