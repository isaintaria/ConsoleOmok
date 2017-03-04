#pragma once
#include "Global.h"

namespace KMH
{


int myOmok[BOARD_X][BOARD_Y] = { BoardType::Empty };
int myOmok1[BOARD_X][BOARD_Y] = { BoardType::Empty };

BoardType ally = BoardType::White;
BoardType enemy = BoardType::Black;

void Recursive(int &x, int &y)
{
	int randX = rand() % BOARD_X;
	int randY = rand() % BOARD_Y;

	if (myOmok[randX][randX] == BoardType::Empty)
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
	

	for (int i = 0; i < BOARD_Y; ++i)
	{
		for (int j = 0; j < BOARD_X; ++j)
		{
			myOmok1[j][i] = 0;
		}
	}

	for (int i = 0; i < BOARD_Y; ++i)
	{
		for (int j = 0; j < BOARD_X; ++j)
		{
			if (myOmok[j][i] != enemy && myOmok[j + 1][i] == enemy && myOmok[j + 2][i] == enemy && myOmok[j + 3][i] == enemy && myOmok[j + 4][i] == enemy && myOmok[j + 5][i] != enemy)
			{
					if (myOmok[j][i] != ally)
						myOmok1[j][i] += BoardType::Count4;
					if (myOmok[j + 5][i] != ally)
						myOmok1[j + 5][i] += BoardType::Count4;
			}
			if (myOmok[j][i] != enemy && myOmok[j][i + 1] == enemy && myOmok[j][i + 2] == enemy && myOmok[j][i + 3] == enemy && myOmok[j][i + 4] == enemy && myOmok[j][i + 5] != enemy)
			{
				if (myOmok[j][i] != ally)
					myOmok1[j][i] += BoardType::Count4;
				if (myOmok[j][i + 5] != ally)
					myOmok1[j][i + 5] += BoardType::Count4;
			}// ↘
			if (myOmok[j][i] != enemy && myOmok[j + 1][i + 1] == enemy && myOmok[j + 2][i + 2] == enemy && myOmok[j + 3][i + 3] == enemy && myOmok[j + 4][i + 4] == enemy && myOmok[j + 5][i + 5] != enemy)
			{
				if (myOmok[j][i] != ally)
					myOmok1[j][i] += BoardType::Count4;
				if (myOmok[j + 5][i + 5] != ally)
					myOmok1[j + 5][i + 5] += BoardType::Count4;
			}// ↙
			if (myOmok[j][i] != enemy && myOmok[j + 1][i - 1] == enemy && myOmok[j + 2][i - 2] == enemy && myOmok[j + 3][i - 3] == enemy && myOmok[j + 4][i - 4] == enemy && myOmok[j + 5][i - 5] != enemy)
			{
				if (myOmok[j][i] != ally)
					myOmok1[j][i] += BoardType::Count4;
				if (myOmok[j + 5][i - 5] != ally)
					myOmok1[j + 5][i - 5] += BoardType::Count4;
			}// 3개의 돌이 연속해서 있는 경우.  →
			if (myOmok[j][i] != enemy && myOmok[j + 1][i] == enemy && myOmok[j + 2][i] == enemy && myOmok[j + 3][i] == enemy && myOmok[j + 4][i] != enemy)
			{
				if (myOmok[j][i] != ally)
					myOmok1[j][i] += BoardType::Count3;
				if (myOmok[j + 4][i] != ally)
					myOmok1[j + 4][i] += BoardType::Count3;
			}// ↓
			if (myOmok[j][i] != enemy && myOmok[j][i + 1] == enemy && myOmok[j][i + 2] == enemy && myOmok[j][i + 3] == enemy && myOmok[j][i + 4] != enemy)
			{
				if (myOmok[j][i] != ally)
					myOmok1[j][i] += BoardType::Count3;
				if (myOmok[j][i + 4] != ally)
					myOmok1[j][i + 4] += BoardType::Count3;
			}// ↘
			if (myOmok[j][i] != enemy && myOmok[j + 1][i + 1] == enemy && myOmok[j + 2][i + 2] == enemy && myOmok[j + 3][i + 3] == enemy && myOmok[j + 4][i + 4] != enemy)
			{
				if (myOmok[j][i] != ally)
					myOmok1[j][i] += BoardType::Count3;
				if (myOmok[j + 4][i + 4] != ally)
					myOmok1[j + 4][i + 4] += BoardType::Count3;
			}// ↙
			if (myOmok[j][i] != enemy && myOmok[j + 1][i - 1] == enemy && myOmok[j + 2][i - 2] == enemy && myOmok[j + 3][i - 3] == enemy && myOmok[j + 4][i - 4] != enemy)
			{
				if (myOmok[j][i] != ally)
					myOmok1[j][i] += BoardType::Count3;
				if (myOmok[j + 4][i - 4] != ally)
					myOmok1[j + 4][i - 4] += BoardType::Count3;
			}// 2개의 돌이 연속해서 있는 경우.  →
			if (myOmok[j][i] != enemy && myOmok[j + 1][i] == enemy && myOmok[j + 2][i] == enemy && myOmok[j + 3][i] != enemy)
			{
				if (myOmok[j][i] != ally)
					myOmok1[j][i] += BoardType::Count2;
				if (myOmok[j + 3][i] != ally)
					myOmok1[j + 3][i] += BoardType::Count2;
			}// ↓
			if (myOmok[j][i] != enemy && myOmok[j][i + 1] == enemy && myOmok[j][i + 2] == enemy && myOmok[j][i + 3] != enemy)
			{
				if (myOmok[j][i] != ally)
					myOmok1[j][i] += BoardType::Count2;
				if (myOmok[j][i + 3] != ally)
					myOmok1[j][i + 3] += BoardType::Count2;
			}// ↘
			if (myOmok[j][i] != enemy && myOmok[j + 1][i + 1] == enemy && myOmok[j + 2][i + 2] == enemy && myOmok[j + 3][i + 3] != enemy)
			{
				if (myOmok[j][i] != ally)
					myOmok1[j][i] += BoardType::Count2;
				if (myOmok[j + 3][i + 3] != ally)
					myOmok1[j + 3][i + 3] += BoardType::Count2;
			}// ↙
			if (myOmok[j][i] != enemy && myOmok[j + 1][i - 1] == enemy && myOmok[j + 2][i - 2] == enemy && myOmok[j + 3][i - 3] != enemy)
			{
				if (myOmok[j][i] != ally)
					myOmok1[j][i] += BoardType::Count2;
				if (myOmok[j + 3][i - 3] != ally)
					myOmok1[j + 3][i - 3] += BoardType::Count2;
			}// 1개의 돌이 있는 경우.
			if (myOmok[j][i] == enemy && myOmok[j + 1][i] != enemy && myOmok[j + 2][i] == enemy && myOmok[j + 3][i] != enemy)
			{
				if (myOmok[j + 1][i] != ally)
					myOmok1[j + 1][i] += BoardType::Count;
				if (myOmok[j + 3][i] != ally)
					myOmok1[j + 3][i] += BoardType::Count;
			}
			if (myOmok[j][i] == enemy && myOmok[j][i + 1] != enemy && myOmok[j][i + 2] == enemy && myOmok[j][i + 3] != enemy)
			{
				if (myOmok[j][i + 1] != ally)
					myOmok1[j][i + 1] += BoardType::Count;
				if (myOmok[j][i + 3] != ally)
					myOmok1[j][i + 3] += BoardType::Count;
			}
			if (myOmok[j][i] == enemy && myOmok[j + 1][i + 1] != enemy && myOmok[j + 2][i + 2] == enemy && myOmok[j + 3][i + 3] != enemy)
			{
				if (myOmok[j + 1][i + 1] != ally)
					myOmok1[j + 1][i + 1] += BoardType::Count;
				if (myOmok[j + 3][i + 3] != ally)
					myOmok1[j + 3][i + 3] += BoardType::Count;
			}
			if (myOmok[j][i] == enemy && myOmok[j + 1][i - 1] != enemy && myOmok[j + 2][i - 2] == enemy && myOmok[j + 3][i - 3] != enemy)
			{
				if (myOmok[j + 1][i - 1] != ally)
					myOmok1[j + 1][i - 1] += BoardType::Count;
				if (myOmok[j + 3][i - 3] != ally)
					myOmok1[j + 3][i - 3] += BoardType::Count;
			}
			if (myOmok[j][i] == enemy && myOmok[j - 1][i - 1] != enemy && myOmok[j - 2][i - 2] == enemy && myOmok[j - 3][i - 3] != enemy)
			{
				if (myOmok[j - 1][i - 1] != ally)
					myOmok1[j - 1][i - 1] += BoardType::Count;
				if (myOmok[j - 3][i - 3] != ally)
					myOmok1[j - 3][i - 3] += BoardType::Count;
			}
			if (myOmok[j][i] == enemy && myOmok[j + 1][i - 1] != enemy && myOmok[j + 2][i - 2] == enemy && myOmok[j + 3][i - 3] != enemy)
			{
				if (myOmok[j + 1][i - 1] != ally)
					myOmok1[j + 1][i - 1] += BoardType::Count;
				if (myOmok[j + 3][i - 3] != ally)
					myOmok1[j + 3][i - 3] += BoardType::Count;
			}
			if (myOmok[j][i] == enemy && myOmok[j - 1][i] != enemy && myOmok[j - 2][i] == enemy && myOmok[j - 3][i] != enemy)
			{
				if (myOmok[j - 1][i] != ally)
					myOmok1[j - 1][i] += BoardType::Count;
				if (myOmok[j - 3][i] != ally)
					myOmok1[j - 3][i] += BoardType::Count;
			}
			if (myOmok[j][i] == enemy && myOmok[j][i - 1] != enemy && myOmok[j][i - 2] == enemy && myOmok[j][i - 3] != enemy)
			{
				if (myOmok[j][i - 1] != ally)
					myOmok1[j][i - 1] += BoardType::Count;
				if (myOmok[j][i - 3] != ally)
					myOmok1[j][i - 3] += BoardType::Count;
			}
		}
	}

	for (int i = 0; i < BOARD_Y; ++i)
	{
		for (int j = 0; j < BOARD_X; ++j)
		{
			if (myOmok[j][i] != ally && myOmok[j + 1][i] == ally && myOmok[j + 2][i] == ally && myOmok[j + 3][i] == ally && myOmok[j + 4][i] == ally && myOmok[j + 5][i] != ally)
			{
				if (myOmok[j][i] != enemy)
					myOmok1[j][i] += BoardType::Count4;
				if (myOmok[j + 5][i] != enemy)
					myOmok1[j + 5][i] += BoardType::Count4;
			}
			if (myOmok[j][i] != ally && myOmok[j][i + 1] == ally && myOmok[j][i + 2] == ally && myOmok[j][i + 3] == ally && myOmok[j][i + 4] == ally && myOmok[j][i + 5] != ally)
			{
				if (myOmok[j][i] != enemy)
					myOmok1[j][i] += BoardType::Count4;
				if (myOmok[j][i + 5] != enemy)
					myOmok1[j][i + 5] += BoardType::Count4;
			}// ↘
			if (myOmok[j][i] != ally && myOmok[j + 1][i + 1] == ally && myOmok[j + 2][i + 2] == ally && myOmok[j + 3][i + 3] == ally && myOmok[j + 4][i + 4] == ally && myOmok[j + 5][i + 5] != ally)
			{
				if (myOmok[j][i] != enemy)
					myOmok1[j][i] += BoardType::Count4;
				if (myOmok[j + 5][i + 5] != enemy)
					myOmok1[j + 5][i + 5] += BoardType::Count4;
			}// ↙
			if (myOmok[j][i] != ally && myOmok[j + 1][i - 1] == ally && myOmok[j + 2][i - 2] == ally && myOmok[j + 3][i - 3] == ally && myOmok[j + 4][i - 4] == ally && myOmok[j + 5][i - 5] != ally)
			{
				if (myOmok[j][i] != enemy)
					myOmok1[j][i] += BoardType::Count4;
				if (myOmok[j + 5][i - 5] != enemy)
					myOmok1[j + 5][i - 5] += BoardType::Count4;
			}// 3개의 돌이 연속해서 있는 경우.  →
			if (myOmok[j][i] != ally && myOmok[j + 1][i] == ally && myOmok[j + 2][i] == ally && myOmok[j + 3][i] == ally && myOmok[j + 4][i] != ally)
			{
				if (myOmok[j][i] != enemy)
					myOmok1[j][i] += BoardType::Count3;
				if (myOmok[j + 4][i] != enemy)
					myOmok1[j + 4][i] += BoardType::Count3;
			}// ↓
			if (myOmok[j][i] != ally && myOmok[j][i + 1] == ally && myOmok[j][i + 2] == ally && myOmok[j][i + 3] == ally && myOmok[j][i + 4] != ally)
			{
				if (myOmok[j][i] != enemy)
					myOmok1[j][i] += BoardType::Count3;
				if (myOmok[j][i + 4] != enemy)
					myOmok1[j][i + 4] += BoardType::Count3;
			}// ↘
			if (myOmok[j][i] != ally && myOmok[j + 1][i + 1] == ally && myOmok[j + 2][i + 2] == ally && myOmok[j + 3][i + 3] == ally && myOmok[j + 4][i + 4] != ally)
			{
				if (myOmok[j][i] != enemy)
					myOmok1[j][i] += BoardType::Count3;
				if (myOmok[j + 4][i + 4] != enemy)
					myOmok1[j + 4][i + 4] += BoardType::Count3;
			}// ↙
			if (myOmok[j][i] != ally && myOmok[j + 1][i - 1] == ally && myOmok[j + 2][i - 2] == ally && myOmok[j + 3][i - 3] == ally && myOmok[j + 4][i - 4] != ally)
			{
				if (myOmok[j][i] != enemy)
					myOmok1[j][i] += BoardType::Count3;
				if (myOmok[j + 4][i - 4] != enemy)
					myOmok1[j + 4][i - 4] += BoardType::Count3;
			}// 2개의 돌이 연속해서 있는 경우.  →
			if (myOmok[j][i] != ally && myOmok[j + 1][i] == ally && myOmok[j + 2][i] == ally && myOmok[j + 3][i] != ally)
			{
				if (myOmok[j][i] != enemy)
					myOmok1[j][i] += BoardType::Count2;
				if (myOmok[j + 3][i] != enemy)
					myOmok1[j + 3][i] += BoardType::Count2;
			}// ↓
			if (myOmok[j][i] != ally && myOmok[j][i + 1] == ally && myOmok[j][i + 2] == ally && myOmok[j][i + 3] != ally)
			{
				if (myOmok[j][i] != enemy)
					myOmok1[j][i] += BoardType::Count2;
				if (myOmok[j][i + 3] != enemy)
					myOmok1[j][i + 3] += BoardType::Count2;
			}// ↘
			if (myOmok[j][i] != ally && myOmok[j + 1][i + 1] == ally && myOmok[j + 2][i + 2] == ally && myOmok[j + 3][i + 3] != ally)
			{
				if (myOmok[j][i] != enemy)
					myOmok1[j][i] += BoardType::Count2;
				if (myOmok[j + 3][i + 3] != enemy)
					myOmok1[j + 3][i + 3] += BoardType::Count2;
			}// ↙
			if (myOmok[j][i] != ally && myOmok[j + 1][i - 1] == ally && myOmok[j + 2][i - 2] == ally && myOmok[j + 3][i - 3] != ally)
			{
				if (myOmok[j][i] != enemy)
					myOmok1[j][i] += BoardType::Count2;
				if (myOmok[j + 3][i - 3] != enemy)
					myOmok1[j + 3][i - 3] += BoardType::Count2;
			}// 1개의 돌이 있는 경우.
			if (myOmok[j][i] == ally && myOmok[j + 1][i] != ally && myOmok[j + 2][i] == ally && myOmok[j + 3][i] != ally)
			{
				if (myOmok[j + 1][i] != enemy)
					myOmok1[j + 1][i] += BoardType::Count;
				if (myOmok[j + 3][i] != enemy)
					myOmok1[j + 3][i] += BoardType::Count;
			}
			if (myOmok[j][i] == ally && myOmok[j][i + 1] != ally && myOmok[j][i + 2] == ally && myOmok[j][i + 3] != ally)
			{
				if (myOmok[j][i + 1] != enemy)
					myOmok1[j][i + 1] += BoardType::Count;
				if (myOmok[j][i + 3] != enemy)
					myOmok1[j][i + 3] += BoardType::Count;
			}
			if (myOmok[j][i] == ally && myOmok[j + 1][i + 1] != ally && myOmok[j + 2][i + 2] == ally && myOmok[j + 3][i + 3] != ally)
			{
				if (myOmok[j + 1][i + 1] != enemy)
					myOmok1[j + 1][i + 1] += BoardType::Count;
				if (myOmok[j + 3][i + 3] != enemy)
					myOmok1[j + 3][i + 3] += BoardType::Count;
			}
			if (myOmok[j][i] == ally && myOmok[j + 1][i - 1] != ally && myOmok[j + 2][i - 2] == ally && myOmok[j + 3][i - 3] != ally)
			{
				if (myOmok[j + 1][i - 1] != enemy)
					myOmok1[j + 1][i - 1] += BoardType::Count;
				if (myOmok[j + 3][i - 3] != enemy)
					myOmok1[j + 3][i - 3] += BoardType::Count;
			}
			if (myOmok[j][i] == ally && myOmok[j - 1][i - 1] != ally && myOmok[j - 2][i - 2] == ally && myOmok[j - 3][i - 3] != ally)
			{
				if (myOmok[j - 1][i - 1] != enemy)
					myOmok1[j - 1][i - 1] += BoardType::Count;
				if (myOmok[j - 3][i - 3] != enemy)
					myOmok1[j - 3][i - 3] += BoardType::Count;
			}
			if (myOmok[j][i] == ally && myOmok[j + 1][i - 1] != ally && myOmok[j + 2][i - 2] == ally && myOmok[j + 3][i - 3] != ally)
			{
				if (myOmok[j + 1][i - 1] != enemy)
					myOmok1[j + 1][i - 1] += BoardType::Count;
				if (myOmok[j + 3][i - 3] != enemy)
					myOmok1[j + 3][i - 3] += BoardType::Count;
			}
			if (myOmok[j][i] == ally && myOmok[j - 1][i] != ally && myOmok[j - 2][i] == ally && myOmok[j - 3][i] != ally)
			{
				if (myOmok[j - 1][i] != enemy)
					myOmok1[j - 1][i] += BoardType::Count;
				if (myOmok[j - 3][i] != enemy)
					myOmok1[j - 3][i] += BoardType::Count;
			}
			if (myOmok[j][i] == ally && myOmok[j][i - 1] != ally && myOmok[j][i - 2] == ally && myOmok[j][i - 3] != ally)
			{
				if (myOmok[j][i - 1] != enemy)
					myOmok1[j][i - 1] += BoardType::Count;
				if (myOmok[j][i - 3] != enemy)
					myOmok1[j][i - 3] += BoardType::Count;
			}
		}
	}


	int bestScore = 10;

	for (int i = 0; i < BOARD_Y; ++i)
	{
		for (int j = 0; j < BOARD_X; ++j)
		{
			if (bestScore < myOmok1[j][i])
			{
				bestScore = myOmok1[j][i];
			}
		}
	}

	for (int i = 0; i < BOARD_Y; ++i)
	{
		for (int j = 0; j < BOARD_X; ++j)
		{
			if (bestScore == myOmok1[j][i] && bestScore >= BoardType::Count2)
			{
				*x = j;
				*y = i;
			    myOmok[j][i] = ally;

				return;
			}
			else if (bestScore == 10)
			{
				*x = 10;
				*y = 10;
				myOmok[10][10] = ally;

				return;
			}
				
		}
	}
}
	


void Defence(int x, int y)
{
	if (BoardType::White == ally)
	{
		myOmok[x][y] = BoardType::Black;
	}
	else
	{
		myOmok[x][y] = BoardType::White;
	}
}
}


