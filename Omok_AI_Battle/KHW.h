#pragma once
#include "Global.h"
#include <time.h>

namespace KHW
{
	int myBoard[BOARD_X][BOARD_Y] = { BoardType::Empty };

	BoardType	player = BoardType::White;
	BoardType	enemy = BoardType::Black;
	int			_x = 9;
	int			_y = 9;

	void Recursive(int &x, int &y)
	{
		if (myBoard[x][y] != BoardType::Empty)
		{
			switch (rand() % 4)
			{
			case 0:
				x += 1;
				break;
			case 1:
				x -= 1;
				break;
			case 2:
				y += 1;
				break;
			case 3:
				y -= 1;
				break;
			}

			Recursive(x, y);
		}
	}

	bool Search8Way1(int x, int y)
	{
#pragma region 내꺼 4개가 연속으로 있는경우
		if (myBoard[x + 1][y] == player && myBoard[x + 2][y] == player && myBoard[x + 3][y] == player && myBoard[x + 4][y] == player ||
			myBoard[x - 1][y] == player && myBoard[x - 2][y] == player && myBoard[x - 3][y] == player && myBoard[x - 4][y] == player ||
			myBoard[x + 1][y + 1] == player && myBoard[x + 2][y + 2] == player && myBoard[x + 3][y + 3] == player && myBoard[x + 4][y + 4] == player ||
			myBoard[x - 1][y - 1] == player && myBoard[x - 2][y - 2] == player && myBoard[x - 3][y - 3] == player && myBoard[x - 4][y - 4] == player ||
			myBoard[x][y + 1] == player && myBoard[x][y + 2] == player && myBoard[x][y + 3] == player && myBoard[x][y + 4] == player ||
			myBoard[x][y - 1] == player && myBoard[x][y - 2] == player && myBoard[x][y - 3] == player && myBoard[x][y - 4] == player ||
			myBoard[x - 1][y + 1] == player && myBoard[x - 2][y + 2] == player && myBoard[x - 3][y + 3] == player && myBoard[x - 4][y + 4] == player ||
			myBoard[x + 1][y - 1] == player && myBoard[x + 2][y - 2] == player && myBoard[x + 3][y - 3] == player && myBoard[x + 4][y - 4] == player)
		{
			return true;
		}
#pragma endregion
#pragma region 내꺼 2개씩 or 1,3 or 3,1 좌우로 있는 경우
		else if (myBoard[x - 1][y] == player && myBoard[x - 2][y] == player && myBoard[x + 1][y] == player && myBoard[x + 2][y] == player ||
			myBoard[x - 1][y - 1] == player && myBoard[x - 2][y - 2] == player && myBoard[x + 1][y + 1] == player && myBoard[x + 2][y + 2] == player ||
			myBoard[x][y - 1] == player && myBoard[x][y - 2] == player && myBoard[x][y + 1] == player && myBoard[x][y + 2] == player ||
			myBoard[x - 1][y + 1] == player && myBoard[x - 2][y + 2] == player && myBoard[x + 1][y - 1] == player && myBoard[x + 2][y - 2] == player ||

			myBoard[x - 1][y] == player && myBoard[x + 1][y] == player && myBoard[x + 2][y] == player && myBoard[x + 3][y] == player ||
			myBoard[x - 1][y - 1] == player && myBoard[x + 1][y + 1] == player && myBoard[x + 2][y + 2] == player && myBoard[x + 3][y + 3] == player ||
			myBoard[x][y - 1] == player && myBoard[x][y + 1] == player && myBoard[x][y + 2] == player && myBoard[x][y + 3] == player ||
			myBoard[x - 1][y + 1] == player && myBoard[x + 1][y - 1] == player && myBoard[x + 2][y - 2] == player && myBoard[x + 3][y - 3] == player ||

			myBoard[x + 1][y] == player && myBoard[x - 1][y] == player && myBoard[x - 2][y] == player && myBoard[x - 3][y] == player ||
			myBoard[x + 1][y + 1] == player && myBoard[x - 1][y - 1] == player && myBoard[x - 2][y - 2] == player && myBoard[x - 3][y - 3] == player ||
			myBoard[x][y + 1] == player && myBoard[x][y - 1] == player && myBoard[x][y - 2] == player && myBoard[x][y - 3] == player ||
			myBoard[x + 1][y - 1] == player && myBoard[x - 1][y + 1] == player && myBoard[x - 2][y + 2] == player && myBoard[x - 3][y + 3] == player
			)
		{
			return true;
		}
#pragma endregion
#pragma region 상대방 2개씩 or 1,3 or 3,1 좌우로 있는 경우
		else if (myBoard[x - 1][y] == enemy && myBoard[x - 2][y] == enemy && myBoard[x + 1][y] == enemy && myBoard[x + 2][y] == enemy ||
			myBoard[x + 1][y + 1] == enemy && myBoard[x + 2][y + 2] == enemy && myBoard[x - 1][y - 1] == enemy && myBoard[x - 4][y - 4] == enemy ||
			myBoard[x][y - 1] == enemy && myBoard[x][y - 2] == enemy && myBoard[x][y + 1] == enemy && myBoard[x][y + 2] == enemy ||
			myBoard[x - 1][y + 1] == enemy && myBoard[x - 2][y + 2] == enemy && myBoard[x + 1][y - 1] == enemy && myBoard[x + 2][y - 2] == enemy ||

			myBoard[x - 1][y] == enemy && myBoard[x + 1][y] == enemy && myBoard[x + 2][y] == enemy && myBoard[x + 3][y] == enemy ||
			myBoard[x - 1][y - 1] == enemy && myBoard[x + 1][y + 1] == enemy && myBoard[x + 2][y + 2] == enemy && myBoard[x + 3][y + 3] == enemy ||
			myBoard[x][y - 1] == enemy && myBoard[x][y + 1] == enemy && myBoard[x][y + 2] == enemy && myBoard[x][y + 3] == enemy ||
			myBoard[x - 1][y + 1] == enemy && myBoard[x + 1][y - 1] == enemy && myBoard[x + 2][y - 2] == enemy && myBoard[x + 3][y - 3] == enemy ||

			myBoard[x + 1][y] == enemy && myBoard[x - 1][y] == enemy && myBoard[x - 2][y] == enemy && myBoard[x - 3][y] == enemy ||
			myBoard[x + 1][y + 1] == enemy && myBoard[x - 1][y - 1] == enemy && myBoard[x - 2][y - 2] == enemy && myBoard[x - 3][y - 3] == enemy ||
			myBoard[x][y + 1] == enemy && myBoard[x][y - 1] == enemy && myBoard[x][y - 2] == enemy && myBoard[x][y - 3] == enemy ||
			myBoard[x + 1][y - 1] == enemy && myBoard[x - 1][y + 1] == enemy && myBoard[x - 2][y + 2] == enemy && myBoard[x - 3][y + 3] == enemy)
		{
			return true;
		}
#pragma endregion
#pragma region 상대방 4개가 연속으로 있으며 끝을 막은경우
		else if (myBoard[x + 1][y] == enemy && myBoard[x + 2][y] == enemy && myBoard[x + 3][y] == enemy && myBoard[x + 4][y] == enemy && myBoard[x + 5][y] == player ||
			myBoard[x - 1][y] == enemy && myBoard[x - 2][y] == enemy && myBoard[x - 3][y] == enemy && myBoard[x - 4][y] == enemy && myBoard[x - 5][y] == player ||
			myBoard[x + 1][y + 1] == enemy && myBoard[x + 2][y + 2] == enemy && myBoard[x + 3][y + 3] == enemy && myBoard[x + 4][y + 4] == enemy && myBoard[x + 5][y + 5] == player ||
			myBoard[x - 1][y - 1] == enemy && myBoard[x - 2][y - 2] == enemy && myBoard[x - 3][y - 3] == enemy && myBoard[x - 4][y - 4] == enemy && myBoard[x - 5][y - 5] == player ||
			myBoard[x][y - 1] == enemy && myBoard[x][y - 2] == enemy && myBoard[x][y - 3] == enemy && myBoard[x][y - 4] == enemy && myBoard[x][y - 5] == player ||
			myBoard[x][y + 1] == enemy && myBoard[x][y + 2] == enemy && myBoard[x][y + 3] == enemy && myBoard[x][y + 4] == enemy && myBoard[x][y + 5] == player ||
			myBoard[x - 1][y + 1] == enemy && myBoard[x - 2][y + 2] == enemy && myBoard[x - 3][y + 3] == enemy && myBoard[x - 4][y + 4] == enemy && myBoard[x - 5][y + 5] == player ||
			myBoard[x + 1][y - 1] == enemy && myBoard[x + 2][y - 2] == enemy && myBoard[x + 3][y - 3] == enemy && myBoard[x + 4][y - 4] == enemy && myBoard[x + 5][y - 5] == player)
		{
			return true;
		}
#pragma endregion

		return false;
	}

	bool Search8Way2(int x, int y)
	{
#pragma region 내꺼 3개가 연속으로 있고 끝이 빈경우
		if (myBoard[x + 1][y] == player && myBoard[x + 2][y] == player && myBoard[x + 3][y] == player && myBoard[x + 4][y] == BoardType::Empty ||
			myBoard[x - 1][y] == player && myBoard[x - 2][y] == player && myBoard[x - 3][y] == player && myBoard[x - 4][y] == BoardType::Empty ||
			myBoard[x + 1][y + 1] == player && myBoard[x + 2][y + 2] == player && myBoard[x + 3][y + 3] == player && myBoard[x + 4][y + 4] == BoardType::Empty ||
			myBoard[x - 1][y - 1] == player && myBoard[x - 2][y - 2] == player && myBoard[x - 3][y - 3] == player && myBoard[x - 4][y - 4] == BoardType::Empty ||
			myBoard[x][y - 1] == player && myBoard[x][y - 2] == player && myBoard[x][y - 3] == player && myBoard[x][y - 4] == BoardType::Empty ||
			myBoard[x][y + 1] == player && myBoard[x][y + 2] == player && myBoard[x][y + 3] == player && myBoard[x][y + 4] == BoardType::Empty ||
			myBoard[x - 1][y + 1] == player && myBoard[x - 2][y + 2] == player && myBoard[x - 3][y + 3] == player && myBoard[x - 4][y + 4] == BoardType::Empty ||
			myBoard[x + 1][y - 1] == player && myBoard[x + 2][y - 2] == player && myBoard[x + 3][y - 3] == player && myBoard[x + 4][y - 4] == BoardType::Empty)
		{
			return true;
		}
#pragma endregion
#pragma region 내꺼 1,2 or 2,1 좌우로 있으며 양끝이 빈경우
		else if (myBoard[x - 2][y] == BoardType::Empty && myBoard[x - 1][y] == player && myBoard[x + 1][y] == player && myBoard[x + 2][y] == player && myBoard[x + 3][y] == BoardType::Empty ||
			myBoard[x + 2][y] == BoardType::Empty && myBoard[x + 1][y] == player && myBoard[x - 1][y] == player && myBoard[x - 2][y] == player && myBoard[x - 3][y] == BoardType::Empty ||
			myBoard[x - 2][y - 2] == BoardType::Empty && myBoard[x - 1][y - 1] == player && myBoard[x + 1][y + 1] == player && myBoard[x + 2][y + 2] == player && myBoard[x + 3][y + 3] == BoardType::Empty ||
			myBoard[x + 2][y + 2] == BoardType::Empty && myBoard[x + 1][y + 1] == player && myBoard[x - 1][y - 1] == player && myBoard[x - 2][y - 2] == player && myBoard[x - 3][y - 3] == BoardType::Empty ||
			myBoard[x][y - 2] == BoardType::Empty && myBoard[x][y - 1] == player && myBoard[x][y + 1] == player && myBoard[x][y + 2] == player && myBoard[x][y + 3] == BoardType::Empty ||
			myBoard[x][y + 2] == BoardType::Empty && myBoard[x][y + 1] == player && myBoard[x][y - 1] == player && myBoard[x][y - 2] == player && myBoard[x][y - 3] == BoardType::Empty ||
			myBoard[x - 2][y + 2] == BoardType::Empty && myBoard[x - 1][y + 1] == player && myBoard[x + 1][y - 1] == player && myBoard[x + 2][y - 2] == player && myBoard[x + 3][y - 3] == BoardType::Empty ||
			myBoard[x + 2][y - 2] == BoardType::Empty && myBoard[x + 1][y - 1] == player && myBoard[x - 1][y + 1] == player && myBoard[x - 2][y + 2] == player && myBoard[x - 3][y + 3] == BoardType::Empty)
		{
			return true;
		}
#pragma endregion
#pragma region 상대방 3개가 연속으로 있고 끝이 빈경우
		else if (myBoard[x + 1][y] == enemy && myBoard[x + 2][y] == enemy && myBoard[x + 3][y] == enemy && myBoard[x + 4][y] == BoardType::Empty ||
			myBoard[x - 1][y] == enemy && myBoard[x - 2][y] == enemy && myBoard[x - 3][y] == enemy && myBoard[x - 4][y] == BoardType::Empty ||
			myBoard[x + 1][y + 1] == enemy && myBoard[x + 2][y + 2] == enemy && myBoard[x + 3][y + 3] == enemy && myBoard[x + 4][y + 4] == BoardType::Empty ||
			myBoard[x - 1][y - 1] == enemy && myBoard[x - 2][y - 2] == enemy && myBoard[x - 3][y - 3] == enemy && myBoard[x - 4][y - 4] == BoardType::Empty ||
			myBoard[x][y - 1] == enemy && myBoard[x][y - 2] == enemy && myBoard[x][y - 3] == enemy && myBoard[x][y - 4] == BoardType::Empty ||
			myBoard[x][y + 1] == enemy && myBoard[x][y + 2] == enemy && myBoard[x][y + 3] == enemy && myBoard[x][y + 4] == BoardType::Empty ||
			myBoard[x - 1][y + 1] == enemy && myBoard[x - 2][y + 2] == enemy && myBoard[x - 3][y + 3] == enemy && myBoard[x - 4][y + 4] == BoardType::Empty ||
			myBoard[x + 1][y - 1] == enemy && myBoard[x + 2][y - 2] == enemy && myBoard[x + 3][y - 3] == enemy && myBoard[x + 4][y - 4] == BoardType::Empty)
		{
			return true;
		}
#pragma endregion
#pragma region 상대방 1,2 or 2,1 좌우로 있으며 양끝이 빈경우
		else if (myBoard[x - 2][y] == BoardType::Empty && myBoard[x - 1][y] == enemy && myBoard[x + 1][y] == enemy && myBoard[x + 2][y] == enemy && myBoard[x + 3][y] == BoardType::Empty ||
			myBoard[x + 2][y] == BoardType::Empty && myBoard[x + 1][y] == enemy && myBoard[x - 1][y] == enemy && myBoard[x - 2][y] == enemy && myBoard[x - 3][y] == BoardType::Empty ||
			myBoard[x - 2][y - 2] == BoardType::Empty && myBoard[x - 1][y - 1] == enemy && myBoard[x + 1][y + 1] == enemy && myBoard[x + 2][y + 2] == enemy && myBoard[x + 3][y + 3] == BoardType::Empty ||
			myBoard[x + 2][y + 2] == BoardType::Empty && myBoard[x + 1][y + 1] == enemy && myBoard[x - 1][y - 1] == enemy && myBoard[x - 2][y - 2] == enemy && myBoard[x - 3][y - 3] == BoardType::Empty ||
			myBoard[x][y - 2] == BoardType::Empty && myBoard[x][y - 1] == enemy && myBoard[x][y + 1] == enemy && myBoard[x][y + 2] == enemy && myBoard[x][y + 3] == BoardType::Empty ||
			myBoard[x][y + 2] == BoardType::Empty && myBoard[x][y + 1] == enemy && myBoard[x][y - 1] == enemy && myBoard[x][y - 2] == enemy && myBoard[x][y - 3] == BoardType::Empty ||
			myBoard[x - 2][y + 2] == BoardType::Empty && myBoard[x - 1][y + 1] == enemy && myBoard[x + 1][y - 1] == enemy && myBoard[x + 2][y - 2] == enemy && myBoard[x + 3][y - 3] == BoardType::Empty ||
			myBoard[x + 2][y - 2] == BoardType::Empty && myBoard[x + 1][y - 1] == enemy && myBoard[x - 1][y + 1] == enemy && myBoard[x - 2][y + 2] == enemy && myBoard[x - 3][y + 3] == BoardType::Empty)
		{
			return true;
		}
#pragma endregion

		return false;
	}

	bool Search8Way3(int x, int y)
	{
#pragma region 내꺼 3개가 연속이며 한쪽끝은 막혔고 한쪽끝은 빈경우
		if (myBoard[x - 1][y] == BoardType::Empty && myBoard[x + 1][y] == player && myBoard[x + 2][y] == player && myBoard[x + 3][y] == player && myBoard[x + 4][y] == enemy ||
			myBoard[x + 1][y] == BoardType::Empty && myBoard[x - 1][y] == player && myBoard[x - 2][y] == player && myBoard[x - 3][y] == player && myBoard[x - 4][y] == enemy ||
			myBoard[x - 1][y - 1] == BoardType::Empty && myBoard[x + 1][y + 1] == player && myBoard[x + 2][y + 2] == player && myBoard[x + 3][y + 3] == player && myBoard[x + 4][y + 4] == enemy ||
			myBoard[x + 1][y + 1] == BoardType::Empty && myBoard[x - 1][y - 1] == player && myBoard[x - 2][y - 2] == player && myBoard[x - 3][y - 3] == player && myBoard[x - 4][y - 4] == enemy ||
			myBoard[x][y + 1] == BoardType::Empty && myBoard[x][y - 1] == player && myBoard[x][y - 2] == player && myBoard[x][y - 3] == player && myBoard[x][y - 4] == enemy ||
			myBoard[x][y - 1] == BoardType::Empty && myBoard[x][y + 1] == player && myBoard[x][y + 2] == player && myBoard[x][y + 3] == player && myBoard[x][y + 4] == enemy ||
			myBoard[x + 1][y - 1] == BoardType::Empty && myBoard[x - 1][y + 1] == player && myBoard[x - 2][y + 2] == player && myBoard[x - 3][y + 3] == player && myBoard[x - 4][y + 4] == enemy ||
			myBoard[x - 1][y + 1] == BoardType::Empty && myBoard[x + 1][y - 1] == player && myBoard[x + 2][y - 2] == player && myBoard[x + 3][y - 3] == player && myBoard[x + 4][y - 4] == enemy)
		{
			return true;
		}
#pragma endregion
#pragma region 내꺼 좌우 or 2개가 연속으로 있고 양끝이 빈경우
		else if (myBoard[x - 2][y] == BoardType::Empty && myBoard[x - 1][y] == player && myBoard[x + 1][y] == player && myBoard[x + 2][y] == BoardType::Empty ||
			myBoard[x][y - 2] == BoardType::Empty && myBoard[x][y - 1] == player && myBoard[x][y + 1] == player && myBoard[x][y + 2] == BoardType::Empty ||
			myBoard[x - 2][y - 2] == BoardType::Empty && myBoard[x - 1][y - 1] == player && myBoard[x + 1][y + 1] == player && myBoard[x + 2][y + 2] == BoardType::Empty ||
			myBoard[x - 2][y + 2] == BoardType::Empty && myBoard[x - 1][y + 1] == player && myBoard[x + 1][y - 1] == player && myBoard[x + 2][y - 2] == BoardType::Empty ||

			myBoard[x - 1][y] == BoardType::Empty && myBoard[x + 1][y] == player && myBoard[x + 2][y] == player && myBoard[x + 3][y] == BoardType::Empty ||
			myBoard[x + 1][y] == BoardType::Empty && myBoard[x - 1][y] == player && myBoard[x - 2][y] == player && myBoard[x - 3][y] == BoardType::Empty ||
			myBoard[x - 1][y - 1] == BoardType::Empty && myBoard[x + 1][y + 1] == player && myBoard[x + 2][y + 2] == player && myBoard[x + 3][y + 3] == BoardType::Empty ||
			myBoard[x + 1][y + 1] == BoardType::Empty && myBoard[x - 1][y - 1] == player && myBoard[x - 2][y - 2] == player && myBoard[x - 3][y - 3] == BoardType::Empty ||
			myBoard[x][y - 1] == BoardType::Empty && myBoard[x][y + 1] == player && myBoard[x][y + 2] == player && myBoard[x][y + 3] == BoardType::Empty ||
			myBoard[x][y + 1] == BoardType::Empty && myBoard[x][y - 1] == player && myBoard[x][y - 2] == player && myBoard[x][y - 3] == BoardType::Empty ||
			myBoard[x - 1][y + 1] == BoardType::Empty && myBoard[x + 1][y - 1] == player && myBoard[x + 2][y - 2] == player && myBoard[x + 3][y - 3] == BoardType::Empty ||
			myBoard[x + 1][y - 1] == BoardType::Empty && myBoard[x - 1][y + 1] == player && myBoard[x - 2][y + 2] == player && myBoard[x - 3][y + 3] == BoardType::Empty)
		{
			return true;
		}
#pragma endregion

		return false;
	}

	void Attack(int *retX, int * retY)
	{
		for (int y = 0; y < BOARD_Y; ++y)
		{
			for (int x = 0; x < BOARD_X; ++x)
			{
				if (BoardType::Empty == myBoard[x][y] &&
					true == Search8Way1(x, y))
				{
					*retX = x;
					*retY = y;
					myBoard[x][y] = player;
					return;
				}
			}
		}

		for (int y = 0; y < BOARD_Y; ++y)
		{
			for (int x = 0; x < BOARD_X; ++x)
			{
				if (BoardType::Empty == myBoard[x][y] &&
					true == Search8Way2(x, y))
				{
					*retX = x;
					*retY = y;
					myBoard[x][y] = player;
					return;
				}
			}
		}

		for (int y = 0; y < BOARD_Y; ++y)
		{
			for (int x = 0; x < BOARD_X; ++x)
			{
				if (BoardType::Empty == myBoard[x][y] &&
					true == Search8Way3(x, y))
				{
					*retX = x;
					*retY = y;
					myBoard[x][y] = player;
					return;
				}
			}
		}

		srand((unsigned)time(NULL));

		Recursive(_x, _y);

		*retX = _x;
		*retY = _y;
		myBoard[_x][_y] = player;
	}

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