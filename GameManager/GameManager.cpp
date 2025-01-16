#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

GameManager::GameManager()
{
	srand(static_cast<unsigned>(time(0))); // 랜덤 시드 초기화
}

void GameManager::DisplayInven(Character* player)
{
	int gold = player->getGold();
	__int64 HPItemcount;
	__int64 ATKItemcount;
	FindItem(player, &HPItemcount, &ATKItemcount);

	cout << endl;
	cout << "+-------------------------------+" << endl;
	cout << "|         [ 인벤토리 ]          |" << endl;
	cout << "+-------------------------------+" << endl;
	cout << "| 재화: " << gold << "골드                   |" << endl;
	cout << "| 개 껌: " << HPItemcount << "                      |" << endl;
	cout << "| 사 료: " << ATKItemcount << "                      |" << endl;
	cout << "+-------------------------------+" << endl;

	if (HPItemcount > 0 || ATKItemcount > 0)
	{
		int choice;
		cout << "+-------------------------------+" << endl;
		cout << "|   아이템을 사용하시겠습니까?   |" << endl;
		cout << "+-------------------------------+" << endl;
		cout << "| 1. 개껌 사용                  |" << endl;
		cout << "| 2. 사료 사용                  |" << endl;
		cout << "| 3. 나가기                     |" << endl;
		cout << "+-------------------------------+" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: // 개껌 사용
			if (HPItemcount > 0)
			{
				UseItem(player, "health");
			}
			else
			{
				cout << "개껌이 없습니다!" << endl;
			}
			break;

		case 2: // 사료 사용
			if (ATKItemcount > 0)
			{
				UseItem(player, "attack");
			}
			else
			{
				cout << "사료가 없습니다!" << endl;
			}
			break;

		case 3: // 나가기
			cout << "인벤토리를 닫습니다." << endl;
			break;

		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
	else
	{
		cout << "사용할 아이템이 없습니다!" << endl;
	}
}

void GameManager::UseItem(Character* player, const string& itemType)
{
	vector<Item*>& inventory = player->getInventory();
	auto it = find_if(inventory.begin(), inventory.end(), [&](Item* i) 
		{
		return i->getType() == itemType;
		});

	if (it != inventory.end())
	{
		Item* item = *it;
		item->use(player);
		inventory.erase(it); // 사용한 아이템 제거
		delete item;
	}
	else
	{
		cout << "해당 아이템이 없습니다!" << endl;
	}
}


int GameManager::RandomValue(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);
	return dis(gen);
}
Monster* GameManager::generateMonster(int level)
{
	int monsterType = rand() % 4; // 0~3 사이의 랜덤 값
	switch (monsterType)
	{
	case 0:
		return new Maltese(level);
	case 1:
		return new Pomeranian(level);
	case 2:
		return new Malamute(level);
	case 3:
		return new Samoyed(level);
	default:
		return nullptr;
	}
}

Human* GameManager::generateBossMonster(int level)
{
	return new Human(level);
}

void GameManager::battle(Character* player)
{
	Character* Player_ = player;
	Player_->displayStats();


	cout << "게임을 시작합니다!" << endl;
	while (Player_ != nullptr)
	{
		int move = 0;
		cout << endl;
		cout << "+-------------------------------+" << endl;
		cout << "|      [ 선택지를 고르세요 ]    |" << endl;
		cout << "+-------------------------------+" << endl;
		cout << "| 1. 앞으로 이동                |" << endl;
		cout << "| 2. 상점 이용                  |" << endl;
		cout << "| 3. 스탯 확인                  |" << endl;
		cout << "| 4. 인벤토리                   |" << endl;
		cout << "+-------------------------------+" << endl;
		cin >> move;

		switch (move)
		{
		case 1: // 몬스터와 전투
		{
			cout << endl <<"앞으로 이동 중..." << endl << endl;
			cout << "몬스터를 만났습니다!" << endl << endl;
			cout << "전투: 1 | 도망: 2" << endl;
			cin >> move;
			switch (move)
			{
			case 1:
			{
				Monster* enemy = nullptr;

				if (Player_->getLevel() < 10)
				{
					// 일반 몬스터 생성
					enemy = generateMonster(Player_->getLevel());
					cout << "앗! 몬스터 " << enemy->getName() << " 이(가) 나타났습니다!" << endl;
				}
				else
				{
					// 보스 몬스터 생성
					enemy = generateBossMonster(Player_->getLevel());
					cout << "마지막이군... 보스 몬스터 " << enemy->getName() << " 이 나타났습니다!" << endl;
				}

				cout << enemy->getName() << " HP: " << enemy->getHealth() << " ATK: " << enemy->getAttack() << endl << endl;

				while (enemy != nullptr && Player_ != nullptr && enemy->getHealth() > 0 && Player_->getHealth() > 0)
				{
					// 캐릭터가 몬스터 공격
					enemy->takeDamage(Player_->getAttack());
					if (enemy->getHealth() <= 0)//몬스터 죽었을때
					{
						cout << Player_->getName() << "이(가) " << enemy->getName() << "을(를) 공격했다! " << enemy->getName() << "의 남은 HP: 0" << endl;
						cout << enemy->getName() << "이(가) 쓰러졌다! 승리!" << endl;
						Player_->setTotalKillMonster();
						int rangold = RandomValue(10, 20);
						Player_->gainGold(rangold);
						Player_->gainExperience();
						LootItem(Player_);
						cout << "현재 골드 : " << Player_->getGold() << ", Exp : " << Player_->getExp() << " / 100" << endl;

						delete enemy;
						enemy = nullptr;
						break;
					}
					else
					{
						cout << Player_->getName() << "이(가) " << enemy->getName() << "을(를) 공격했다! " << enemy->getName() << "의 남은 HP: " << enemy->getHealth() << endl;
					}




					// 몬스터가 캐릭터 공격
					Player_->takeDamage(enemy->getAttack());
					cout << enemy->getName() << "이(가) " << Player_->getName() << "을(를) 공격했다! " << Player_->getName() << "의 남은 HP: " << Player_->getHealth() << endl;

					if (Player_->getHealth() <= 0) //캐릭터 죽었을때
					{
						cout << Player_->getName() << "이(가) 쓰러졌다! 게임 오버!" << endl;
						delete Player_;
						Player_ = nullptr;
						break;
					}
				}
				break;
			}
			case 2:
			{
				cout << player->getName() << "은(는) 도망쳤다!" << endl;
				break;
			}
			default:
				cout << "잘못된 입력입니다." << endl;
				break;
			}
			break;
		}
		case 2: // 상점
		{
			Shop* shop = new Shop();
			shop->DisplayItems();
			break;
		}
		case 3: // 스탯 확인
			Player_->displayStats();
			break;

		case 4: // 인벤토리 확인
			DisplayInven(Player_);
			break;

		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
}

void GameManager::LootItem(Character* player)
{
	cout << endl << "* " << player->getName() << "가 전리품을 챙겼습니다! *" << endl;
	player->gainItem(RandomValue(1, 100));
	player->gainExperience(); //50exp 고정
	player->gainGold(RandomValue(10, 20));
}

int GameManager::FindItem(Character* player, __int64* HPItemcount, __int64* ATKItemcount)
{
	vector<Item*> item = player->getInventory();
	*HPItemcount = count_if(item.begin(), item.end(), [](Item* i) { return dynamic_cast<HealthItem*>(i) != nullptr; });
	*ATKItemcount = count_if(item.begin(), item.end(), [](Item* i) { return dynamic_cast<AttackBoost*>(i) != nullptr; });
	return 0;
}
