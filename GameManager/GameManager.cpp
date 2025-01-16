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
            << "������ �̵� : 1 " << endl
            << "���� �̿� : 2" << endl
            << "���� Ȯ�� : 3" << endl
            << "�κ��丮 : 4" << endl;
        cin >> move;

        switch (move)
        {
        case 1: // ���� ����
        {
            cout << "������ �̵� ��..." << endl << endl;
            Monster* enemy = nullptr;
            if (InsPlayer->getLevel() < 10)
            {
                enemy = generateMonster(InsPlayer->getLevel());
                cout << "��! " << enemy->getName() << "�� ��Ÿ����!" << endl << endl;
            }
            else
            {
                enemy = generateBossMonster(InsPlayer->getLevel());
                cout << "�������̱�... " << enemy->getName() << "�� ��Ÿ����!" << endl << endl;
            }

            cout << enemy->getName() << "�� �ɷ�ġ - HP: " << enemy->getHealth() << " ATK: " << enemy->getAttack() << endl << endl;
            cout << "����ϰ� �ο��! : 1" << endl;
            cout << "���� ���� ����ġ��... : 2" << endl;
            cin >> move;
            switch (move)
            {
            case 1:
            {
                int turnCount = 1;
                while (enemy != nullptr && InsPlayer != nullptr && enemy->getHealth() > 0 && InsPlayer->getHealth() > 0)
                {
                    cout << "=====Turn" << turnCount << "=====" << endl;
                    
                    cout << "\n[���� ����]" << endl;
                    cout << InsPlayer->getName() << " - HP: " << InsPlayer->getHealth() << endl;
                    cout << enemy->getName() << " - HP: " << enemy->getHealth() << endl << endl;

                    cout << "����� ���Դϴ�!\n" << endl;
                    cout << "1. �Ϲ� ����" << endl;
                    cout << "2. ������ ���" << endl;
                    cout << "3. ��������" << endl;
                    cout << "����:\n ";
                    int choice;
                    cin >> choice; 

                    switch (choice) {
                    case 1: 
                    {
                        enemy->takeDamage(InsPlayer->getAttack());
                        cout << InsPlayer->getName() << "��(��) " << enemy->getName() << "��(��) �����ߴ�!\n" << endl;
                        cout << enemy->getName() << "�� ���� HP:\n " << max(0, enemy->getHealth()) << endl;
                        break;
                    }
                    case 2: // ������ ���
                    {
                        __int64 HPItemcount, ATKItemcount;
                        FindItem(InsPlayer, &HPItemcount, &ATKItemcount);
                        cout << "\n����� �������� �����ϼ���:" << endl;
                        cout << "1. ���� (HPȸ��) - " << HPItemcount << "�� ������" << endl;
                        cout << "2. ��� (���ݷ�����) - " << ATKItemcount << "�� ������" << endl;
                        cout << "3. ���ư���" << endl;
                        int itemChoice;
                        cin >> itemChoice;
                        
                        break;
                    }
                    case 3: 
                    {
                        if (RandomValue(1, 100) <= 30) {
                            cout << InsPlayer->getName() << "��(��) ����ġ�µ� �����ߴ�!" << endl;
                            delete enemy;
                            return;
                        }
                        else {
                            cout << InsPlayer->getName() << "��(��) ����ġ�� ���ߴ�!" << endl;
                        }
                        break;
                    }
                    default:
                        cout << "�߸��� �����Դϴ�. ���� �ѱ�ϴ�." << endl;
                        break;
                    }

                   
                    if (enemy->getHealth() <= 0) {
                        cout << InsPlayer->getName() << "��(��) " << enemy->getName() << "��(��) �����ߴ�! " << enemy->getName() << "�� ���� HP: 0\n" << endl;
                        cout << enemy->getName() << "��(��) ��������! �¸�!\n" << endl;
                        InsPlayer->setTotalKillMonster();
                        int rangold = RandomValue(10, 20);
                        InsPlayer->gainGold(rangold);
                        InsPlayer->gainExperience();
                        LootItem(InsPlayer);
                        cout << InsPlayer->getName() << "��(��)" << rangold << "��带 ȹ���߽��ϴ�. ���� ���: " << InsPlayer->getGold() << endl; // "exp: 50/100" �߰��ؾߵ� getExp()�Լ� �߰��ؾߵ�

                        delete enemy;
                        enemy = nullptr;
                        break;
                    }

                    // ���� ��
                    cout << "\n" << enemy->getName() << "�� ���Դϴ�!" << endl;
                    InsPlayer->takeDamage(enemy->getAttack());
                    cout << enemy->getName() << "��(��) " << InsPlayer->getName() << "��(��) �����ߴ�!\n" << endl;
                    cout << InsPlayer->getName() << "�� ���� HP: " << InsPlayer->getHealth() << endl;

                    // �÷��̾� ���� Ȯ��
                    if (InsPlayer->getHealth() <= 0) {
                        cout << "\n" << InsPlayer->getName() << "��(��) ��������! ���� ����!/n" << endl;
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
                cout << player->getName() << "��(��) ������ ���� �����ƴ�!" << endl;
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
    cout << player->getName() << "�� ����ǰ�� ì���!" << endl;
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