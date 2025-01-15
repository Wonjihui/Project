#include "GameManager.h"

void GameManager::DisplayInven(Character* player)
{
	int gold = player->getGold();
	__int64 HPItemcount;
	__int64 ATKItemcount;
	FindItem(player, &HPItemcount, &ATKItemcount);
	cout << "��ȭ: " << gold << "���" << endl << "�� ��:" << HPItemcount << endl << "���:" << ATKItemcount << endl << endl;
}

void GameManager::BattleSys(Character* player)
{
	player->displayStats();
	int move = 0;
	cout << "������ �����մϴ�!" << endl << endl;
	while (player != nullptr)
	{
		cout << "������ �̵� : 1 " << endl << "���� �̿� : 2" << endl << "���� Ȯ�� : 3" << endl << "�κ��丮 : 4" << endl;
		cin >> move;
		switch (move)
		{
		case 1:
		{
			cout << "������ �̵� ��..." << endl << endl;
			Monster* mob = MonsterSpawn(player->getLevel());
			while (mob != nullptr && player != nullptr && mob->getHealth() > 0 && player->getHealth() > 0)
			{
				mob->takeDamage(player->getAttack());
				cout << mob->getName() << "�� ���� ������! ���� HP: " << mob->getHealth() << endl << endl;

				player->getDamage(mob->getAttack());
				cout << player->getName() << "�� �������� �Ծ���! ���� HP: " << player->getHealth() << endl << endl;

				if (mob->getHealth() <= 0)
				{
					cout << mob->getName() << "�� �������� �¸�!" << endl << endl;

					delete mob;
					mob = nullptr;
					LootItem(player);
					player->displayStats();
				}
				if (player->getHealth() <= 0)
				{
					cout << player->getName() << "�� ��������!" << player->getName() << "�� �й�..." << endl << "���� ����";
					delete player;
					player = nullptr;
				}
			}
			break;
		}
		case 2:
		{
			Shop* shop = new Shop();
			shop->DisplayItems();
			break;
		}
		case 3:
			player->displayStats();
			break;
		case 4:
			cout << "�κ��丮 ����" << endl;
			DisplayInven(player);
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

void GameManager::LootItem(Character* player)
{
	cout << player->getName() << "�� ����ǰ�� ì����ϴ�!" << endl << endl;
	player->gainItem(RandomValue(1,100));
	int exp = player->gainExperience(50);
	int gold = player->gainGold(RandomValue(10, 20));
}

int GameManager::FindItem(Character* player, __int64* HPItemcount, __int64* ATKItemcount)
{
	vector<Item*> item = player->getInventory();
	*HPItemcount = count_if(item.begin(), item.end(), [](Item* i) { return dynamic_cast<HealthItem*>(i) != nullptr; });
	*ATKItemcount = count_if(item.begin(), item.end(), [](Item* i) { return dynamic_cast<AttackBoost*>(i) != nullptr; });
	return 0;
}
