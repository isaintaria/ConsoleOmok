#pragma once
#include "Global.h"
#include <time.h>

namespace KSM
{
	int Enemy_x = 9;
	int	Enemy_y = 9;
	int myBoard[BOARD_X][BOARD_Y] = { BoardType::Empty };
	int Markes[BOARD_X][BOARD_Y] = { 0 };

	BoardType myTeam = BoardType::White;
	BoardType Enemy = BoardType::Black;
	int scroes = 0;

	void rec(int &x,int &y)
	{
		if (myBoard[x][y] != BoardType::Empty)
		{
			srand((unsigned)time(NULL));
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

				rec(x, y);
			}
		}
	}

	void Search()
	{
		
		Markes[BOARD_X][BOARD_Y] = { 0 };
		for (int y = 0; y < BOARD_Y; y++)
		{
			for (int x = 0; x < BOARD_X; x++)
			{
#pragma region 내가 4개일때

				if (myBoard[x][y] == myTeam && myBoard[x + 1][y] == myTeam && myBoard[x + 2][y] == myTeam && myBoard[x + 3][y] == myTeam)
				{
					if (myBoard[x + 4][y] == BoardType::Empty  && myBoard[x - 1][y] == BoardType::Empty)
					{
						scroes = 300000;
						Markes[x + 4][y] += scroes;
						Markes[x - 1][y] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x][y + 1] == myTeam && myBoard[x][y + 2] == myTeam && myBoard[x][y + 3] == myTeam)
				{
					if (myBoard[x][y + 4] == BoardType::Empty && myBoard[x][y - 1] == BoardType::Empty)
					{
						scroes = 300000;
						Markes[x][y + 4] += scroes;
						Markes[x][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x + 1][y + 1] == myTeam && myBoard[x + 2][y + 2] == myTeam && myBoard[x + 3][y + 3] == myTeam)
				{
					if (myBoard[x + 4][y + 4] == BoardType::Empty && myBoard[x - 1][y - 1] == BoardType::Empty)
					{
						scroes = 300000;
						Markes[x + 4][y + 4] += scroes;
						Markes[x - 1][y - 1] += scroes;
					}
				}if (myBoard[x][y] == myTeam && myBoard[x - 1][y + 1] == myTeam && myBoard[x - 2][y + 2] == myTeam && myBoard[x - 3][y - 3] == myTeam)
				{
					if (myBoard[x + 4][y + 4] == BoardType::Empty && myBoard[x - 1][y - 1] == BoardType::Empty)
					{
						scroes = 300000;
						Markes[x - 4][y + 4] += scroes;
						Markes[x + 1][y - 1] += scroes;
					}
				}
#pragma endregion
#pragma region 내가 4개인데 하나가 막혔을때

				if (myBoard[x][y] == myTeam && myBoard[x + 1][y] == myTeam && myBoard[x + 2][y] == myTeam && myBoard[x + 3][y] == myTeam)
				{
					if (myBoard[x + 4][y] == BoardType::Empty && (myBoard[x - 1][y] == Enemy || x < 1))
					{
						scroes = 300000;
						Markes[x + 4][y] += scroes;
					}
					else if (myBoard[x - 1][y] == BoardType::Empty && (myBoard[x + 4][y] == Enemy || x > BOARD_X - 4))
					{
						scroes = 300000;
						Markes[x - 1][y] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x][y + 1] == myTeam && myBoard[x][y + 2] == myTeam && myBoard[x][y + 3] == myTeam)
				{
					if (myBoard[x][y + 4] == BoardType::Empty && (myBoard[x][y - 1] == Enemy || y < 1))
					{
						scroes = 300000;
						Markes[x][y + 4] += scroes;
					}
					else if (myBoard[x][y - 1] == BoardType::Empty && (myBoard[x][y + 4] == Enemy || y > BOARD_Y - 4))
					{
						scroes = 300000;
						Markes[x][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x + 1][y + 1] == myTeam && myBoard[x + 2][y + 2] == myTeam && myBoard[x + 3][y + 3] == myTeam)
				{
					if (myBoard[x + 4][y + 4] == BoardType::Empty && (myBoard[x - 1][y - 1] == Enemy || x < 1 || y < 1))
					{
						scroes = 300000;
						Markes[x + 4][y + 4] += scroes;
					}
					else if (myBoard[x - 1][y - 1] == BoardType::Empty && (myBoard[x + 4][y + 4] == Enemy || x > BOARD_X - 4 || y > BOARD_Y - 4))
					{
						scroes = 300000;
						Markes[x - 1][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x - 1][y + 1] == myTeam && myBoard[x - 2][y + 2] == myTeam && myBoard[x - 3][y + 3] == myTeam)
				{
					if (myBoard[x - 4][y + 4] == BoardType::Empty && (myBoard[x + 1][y - 1] == Enemy || x > BOARD_X -1 || y <1))
					{
						scroes = 300000;
						Markes[x - 4][y + 4] += scroes;
					}
					else if (myBoard[x + 1][y - 1] == BoardType::Empty && (myBoard[x - 4][y + 4] == Enemy || x < 4 || y > BOARD_Y - 4))
					{
						scroes = 300000;
						Markes[x + 1][y - 1] += scroes;
					}
				}
#pragma endregion
#pragma region 적이 4개인데 하나가 막혔을때
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y] == Enemy && myBoard[x + 2][y] == Enemy && myBoard[x + 3][y] == Enemy)
				{
					if (myBoard[x + 4][y] == BoardType::Empty && (myBoard[x - 1][y] == myTeam || x < 1))
					{
						scroes = 99999;
						Markes[x + 4][y] += scroes;
					}
					else if (myBoard[x - 1][y] == BoardType::Empty && (myBoard[x + 4][y] == myTeam || x > BOARD_X - 4))
					{
						scroes = 99999;
						Markes[x - 1][y] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x][y + 1] == Enemy && myBoard[x][y + 2] == Enemy && myBoard[x][y + 3] == Enemy)
				{
					if (myBoard[x][y + 4] == BoardType::Empty && (myBoard[x][y - 1] == myTeam || y < 1))
					{
						scroes = 99999;
						Markes[x][y + 4] += scroes;
					}
					else if (myBoard[x][y - 1] == BoardType::Empty && (myBoard[x][y + 4] == myTeam || y > BOARD_Y - 4))
					{
						scroes = 99999;
						Markes[x][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y + 1] == Enemy && myBoard[x + 2][y + 2] == Enemy && myBoard[x + 3][y + 3] == Enemy)
				{
					if (myBoard[x + 4][y + 4] == BoardType::Empty && (myBoard[x - 1][y - 1] == myTeam || x < 1 || y < 1))
					{
						scroes = 99999;
						Markes[x + 4][y + 4] += scroes;
					}
					else if (myBoard[x - 1][y - 1] == BoardType::Empty && (myBoard[x + 4][y + 4] == myTeam || x > BOARD_X - 4 || y > BOARD_Y - 4))
					{
						scroes = 99999;
						Markes[x - 1][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x - 1][y + 1] == Enemy && myBoard[x - 2][y + 2] == Enemy && myBoard[x - 3][y + 3] == Enemy)
				{
					if (myBoard[x - 4][y + 4] == BoardType::Empty && (myBoard[x + 1][y - 1] == myTeam || x > BOARD_X-1 || y < 1))
					{
						scroes = 99999;
						Markes[x + 4][y + 4] += scroes;
					}
					else if (myBoard[x + 1][y - 1] == BoardType::Empty && (myBoard[x - 4][y + 4] == myTeam || x < 4 || y > BOARD_Y - 4))
					{
						scroes = 99999;
						Markes[x - 1][y - 1] += scroes;
					}
				}
#pragma endregion
#pragma region 3하고 1띄어있을때 방어
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y] == Enemy && myBoard[x + 2][y] == Enemy)
				{
					if (myBoard[x + 3][y] == BoardType::Empty && myBoard[x + 4][y] == Enemy)
					{
						Markes[x + 3][y] += 30010;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y] == Enemy && myBoard[x + 2][y] == Enemy)
				{
					if (myBoard[x - 1][y] == BoardType::Empty && myBoard[x - 2][y] == Enemy)
					{
						Markes[x - 1][y] += 30010;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x][y + 1] == Enemy && myBoard[x][y + 2] == Enemy)
				{
					if (myBoard[x][y + 3] == BoardType::Empty  && myBoard[x][y + 4] == Enemy)
					{
						scroes = 30010;
						Markes[x][y + 3] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x][y + 1] == Enemy && myBoard[x][y + 2] == Enemy)
				{
					if (myBoard[x][y - 1] == BoardType::Empty  && myBoard[x][y - 2] == Enemy)
					{
						scroes = 30010;
						Markes[x][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y + 1] == Enemy && myBoard[x + 2][y + 2] == Enemy)
				{
					if (myBoard[x + 3][y + 3] == BoardType::Empty && myBoard[x + 4][y + 4] == Enemy)
					{
						scroes = 30010;
						Markes[x + 3][y + 3] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y + 1] == Enemy && myBoard[x + 2][y + 2] == Enemy)
				{
					if (myBoard[x - 1][y -1] == BoardType::Empty && myBoard[x -2][y -2] == Enemy)
					{
						scroes = 30010;
						Markes[x -1][y -1] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x - 1][y + 1] == Enemy && myBoard[x - 2][y + 2] == Enemy)
				{
					if (myBoard[x - 3][y + 3] == BoardType::Empty && myBoard[x - 4][y + 4] == Enemy)
					{
						scroes = 30010;
						Markes[x - 3][y + 3] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x - 1][y + 1] == Enemy && myBoard[x - 2][y + 2] == Enemy)
				{
					if (myBoard[x +1][y -1] == BoardType::Empty && myBoard[x +2][y -2] == Enemy)
					{
						scroes = 30010;
						Markes[x +1][y -1] += scroes;
					}
				}
#pragma endregion
#pragma region 내가 3개일때
				if (myBoard[x][y] == myTeam && myBoard[x][y + 1] == myTeam && myBoard[x][y + 2] == myTeam)
				{
					if (myBoard[x][y + 3] == BoardType::Empty && myBoard[x][y - 1] == BoardType::Empty)
					{
						scroes = 30005;
						Markes[x][y + 3] += scroes;
						Markes[x][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x + 1][y] == myTeam && myBoard[x + 2][y] == myTeam)
				{
					if (myBoard[x + 3][y] == BoardType::Empty && myBoard[x - 1][y] == BoardType::Empty)
					{
						scroes = 30005;
						Markes[x + 3][y] += scroes;
						Markes[x - 1][y] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x + 1][y + 1] == myTeam && myBoard[x + 2][y + 2] == myTeam)
				{
					if (myBoard[x + 3][y + 3] == BoardType::Empty && myBoard[x - 1][y - 1] == BoardType::Empty)
					{
						scroes = 30005;
						Markes[x + 3][y + 3] += scroes;
						Markes[x - 1][y + 3] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x - 1][y + 1] == myTeam && myBoard[x - 2][y + 2] == myTeam)
				{
					if (myBoard[x - 3][y + 3] == BoardType::Empty && myBoard[x + 1][y - 1] == BoardType::Empty)
					{
						scroes = 30005;
						Markes[x - 3][y + 3] += scroes;
						Markes[x + 1][y + 3] += scroes;
					}
				}
#pragma endregion
#pragma region 적이 3개일때
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y] == Enemy && myBoard[x + 2][y] == Enemy)
				{
					if (myBoard[x + 3][y] == BoardType::Empty && myBoard[x - 1][y] == BoardType::Empty)
					{
						scroes = 10000;
						Markes[x + 3][y] += scroes;
						Markes[x - 1][y] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x][y + 1] == Enemy && myBoard[x][y + 2] == Enemy)
				{
					if (myBoard[x][y + 3] == BoardType::Empty  && myBoard[x][y - 1] == BoardType::Empty)
					{
						scroes = 10000;
						Markes[x][y + 3] += scroes;
						Markes[x][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y + 1] == Enemy && myBoard[x + 2][y + 2] == Enemy)
				{
					if (myBoard[x + 3][y + 3] == BoardType::Empty && myBoard[x - 1][y - 1] == BoardType::Empty)
					{
						scroes = 10000;
						Markes[x + 3][y + 3] += scroes;
						Markes[x - 1][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x - 1][y + 1] == Enemy && myBoard[x - 2][y + 2] == Enemy)
				{
					if (myBoard[x - 3][y + 3] == BoardType::Empty && myBoard[x + 1][y - 1] == BoardType::Empty)
					{
						scroes = 10000;
						Markes[x - 3][y + 3] += scroes;
						Markes[x + 1][y - 1] += scroes;
					}
				}

#pragma endregion
#pragma region 1개 띄고 2개, 2개 띄고 1개

				if (myBoard[x][y] == Enemy && myBoard[x + 1][y] == Enemy && myBoard[x + 2][y] == BoardType::Empty && myBoard[x + 3][y] == Enemy )
				{
					if (myBoard[x + 4][y] == BoardType::Empty && myBoard[x - 1][y] == BoardType::Empty)
					{
						Markes[x + 3][y] += 10010;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y] == BoardType::Empty && myBoard[x + 2][y] == Enemy && myBoard[x + 3][y] == Enemy)
				{
					if (myBoard[x + 4][y] == BoardType::Empty && myBoard[x - 1][y] == BoardType::Empty)
					{
						Markes[x + 1][y] += 10010;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x][y + 1] == Enemy && myBoard[x][y + 2] == BoardType::Empty && myBoard[x][y+3] == Enemy)
				{
					if (myBoard[x][y + 4] == BoardType::Empty  && myBoard[x][y - 1] == BoardType::Empty)
					{
						Markes[x][y + 2] += 10010;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x][y + 1] == BoardType::Empty && myBoard[x][y + 2] == Enemy && myBoard[x][y + 3] == Enemy)
				{
					if (myBoard[x][y + 4] == BoardType::Empty  && myBoard[x][y - 1] == BoardType::Empty)
					{
						Markes[x][y + 1] += 10010;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y + 1] == BoardType::Empty && myBoard[x + 2][y + 2] == Enemy && myBoard[x + 3][y + 3] == Enemy)
				{
					if (myBoard[x + 4][y + 4] == BoardType::Empty && myBoard[x - 1][y - 1] == BoardType::Empty)
					{
						Markes[x + 1][y + 1] += 10010;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y + 1] == Enemy && myBoard[x + 2][y + 2] == BoardType::Empty && myBoard[x + 3][y + 3] == Enemy)
				{
					if (myBoard[x + 4][y + 4] == BoardType::Empty && myBoard[x - 1][y - 1] == BoardType::Empty)
					{
						Markes[x + 2][y + 2] += 10010;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x - 1][y + 1] == BoardType::Empty && myBoard[x - 2][y + 2] == Enemy && myBoard[x - 3][y + 3] == Enemy)
				{
					if (myBoard[x - 4][y + 4] == BoardType::Empty && myBoard[x + 1][y - 1] == BoardType::Empty)
					{
						Markes[x - 1][y + 1] += 10010;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x - 1][y + 1] == Enemy && myBoard[x - 2][y + 2] == BoardType::Empty && myBoard[x - 3][y + 3] == Enemy)
				{
					if (myBoard[x - 4][y + 4] == BoardType::Empty && myBoard[x + 1][y - 1] == BoardType::Empty)
					{
						Markes[x - 2][y + 1] += 10010;
					}
				}
#pragma endregion
#pragma region 내가 3개인데 하나가 막혔을때
				if (myBoard[x][y] == myTeam && myBoard[x][y + 1] == myTeam && myBoard[x][y + 2] == myTeam)
				{
					if (myBoard[x][y + 3] == BoardType::Empty && (myBoard[x][y - 1] == Enemy || y < 1))
					{
						scroes = 999;
						Markes[x][y + 3] += scroes;
					}
					else if (myBoard[x][y - 1] == BoardType::Empty && (myBoard[x][y + 3] == Enemy || x > BOARD_Y - 3))
					{
						scroes = 999;
						Markes[x][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x + 1][y] == myTeam && myBoard[x + 2][y] == myTeam)
				{
					if (myBoard[x + 3][y] == BoardType::Empty && (myBoard[x - 1][y] == Enemy || x < 1))
					{
						scroes = 999;
						Markes[x + 3][y] += scroes;
					}
					else if (myBoard[x - 1][y] == BoardType::Empty && (myBoard[x + 3][y] == Enemy || x > BOARD_X - 3))
					{
						scroes = 999;
						Markes[x - 1][y] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x + 1][y + 1] == myTeam && myBoard[x + 2][y + 2] == myTeam)
				{
					if (myBoard[x + 3][y + 3] == BoardType::Empty && (myBoard[x - 1][y - 1] == Enemy || x < 1 || y < 1))
					{
						scroes = 999;
						Markes[x + 3][y + 3] += scroes;
					}
					else if (myBoard[x - 1][y - 1] == BoardType::Empty && (myBoard[x + 3][y + 3] == Enemy || x > BOARD_X - 3 || y > BOARD_Y - 3))
					{
						scroes = 999;
						Markes[x - 1][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x - 1][y + 1] == myTeam && myBoard[x - 2][y + 2] == myTeam)
				{
					if (myBoard[x - 3][y + 3] == BoardType::Empty && (myBoard[x + 1][y - 1] == Enemy || x > BOARD_X-1 || y < 1))
					{
						scroes = 999;
						Markes[x - 3][y + 3] += scroes;
					}
					else if (myBoard[x + 1][y - 1] == BoardType::Empty && (myBoard[x - 3][y + 3] == Enemy || x < 3 || y > BOARD_Y - 3))
					{
						scroes = 999;
						Markes[x + 1][y - 1] += scroes;
					}
				}
#pragma endregion
#pragma region 내가 2개일때
				if (myBoard[x][y] == myTeam && myBoard[x + 1][y] == myTeam)
				{
					if (myBoard[x + 2][y] == BoardType::Empty && myBoard[x - 1][y] == BoardType::Empty)
					{
						scroes = 999;
						Markes[x + 2][y] += scroes;
						Markes[x - 1][y] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x][y + 1] == myTeam)
				{
					if (myBoard[x][y + 2] == BoardType::Empty && myBoard[x][y - 1] == BoardType::Empty)
					{
						scroes = 999;
						Markes[x][y + 2] += scroes;
						Markes[x][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x + 1][y + 1] == myTeam)
				{
					if (myBoard[x + 2][y + 2] == BoardType::Empty && myBoard[x - 1][y - 1] == BoardType::Empty)
					{
						scroes = 999;
						Markes[x + 2][y + 2] += scroes;
						Markes[x - 1][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x - 1][y + 1] == myTeam)
				{
					if (myBoard[x - 2][y + 2] == BoardType::Empty && myBoard[x + 1][y - 1] == BoardType::Empty)
					{
						scroes = 999;
						Markes[x - 2][y + 2] += scroes;
						Markes[x + 1][y - 1] += scroes;
					}
				}
#pragma endregion
#pragma region 2개일떄 띄고 1개 공격

				if (myBoard[x][y] == myTeam && myBoard[x + 1][y] == myTeam)
				{
					if (myBoard[x + 2][y] == BoardType::Empty && myBoard[x - 1][y] == BoardType::Empty && myBoard[x-2][y] == BoardType::Empty)
					{
						myBoard[x - 2][y] += 1010;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x + 1][y] == myTeam)
				{
					if (myBoard[x + 2][y] == BoardType::Empty && myBoard[x - 1][y] == BoardType::Empty && myBoard[x + 3][y] == BoardType::Empty)
					{
						myBoard[x + 3][y] += 1010;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x][y+1] == myTeam)
				{
					if (myBoard[x][y+2] == BoardType::Empty && myBoard[x][y-1] == BoardType::Empty && myBoard[x][y+3] == BoardType::Empty)
					{
						myBoard[x][y+3] += 1010;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x][y + 1] == myTeam)
				{
					if (myBoard[x][y + 2] == BoardType::Empty && myBoard[x][y - 1] == BoardType::Empty && myBoard[x][y-2] == BoardType::Empty)
					{
						myBoard[x][y -2] += 1010;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x+1][y + 1] == myTeam)
				{
					if (myBoard[x+2][y + 2] == BoardType::Empty && myBoard[x-1][y - 1] == BoardType::Empty && myBoard[x-2][y - 2] == BoardType::Empty)
					{
						myBoard[x-2][y - 2] += 1010;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x + 1][y + 1] == myTeam)
				{
					if (myBoard[x + 2][y + 2] == BoardType::Empty && myBoard[x - 1][y - 1] == BoardType::Empty && myBoard[x + 3][y + 3] == BoardType::Empty)
					{
						myBoard[x + 3][y + 3] += 1010;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x - 1][y + 1] == myTeam)
				{
					if (myBoard[x - 2][y + 2] == BoardType::Empty && myBoard[x + 1][y - 1] == BoardType::Empty && myBoard[x + 2][y - 2] == BoardType::Empty)
					{
						myBoard[x + 2][y - 2] += 1010;
					}
				}
				if (myBoard[x][y] == myTeam && myBoard[x - 1][y + 1] == myTeam)
				{
					if (myBoard[x - 2][y + 2] == BoardType::Empty && myBoard[x + 1][y - 1] == BoardType::Empty && myBoard[x - 3][y + 3] == BoardType::Empty)
					{
						myBoard[x + 3][y - 3] += 1010;
					}
				}
#pragma endregion
#pragma region 적이 3개인데 하나 막혔을때
				/*if (myBoard[x][y] == Enemy && myBoard[x + 1][y] == Enemy && myBoard[x + 2][y] == Enemy)
				{
					if (myBoard[x + 3][y] == BoardType::Empty && (myBoard[x - 1][y] == myTeam || x < 1))
					{
						scroes = 200;
						Markes[x + 3][y] += scroes;
					}
					else if (myBoard[x - 1][y] == BoardType::Empty && (myBoard[x + 3][y] == myTeam || x > BOARD_X - 2))
					{
						scroes = 200;
						Markes[x - 1][y] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x][y + 1] == Enemy && myBoard[x][y + 2] == Enemy)
				{
					if (myBoard[x][y + 3] == BoardType::Empty && (myBoard[x][y - 1] == myTeam || y < 1))
					{
						scroes = 200;
						Markes[x][y + 3] += scroes;
					}
					else if (myBoard[x][y - 1] == BoardType::Empty && (myBoard[x][y + 3] == myTeam || y > BOARD_Y - 2))
					{
						scroes = 200;
						Markes[x][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y + 1] == Enemy && myBoard[x + 2][y + 2] == Enemy)
				{
					if (myBoard[x + 3][y + 3] == BoardType::Empty && (myBoard[x - 1][y - 1] == myTeam || x < 1 || y < 1))
					{
						scroes = 200;
						Markes[x + 3][y + 3] += scroes;
					}
					else if (myBoard[x - 1][y - 1] == BoardType::Empty && (myBoard[x + 3][y + 3] == myTeam || x > BOARD_X - 2 || y < BOARD_Y - 2))
					{
						scroes = 200;
						Markes[x - 1][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x - 1][y + 1] == Enemy && myBoard[x - 2][y + 2] == Enemy)
				{
					if (myBoard[x - 3][y + 3] == BoardType::Empty && (myBoard[x + 1][y - 1] == myTeam || x > BOARD_X-1 || y < 1))
					{
						scroes = 200;
						Markes[x - 3][y + 3] += scroes;
					}
					else if (myBoard[x + 1][y - 1] == BoardType::Empty && (myBoard[x - 3][y + 3] == myTeam || x <3 || y > BOARD_Y - 3))
					{
						scroes = 200;
						Markes[x + 1][y - 1] += scroes;
					}*/
				

#pragma endregion
#pragma region 내가 1개일때
				if (myBoard[x][y] == myTeam)
				{
					if (myBoard[x + 1][y] == BoardType::Empty)
					{
						Markes[x + 1][y] += 99;
					}
				}
				if (myBoard[x][y] == myTeam)
				{
					if (myBoard[x][y + 1] == BoardType::Empty)
					{
						Markes[x][y + 1] += 99;
					}
				}
				if (myBoard[x][y] == myTeam)
				{
					if (myBoard[x + 1][y + 1] == BoardType::Empty)
					{
						Markes[x + 1][y + 1] += 99;
					}
				}
				if (myBoard[x][y] == myTeam)
				{
					if (myBoard[x + 1][y - 1] == BoardType::Empty)
					{
						Markes[x + 1][y - 1] += 99;
					}
				}
#pragma endregion
#pragma region 적이 2개일때
				/*if (myBoard[x][y] == Enemy && myBoard[x + 1][y] == Enemy)
				{
					if (myBoard[x + 2][y] == BoardType::Empty && myBoard[x - 1][y] == BoardType::Empty)
					{
						scroes = 30;
						Markes[x + 2][y] += scroes;
						Markes[x - 1][y] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x][y + 1] == Enemy)
				{
					if (myBoard[x][y + 2] == BoardType::Empty && myBoard[x][y - 1] == BoardType::Empty)
					{
						scroes = 30;
						Markes[x][y + 2] += scroes;
						Markes[x][y - 1] += scroes;
					}
				}
				if (myBoard[x][y] == Enemy && myBoard[x + 1][y + 1] == Enemy)
				{
					if (myBoard[x + 2][y + 2] == BoardType::Empty && myBoard[x - 1][y - 1] == BoardType::Empty)
					{
						scroes = 30;
						Markes[x + 2][y + 2] += scroes;
						Markes[x - 1][y - 1] += scroes;
					}
				}*/
#pragma endregion
#pragma region 첫 수
				if (myBoard[Enemy_x][Enemy_y] == BoardType::Empty)
				{
					Markes[Enemy_x][Enemy_y] += 5;
				}
				else
				{
					rec(Enemy_x, Enemy_y);
					Markes[Enemy_x][Enemy_y] += 3;
					
					/*myBoard[x][y] == Enemy;
					Markes[x-1][y] += 3;
					Markes[x+1][y] += 3;
					Markes[x][y-1] += 3;
					Markes[x][y+1] += 3;
					Markes[x-1][y-1] += 3;
					Markes[x-1][y+1] += 3;
					Markes[x+1][y-1] += 3;
					Markes[x+1][y+1] += 3;*/

				}

#pragma endregion
#pragma region 3,3경우수
				/*if (myBoard[x][y+1] == myTeam && myBoard[x][y +2] == myTeam &&  myBoard[x+1][y] == myTeam && myBoard[x + 2][y] == myTeam )
				{
					if ( myBoard[x][y + 3] == BoardType::Empty && myBoard[x][y - 1] == BoardType::Empty && myBoard[x + 3][y] == BoardType::Empty && myBoard[x - 1][y] == BoardType::Empty)
					{
						Markes[x][y] = 0;
					}
				}
				if (myBoard[x][y + 1] == myTeam && myBoard[x][y + 2] == myTeam && myBoard[x+1][y+1] == myTeam && myBoard[x + 2][y + 2] == myTeam)
				{
					if (myBoard[x][y + 3] == BoardType::Empty && myBoard[x][y - 1] == BoardType::Empty && myBoard[x + 2][y + 2] == BoardType::Empty && myBoard[x - 1][y - 1] == BoardType::Empty)
					{
						Markes[x][y] = 0;
					}
				}
				if (myBoard[x + 1][y] == myTeam && myBoard[x + 2][y] == myTeam && myBoard[x + 1][y + 1] == myTeam && myBoard[x + 2][y + 2] == myTeam)
				{
					if (myBoard[x + 3][y] == BoardType::Empty && myBoard[x - 1][y] == BoardType::Empty && myBoard[x + 2][y + 2] == BoardType::Empty && myBoard[x - 1][y - 1] == BoardType::Empty)
					{
						Markes[x][y] = 0;
					}
				}*/

#pragma endregion
#pragma region 이미 돌이 있을경우
				if (myBoard[x][y] == BoardType::Black || myBoard[x][y] == BoardType::White)
				{
					Markes[x][y] = 0;
				}
#pragma endregion

			}
		}
	}

	void Attack(int *_x, int *_y)
	{
		int Max = 0;
		int Max_x = 0, Max_y = 0;
		Search();
		for (int y = 0; y < BOARD_Y; y++)
			for (int x = 0; x < BOARD_X; x++)
			{
				if (Markes[x][y] > Max)
				{
					Max = Markes[x][y];
					Max_x = x;
					Max_y = y;
				}
			}
		*_x = Max_x;
		*_y = Max_y;
		myBoard[Max_x][Max_y] = myTeam;
	}

	void Defence(int x, int y)
	{
		myBoard[x][y] = Enemy;
		Enemy_x = x;
		Enemy_y = y;
	}
}