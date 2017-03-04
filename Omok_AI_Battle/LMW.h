#pragma once

#ifndef LAI_H_
#define LAI_H_

#include "Global.h"

#include <math.h>
#include <cstdlib>
#include <ctime>
#include <list>


#endif // !1

using namespace std;

namespace LMW 
{

	int myBoard[BOARD_X][BOARD_Y] = { BoardType::Empty };

	BoardType myTeam = BoardType::Black;

	int TempX;
	int TempY;

	struct StonePoint {

	public:
		int x;
		int y;

		StonePoint() {}

		StonePoint(int _x, int _y) {
			x = _x;
			y = _y;
		}
	};

	list<StonePoint> Enemy;

	list<StonePoint> MyStone;

	BoardType EnemyT;

	void CHeckerDone() {

		while (true) {
			srand((unsigned int)time(NULL));

			int dx = 0;
			int dy = 0;

			int t = rand() % Enemy.size();

			int d = rand() % 8;

			list<StonePoint>::iterator C;

			C = Enemy.begin();

			for (int i = 0; i < t; i++) {
				C++;
			}

			switch (d)
			{
			case 0:
				dx = 1;
				dy = 0;
				break;
			case 1:
				dx = 1;
				dy = 1;
				break;
			case 2:
				dx = 0;
				dy = 1;
				break;
			case 3:
				dx = -1;
				dy = 1;
				break;
			case 4:
				dx = 0;
				dy = -1;
				break;
			case 5:
				dx = -1;
				dy = -1;
				break;
			case 6:
				dx = 0;
				dy = -1;
				break;
			case 7:
				dx = 1;
				dy = -1;
				break;
			default:
				break;
			}


			//	cout << "InDone : "<< d << endl;

			if (myBoard[C->x + dx][C->y + dy] == BoardType::Empty) {
				myBoard[C->x + dx][C->y + dy] = myTeam;

				//		MyStone.push_back(StonePoint(C->x + dx, C->y + dy));

				TempX = C->x + dx;
				TempY = C->y + dy;
				break;
			}
			else {
				continue;
			}

		}
	}


	bool DoPutMyStone(int _x, int _y, StonePoint Ch1, bool attack) {

		int tx = _x + _x;
		int ty = _y + _y;

		BoardType Temp;

		BoardType TempR;

		if (attack) {
			Temp = myTeam;
			TempR = EnemyT;
		}
		else {
			Temp = EnemyT;
			TempR = myTeam;
		}

		if (myBoard[Ch1.x + tx][Ch1.y + ty] == Temp) {

			if (myBoard[Ch1.x + (tx + _x)][Ch1.y + (ty + _y)] == Temp) {
				if (myBoard[Ch1.x + (tx + _x + _x)][Ch1.y + (ty + _y + _y)] == BoardType::Empty) {
					myBoard[Ch1.x + (tx + _x + _x)][Ch1.y + (ty + _y + _y)] = myTeam;

					//MyStone.push_back(StonePoint(Ch1.x + (tx + _x + _x), Ch1.y + (ty + _y + _y)));

					TempX = Ch1.x + (tx + _x + _x);
					TempY = Ch1.y + (ty + _y + _y);

					return true;
				}
			}
			else {
				if (myBoard[Ch1.x + (tx + _x)][Ch1.y + (ty + _y)] == BoardType::Empty) {

					/*if (!attack) {
						if (myBoard[Ch1.x - _x][Ch1.y - _y] == TempR) {
							return false;
						}
					}
					else {*/

					myBoard[Ch1.x + (tx + _x)][Ch1.y + (ty + _y)] = myTeam;

					//MyStone.push_back(StonePoint(Ch1.x + (tx + _x), Ch1.y + (ty + _y)));

					TempX = Ch1.x + (tx + _x);
					TempY = Ch1.y + (ty + _y);

					return true;

					//	}
				}
			}
		}
		else {
			if (myBoard[Ch1.x + (tx + _x)][Ch1.y + (ty + _y)] == Temp) {
				if (myBoard[Ch1.x + tx][Ch1.y + ty] == BoardType::Empty) {
					myBoard[Ch1.x + tx][Ch1.y + ty] = myTeam;

					//MyStone.push_back(StonePoint(Ch1.x + tx, Ch1.y + ty));

					TempX = Ch1.x + (tx);
					TempY = Ch1.y + (ty);

					return true;
				}
			}
		}

		return false;
	}


	void DoAttack() {

		//cout << "DoAttack" << endl;

		//MyStone.clear();

		list<StonePoint>::iterator FirstCheck;

		list<StonePoint>::iterator NextChecker;


		if (MyStone.size() <= 1) {
			CHeckerDone();
		}
		else {

			bool checker = true;

			for (FirstCheck = MyStone.begin(); FirstCheck != MyStone.end(); FirstCheck++)
			{
				for (NextChecker = MyStone.begin(); NextChecker != MyStone.end(); NextChecker++)
				{
					if (abs(FirstCheck->x - NextChecker->x) == 1 && abs(FirstCheck->y - NextChecker->y) == 1) {

						if (NextChecker->x - FirstCheck->x == 1 && -FirstCheck->y == 1) {
							checker = DoPutMyStone(1, 1, *FirstCheck, true);
						}
						else if (NextChecker->x - FirstCheck->x == -1 && NextChecker->y - FirstCheck->y == 1) {
							checker = DoPutMyStone(-1, 1, *FirstCheck, true);
						}
						else if (NextChecker->x - FirstCheck->x == 1 && NextChecker->y - FirstCheck->y == -1) {
							checker = DoPutMyStone(1, -1, *FirstCheck, true);
						}
						else if (NextChecker->x - FirstCheck->x == -1 && NextChecker->y - FirstCheck->y == -1) {
							checker = DoPutMyStone(-1, -1, *FirstCheck, true);
						}
					}
					else if (abs(FirstCheck->x - NextChecker->x) == 1) {
						if (NextChecker->x - FirstCheck->x == 1) {
							checker = DoPutMyStone(1, 0, *FirstCheck, true);
						}
						else {
							checker = DoPutMyStone(-1, 0, *FirstCheck, true);
						}
					}
					else if (abs(FirstCheck->y - NextChecker->y) == 1) {
						if (NextChecker->y - FirstCheck->y == 1) {
							checker = DoPutMyStone(0, 1, *FirstCheck, true);
						}
						else {
							checker = DoPutMyStone(0, -1, *FirstCheck, true);
						}
					}
				}
			}

			if (!checker) {
				CHeckerDone();
			}
		}

	}


	void SetList() {
		Enemy.clear();
		MyStone.clear();

		for (int i = 0; i < BOARD_X; i++) {
			for (int j = 0; j < BOARD_Y; j++) {
				if (myBoard[i][j] == EnemyT) {
					Enemy.push_back(StonePoint(i, j));
				}
				else if (myBoard[i][j] == myTeam) {
					MyStone.push_back(StonePoint(i, j));
				}
			}
		}
	}

	void Attack(int *retX, int * retY)
	{

		//cout << "attack" << endl;

		if (myTeam == BoardType::White) {

			EnemyT = BoardType::Black;
		}
		else {

			EnemyT = BoardType::White;
		}


		SetList();

		list<StonePoint>::iterator FirstCheck;

		list<StonePoint>::iterator NextChecker;

		/*for (FirstCheck = Enemy.begin(); FirstCheck != Enemy.end(); FirstCheck++) {
			cout <<"EnemyTile : "<<Enemy.size() << " - " <<FirstCheck->x << " : " << FirstCheck->y << endl;
		}*/

		if (Enemy.size() == 0) {

			myBoard[BOARD_X / 2][BOARD_X / 2] = myTeam;

			TempX = BOARD_X / 2;
			TempY = BOARD_X / 2;

		}
		else if (Enemy.size() == 1) {
			CHeckerDone();
		}
		else {

			bool checker = true;

			for (FirstCheck = Enemy.begin(); FirstCheck != Enemy.end(); FirstCheck++) {
				for (NextChecker = Enemy.begin(); NextChecker != Enemy.end(); NextChecker++) {
					if (abs(FirstCheck->x - NextChecker->x) == 1 && abs(FirstCheck->y - NextChecker->y) == 1) {
						if (NextChecker->x - FirstCheck->x == 1 && NextChecker->y - FirstCheck->y == 1) {
							checker = DoPutMyStone(1, 1, *FirstCheck, false);
							if (checker) {
								break;
							}
						}
						else if (NextChecker->x - FirstCheck->x == -1 && NextChecker->y - FirstCheck->y == 1) {
							checker = DoPutMyStone(-1, 1, *FirstCheck, false);
							if (checker) {
								break;
							}
						}
						else if (NextChecker->x - FirstCheck->x == 1 && NextChecker->y - FirstCheck->y == -1) {
							checker = DoPutMyStone(1, -1, *FirstCheck, false);
							if (checker) {
								break;
							}
						}
						else if (NextChecker->x - FirstCheck->x == -1 && NextChecker->y - FirstCheck->y == -1) {
							checker = DoPutMyStone(-1, -1, *FirstCheck, false);
							if (checker) {
								break;
							}
						}
					}
					else if (abs(FirstCheck->x - NextChecker->x) == 1) {
						if (NextChecker->x - FirstCheck->x == 1) {

							/*if (myBoard[FirstCheck->x + 2][FirstCheck->y] == EnemyT) {
								if (myBoard[FirstCheck->x + 3][FirstCheck->y] == EnemyT) {
									myBoard[FirstCheck->x + 4][FirstCheck->y] = myTeam;
								}
								else {
									myBoard[FirstCheck->x + 3][FirstCheck->y] = myTeam;
								}
							}*/

							checker = DoPutMyStone(1, 0, *FirstCheck, false);
							if (checker) {
								break;
							}
						}
						else {

							/*if (myBoard[FirstCheck->x - 2][FirstCheck->y] == EnemyT) {
								if (myBoard[FirstCheck->x - 3][FirstCheck->y] == EnemyT) {
									myBoard[FirstCheck->x - 4][FirstCheck->y] = myTeam;
								}
								else {
									myBoard[FirstCheck->x - 3][FirstCheck->y] = myTeam;
								}
							}*/

							checker = DoPutMyStone(-1, 0, *FirstCheck, false);
							if (checker) {
								break;
							}
						}
					}
					else if (abs(FirstCheck->y - NextChecker->y) == 1) {
						if (NextChecker->y - FirstCheck->y == 1) {
							checker = DoPutMyStone(0, 1, *FirstCheck, false);
							if (checker) {
								break;
							}
						}
						else {
							checker = DoPutMyStone(0, -1, *FirstCheck, false);
							if (checker) {
								break;
							}
						}
					}
				}


				if (checker) {
					break;
				}
			}

			if (!checker) {
				DoAttack();
			}
		}

		*retX = TempX + 1;
		*retY = TempY + 1;

		//	cout << "Attack - " << *retX << " : " << *retY << endl;
	}

	/*void DrawMyBoard() {
		cout << endl << endl << endl << "MyBoard" << endl;
		cout << "\t 1 2 3 4 5 6 7 8 910111213141516171819" << endl << endl;
		for (int y = 0; y < BOARD_Y; ++y) // 세로줄
		{
			cout << y + 1 << "\t";
			for (int x = 0; x < BOARD_X; ++x) // 가로줄
			{
				switch (myBoard[x][y])
				{
				case BoardType::Empty:
					cout << "┼";
					break;
				case BoardType::Black:
					cout << "○";
					break;
				case BoardType::White:
					cout << "●";
					break;
				}
			}
			cout << endl;
		}
		cout << endl << endl << endl;
	}
	*/


	void Defence(int x, int y)
	{

		//x = x - 1;
		//y = y - 1;

		if (myTeam == BoardType::White) {
			EnemyT = BoardType::Black;
		}
		else {
			EnemyT = BoardType::White;
		}

		//	DrawMyBoard();
	}

}