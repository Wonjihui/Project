#include "GameManager.h"

void GameManager::DisplayInven(Character* player)
{
	Character* InsPlayerInvent = Character::getInstance();
	int gold = InsPlayerInvent->getGold();
	cout << "��ȭ: " << gold << "���" << endl << "�� ��:" << endl << "���:" << endl << endl;
}

void GameManager::BattleSys(Character* player)
{
	Character* InsPlayer = Character::getInstance();
	InsPlayer->displayStats();
	int move = 0;
	cout << "������ �����մϴ�!" << endl << endl;
	while (InsPlayer != nullptr)
	{
		cout << "������ �̵� : 1 " << endl << "���� �̿� : 2" << endl << "���� Ȯ�� : 3" << endl << "�κ��丮 : 4" << endl;
		cin >> move;
		switch (move)
		{
		case 1:
		{
			cout << "������ �̵� ��..." << endl << endl;
			Monster* mob = MonsterSpawn(InsPlayer->getLevel());
			while (mob != nullptr && InsPlayer!= nullptr && mob->getHealth() > 0 && InsPlayer->getHealth() > 0)
			{
				mob->takeDamage(InsPlayer->getAttack());
				cout << mob->getName() << "�� ���� ������! ���� HP: " << mob->getHealth() << endl << endl;

				InsPlayer->getDamage(mob->getAttack());
				cout << InsPlayer->getName() << "�� �������� �Ծ���! ���� HP: " << InsPlayer->getHealth() << endl << endl;

				if (mob->getHealth() <= 0)
				{
					cout << mob->getName() << "�� �������� �¸�!" << endl << endl;

					delete mob;
					mob = nullptr;
					InsPlayer->gainGold(RandomValue(10, 20));
					InsPlayer->gainExperience(50);
					cout << InsPlayer->getName() << "�� ����ǰ�� ì����ϴ�!" << endl << "���: " << gold << endl << "����ġ : " << exp << endl << endl;
					InsPlayer->displayStats();
				}
				if (InsPlayer->getHealth() <= 0)
				{
					cout << InsPlayer->getName() << "�� ��������!" << InsPlayer->getName() << "�� �й�..." << endl << "���� ����";
					delete InsPlayer;
					InsPlayer = nullptr;
				}
			}
			break;
		}
		case 2:
		{
			cout << "���� �̱���" << endl;
			break;
		}
		case 3:
			InsPlayer->displayStats();
			break;
		case 4:
			cout << "�κ��丮 ����" << endl;
			DisplayInven(InsPlayer);
			break;
		}
	}
}

Monster* GameManager::MonsterSpawn(int level)
{

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 4);
	int spawnMob = dis(gen);
	switch (spawnMob)
	{
	case 1:
	{
		cout << "��Ƽ� ��Ÿ����!" << endl;
		Monster* mob1 = new Maltese(level);
		cout << endl << mob1->getName() << " Lv: " << level << endl << "HP: " << mob1->getHealth() << " ATK: " << mob1->getAttack() << endl << endl;
		return mob1;
	}
	case 2:
	{
		cout << "�����Ʈ�� ��Ÿ����!" << endl;
		Monster* mob2 = new Malamute(level);
		cout << endl << mob2->getName() << " Lv: " << level << endl << "HP: " << mob2->getHealth() << " ATK: " << mob2->getAttack() << endl << endl;
		return mob2;
	}
	case 3:
	{
		cout << "���޶�Ͼ��� ��Ÿ����!" << endl;
		Monster* mob3 = new Pomeranian(level);
		cout << endl << mob3->getName() << " Lv: " << level << endl << "HP: " << mob3->getHealth() << " ATK: " << mob3->getAttack() << endl << endl;
		return mob3;
	}
	case 4:
	{
		cout << "��𿹵尡 ��Ÿ����!" << endl;
		Monster* mob4 = new Samoyed(level);
		cout << endl << mob4->getName() << " Lv: " << level << endl << "HP: " << mob4->getHealth() << " ATK: " << mob4->getAttack() << endl << endl;
		return mob4;
	}
	}
	return nullptr;
}

int GameManager::RandomValue(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);
	int num = dis(gen);
	return num;
}
