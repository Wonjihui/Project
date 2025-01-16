#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Monster.h"
#include "Character.h"
#include "Item.h"
#include "Shop.h"
#include <vector>

class GameManager
{
public:
    GameManager();
    void DisplayInven(Character* player);
    int RandomValue(int min, int max);
    Monster* generateMonster(int level); // ���� ���� ����
    Human* generateBossMonster(int level); // ���� ���� ����
    void battle(Character* player); // ���� ����
    void LootItem(Character* player);
    int FindItem(Character* player, __int64* HPItemcount, __int64* ATKItemcount, __int64* RVVItemcount);


};

#endif