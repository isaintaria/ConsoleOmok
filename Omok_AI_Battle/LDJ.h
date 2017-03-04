#pragma once
#include "Global.h"
#include <time.h>

namespace LDJ
{
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
				if (myBoard[ux][uy] == Enemy && myBoard[ux][uy + 1] == Enemy && myBoard[ux][uy + 2] == Enemy) // �浹�� ���η� 3�� ������ ���
				{
					if (uy + 3 < BOARD_Y && myBoard[ux][uy + 3] == BoardType::Empty)
					{
						*x = ux;
						*y = uy + 3;
						myBoard[ux][uy] = Player;
						return;
					}
					else if (uy - 1 >= 0 && myBoard[ux][uy - 1] == BoardType::Empty)
					{
						*x = ux;
						*y = uy - 1;
						myBoard[ux][uy] = Player;
						return;
					}
				}
				else if (myBoard[ux][uy] == Enemy && myBoard[ux + 1][uy] == Enemy && myBoard[ux + 2][uy] == Enemy) // �浹�� ���η� 3�� ������ ���
				{
					if (ux + 3 < BOARD_X && myBoard[ux + 3][uy] == BoardType::Empty)
					{
						*x = ux + 3;
						*y = uy;
						myBoard[ux][uy] = Player;
						return;
					}
					else if (ux - 1 >= 0 && myBoard[ux - 1][uy] == BoardType::Empty)
					{
						*x = ux - 1;
						*y = uy;
						myBoard[ux][uy] = Player;
						return;
					}
				}
				else if (myBoard[ux][uy] == Enemy && myBoard[ux + 1][uy + 1] == Enemy && myBoard[ux + 2][uy + 2] == Enemy) // �浹�� �»󿡼� ���� �밢������ 3�� ������ ���
				{
					if (myBoard[ux + 3][uy + 3] == BoardType::Empty)
					{
						*x = ux + 3;
						*y = uy + 3;
						myBoard[ux][uy] = Player;
						return;
					}
					else if (myBoard[ux - 1][uy - 1] == BoardType::Empty)
					{
						*x = ux - 1;
						*y = uy - 1;
						myBoard[ux][uy] = Player;
						return;
					}
				}
				else if (myBoard[ux][uy] == Enemy && myBoard[ux - 1][uy + 1] == Enemy && myBoard[ux - 2][uy + 2] == Enemy) // �浹�� ���Ͽ��� ��� �밢������ 3�� ������ ���
				{
					if (myBoard[ux - 3][uy + 3] == BoardType::Empty)
					{
						*x = ux - 3;
						*y = uy + 3;
						myBoard[ux][uy] = Player;
						return;
					}
					else if (myBoard[ux + 1][uy - 1] == BoardType::Empty)
					{
						*x = ux + 1;
						*y = uy - 1;
						myBoard[ux][uy] = Player;
						return;
					}
				}
				else if (myBoard[ux][uy] == Player && myBoard[ux][uy + 1] == Player && myBoard[ux][uy + 2] == Player && myBoard[ux][uy + 3] == Player) // �鵹�� ���η� 4�� ������ ���
				{
					if (myBoard[ux][uy + 4] == BoardType::Empty)
					{
						*x = ux;
						*y = uy + 4;
						myBoard[ux][uy] = Player;
						return;
					}
					else if (myBoard[ux][uy - 1] == BoardType::Empty)
					{
						*x = ux;
						*y = uy - 1;
						myBoard[ux][uy - 1] = Player;
						return;
					}
				}
				else if (myBoard[ux][uy] == Player && myBoard[ux + 1][uy] == Player && myBoard[ux + 2][uy] == Player && myBoard[ux + 3][uy] == Player) // �鵹�� ���η� 4�� ������ ���
				{
					if (myBoard[ux + 4][uy] == BoardType::Empty)
					{
						*x = ux + 4;
						*y = uy;
						myBoard[ux][uy] = Player;
						return;
					}
					else if (myBoard[ux - 1][uy] == BoardType::Empty)
					{
						*x = ux - 1;
						*y = uy;
						myBoard[ux - 1][uy] = Player;
						return;
					}
				}
				else if (myBoard[ux][uy] == Player && myBoard[ux + 1][uy + 1] == Player && myBoard[ux + 2][uy + 2] == Player && myBoard[ux + 3][uy + 3] == Player) // �鵹�� �»󿡼� ���� �밢������ 4�� ������ ���
				{
					if (myBoard[ux + 4][uy + 4] == BoardType::Empty)
					{
						*x = ux + 4;
						*y = uy + 4;
						myBoard[ux][uy] = Player;
						return;
					}
					else if (myBoard[ux - 1][uy - 1] == BoardType::Empty)
					{
						*x = ux - 1;
						*y = uy - 1;
						myBoard[ux - 1][uy - 1] = Player;
						return;
					}
				}
				else if (myBoard[ux][uy] == Player && myBoard[ux - 1][uy + 1] == Player && myBoard[ux - 2][uy + 2] == Player && myBoard[ux - 3][uy + 3] == Player) // �鵹�� ���Ͽ��� ��� �밢������ 4�� ������ ���
				{
					if (myBoard[ux - 4][uy + 4] == BoardType::Empty)
					{
						*x = ux - 4;
						*y = uy + 4;
						myBoard[ux][uy] = Player;
						return;
					}
					else if (myBoard[ux + 1][uy - 1] == BoardType::Empty)
					{
						*x = ux + 1;
						*y = uy - 1;
						myBoard[ux + 1][uy - 1] = Player;
						return;
					}
				}
			}
		}

		int _x = 0;
		int _y = 0;

		srand((unsigned)time(NULL));

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
}