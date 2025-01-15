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
	cout << "전투가 시작되었습니다." << endl;

	//전투 구현 필요

	/*승리시
	if (몬스터 사망) {
		cout << "전투에서 승리하였습니다." << endl;
		totalGold += getgold;
		totalKillMonster++;
		cout << "현재 골드 :" << totalGold << endl;
		cout << "오늘 처치한 몬스터 수 :" << totalKillMonster << endl;
		//패배시
		cout << "전투에서 패배하였습니다." << endl;
	}*/
}

void GameManager::displayInventory(Character* player)
{
	if (item.empty()) {
		cout << "현재 아이템이 없습니다." << endl;
		return;
	}

	cout << "현재 아이템 목록 :" << endl;
	for (size_t i = 0; i < item.size(); i++) {
		cout << "- " << item.name << endl;
	}
}

void GameManager::visitshop(Character* player)
{
	Shop::GetInstance()->DisplayItems();
}