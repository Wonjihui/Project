#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameManager::GameManager()
{
    srand(static_cast<unsigned>(time(0))); // 랜덤 시드 초기화
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
    if (player->getLevel() < 10)
    {
        // 기존 몬스터와 전투
        Monster* monster = generateMonster(player->getLevel());
        std::cout << "A wild " << monster->getName() << " appears!" << std::endl;

        while (monster->getHealth() > 0 && player->getHealth() > 0)
        {
            // 캐릭터 공격
            monster->takeDamage(player->getAttack());
            if (monster->getHealth() <= 0)
            {
                std::cout << monster->getName() << " defeated!" << std::endl;
                delete monster;
                player->levelUp();
                return;
            }

            // 몬스터 공격
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
        // 보스 몬스터와 전투
        Human* Human = generateBossMonster(player->getLevel());
        std::cout << "보스 몬스터 " << Human->getName() << " 이 나타났습니다!" << std::endl;

        while (Human->getHealth() > 0 && player->getHealth() > 0)
        {
            // 캐릭터 공격
            Human->takeDamage(player->getAttack());
            std::cout << Human->getName() << " defeated!" << std::endl;
            if (Human->getHealth() <= 0)
            {
                std::cout << Human->getName() << " defeated!" << std::endl;
                delete Human;
                return;
            }

            // 보스 몬스터 공격
            player->takeDamage(Human->getAttack());
            if (player->getHealth() <= 0)
            {
                std::cout << "보스 몬스터와의 전투에서 패배했습니다" << std::endl;
                return;
            }
        }
    }
}