#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../Monster/Monster.h"
#include "../Character/Character.h"
#include "../Item/Item.h"
#include "../Shop/Shop.h"
#include <vector>

class GameManager
{
public:
    GameManager();
    void DisplayInven(Character* player);
    int RandomValue(int min, int max);
    Monster* generateMonster(int level); // 기존 몬스터 생성
    Human* generateBossMonster(int level); // 보스 몬스터 생성
    void battle(Character* player); // 전투 관리
    void LootItem(Character* player);
    int FindItem(Character* player, __int64* HPItemcount, __int64* ATKItemcount);


};

#endif