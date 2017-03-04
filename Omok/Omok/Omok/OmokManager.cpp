#include "OmokManager.h"

void OmokManager::ShowMenu()
{
	cout << "-----����ִ� ������� v1.0-----" << endl;
	cout << "1 : ������� ����" << endl;
	cout << "2 : ������� �ܰ躰 �ҷ�����" << endl;
	cout << "3 : ������� �ð��� �ҷ�����" << endl;
	cout << "4 : ����" << endl;
}

void OmokManager::Draw()
{
	cout << "\t 1 2 3 4 5 6 7 8 910111213141516171819" << endl << endl;
	for (int x = 0; x < BOARD_X; x++)									// ������.
	{
		cout << x + 1 << "\t";
		for (int y = 0; y < BOARD_Y; y++)								// ������.
		{
			switch (board[x][y])
			{
			case BoardType::Empty:
				cout << "��";
				break;
			case BoardType::Black:
				cout << "��";
				break;
			case BoardType::White:
				cout << "��";
				break;
			}
		}
		cout << endl;
	}
}

void OmokManager::Play()
{
	ofstream of("replay.txt");
	int bw = 0;
	int x = 0;
	int y = 0;
	string point;
	int start;

	while (true)
	{
		start = GetTickCount();
		
		char token = ',';

		if (bw % 2 == 0)
		{
			string color = bw % 2 == 0 ? "��" : "��";
			cout << color << " ��ǥ�� �Է����ּ���(ex : 4,2)(-1 = ����) :";

			cin >> x >> token >> y;													//�Է¹޴� �κ�.

			if (true == cin.fail())
			{
				cout << "�߸� �Է��Ͽ����ϴ� �ٽ� �Է����ּ���" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				continue;
			}

			if (x == -1 || y == -1)											//�����ϴ� �κ�.
			{
				of.close();
				cout << "����Ǿ����ϴ�." << endl;
				BoardClear();
				return;
			}

			x -= 1;
			y -= 1;

			AIDefence(x, y);
		}
		else
		{
			AIAttack(&x, &y);
		}

		of << GetTickCount() - start << endl;
		of << x << token << y << endl;
		
		PutStone(bw, x, y);

		if (GameState::None != CheckEnd())
		{
			cout << "���ӳ�" << endl;
			BoardClear();
			break;
		}
	}
}

void OmokManager::RePlay()
{
	ifstream file("replay.txt");

	char token;
	int elapsedTime;
	int checkTime;
	int x;
	int y;
	int bw = 0;

	while (file.eof() == false)
	{
		file >> elapsedTime;
		file >> x >> token >> y;

		checkTime = GetTickCount();

		while (GetTickCount() - checkTime < elapsedTime)
		{
			
		}

		PutStone(bw, x, y);
	}
}

GameState OmokManager::CheckEnd()
{
	for (int x = 0; x < BOARD_X; x++)
	{
		for (int y = 0; y < BOARD_Y; y++)
		{
			if (OmokManager::CheckX(x, y, BoardType::Black) == 5 || OmokManager::CheckY(x, y, BoardType::Black) == 5 || OmokManager::CheckXY(x, y, BoardType::Black) == 5)
			{
				puts("�浹�� ����Ͽ����ϴ�!!");
				return GameState::WinBlack;
			}

			if (OmokManager::CheckX(x, y, BoardType::White) == 5 || OmokManager::CheckY(x, y, BoardType::White) == 5 || OmokManager::CheckXY(x, y, BoardType::White) == 5)
			{
				puts("�鵹�� ����Ͽ����ϴ�!!");
				return GameState::WinWhite;
			}
		}
	}

	return GameState::None;
}

void OmokManager::SetAI(void(*pAIAttack)(int *x, int *y), void(*pAIDefence)(int x, int y))
{
	AIAttack = pAIAttack;
	AIDefence = pAIDefence;
}

int OmokManager::CheckX(int x, int y, BoardType type)
{
	int count = 0;

	if (board[x][y] == type)
		count++;
	if (x < BOARD_X - 1 && board[x + 1][y] == type)
		count++;
	if (x < BOARD_X - 2 && board[x + 2][y] == type)
		count++;
	if (x < BOARD_X - 3 && board[x + 3][y] == type)
		count++;
	if (x < BOARD_X - 4 && board[x + 4][y] == type)
		count++;

	return count;
}

int OmokManager::CheckY(int x, int y, BoardType type)
{
	int count = 0;
	
	if (board[x][y] == type)
		count++;
	if (y < BOARD_Y - 1 && board[x][y + 1] == type)
		count++;
	if (y < BOARD_Y - 2 && board[x][y + 2] == type)
		count++;
	if (y < BOARD_Y - 3 && board[x][y + 3] == type)
		count++;
	if (y < BOARD_Y - 4 && board[x][y + 4] == type)
		count++;

	return count;
}

int OmokManager::CheckXY(int x, int y, BoardType type)
{
	int count = 0;

	if (board[x][y] == type)
		count++;
	if (x < BOARD_X - 1 && y < BOARD_Y - 1 && board[x + 1][y + 1] == type)
		count++;
	if (x < BOARD_X - 2 && y < BOARD_Y - 2 && board[x + 2][y + 2] == type)
		count++;
	if (x < BOARD_X - 3 && y < BOARD_Y - 3 && board[x + 3][y + 3] == type)
		count++;
	if (x < BOARD_X - 4 && y < BOARD_Y - 4 && board[x + 4][y + 4] == type)
		count++;

	return count;
}

void OmokManager::BoardClear()
{
	for (int x = 0; x < BOARD_X; x++)
	{
		for (int y = 0; y < BOARD_Y; y++)
		{
			board[x][y] = BoardType::Empty;
		}
	}
}

void OmokManager::PutStone(int &bw, int x, int y)
{
	if (x >= 0 && x<BOARD_X && y >= 0 && y<BOARD_Y)
	{
		if (board[x][y] != 0)										//�ʵ����Ϳ� ���� �������� üũ.
		{
			cout << "���� ������ �ִ� ��ġ�Դϴ�." << endl;
		}
		else
		{
			board[x][y] = (bw % 2) + 1;								//�ʵ����Ϳ� �����ϴ� �κ�.

			bw++;												//����� �׷��ִ� �κ�.
			system("cls");
			Draw();
		}
	}
	else
	{
		cout << "������ ���� ��ġ�Դϴ�." << endl;
	}
}