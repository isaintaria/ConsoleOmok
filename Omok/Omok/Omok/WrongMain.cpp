/*
#include <iostream>
#include <Windows.h>//system("cls");를 쓰기위해선언
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include <string>

using namespace std;

void menu();
void drawomok(int(*arr)[19]);
void playomok();
void loadomoklevel();
void loadomoktime();
int victory(int(*arr)[19]);

vector <pair<int, int>> v;

int main()
{
	int ch;
	int arr[19][19] = { 0 };
	while (1)
	{
		menu();
		cout << "번호를 입력해주세요 :";
		cin >> ch;

		if (true == cin.fail())
		{
			cout << "잘못 입력하였습니다 다시 입력해주세요" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}

		switch (ch)
		{
		case 1:
		{
			drawomok(arr);
			playomok();
			break;
		}
		case 2:
		{
			loadomoklevel();
			break;
		}
		case 3:
		{
			loadomoktime();
			break;
		}
		case 4:
		{
			cout << "감사합니다^^" << endl;
			return 0;
		}
		default:
		{
			cout << "번호를 잘못 입력하셨습니다." << endl;
			break;
		}
		}
	}
}

void menu()
{
	cout << "-----재미있는 오목게임 v1.0-----" << endl;
	cout << "1 : 오목게임 실행" << endl;
	cout << "2 : 오목게임 단계별 불러오기" << endl;
	cout << "3 : 오목게임 시간별 불러오기" << endl;
	cout << "4 : 종료" << endl;
}

void drawomok(int(*arr)[19])
{
	int i, j;
	cout << "-----재미있는 오목게임 v1.0-----" << endl;
	cout << "\t 1 2 3 4 5 6 7 8 910111213141516171819" << endl << endl;
	for (i = 0; i<19; i++)
	{
		cout << i + 1 << "\t";
		for (j = 0; j<19; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << "┼";
			}
			if (arr[i][j] == 1)
			{
				cout << "○";
			}
			if (arr[i][j] == 2)
			{
				cout << "●";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void playomok()
{
	int arr[19][19] = { 0 };
	int i = 0;
	int j = 0;
	int bw = 0;
	int start, end;
	ofstream of("replay.txt");

	while (1)
	{
		pair<int, int> p;
		
		string color = bw % 2 == 0 ? "흑" : "백";
		cout << color << " 좌표를 입력해주세요(ex : 4,2)(1=저장):"; //bw가 0이면 흑 아니면 백
		start = GetTickCount();
		char token = ',';
		cin >> i >> token >> j;

		if (true == cin.fail())
		{
			cout << "잘못 입력하였습니다 다시 입력해주세요" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}

		end = GetTickCount();
		p.first = start;
		p.second = end;
		v.push_back(p);

		if (i < 20 && j < 20 && i > 0 && j > 0)
		{
			if (arr[i - 1][j - 1] == 0)
			{
				p.first = i;
				p.second = j;
				v.push_back(p);

				arr[i - 1][j - 1] = (bw % 2) + 1;//배열 i-1,j-1 에 bw를 2로 나눈 나머지에 1을 더한값을 넣는다.
				bw++;
				system("cls"); //깔끔한 오목게임을위해 페이지 지우고 다시그림
				drawomok(arr);
			}
			else
			{
				cout << "중복된 좌표입니다";
			}
		}

		else if (i == 1)
		{
			for (auto r = v.begin(); r<v.end(); ++r)
			{
				of << endl << r->first << "," << r->second;
			}
			of.close();
			cout << "저장되었습니다.";
			return;
		}
		else
		{
			cout << "허용되지 않은 좌표입니다";
		}

		//승리조건 호출
		if (victory(arr) == 0)
		{
			//승리시에도 기보를 자동 저장한다.
			for (auto r = v.begin(); r<v.end(); ++r)
			{
				of << endl << r->first << "," << r->second;
			}
			of.close();
			return;
		}
	}
}

void loadomoklevel()
{
	int arr[19][19] = { 0 };
	int i, j;
	int bw = 0;
	int start, end;
	pair<int, int> p;
	char com;
	ifstream fin("replay.txt");
	char input;
	v.clear();
	while (!fin.eof())
	{
		fin >> p.first >> com >> p.second;
		v.push_back(p);
		if (p.first>20)
			continue;
		arr[p.first - 1][p.second - 1] = (bw % 2) + 1;//배열 i-1,j-1 에 bw를 2로 나눈 나머지에 1을 더한값을 넣는다.
		bw++;
		input = getch();
		if (input == ' ')
		{
			system("cls");
			drawomok(arr);
		}
	}

	//판을 불러온상태로 승리조건 호출
	if (victory(arr) == 0)
	{
		fin.close();
		return;
	}

	//불러온후 파일에 이어서 기보를 작성하고 오목게임을 진행함
	ofstream of("replay.txt");

	while (1)
	{
		fflush(stdin);//버퍼를 비움, scanf 에 다른값이 절대 들어올수 없게함!!
		i = 0, j = 0;
		printf("%s 좌표를 입력해주세요(ex : 4,2)(1=저장):", bw % 2 == 0 ? "흑" : "백");//bw가 0이면 흑 아니면 백
		start = GetTickCount();
		scanf("%d,%d", &i, &j);
		end = GetTickCount();
		p.first = start;
		p.second = end;
		v.push_back(p);

		if (i<20 && j<20 && i>0 && j>0)
		{
			if (arr[i - 1][j - 1] == 0)
			{
				p.first = i;
				p.second = j;
				v.push_back(p);

				arr[i - 1][j - 1] = (bw % 2) + 1;//배열 i-1,j-1 에 bw를 2로 나눈 나머지에 1을 더한값을 넣는다.
				bw++;
				system("cls");//깔끔한 오목게임을위해 페이지 지우고 다시그림
				drawomok(arr);
			}
			else
			{
				puts("중복된 좌표입니다");
			}
		}

		else if (i == 1)
		{
			for (auto r = v.begin(); r<v.end(); ++r)
			{
				of << endl << r->first << "," << r->second;
			}
			of.close();
			puts("저장되었습니다.");
			return;
		}
		else
		{
			puts("허용되지 않은 좌표입니다");
		}

		//승리조건 호출
		if (victory(arr) == 0)
		{
			//승리시에도 기보를 자동 저장한다.
			for (auto r = v.begin(); r<v.end(); ++r)
			{
				of << endl << r->first << "," << r->second;
			}
			of.close();
			return;
		}
	}
}

void loadomoktime()
{
	int arr[19][19] = { 0 };
	int i, j;
	int bw = 0;
	int start, end;
	pair<int, int> p;
	char com;
	ifstream fin("replay.txt");
	v.clear();
	while (!fin.eof())
	{
		fin >> p.first >> com >> p.second;
		v.push_back(p);
		if (p.first>20)
		{
			start = GetTickCount();
			while (1)
			{
				end = GetTickCount();
				end -= start;
				if (p.second - p.first<end)
					break;
			}
			continue;
		}
		arr[p.first - 1][p.second - 1] = (bw % 2) + 1;//배열 i-1,j-1 에 bw를 2로 나눈 나머지에 1을 더한값을 넣는다.
		bw++;
		system("cls");
		drawomok(arr);
	}

	//판을 불러온상태로 승리조건 호출
	if (victory(arr) == 0)
	{
		fin.close();
		return;
	}

	//불러온후 파일에 이어서 기보를 작성하고 오목게임을 진행함
	ofstream of("replay.txt");

	while (1)
	{
		fflush(stdin);//버퍼를 비움, scanf 에 다른값이 절대 들어올수 없게함!!
		i = 0, j = 0;
		printf("%s 좌표를 입력해주세요(ex : 4,2)(1=저장):", bw % 2 == 0 ? "흑" : "백");//bw가 0이면 흑 아니면 백
		start = GetTickCount();
		scanf("%d,%d", &i, &j);
		end = GetTickCount();
		p.first = start;
		p.second = end;
		v.push_back(p);

		if (i<20 && j<20 && i>0 && j>0)
		{
			if (arr[i - 1][j - 1] == 0)
			{
				p.first = i;
				p.second = j;
				v.push_back(p);

				arr[i - 1][j - 1] = (bw % 2) + 1;//배열 i-1,j-1 에 bw를 2로 나눈 나머지에 1을 더한값을 넣는다.
				bw++;
				system("cls");//깔끔한 오목게임을위해 페이지 지우고 다시그림
				drawomok(arr);
			}
			else
			{
				puts("중복된 좌표입니다");
			}
		}

		else if (i == 1)
		{
			for (auto r = v.begin(); r<v.end(); ++r)
			{
				of << endl << r->first << "," << r->second;
			}
			of.close();
			puts("저장되었습니다.");
			return;
		}
		else
		{
			puts("허용되지 않은 좌표입니다");
		}

		//승리조건 호출
		if (victory(arr) == 0)
		{
			//승리시에도 기보를 자동 저장한다.
			for (auto r = v.begin(); r<v.end(); ++r)
			{
				of << endl << r->first << "," << r->second;
			}
			of.close();
			return;
		}
	}
}

int victory(int(*arr)[19])
{
	int i, j;
	for (i = 0; i<19; i++)
	{
		for (j = 0; j<19; j++)
		{
			if (arr[i][j] == 1 && arr[i][j + 1] == 1 && arr[i][j + 2] == 1 && arr[i][j + 3] == 1 && arr[i][j + 4] == 1)
			{
				puts("흑돌이 우승하였습니다!!");
				return 0;
			}
			if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i + 2][j] == 1 && arr[i + 3][j] == 1 && arr[i + 4][j] == 1)
			{
				puts("흑돌이 우승하였습니다!!");
				return 0;
			}
			if (arr[i][j] == 1 && arr[i + 1][j + 1] == 1 && arr[i + 2][j + 2] == 1 && arr[i + 3][j + 3] == 1 && arr[i + 4][j + 4] == 1)
			{
				puts("흑돌이 우승하였습니다!!");
				return 0;
			}

			if (arr[i][j] == 2 && arr[i][j + 1] == 2 && arr[i][j + 2] == 2 && arr[i][j + 3] == 2 && arr[i][j + 4] == 2)
			{
				puts("백돌이 우승하였습니다!!");
				return 0;
			}
			if (arr[i][j] == 2 && arr[i + 1][j] == 2 && arr[i + 2][j] == 2 && arr[i + 3][j] == 2 && arr[i + 4][j] == 2)
			{
				puts("백돌이 우승하였습니다!!");
				return 0;
			}
			if (arr[i][j] == 2 && arr[i + 1][j + 1] == 2 && arr[i + 2][j + 2] == 2 && arr[i + 3][j + 3] == 2 && arr[i + 4][j + 4] == 2)
			{
				puts("백돌이 우승하였습니다!!");
				return 0;
			}
		}
	}
}
*/