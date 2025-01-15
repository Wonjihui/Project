#include "GameManager.h"
#include "monster.h"
#include "character.h"
#include "item.h"
#include <iostream>
#include<cstdlib>
#include<ctime>
#include<shop.h>

Monster* GameManager::generateMonster(int level)
{
	Monster* monster = nullptr;
	int randomNum = std::rand() % 4; // Generate a random number (0, 1, 2, 3)

	if (level == 10)
		monster = new BossMonster(level);
	else
	{
		switch (randomNum) {
		case 0: return new Maltese(level);
			break;
		case 1: return new Pomeranian(level);
			break;
		case 2: return new Malamute(level);
			break;
		case 3: return new Samoyed(level);
			break;
		}
	}
	return monster;
}

void GameManager::battle(Character* player)
{
	cout << "������ ���۵Ǿ����ϴ�." << endl;

	//���� ���� �ʿ�

	/*�¸���
	if (���� ���) {
		cout << "�������� �¸��Ͽ����ϴ�." << endl;
		totalGold += getgold;
		totalKillMonster++;
		cout << "���� ��� :" << totalGold << endl;
		cout << "���� óġ�� ���� �� :" << totalKillMonster << endl;
		//�й��
		cout << "�������� �й��Ͽ����ϴ�." << endl;
	}*/
}

void GameManager::displayInventory(Character* player)
{
	if (item.empty()) {
		cout << "���� �������� �����ϴ�." << endl;
		return;
	}

	cout << "���� ������ ��� :" << endl;
	for (size_t i = 0; i < item.size(); i++) {
		cout << "- " << item.name << endl;
	}
}

void GameManager::visitshop(Character* player)
{
	Shop::GetInstance()->DisplayItems();
}