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
		cout << "��ȣ�� �Է����ּ��� : ";
		cin >> MenuNumber;

		if (true == cin.fail())
		{
			cout << "�߸� �Է��Ͽ����ϴ� �ٽ� �Է����ּ���" << endl;
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
			cout << "�����մϴ�^^" << endl;
			return 0;
		default:
			cout << "��ȣ�� �߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
	}
	return 0;
}