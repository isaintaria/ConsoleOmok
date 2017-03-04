#include "OmokManager.h"
#include "AI.h"

int main()
{
	int MenuNumber;
	OmokManager* manager = new OmokManager;

	manager->SetAI(Attack, Defence);

	while (true)
	{
		manager->ShowMenu();
		cout << "번호를 입력해주세요 : ";
		cin >> MenuNumber;

		if (true == cin.fail())
		{
			cout << "잘못 입력하였습니다 다시 입력해주세요" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}

		switch (MenuNumber)
		{
		case 1:
			manager->Draw();
			manager->Play();
			break;
		case 2:
			break;
		case 3:
			manager->Draw();
			manager->RePlay();
			break;
		case 4:
			cout << "감사합니다^^" << endl;
			return 0;
		default:
			cout << "번호를 잘못 입력하셨습니다." << endl;
			break;
		}
	}
	return 0;
}