#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../Monster/Monster.h"
#include "../sorce/Character.h"
#include <vector>

class GameManager
{
public:
    GameManager();
    Monster* generateMonster(int level); // ���� ���� ����
    Human* generateBossMonster(int level); // ���� ���� ����
    void battle(Character* player); // ���� ����
};

#endif