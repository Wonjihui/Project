#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../Monster/Monster.h"
#include "../sorce/Character.h"
#include <vector>

class GameManager
{
public:
    GameManager();
    Monster* generateMonster(int level); // 기존 몬스터 생성
    Human* generateBossMonster(int level); // 보스 몬스터 생성
    void battle(Character* player); // 전투 관리
};

#endif