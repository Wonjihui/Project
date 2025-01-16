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
    Character* InsPlayer = player;
    InsPlayer->displayStats();


    cout << "게임을 시작합니다!" << endl << endl;
    while (InsPlayer != nullptr)
    {
        int move = 0;
        cout << endl
            << "앞으로 이동 : 1 " << endl
            << "상점 이용 : 2" << endl
            << "스텟 확인 : 3" << endl
            << "인벤토리 : 4" << endl;
        cin >> move;

        switch (move)
        {
        case 1: // 몬스터 전투
        {
            cout << "앞으로 이동 중..." << endl << endl;
            Monster* enemy = nullptr;
            if (InsPlayer->getLevel() < 10)
            {
                enemy = generateMonster(InsPlayer->getLevel());
                cout << "앗! " << enemy->getName() << "가 나타났다!" << endl << endl;
            }
            else
            {
                enemy = generateBossMonster(InsPlayer->getLevel());
                cout << "마지막이군... " << enemy->getName() << "가 나타났다!" << endl << endl;
            }

            cout << enemy->getName() << "의 능력치 - HP: " << enemy->getHealth() << " ATK: " << enemy->getAttack() << endl << endl;
            cout << "용맹하게 싸우기! : 1" << endl;
            cout << "꼬리 말고 도망치기... : 2" << endl;
            cin >> move;
            switch (move)
            {
            case 1:
            {
                int turnCount = 1;
                while (enemy != nullptr && InsPlayer != nullptr && enemy->getHealth() > 0 && InsPlayer->getHealth() > 0)
                {
                    cout << "=====Turn" << turnCount << "=====" << endl;
                    
                    cout << "\n[현재 상태]" << endl;
                    cout << InsPlayer->getName() << " - HP: " << InsPlayer->getHealth() << endl;
                    cout << enemy->getName() << " - HP: " << enemy->getHealth() << endl << endl;

                    cout << "당신의 턴입니다!\n" << endl;
                    cout << "1. 일반 공격" << endl;
                    cout << "2. 아이템 사용" << endl;
                    cout << "3. 도망가기" << endl;
                    cout << "선택:\n ";
                    int choice;
                    cin >> choice; 

                    switch (choice) {
                    case 1: 
                    {
                        enemy->takeDamage(InsPlayer->getAttack());
                        cout << InsPlayer->getName() << "이(가) " << enemy->getName() << "을(를) 공격했다!\n" << endl;
                        cout << enemy->getName() << "의 남은 HP:\n " << max(0, enemy->getHealth()) << endl;
                        break;
                    }
                    case 2: // 아이템 사용
                    {
                        __int64 HPItemcount, ATKItemcount;
                        FindItem(InsPlayer, &HPItemcount, &ATKItemcount);
                        cout << "\n사용할 아이템을 선택하세요:" << endl;
                        cout << "1. 개껌 (HP회복) - " << HPItemcount << "개 보유중" << endl;
                        cout << "2. 사료 (공격력증가) - " << ATKItemcount << "개 보유중" << endl;
                        cout << "3. 돌아가기" << endl;
                        int itemChoice;
                        cin >> itemChoice;
                        
                        break;
                    }
                    case 3: 
                    {
                        if (RandomValue(1, 100) <= 30) {
                            cout << InsPlayer->getName() << "은(는) 도망치는데 성공했다!" << endl;
                            delete enemy;
                            return;
                        }
                        else {
                            cout << InsPlayer->getName() << "은(는) 도망치지 못했다!" << endl;
                        }
                        break;
                    }
                    default:
                        cout << "잘못된 선택입니다. 턴을 넘깁니다." << endl;
                        break;
                    }

                   
                    if (enemy->getHealth() <= 0) {
                        cout << InsPlayer->getName() << "이(가) " << enemy->getName() << "을(를) 공격했다! " << enemy->getName() << "의 남은 HP: 0\n" << endl;
                        cout << enemy->getName() << "이(가) 쓰러졌다! 승리!\n" << endl;
                        InsPlayer->setTotalKillMonster();
                        int rangold = RandomValue(10, 20);
                        InsPlayer->gainGold(rangold);
                        InsPlayer->gainExperience();
                        LootItem(InsPlayer);
                        cout << InsPlayer->getName() << "이(가)" << rangold << "골드를 획득했습니다. 현재 골드: " << InsPlayer->getGold() << endl; // "exp: 50/100" 추가해야됨 getExp()함수 추가해야됨

                        delete enemy;
                        enemy = nullptr;
                        break;
                    }

                    // 몬스터 턴
                    cout << "\n" << enemy->getName() << "의 턴입니다!" << endl;
                    InsPlayer->takeDamage(enemy->getAttack());
                    cout << enemy->getName() << "이(가) " << InsPlayer->getName() << "을(를) 공격했다!\n" << endl;
                    cout << InsPlayer->getName() << "의 남은 HP: " << InsPlayer->getHealth() << endl;

                    // 플레이어 생존 확인
                    if (InsPlayer->getHealth() <= 0) {
                        cout << "\n" << InsPlayer->getName() << "이(가) 쓰러졌다! 게임 오버!/n" << endl;
                        delete InsPlayer;
                        InsPlayer = nullptr;
                        break;
                    }

                    turnCount++;
                }
                break;
            }
            case 2:
            {
                cout << player->getName() << "은(는) 꼬리를 말고 도망쳤다!" << endl;
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
            InsPlayer->displayStats();
            break;

        case 4: // 인벤토리 확인
            cout << "인벤토리 오픈" << endl;
            DisplayInven(InsPlayer);
            break;

        default:
            cout << "잘못된 입력입니다." << endl;
            break;
        }
    }
}

void GameManager::LootItem(Character* player)
{
    cout << player->getName() << "가 전리품을 챙겼다!" << endl;
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