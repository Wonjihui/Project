#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameManager::GameManager()
{
    srand(static_cast<unsigned>(time(0))); // ���� �õ� �ʱ�ȭ
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
    if (player->getLevel() < 10)
    {
        // ���� ���Ϳ� ����
        Monster* monster = generateMonster(player->getLevel());
        std::cout << "A wild " << monster->getName() << " appears!" << std::endl;

        while (monster->getHealth() > 0 && player->getHealth() > 0)
        {
            // ĳ���� ����
            monster->takeDamage(player->getAttack());
            if (monster->getHealth() <= 0)
            {
                std::cout << monster->getName() << " defeated!" << std::endl;
                delete monster;
                player->levelUp();
                return;
            }

            // ���� ����
            player->takeDamage(monster->getAttack());
            if (player->getHealth() <= 0)
            {
                std::cout << "You have been defeated!" << std::endl;
                return;
            }
        }
    }
    else
    {
        // ���� ���Ϳ� ����
        Human* Human = generateBossMonster(player->getLevel());
        std::cout << "���� ���� " << Human->getName() << " �� ��Ÿ�����ϴ�!" << std::endl;

        while (Human->getHealth() > 0 && player->getHealth() > 0)
        {
            // ĳ���� ����
            Human->takeDamage(player->getAttack());
            std::cout << Human->getName() << " defeated!" << std::endl;
            if (Human->getHealth() <= 0)
            {
                std::cout << Human->getName() << " defeated!" << std::endl;
                delete Human;
                return;
            }

            // ���� ���� ����
            player->takeDamage(Human->getAttack());
            if (player->getHealth() <= 0)
            {
                std::cout << "���� ���Ϳ��� �������� �й��߽��ϴ�" << std::endl;
                return;
            }
        }
    }
}