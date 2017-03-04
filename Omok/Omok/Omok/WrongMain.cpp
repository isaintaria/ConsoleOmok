/*
#include <iostream>
#include <Windows.h>//system("cls");�� �������ؼ���
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
		cout << "��ȣ�� �Է����ּ��� :";
		cin >> ch;

		if (true == cin.fail())
		{
			cout << "�߸� �Է��Ͽ����ϴ� �ٽ� �Է����ּ���" << endl;
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
			cout << "�����մϴ�^^" << endl;
			return 0;
		}
		default:
		{
			cout << "��ȣ�� �߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
		}
	}
}

void menu()
{
	cout << "-----����ִ� ������� v1.0-----" << endl;
	cout << "1 : ������� ����" << endl;
	cout << "2 : ������� �ܰ躰 �ҷ�����" << endl;
	cout << "3 : ������� �ð��� �ҷ�����" << endl;
	cout << "4 : ����" << endl;
}

void drawomok(int(*arr)[19])
{
	int i, j;
	cout << "-----����ִ� ������� v1.0-----" << endl;
	cout << "\t 1 2 3 4 5 6 7 8 910111213141516171819" << endl << endl;
	for (i = 0; i<19; i++)
	{
		cout << i + 1 << "\t";
		for (j = 0; j<19; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << "��";
			}
			if (arr[i][j] == 1)
			{
				cout << "��";
			}
			if (arr[i][j] == 2)
			{
				cout << "��";
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
		
		string color = bw % 2 == 0 ? "��" : "��";
		cout << color << " ��ǥ�� �Է����ּ���(ex : 4,2)(1=����):"; //bw�� 0�̸� �� �ƴϸ� ��
		start = GetTickCount();
		char token = ',';
		cin >> i >> token >> j;

		if (true == cin.fail())
		{
			cout << "�߸� �Է��Ͽ����ϴ� �ٽ� �Է����ּ���" << endl;
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

				arr[i - 1][j - 1] = (bw % 2) + 1;//�迭 i-1,j-1 �� bw�� 2�� ���� �������� 1�� ���Ѱ��� �ִ´�.
				bw++;
				system("cls"); //����� ������������� ������ ����� �ٽñ׸�
				drawomok(arr);
			}
			else
			{
				cout << "�ߺ��� ��ǥ�Դϴ�";
			}
		}

		else if (i == 1)
		{
			for (auto r = v.begin(); r<v.end(); ++r)
			{
				of << endl << r->first << "," << r->second;
			}
			of.close();
			cout << "����Ǿ����ϴ�.";
			return;
		}
		else
		{
			cout << "������ ���� ��ǥ�Դϴ�";
		}

		//�¸����� ȣ��
		if (victory(arr) == 0)
		{
			//�¸��ÿ��� �⺸�� �ڵ� �����Ѵ�.
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
		arr[p.first - 1][p.second - 1] = (bw % 2) + 1;//�迭 i-1,j-1 �� bw�� 2�� ���� �������� 1�� ���Ѱ��� �ִ´�.
		bw++;
		input = getch();
		if (input == ' ')
		{
			system("cls");
			drawomok(arr);
		}
	}

	//���� �ҷ��»��·� �¸����� ȣ��
	if (victory(arr) == 0)
	{
		fin.close();
		return;
	}

	//�ҷ����� ���Ͽ� �̾ �⺸�� �ۼ��ϰ� ��������� ������
	ofstream of("replay.txt");

	while (1)
	{
		fflush(stdin);//���۸� ���, scanf �� �ٸ����� ���� ���ü� ������!!
		i = 0, j = 0;
		printf("%s ��ǥ�� �Է����ּ���(ex : 4,2)(1=����):", bw % 2 == 0 ? "��" : "��");//bw�� 0�̸� �� �ƴϸ� ��
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

				arr[i - 1][j - 1] = (bw % 2) + 1;//�迭 i-1,j-1 �� bw�� 2�� ���� �������� 1�� ���Ѱ��� �ִ´�.
				bw++;
				system("cls");//����� ������������� ������ ����� �ٽñ׸�
				drawomok(arr);
			}
			else
			{
				puts("�ߺ��� ��ǥ�Դϴ�");
			}
		}

		else if (i == 1)
		{
			for (auto r = v.begin(); r<v.end(); ++r)
			{
				of << endl << r->first << "," << r->second;
			}
			of.close();
			puts("����Ǿ����ϴ�.");
			return;
		}
		else
		{
			puts("������ ���� ��ǥ�Դϴ�");
		}

		//�¸����� ȣ��
		if (victory(arr) == 0)
		{
			//�¸��ÿ��� �⺸�� �ڵ� �����Ѵ�.
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
		arr[p.first - 1][p.second - 1] = (bw % 2) + 1;//�迭 i-1,j-1 �� bw�� 2�� ���� �������� 1�� ���Ѱ��� �ִ´�.
		bw++;
		system("cls");
		drawomok(arr);
	}

	//���� �ҷ��»��·� �¸����� ȣ��
	if (victory(arr) == 0)
	{
		fin.close();
		return;
	}

	//�ҷ����� ���Ͽ� �̾ �⺸�� �ۼ��ϰ� ��������� ������
	ofstream of("replay.txt");

	while (1)
	{
		fflush(stdin);//���۸� ���, scanf �� �ٸ����� ���� ���ü� ������!!
		i = 0, j = 0;
		printf("%s ��ǥ�� �Է����ּ���(ex : 4,2)(1=����):", bw % 2 == 0 ? "��" : "��");//bw�� 0�̸� �� �ƴϸ� ��
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

				arr[i - 1][j - 1] = (bw % 2) + 1;//�迭 i-1,j-1 �� bw�� 2�� ���� �������� 1�� ���Ѱ��� �ִ´�.
				bw++;
				system("cls");//����� ������������� ������ ����� �ٽñ׸�
				drawomok(arr);
			}
			else
			{
				puts("�ߺ��� ��ǥ�Դϴ�");
			}
		}

		else if (i == 1)
		{
			for (auto r = v.begin(); r<v.end(); ++r)
			{
				of << endl << r->first << "," << r->second;
			}
			of.close();
			puts("����Ǿ����ϴ�.");
			return;
		}
		else
		{
			puts("������ ���� ��ǥ�Դϴ�");
		}

		//�¸����� ȣ��
		if (victory(arr) == 0)
		{
			//�¸��ÿ��� �⺸�� �ڵ� �����Ѵ�.
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
				puts("�浹�� ����Ͽ����ϴ�!!");
				return 0;
			}
			if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i + 2][j] == 1 && arr[i + 3][j] == 1 && arr[i + 4][j] == 1)
			{
				puts("�浹�� ����Ͽ����ϴ�!!");
				return 0;
			}
			if (arr[i][j] == 1 && arr[i + 1][j + 1] == 1 && arr[i + 2][j + 2] == 1 && arr[i + 3][j + 3] == 1 && arr[i + 4][j + 4] == 1)
			{
				puts("�浹�� ����Ͽ����ϴ�!!");
				return 0;
			}

			if (arr[i][j] == 2 && arr[i][j + 1] == 2 && arr[i][j + 2] == 2 && arr[i][j + 3] == 2 && arr[i][j + 4] == 2)
			{
				puts("�鵹�� ����Ͽ����ϴ�!!");
				return 0;
			}
			if (arr[i][j] == 2 && arr[i + 1][j] == 2 && arr[i + 2][j] == 2 && arr[i + 3][j] == 2 && arr[i + 4][j] == 2)
			{
				puts("�鵹�� ����Ͽ����ϴ�!!");
				return 0;
			}
			if (arr[i][j] == 2 && arr[i + 1][j + 1] == 2 && arr[i + 2][j + 2] == 2 && arr[i + 3][j + 3] == 2 && arr[i + 4][j + 4] == 2)
			{
				puts("�鵹�� ����Ͽ����ϴ�!!");
				return 0;
			}
		}
	}
}
*/