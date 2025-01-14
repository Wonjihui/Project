#include "GameManager.h"

void GameManager::DisplayInven(Character* player)
{
	Character* InsPlayerInvent = Character::getInstance();
	int gold = InsPlayerInvent->getGold();
	cout << "재화: " << gold << "골드" << endl << "개 껌:" << endl << "사료:" << endl << endl;
}

void GameManager::BattleSys(Character* player)
{
	Character* InsPlayer = Character::getInstance();
	InsPlayer->displayStats();
	int move = 0;
	cout << "게임을 시작합니다!" << endl << endl;
	while (InsPlayer != nullptr)
	{
		cout << "앞으로 이동 : 1 " << endl << "상점 이용 : 2" << endl << "스텟 확인 : 3" << endl << "인벤토리 : 4" << endl;
		cin >> move;
		switch (move)
		{
		case 1:
		{
			cout << "앞으로 이동 중..." << endl << endl;
			Monster* mob = MonsterSpawn(InsPlayer->getLevel());
			while (mob != nullptr && InsPlayer!= nullptr && mob->getHealth() > 0 && InsPlayer->getHealth() > 0)
			{
				mob->takeDamage(InsPlayer->getAttack());
				cout << mob->getName() << "의 몸을 물었다! 남은 HP: " << mob->getHealth() << endl << endl;

				InsPlayer->getDamage(mob->getAttack());
				cout << InsPlayer->getName() << "가 데미지를 입었다! 남은 HP: " << InsPlayer->getHealth() << endl << endl;

				if (mob->getHealth() <= 0)
				{
					cout << mob->getName() << "가 도망갔다 승리!" << endl << endl;

					delete mob;
					mob = nullptr;
					InsPlayer->gainGold(RandomValue(10, 20));
					InsPlayer->gainExperience(50);
					cout << InsPlayer->getName() << "가 전리품을 챙겼습니다!" << endl << "골드: " << gold << endl << "경험치 : " << exp << endl << endl;
					InsPlayer->displayStats();
				}
				if (InsPlayer->getHealth() <= 0)
				{
					cout << InsPlayer->getName() << "가 쓰러졌다!" << InsPlayer->getName() << "의 패배..." << endl << "게임 오버";
					delete InsPlayer;
					InsPlayer = nullptr;
				}
			}
			break;
		}
		case 2:
		{
			cout << "상점 미구현" << endl;
			break;
		}
		case 3:
			InsPlayer->displayStats();
			break;
		case 4:
			cout << "인벤토리 오픈" << endl;
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
		cout << "말티즈가 나타났다!" << endl;
		Monster* mob1 = new Maltese(level);
		cout << endl << mob1->getName() << " Lv: " << level << endl << "HP: " << mob1->getHealth() << " ATK: " << mob1->getAttack() << endl << endl;
		return mob1;
	}
	case 2:
	{
		cout << "말라뮤트가 나타났다!" << endl;
		Monster* mob2 = new Malamute(level);
		cout << endl << mob2->getName() << " Lv: " << level << endl << "HP: " << mob2->getHealth() << " ATK: " << mob2->getAttack() << endl << endl;
		return mob2;
	}
	case 3:
	{
		cout << "포메라니안이 나타났다!" << endl;
		Monster* mob3 = new Pomeranian(level);
		cout << endl << mob3->getName() << " Lv: " << level << endl << "HP: " << mob3->getHealth() << " ATK: " << mob3->getAttack() << endl << endl;
		return mob3;
	}
	case 4:
	{
		cout << "사모예드가 나타났다!" << endl;
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
