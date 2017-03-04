#pragma once
#include"Global.h"
#include<time.h>
#include <iostream>
namespace PYS
{
	int myBoard[BOARD_X][BOARD_Y] = { BoardType::Empty };

	BoardType player = BoardType::White;
	BoardType enemy = BoardType::Black;
	int _x = 12;
	int _y = 13;

	void Recursive(int &x, int &y)
	{


		int randX = rand() % BOARD_X;
		int randY = rand() % BOARD_Y;


		if (myBoard[randX][randY] != BoardType::Empty)
		{
			switch (rand() % 2)
			{
			case 0:
				x += 1;
				break;

			case 1:
				y += 1;
				break;
			default:
				break;
			}

		}
		else
		{
			Recursive(x, y);
		}
	}


	void Attack(int *retX, int * retY)
	{

		int x = 0;
		int y = 0;

		///////////////////////////////////////////////////////////////////////////////////
						//���� ����
		for (int i = 0; i < BOARD_Y; ++i)
		{
			for (int j = 0; j < BOARD_X; ++j)
			{


				if (
					myBoard[j][i] == BoardType::Black &&
					myBoard[j + 1][i] == BoardType::Black &&
					myBoard[j + 2][i] == BoardType::Black)
				{

					// ������ ����
					if (myBoard[j - 1][i] == BoardType::White)
					{

						*retX = j + 3;
						*retY = i;
						myBoard[j][i] = player;
						return;
					}
					else if (
						myBoard[j - 1][i + 1] == BoardType::Black &&
						myBoard[j - 1][i + 2] == BoardType::Black)
					{
						// �Ʒ��� ����
						if (myBoard[j - 1][i - 1] == BoardType::White)
						{
							*retX = j - 1;
							*retY = i + 3;
							myBoard[j][i] = player;
							return;
						}
						// �� ����
						*retX = j - 1;
						*retY = i - 1;
						myBoard[j][i] = player;
						return;

					}
					// ���� ����
					*retX = j - 1;
					*retY = i;
					myBoard[j][i] = player;
					return;

				}

				if (
					myBoard[j][i] == BoardType::Black &&
					myBoard[j][i + 1] == BoardType::Black &&
					myBoard[j][i + 2] == BoardType::Black)
				{
					// �Ʒ��� ����
					if (myBoard[j][i - 1] == BoardType::White)
					{
						*retX = j;
						*retY = i + 3;
						myBoard[j][i] = player;
						return;
					}
					// �� ����
					*retX = j;
					*retY = i - 1;
					myBoard[j][i] = player;
					return;

				}

				if (
					myBoard[j][i] == BoardType::Black &&
					myBoard[j + 1][i + 1] == BoardType::Black &&
					myBoard[j + 2][i + 2] == BoardType::Black
					)
				{
					// �밢�� �Ʒ��� ����
					if (myBoard[j - 1][i - 1] == BoardType::White)
					{
						*retX = j + 3;
						*retY = i + 3;
						myBoard[j][i] = player;
						return;
					}
					//�밢�� ���� ����
					*retX = j - 1;
					*retY = i - 1;
					myBoard[j][i] = player;
					return;
				}

				if (
					myBoard[j][i] == BoardType::Black &&
					myBoard[j + 1][i - 1] == BoardType::Black &&
					myBoard[j + 2][i - 2] == BoardType::Black

					)
				{
					// �밢�� �Ʒ��� ����
					if (myBoard[j - 1][i + 1] == BoardType::White)
					{
						*retX = j + 3;
						*retY = i - 3;
						myBoard[j][i] = player;
						return;
					}
					//�밢�� ���� ����
					*retX = j - 1;
					*retY = i + 1;
					myBoard[j][i] = player;
					return;
				}
			}
		}

		/*
		///////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < BOARD_Y; ++i)
		{
			for (int j = 0; j < BOARD_X; ++j)
			{

				////////////////////////////////����///////////////////////////////////
				// ���� 3�� ���� (���� ����)

				//���� ����
				if (
					myBoard[j][i] == BoardType::Black &&
					myBoard[j][i + 1] == BoardType::Black &&
					myBoard[j][i + 2] == BoardType::Black)
				{
					// �Ʒ��� ����
					if (myBoard[j][i - 1] == BoardType::White)
					{
						*retX = j;
						*retY = i + 3;
						myBoard[j][i] = player;
						return;
					}
					// �� ����
					*retX = j;
					*retY = i - 1;
					myBoard[j][i] = player;
					return;

				}

			}
		}
		// ������ �Ʒ��� �밢�� 3������
		for (int i = 0; i < BOARD_Y; ++i)
		{
			for (int j = 0; j < BOARD_X; ++j)
			{

				if (
					myBoard[j][i] == BoardType::Black &&
					myBoard[j + 1][i + 1] == BoardType::Black &&
					myBoard[j + 2][i + 2] == BoardType::Black
					)
				{
					// �밢�� �Ʒ��� ����
					if (myBoard[j - 1][i - 1] == BoardType::White)
					{
						*retX = j + 3;
						*retY = i + 3;
						myBoard[j][i] = player;
						return;
					}
					//�밢�� ���� ����
					*retX = j - 1;
					*retY = i - 1;
					myBoard[j][i] = player;
					return;
				}

			}
		}
		///////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < BOARD_Y; ++i)
		{
			for (int j = 0; j < BOARD_X; ++j)
			{

				// ���� �Ʒ��� �밢�� ����
				if (
					myBoard[j][i] == BoardType::Black &&
					myBoard[j + 1][i - 1] == BoardType::Black &&
					myBoard[j + 2][i - 2] == BoardType::Black

					)
				{
					// �밢�� �Ʒ��� ����
					if (myBoard[j - 1][i + 1] == BoardType::White)
					{
						*retX = j + 3;
						*retY = i - 3;
						myBoard[j][i] = player;
						return;
					}
					//�밢�� ���� ����
					*retX = j - 1;
					*retY = i + 1;
					myBoard[j][i] = player;
					return;
				}
			}
		}
		///////////////////////////////////////////////////////////////////////////////////


				*/
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				 //////////////////////////////////////////////���� ġ��������... �Ϲ������� �±⸸ �ϴ� �����Ÿ////////////////////////////////



		srand((unsigned)time(NULL));
		Recursive(_x, _y);

		*retX = _x;
		*retY = _y;

		myBoard[_x][_y] = player;
		return;


	}


	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	void Defence(int x, int y)
	{
		_x = x;
		_y = y;
		if (BoardType::White == player)
		{
			myBoard[x][y] = BoardType::Black;
		}
		else
		{
			myBoard[x][y] = BoardType::White;
		}
	}

}