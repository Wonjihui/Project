#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

GameManager::GameManager()
{
    srand(static_cast<unsigned>(time(0))); // ���� �õ� �ʱ�ȭ
}
void GameManager::DisplayInven(Character* player)
{
    int gold = player->getGold();
    __int64 HPItemcount;
    __int64 ATKItemcount;
    FindItem(player, &HPItemcount, &ATKItemcount);
    cout << "��ȭ: " << gold << "���" << endl << "�� ��:" << HPItemcount << endl << "���:" << ATKItemcount << endl << endl;
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
    int monsterType = rand() % 4; // 0~3 ������ ���� ��
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


    cout << "������ �����մϴ�!" << endl << endl;
    while (InsPlayer != nullptr)
    {
        int move = 0;
        cout << endl
            <<"������ �̵� : 1 " << endl
            << "���� �̿� : 2" << endl
            << "���� Ȯ�� : 3" << endl
            << "�κ��丮 : 4" << endl;
        cin >> move;

        switch (move)
        {
        case 1: // ���Ϳ� ����
        {
            cout << "������ �̵� ��..." << endl << endl;
            cout << "���͸� �������ϴ�!" << endl << endl;
            cout << "���� : 1" << endl;
            cout << "���� : 2" << endl;
            cin >> move;
            switch (move)
            {
            case 1:
            {
                Monster* enemy = nullptr;

                if (InsPlayer->getLevel() < 10)
                {
                    // �Ϲ� ���� ����
                    enemy = generateMonster(InsPlayer->getLevel());
                    cout << "���� " << enemy->getName() << " ��(��) ��Ÿ�����ϴ�!" << endl;
                }
                else
                {
                    // ���� ���� ����
                    enemy = generateBossMonster(InsPlayer->getLevel());
                    cout << "���� ���� " << enemy->getName() << " ��(��) ��Ÿ�����ϴ�!" << endl;
                }

                cout << enemy->getName() << " HP: " << enemy->getHealth() << " ATK: " << enemy->getAttack() << endl << endl;

                while (enemy != nullptr && InsPlayer != nullptr && enemy->getHealth() > 0 && InsPlayer->getHealth() > 0)
                {
                    // ĳ���Ͱ� ���� ����
                    enemy->takeDamage(InsPlayer->getAttack());
                    if (enemy->getHealth() <= 0)
                    {
                        cout << InsPlayer->getName() << "��(��) " << enemy->getName() << "��(��) �����ߴ�! " << enemy->getName() << "�� ���� HP: 0" << endl;
                        cout << enemy->getName() << "��(��) ��������! �¸�!" << endl;
                        InsPlayer->setTotalKillMonster();
                        int rangold = RandomValue(10, 20);
                        InsPlayer->gainGold(rangold);
                        InsPlayer->gainExperience();
                        InsPlayer->gainItem(RandomValue(1, 100));
                        cout << InsPlayer->getName() << "��(��) 50EXP�� " << rangold << "��带 ȹ���߽��ϴ�. ���� ���: " << InsPlayer->getGold() << endl; // "exp: 50/100" �߰��ؾߵ� getExp()�Լ� �߰��ؾߵ�

                        delete enemy;
                        enemy = nullptr;
                        break;
                    }
                    else
                    {
                        cout << InsPlayer->getName() << "��(��) " << enemy->getName() << "��(��) �����ߴ�! " << enemy->getName() << "�� ���� HP: " << enemy->getHealth() << endl;
                    }




                    // ���Ͱ� ĳ���� ����
                    InsPlayer->takeDamage(enemy->getAttack());
                    cout << enemy->getName() << "��(��) " << InsPlayer->getName() << "��(��) �����ߴ�! " << InsPlayer->getName() << "�� ���� HP: " << InsPlayer->getHealth() << endl;

                    if (InsPlayer->getHealth() <= 0)
                    {
                        cout << InsPlayer->getName() << "��(��) ��������! ���� ����!" << endl;
                        delete InsPlayer;
                        InsPlayer = nullptr;
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                cout << player->getName() << "��(��) �����ƴ�!" << endl;
                break;
            }
            default:
                cout << "�߸��� �Է��Դϴ�." << endl;
                break;
            }
            break;
        }

        case 2: // ����
        {
            Shop* shop = new Shop();
            shop->DisplayItems();
            break;
        }
        case 3: // ���� Ȯ��
            InsPlayer->displayStats();
            break;

        case 4: // �κ��丮 Ȯ��
            cout << "�κ��丮 ����" << endl;
            DisplayInven(InsPlayer);
            break;

        default:
            cout << "�߸��� �Է��Դϴ�." << endl;
            break;
        }
    }
}

void GameManager::LootItem(Character* player)
{
    cout << player->getName() << "�� ����ǰ�� ì����ϴ�!" << endl << endl;
    player->gainItem(RandomValue(1, 100));
    player->gainExperience(); //50exp ����
    player->gainGold(RandomValue(10, 20));
}

int GameManager::FindItem(Character* player, __int64* HPItemcount, __int64* ATKItemcount)
{
    vector<Item*> item = player->getInventory();
    *HPItemcount = count_if(item.begin(), item.end(), [](Item* i) { return dynamic_cast<HealthItem*>(i) != nullptr; });
    *ATKItemcount = count_if(item.begin(), item.end(), [](Item* i) { return dynamic_cast<AttackBoost*>(i) != nullptr; });
    return 0;
}
