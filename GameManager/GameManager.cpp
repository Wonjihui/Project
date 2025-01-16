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
    cout << "재화: " << gold << "골드" << endl << "개 껌:" << HPItemcount << endl << "사료:" << ATKItemcount << endl << endl;
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


    cout << "게임을 시작합니다!" << endl << endl;
    while (Player_ != nullptr)
    {
        int move = 0;
        cout << endl
            <<"앞으로 이동 : 1 " << endl
            << "상점 이용 : 2" << endl
            << "스텟 확인 : 3" << endl
            << "인벤토리 : 4" << endl;
        cin >> move;

        switch (move)
        {
        case 1: // 몬스터와 전투
        {
            cout << "앞으로 이동 중..." << endl << endl;

            Monster* enemy = nullptr;

            if (Player_->getLevel() < 10)
            {
                // 일반 몬스터 생성
                enemy = generateMonster(Player_->getLevel());
                cout << "몬스터 " << enemy->getName() << " 이(가) 나타났습니다!" << endl;
            }
            else
            {
                // 보스 몬스터 생성
                enemy = generateBossMonster(Player_->getLevel());
                cout << "보스 몬스터 " << enemy->getName() << " 이(가) 나타났습니다!" << endl;
            }

            cout << enemy->getName() << " HP: " << enemy->getHealth() << " ATK: " << enemy->getAttack() << endl << endl;

            while (enemy != nullptr && Player_ != nullptr && enemy->getHealth() > 0 && Player_->getHealth() > 0)
            {
                // 캐릭터가 몬스터 공격
                enemy->takeDamage(Player_->getAttack());
                if (enemy->getHealth() <= 0)
                {
                    cout << Player_->getName() << "이(가) " << enemy->getName() << "을(를) 공격했다! " << enemy->getName() << "의 남은 HP: 0" << endl;
                    cout << enemy->getName() << "이(가) 쓰러졌다! 승리!" << endl;
                    Player_->setTotalKillMonster();
                    int rangold = RandomValue(10, 20);
                    Player_->gainGold(rangold);
                    Player_->gainExperience();
					cout << Player_->getName() << "이(가) 50EXP와 " << rangold << "골드를 획득했습니다. 현재 골드: " << Player_->getGold() << "Exp: " << Player_->getExp() <<"/100" << endl;

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

                if (Player_->getHealth() <= 0)
                {
                    cout << Player_->getName() << "이(가) 쓰러졌다! 게임 오버!" << endl;
                    delete Player_;
                    Player_ = nullptr;
                    break;
                }
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
            cout << "인벤토리 오픈" << endl;
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
    cout << player->getName() << "가 전리품을 챙겼습니다!" << endl << endl;
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
