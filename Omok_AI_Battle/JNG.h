#pragma once
#include "Global.h"

namespace JNG
{
	BoardType MYCOLOR = BoardType::Black;
	BoardType ENEMY = BoardType::White;

	struct AiData
	{
		int	type;
		double		weight;
		bool		checked;
	};
	AiData aiBoard[BOARD_X][BOARD_Y] = { 0, 1.0, false };
	bool isFirstRun = true;
	int checkPos[8][2] = {
		{ -1, 1 },
		{ 0, 1 },
		{ 1, 1 },
		{ 1, 0 },
		{ 1, -1 },
		{ 0, -1 },
		{ -1, -1 },
		{ -1, 0 }
	};

	void InitAiBoard()
	{
		// 탐색 초기화


		if (isFirstRun)
		{
			for (int i = 0; i < BOARD_Y; i++)
				for (int j = 0; j < BOARD_X; j++)
				{
					aiBoard[i][j].type = BoardType::Empty;
					aiBoard[i][j].checked = false;
					aiBoard[i][j].weight = 1.0;

				}

			isFirstRun = false;
		}
		else
		{
			for (int i = 0; i < BOARD_Y; i++)
				for (int j = 0; j < BOARD_X; j++)
				{
					aiBoard[i][j].weight = 1.0;

				}
		}

	}

	void Defence(int x, int y)
	{
		InitAiBoard();
		if (aiBoard[x][y].type == BoardType::Empty)
			aiBoard[x][y].type = ENEMY;

	}

	void SetBoardWeight()
	{
		for (int k = 0; k < 8; k++)
		{
			for (int i = 0; i < BOARD_Y; i++)
				for (int j = 0; j < BOARD_X; j++)
				{
					aiBoard[i][j].checked = false;

				}
			for (int i = 0; i < BOARD_Y; i++)
			{
				for (int j = 0; j < BOARD_Y; j++)
				{
					// 적
					if (aiBoard[i][j].type == ENEMY && aiBoard[i][j].checked == false)
					{
						int cnt = 0;
						int tx = i, ty = j;
						while (aiBoard[tx][ty].type == ENEMY &&
							tx >= 0 && ty >= 0 && tx <= BOARD_Y && ty <= BOARD_Y)
						{
							cnt++;
							aiBoard[tx][ty].checked = true;
							tx += checkPos[k][0];
							ty += checkPos[k][1];
						}

						bool c1 = false;
						bool c2 = false;
						if (i - checkPos[k][0] >= 0 && j - checkPos[k][1] >= 0 && i - checkPos[k][0] <= BOARD_Y && j - checkPos[k][1] <= BOARD_Y)
						{
							c1 = true;
							if (aiBoard[i - checkPos[k][0]][j - checkPos[k][1]].type == 0 &&
								aiBoard[tx + checkPos[k][0]][ty + checkPos[k][1]].type == 0)
							{
								aiBoard[i - checkPos[k][0]][j - checkPos[k][1]].weight *= pow(2.1, cnt * cnt);								
							}

							else
								aiBoard[i - checkPos[k][0]][j - checkPos[k][1]].weight *= pow(1.8, cnt * cnt);
						}

						if (tx + checkPos[k][0] >= 0 && ty + checkPos[k][1] >= 0 && tx + checkPos[k][0] <= BOARD_Y && ty + checkPos[k][1] <= BOARD_Y)
						{
							c2 = true;
							if (aiBoard[i - checkPos[k][0]][j - checkPos[k][1]].type == 0 &&
								aiBoard[tx + checkPos[k][0]][ty + checkPos[k][1]].type == 0)
							{
								aiBoard[tx][ty].weight *= pow(2.1, cnt * cnt);
								if (cnt == 4)
									aiBoard[tx][ty].weight = INT_MAX-250;
																	
							}
							else
							{
								aiBoard[tx][ty].weight *= pow(1.8, cnt * cnt);
								if (cnt == 4)
									aiBoard[tx][ty].weight = INT_MAX-150;
							}
							if (c1&& c2 && cnt == 3)
							{
								aiBoard[i - checkPos[k][0]][j - checkPos[k][1]].weight = INT_MAX - 100;
							}								
						}
						
					}
					if (aiBoard[i][j].type == MYCOLOR && aiBoard[i][j].checked == false)
					{
						for (int l = 0; l < 8; l++)
						{
							if (i + checkPos[l][0] >= 0 && j + checkPos[l][1] >= 0 && i + checkPos[l][0] <= BOARD_Y && j + checkPos[l][1] <= BOARD_Y)
								aiBoard[i + checkPos[l][0]][j + checkPos[l][1]].weight *= 1.08;
						}

						int cnt = 0;
						int tx = i, ty = j;
						while (aiBoard[tx][ty].type == MYCOLOR &&
							tx >= 0 && ty >= 0 && tx <= BOARD_Y && ty <= BOARD_Y)
						{
							cnt++;
							aiBoard[tx][ty].checked = true;
							tx += checkPos[k][0];
							ty += checkPos[k][1];
						}
						if (cnt > 1)
						{
							if (i - checkPos[k][0] >= 0 && j - checkPos[k][1] >= 0 && i - checkPos[k][0] <= BOARD_Y && j - checkPos[k][1] <= BOARD_Y)
								aiBoard[i - checkPos[k][0]][j - checkPos[k][1]].weight *= pow(2.1, cnt * cnt * 2);
							if (tx + checkPos[k][0] >= 0 && ty + checkPos[k][1] >= 0 && tx + checkPos[k][0] <= BOARD_Y && ty + checkPos[k][1] <= BOARD_Y)
								aiBoard[tx][ty].weight *= pow(1.8, cnt * cnt * 2);
						}
						if (cnt == 3)
						{
							if (i - checkPos[k][0] >= 0 && j - checkPos[k][1] >= 0 && i - checkPos[k][0] <= BOARD_Y && j - checkPos[k][1] <= BOARD_Y)
								aiBoard[i - checkPos[k][0]][j - checkPos[k][1]].weight = INT_MAX - 200;

							if (tx + checkPos[k][0] >= 0 && ty + checkPos[k][1] >= 0 && tx + checkPos[k][0] <= BOARD_Y && ty + checkPos[k][1] <= BOARD_Y)
								aiBoard[tx][ty].weight = INT_MAX - 200;
						}
						if (cnt == 4)
						{
							if (i - checkPos[k][0] >= 0 && j - checkPos[k][1] >= 0 && i - checkPos[k][0] <= BOARD_Y && j - checkPos[k][1] <= BOARD_Y)
								aiBoard[i - checkPos[k][0]][j - checkPos[k][1]].weight = INT_MAX;
							if (tx + checkPos[k][0] >= 0 && ty + checkPos[k][1] >= 0 && tx + checkPos[k][0] <= BOARD_Y && ty + checkPos[k][1] <= BOARD_Y)
								aiBoard[tx][ty].weight = INT_MAX;
						}
					}
									
				}
			}
		}
	}

	void SetPlacePosition(int* x, int* y)
	{
		int placeX = 0;
		int placeY = 0;
		double maxWeight = 0.0;

		for (int i = 0; i < BOARD_Y; i++)
		{
			for (int j = 0; j < BOARD_X; j++)
			{
				if (aiBoard[i][j].weight > maxWeight && aiBoard[i][j].type == BoardType::Empty)
				{
					placeX = i, placeY = j;
					maxWeight = aiBoard[i][j].weight;
				}
			}
		}


		*x = placeX;
		*y = placeY;
		if (x == 0 && y == 0)
		{
			*x = 9;
			*y = 9;
		}
		aiBoard[placeX][placeY].type = MYCOLOR;

	}

	void Attack(int *x, int *y)
	{
		SetBoardWeight();
		SetPlacePosition(x, y);
	}

}