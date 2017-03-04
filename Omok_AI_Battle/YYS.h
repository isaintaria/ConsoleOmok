#pragma once
#include "Global.h"

namespace YYS
{

	int myOmok[BOARD_X][BOARD_Y] = { BoardType::Empty };

	BoardType myTeam = BoardType::Black;
	BoardType enemy = BoardType::White;

	void Attack(int *x, int *y)
	{
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{	//내돌 연속 4개.
				if (myOmok[i][j] == BoardType::Empty
					&& (myOmok[i + 1][j] == myTeam && myOmok[i + 2][j] == myTeam && myOmok[i + 3][j] == myTeam && myOmok[i + 4][j] == myTeam
						|| myOmok[i - 1][j] == myTeam && myOmok[i - 2][j] == myTeam && myOmok[i - 3][j] == myTeam && myOmok[i - 4][j] == myTeam
						|| myOmok[i][j + 1] == myTeam && myOmok[i][j + 2] == myTeam && myOmok[i][j + 3] == myTeam && myOmok[i][j + 4] == myTeam
						|| myOmok[i][j - 1] == myTeam && myOmok[i][j - 2] == myTeam && myOmok[i][j - 3] == myTeam && myOmok[i][j - 4] == myTeam
						|| myOmok[i - 1][j + 1] == myTeam && myOmok[i - 2][j + 2] == myTeam && myOmok[i - 3][j + 3] == myTeam && myOmok[i - 4][j + 4] == myTeam
						|| myOmok[i + 1][j + 1] == myTeam && myOmok[i + 2][j + 2] == myTeam && myOmok[i + 3][j + 3] == myTeam && myOmok[i + 4][j + 4] == myTeam
						|| myOmok[i - 1][j - 1] == myTeam && myOmok[i - 2][j - 2] == myTeam && myOmok[i - 3][j - 3] == myTeam && myOmok[i - 4][j - 4] == myTeam
						|| myOmok[i + 1][j - 1] == myTeam && myOmok[i + 2][j - 2] == myTeam && myOmok[i + 3][j - 3] == myTeam && myOmok[i + 4][j - 4] == myTeam))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{	//내돌 띄어서 4개.
				if (myOmok[i][j] == BoardType::Empty
					&& (myOmok[i + 1][j] == myTeam && myOmok[i + 2][j] == myTeam && myOmok[i + 3][j] == myTeam && myOmok[i - 1][j] == myTeam
						|| myOmok[i - 1][j] == myTeam && myOmok[i - 2][j] == myTeam && myOmok[i - 3][j] == myTeam && myOmok[i + 1][j] == myTeam
						|| myOmok[i][j + 1] == myTeam && myOmok[i][j + 2] == myTeam && myOmok[i][j + 3] == myTeam && myOmok[i][j - 1] == myTeam
						|| myOmok[i][j - 1] == myTeam && myOmok[i][j - 2] == myTeam && myOmok[i][j - 3] == myTeam && myOmok[i][j + 1] == myTeam
						|| myOmok[i][j + 1] == myTeam && myOmok[i][j + 2] == myTeam && myOmok[i][j - 2] == myTeam && myOmok[i][j - 1] == myTeam
						|| myOmok[i][j - 1] == myTeam && myOmok[i][j - 2] == myTeam && myOmok[i][j + 2] == myTeam && myOmok[i][j + 1] == myTeam
						|| myOmok[i - 1][j + 1] == myTeam && myOmok[i - 2][j + 2] == myTeam && myOmok[i - 3][j + 3] == myTeam && myOmok[i + 1][j - 1] == myTeam
						|| myOmok[i + 1][j + 1] == myTeam && myOmok[i + 2][j + 2] == myTeam && myOmok[i + 3][j + 3] == myTeam && myOmok[i - 1][j - 1] == myTeam
						|| myOmok[i - 1][j - 1] == myTeam && myOmok[i - 2][j - 2] == myTeam && myOmok[i - 3][j - 3] == myTeam && myOmok[i + 1][j + 1] == myTeam
						|| myOmok[i + 1][j - 1] == myTeam && myOmok[i + 2][j - 2] == myTeam && myOmok[i + 3][j - 3] == myTeam && myOmok[i - 1][j + 1] == myTeam
						|| myOmok[i - 1][j + 1] == myTeam && myOmok[i - 2][j + 2] == myTeam && myOmok[i + 2][j - 2] == myTeam && myOmok[i + 1][j - 1] == myTeam
						|| myOmok[i + 1][j + 1] == myTeam && myOmok[i + 2][j + 2] == myTeam && myOmok[i - 2][j - 2] == myTeam && myOmok[i - 1][j - 1] == myTeam))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{	//적돌 연속 4개.
				if (myOmok[i][j] == BoardType::Empty
					&& (myOmok[i + 1][j] == enemy && myOmok[i + 2][j] == enemy && myOmok[i + 3][j] == enemy && myOmok[i + 4][j] == enemy
						|| myOmok[i - 1][j] == enemy && myOmok[i - 2][j] == enemy && myOmok[i - 3][j] == enemy && myOmok[i - 4][j] == enemy
						|| myOmok[i][j + 1] == enemy && myOmok[i][j + 2] == enemy && myOmok[i][j + 3] == enemy && myOmok[i][j + 4] == enemy
						|| myOmok[i][j - 1] == enemy && myOmok[i][j - 2] == enemy && myOmok[i][j - 3] == enemy && myOmok[i][j - 4] == enemy
						|| myOmok[i - 1][j + 1] == enemy && myOmok[i - 2][j + 2] == enemy && myOmok[i - 3][j + 3] == enemy && myOmok[i - 4][j + 4] == enemy
						|| myOmok[i + 1][j + 1] == enemy && myOmok[i + 2][j + 2] == enemy && myOmok[i + 3][j + 3] == enemy && myOmok[i + 4][j + 4] == enemy
						|| myOmok[i - 1][j - 1] == enemy && myOmok[i - 2][j - 2] == enemy && myOmok[i - 3][j - 3] == enemy && myOmok[i - 4][j - 4] == enemy
						|| myOmok[i + 1][j - 1] == enemy && myOmok[i + 2][j - 2] == enemy && myOmok[i + 3][j - 3] == enemy && myOmok[i + 4][j - 4] == enemy))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{	//적돌 띄어서 4개.
				if (myOmok[i][j] == BoardType::Empty
					&& (myOmok[i + 1][j] == enemy && myOmok[i + 2][j] == enemy && myOmok[i + 3][j] == enemy && myOmok[i - 1][j] == enemy
						|| myOmok[i - 1][j] == enemy && myOmok[i - 2][j] == enemy && myOmok[i - 3][j] == enemy && myOmok[i + 1][j] == enemy
						|| myOmok[i][j + 1] == enemy && myOmok[i][j + 2] == enemy && myOmok[i][j + 3] == enemy && myOmok[i][j - 1] == enemy
						|| myOmok[i][j - 1] == enemy && myOmok[i][j - 2] == enemy && myOmok[i][j - 3] == enemy && myOmok[i][j + 1] == enemy
						|| myOmok[i][j + 1] == enemy && myOmok[i][j + 2] == enemy && myOmok[i][j - 2] == enemy && myOmok[i][j - 1] == enemy
						|| myOmok[i][j - 1] == enemy && myOmok[i][j - 2] == enemy && myOmok[i][j + 2] == enemy && myOmok[i][j + 1] == enemy
						|| myOmok[i - 1][j + 1] == enemy && myOmok[i - 2][j + 2] == enemy && myOmok[i - 3][j + 3] == enemy && myOmok[i + 1][j - 1] == enemy
						|| myOmok[i + 1][j + 1] == enemy && myOmok[i + 2][j + 2] == enemy && myOmok[i + 3][j + 3] == enemy && myOmok[i - 1][j - 1] == enemy
						|| myOmok[i - 1][j - 1] == enemy && myOmok[i - 2][j - 2] == enemy && myOmok[i - 3][j - 3] == enemy && myOmok[i + 1][j + 1] == enemy
						|| myOmok[i + 1][j - 1] == enemy && myOmok[i + 2][j - 2] == enemy && myOmok[i + 3][j - 3] == enemy && myOmok[i - 1][j + 1] == enemy
						|| myOmok[i - 1][j + 1] == enemy && myOmok[i - 2][j + 2] == enemy && myOmok[i + 2][j - 2] == enemy && myOmok[i + 1][j - 1] == enemy
						|| myOmok[i + 1][j + 1] == enemy && myOmok[i + 2][j + 2] == enemy && myOmok[i - 2][j - 2] == enemy && myOmok[i - 1][j - 1] == enemy))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{	//내돌 연속 3개.
				if (myOmok[i][j] == BoardType::Empty
					&& (myOmok[i + 1][j] == myTeam && myOmok[i + 2][j] == myTeam && myOmok[i + 3][j] == myTeam && myOmok[i - 1][j] == BoardType::Empty
						|| myOmok[i - 1][j] == myTeam && myOmok[i - 2][j] == myTeam && myOmok[i - 3][j] == myTeam && myOmok[i + 1][j] == BoardType::Empty
						|| myOmok[i][j + 1] == myTeam && myOmok[i][j + 2] == myTeam && myOmok[i][j + 3] == myTeam && myOmok[i][j - 1] == BoardType::Empty
						|| myOmok[i][j - 1] == myTeam && myOmok[i][j - 2] == myTeam && myOmok[i][j - 3] == myTeam && myOmok[i][j + 1] == BoardType::Empty
						|| myOmok[i - 1][j + 1] == myTeam && myOmok[i - 2][j + 2] == myTeam && myOmok[i - 3][j + 3] == myTeam && myOmok[i + 1][j - 1] == BoardType::Empty
						|| myOmok[i + 1][j + 1] == myTeam && myOmok[i + 2][j + 2] == myTeam && myOmok[i + 3][j + 3] == myTeam && myOmok[i - 1][j - 1] == BoardType::Empty
						|| myOmok[i - 1][j - 1] == myTeam && myOmok[i - 2][j - 2] == myTeam && myOmok[i - 3][j - 3] == myTeam && myOmok[i + 1][j + 1] == BoardType::Empty
						|| myOmok[i + 1][j - 1] == myTeam && myOmok[i + 2][j - 2] == myTeam && myOmok[i + 3][j - 3] == myTeam && myOmok[i - 1][j + 1] == BoardType::Empty))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{	//내돌 띄어서 3개.
				if (myOmok[i][j] == BoardType::Empty
					&& (myOmok[i + 1][j] == myTeam && myOmok[i + 2][j] == myTeam && (myOmok[i + 3][j] == BoardType::Empty || myOmok[i - 2][j] == BoardType::Empty) && myOmok[i - 1][j] == myTeam
						|| myOmok[i - 1][j] == myTeam && myOmok[i - 2][j] == myTeam && (myOmok[i - 3][j] == BoardType::Empty || myOmok[i + 2][j] == BoardType::Empty) && myOmok[i + 1][j] == myTeam
						|| myOmok[i][j + 1] == myTeam && myOmok[i][j + 2] == myTeam && (myOmok[i][j + 3] == BoardType::Empty || myOmok[i][j - 2] == BoardType::Empty) && myOmok[i][j - 1] == myTeam
						|| myOmok[i][j - 1] == myTeam && myOmok[i][j - 2] == myTeam && (myOmok[i][j - 3] == BoardType::Empty || myOmok[i][j + 2] == BoardType::Empty) && myOmok[i][j + 1] == myTeam
						|| myOmok[i - 1][j + 1] == myTeam && myOmok[i - 2][j + 2] == myTeam && (myOmok[i - 3][j + 3] == BoardType::Empty || myOmok[i + 2][j - 2] == BoardType::Empty) && myOmok[i + 1][j - 1] == myTeam
						|| myOmok[i + 1][j + 1] == myTeam && myOmok[i + 2][j + 2] == myTeam && (myOmok[i + 3][j + 3] == BoardType::Empty || myOmok[i - 2][j - 2] == BoardType::Empty) && myOmok[i - 1][j - 1] == myTeam
						|| myOmok[i - 1][j - 1] == myTeam && myOmok[i - 2][j - 2] == myTeam && (myOmok[i - 3][j - 3] == BoardType::Empty || myOmok[i + 2][j + 2] == BoardType::Empty) && myOmok[i + 1][j + 1] == myTeam
						|| myOmok[i + 1][j - 1] == myTeam && myOmok[i + 2][j - 2] == myTeam && (myOmok[i + 3][j - 3] == BoardType::Empty || myOmok[i - 2][j + 2] == BoardType::Empty) && myOmok[i - 1][j + 1] == myTeam))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{	//적돌 띄어서 3개
				if (myOmok[i][j] == BoardType::Empty
					&& (myOmok[i + 1][j] == enemy && myOmok[i + 2][j] == enemy && myOmok[i + 3][j] == BoardType::Empty && myOmok[i - 2][j] == BoardType::Empty && myOmok[i - 1][j] == enemy
						|| myOmok[i - 1][j] == enemy && myOmok[i - 2][j] == enemy && myOmok[i - 3][j] == BoardType::Empty && myOmok[i + 2][j] == BoardType::Empty && myOmok[i + 1][j] == enemy
						|| myOmok[i][j + 1] == enemy && myOmok[i][j + 2] == enemy && myOmok[i][j + 3] == BoardType::Empty && myOmok[i][j - 2] == BoardType::Empty && myOmok[i][j - 1] == enemy
						|| myOmok[i][j - 1] == enemy && myOmok[i][j - 2] == enemy && myOmok[i][j - 3] == BoardType::Empty && myOmok[i][j + 2] == BoardType::Empty && myOmok[i][j + 1] == enemy
						|| myOmok[i - 1][j + 1] == enemy && myOmok[i - 2][j + 2] == enemy && myOmok[i - 3][j + 3] == BoardType::Empty && myOmok[i + 2][j - 2] == BoardType::Empty && myOmok[i + 1][j - 1] == enemy
						|| myOmok[i + 1][j + 1] == enemy && myOmok[i + 2][j + 2] == enemy && myOmok[i + 3][j + 3] == BoardType::Empty && myOmok[i - 2][j - 2] == BoardType::Empty && myOmok[i - 1][j - 1] == enemy
						|| myOmok[i - 1][j - 1] == enemy && myOmok[i - 2][j - 2] == enemy && myOmok[i - 3][j - 3] == BoardType::Empty && myOmok[i + 2][j + 2] == BoardType::Empty && myOmok[i + 1][j + 1] == enemy
						|| myOmok[i + 1][j - 1] == enemy && myOmok[i + 2][j - 2] == enemy && myOmok[i + 3][j - 3] == BoardType::Empty && myOmok[i - 2][j + 2] == BoardType::Empty && myOmok[i - 1][j + 1] == enemy))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{	//적돌 연속 3개.
				if (myOmok[i][j] == BoardType::Empty
					&& (myOmok[i + 1][j] == enemy && myOmok[i + 2][j] == enemy && myOmok[i + 3][j] == enemy && myOmok[i + 4][j] == BoardType::Empty
						|| myOmok[i - 1][j] == enemy && myOmok[i - 2][j] == enemy && myOmok[i - 3][j] == enemy && myOmok[i - 4][j] == BoardType::Empty
						|| myOmok[i][j + 1] == enemy && myOmok[i][j + 2] == enemy && myOmok[i][j + 3] == enemy && myOmok[i][j + 4] == BoardType::Empty
						|| myOmok[i][j - 1] == enemy && myOmok[i][j - 2] == enemy && myOmok[i][j - 3] == enemy && myOmok[i][j - 4] == BoardType::Empty
						|| myOmok[i - 1][j + 1] == enemy && myOmok[i - 2][j + 2] == enemy && myOmok[i - 3][j + 3] == enemy && myOmok[i - 4][j + 4] == BoardType::Empty
						|| myOmok[i + 1][j + 1] == enemy && myOmok[i + 2][j + 2] == enemy && myOmok[i + 3][j + 3] == enemy && myOmok[i + 4][j + 4] == BoardType::Empty
						|| myOmok[i - 1][j - 1] == enemy && myOmok[i - 2][j - 2] == enemy && myOmok[i - 3][j - 3] == enemy && myOmok[i - 4][j - 4] == BoardType::Empty
						|| myOmok[i + 1][j - 1] == enemy && myOmok[i + 2][j - 2] == enemy && myOmok[i + 3][j - 3] == enemy && myOmok[i + 4][j - 4] == BoardType::Empty))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{	//내돌 연속 두개 띄어서 공격.
				if ((myOmok[i][j] == BoardType::Empty
					&& (myOmok[i + 1][j] == BoardType::Empty && myOmok[i + 2][j] == myTeam && myOmok[i + 3][j] == myTeam && myOmok[i + 4][j] == BoardType::Empty && myOmok[i - 1][j] == BoardType::Empty
						|| myOmok[i - 1][j] == BoardType::Empty && myOmok[i - 2][j] == myTeam && myOmok[i - 3][j] == myTeam && myOmok[i - 4][j] == BoardType::Empty && myOmok[i + 1][j] == BoardType::Empty
						|| myOmok[i][j + 1] == BoardType::Empty && myOmok[i][j + 2] == myTeam && myOmok[i][j + 3] == myTeam && myOmok[i][j + 4] == BoardType::Empty && myOmok[i][j - 1] == BoardType::Empty
						|| myOmok[i][j - 1] == BoardType::Empty && myOmok[i][j - 2] == myTeam && myOmok[i][j - 3] == myTeam && myOmok[i][j - 4] == BoardType::Empty && myOmok[i][j + 1] == BoardType::Empty
						|| myOmok[i - 1][j + 1] == BoardType::Empty && myOmok[i - 2][j + 2] == myTeam && myOmok[i - 3][j + 3] == myTeam && myOmok[i - 4][j + 4] == BoardType::Empty && myOmok[i + 1][j - 1] == BoardType::Empty
						|| myOmok[i + 1][j + 1] == BoardType::Empty && myOmok[i + 2][j + 2] == myTeam && myOmok[i + 3][j + 3] == myTeam && myOmok[i + 4][j + 4] == BoardType::Empty && myOmok[i - 1][j - 1] == BoardType::Empty
						|| myOmok[i - 1][j - 1] == BoardType::Empty && myOmok[i - 2][j - 2] == myTeam && myOmok[i - 3][j - 3] == myTeam && myOmok[i - 4][j - 4] == BoardType::Empty && myOmok[i + 1][j + 1] == BoardType::Empty
						|| myOmok[i + 1][j - 1] == BoardType::Empty && myOmok[i + 2][j - 2] == myTeam && myOmok[i + 3][j - 3] == myTeam && myOmok[i + 4][j - 4] == BoardType::Empty && myOmok[i - 1][j + 1] == BoardType::Empty))
					|| (myOmok[i][j] == BoardType::Empty
						&& (myOmok[i + 1][j] == myTeam && myOmok[i + 2][j] == myTeam && myOmok[i + 3][j] == BoardType::Empty && myOmok[i - 1][j] == BoardType::Empty
							|| myOmok[i - 1][j] == myTeam && myOmok[i - 2][j] == myTeam && myOmok[i - 3][j] == BoardType::Empty && myOmok[i + 1][j] == BoardType::Empty
							|| myOmok[i][j + 1] == myTeam && myOmok[i][j + 2] == myTeam && myOmok[i][j + 3] == BoardType::Empty && myOmok[i][j - 1] == BoardType::Empty
							|| myOmok[i][j - 1] == myTeam && myOmok[i][j - 2] == myTeam && myOmok[i][j - 3] == BoardType::Empty && myOmok[i][j + 1] == BoardType::Empty
							|| myOmok[i - 1][j + 1] == myTeam && myOmok[i - 2][j + 2] == myTeam && myOmok[i - 3][j + 3] == BoardType::Empty && myOmok[i + 1][j - 1] == BoardType::Empty
							|| myOmok[i + 1][j + 1] == myTeam && myOmok[i + 2][j + 2] == myTeam && myOmok[i + 3][j + 3] == BoardType::Empty && myOmok[i - 1][j - 1] == BoardType::Empty
							|| myOmok[i - 1][j - 1] == myTeam && myOmok[i - 2][j - 2] == myTeam && myOmok[i - 3][j - 3] == BoardType::Empty && myOmok[i + 1][j + 1] == BoardType::Empty
							|| myOmok[i + 1][j - 1] == myTeam && myOmok[i + 2][j - 2] == myTeam && myOmok[i + 3][j - 3] == BoardType::Empty && myOmok[i - 1][j + 1] == BoardType::Empty)))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{	//내돌 띄어서 2개.
				if (myOmok[i][j] == BoardType::Empty
					&& (myOmok[i + 1][j] == myTeam && myOmok[i + 2][j] == BoardType::Empty && myOmok[i + 3][j] == myTeam && myOmok[i + 4][j] == BoardType::Empty && myOmok[i - 1][j] == BoardType::Empty
						|| myOmok[i - 1][j] == myTeam && myOmok[i - 2][j] == BoardType::Empty && myOmok[i - 3][j] == myTeam && myOmok[i - 4][j] == BoardType::Empty && myOmok[i + 1][j] == BoardType::Empty
						|| myOmok[i][j + 1] == myTeam && myOmok[i][j + 2] == BoardType::Empty && myOmok[i][j + 3] == myTeam && myOmok[i][j + 4] == BoardType::Empty && myOmok[i][j - 1] == BoardType::Empty
						|| myOmok[i][j - 1] == myTeam && myOmok[i][j - 2] == BoardType::Empty && myOmok[i][j - 3] == myTeam && myOmok[i][j - 4] == BoardType::Empty && myOmok[i][j + 1] == BoardType::Empty
						|| myOmok[i - 1][j + 1] == myTeam && myOmok[i - 2][j + 2] == BoardType::Empty && myOmok[i - 3][j + 3] == BoardType::Empty && myOmok[i - 4][j + 4] == BoardType::Empty && myOmok[i + 1][j - 1] == enemy
						|| myOmok[i + 1][j + 1] == myTeam && myOmok[i + 2][j + 2] == BoardType::Empty && myOmok[i + 3][j + 3] == BoardType::Empty && myOmok[i + 4][j + 4] == BoardType::Empty && myOmok[i - 1][j - 1] == enemy
						|| myOmok[i - 1][j - 1] == myTeam && myOmok[i - 2][j - 2] == BoardType::Empty && myOmok[i - 3][j - 3] == BoardType::Empty && myOmok[i - 4][j - 4] == BoardType::Empty && myOmok[i + 1][j + 1] == enemy
						|| myOmok[i + 1][j - 1] == myTeam && myOmok[i + 2][j - 2] == BoardType::Empty && myOmok[i + 3][j - 3] == BoardType::Empty && myOmok[i + 4][j - 4] == BoardType::Empty && myOmok[i - 1][j + 1] == enemy))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{	//내돌 연속 두개.
				if (myOmok[i][j] == BoardType::Empty
					&& (myOmok[i + 1][j] == myTeam && myOmok[i + 2][j] == myTeam && myOmok[i + 3][j] == BoardType::Empty && myOmok[i - 1][j] == BoardType::Empty
						|| myOmok[i - 1][j] == myTeam && myOmok[i - 2][j] == myTeam && myOmok[i - 3][j] == BoardType::Empty && myOmok[i + 1][j] == BoardType::Empty
						|| myOmok[i][j + 1] == myTeam && myOmok[i][j + 2] == myTeam && myOmok[i][j + 3] == BoardType::Empty && myOmok[i][j - 1] == BoardType::Empty
						|| myOmok[i][j - 1] == myTeam && myOmok[i][j - 2] == myTeam && myOmok[i][j - 3] == BoardType::Empty && myOmok[i][j + 1] == BoardType::Empty
						|| myOmok[i - 1][j + 1] == myTeam && myOmok[i - 2][j + 2] == myTeam && myOmok[i - 3][j + 3] == BoardType::Empty && myOmok[i + 1][j - 1] == BoardType::Empty
						|| myOmok[i + 1][j + 1] == myTeam && myOmok[i + 2][j + 2] == myTeam && myOmok[i + 3][j + 3] == BoardType::Empty && myOmok[i - 1][j - 1] == BoardType::Empty
						|| myOmok[i - 1][j - 1] == myTeam && myOmok[i - 2][j - 2] == myTeam && myOmok[i - 3][j - 3] == BoardType::Empty && myOmok[i + 1][j + 1] == BoardType::Empty
						|| myOmok[i + 1][j - 1] == myTeam && myOmok[i + 2][j - 2] == myTeam && myOmok[i + 3][j - 3] == BoardType::Empty && myOmok[i - 1][j + 1] == BoardType::Empty))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{	//내돌 연속 두개 막힘.
				if (myOmok[i][j] == BoardType::Empty
					&& (myOmok[i + 1][j] == myTeam && myOmok[i + 2][j] == myTeam && myOmok[i - 1][j] == BoardType::Empty
						|| myOmok[i - 1][j] == myTeam && myOmok[i - 2][j] == myTeam && myOmok[i + 1][j] == BoardType::Empty
						|| myOmok[i][j + 1] == myTeam && myOmok[i][j + 2] == myTeam && myOmok[i][j - 1] == BoardType::Empty
						|| myOmok[i][j - 1] == myTeam && myOmok[i][j - 2] == myTeam && myOmok[i][j + 1] == BoardType::Empty
						|| myOmok[i - 1][j + 1] == myTeam && myOmok[i - 2][j + 2] == myTeam && myOmok[i + 1][j - 1] == BoardType::Empty
						|| myOmok[i + 1][j + 1] == myTeam && myOmok[i + 2][j + 2] == myTeam && myOmok[i - 1][j - 1] == BoardType::Empty
						|| myOmok[i - 1][j - 1] == myTeam && myOmok[i - 2][j - 2] == myTeam && myOmok[i + 1][j + 1] == BoardType::Empty
						|| myOmok[i + 1][j - 1] == myTeam && myOmok[i + 2][j - 2] == myTeam && myOmok[i - 1][j + 1] == BoardType::Empty))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{
				if (myOmok[i][j] == BoardType::Empty && i > 5 && j > 5
					&& (myOmok[i - 1][j] == myTeam && myOmok[i - 1][j + 1] == myTeam && myOmok[i - 1][j - 1] == myTeam
						|| myOmok[i][j - 1] == myTeam && myOmok[i + 1][j - 1] == myTeam && myOmok[i - 1][j - 1] == myTeam
						|| myOmok[i - 1][j - 1] == myTeam && myOmok[i][j - 2] == myTeam && myOmok[i - 2][j] == myTeam
						|| myOmok[i - 1][j + 1] == myTeam && myOmok[i][j + 2] == myTeam && myOmok[i - 2][j] == myTeam))
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
		for (int i = 0; i < BOARD_X; ++i)
		{
			for (int j = 0; j < BOARD_Y; ++j)
			{
				if (myOmok[i][j] == BoardType::Empty && i > 7 && j > 7)
				{
					*x = i;
					*y = j;

					myOmok[i][j] = myTeam;
					return;
				}
			}
		}
	}

	void Defence(int i, int j)
	{
		if (BoardType::White == myTeam)
		{
			myOmok[i][j] = BoardType::Black;
		}
		else
		{
			myOmok[i][j] = BoardType::White;
		}
	}
}