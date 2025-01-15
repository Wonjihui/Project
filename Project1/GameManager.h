#pragma once
#include <iostream>
#include <string>
#include <random>
#include "Character.h"
#include "Monster.h"
#include "Shop.h"
using namespace std;

class GameManager
{
public:
	void DisplayInven(Character* player);

	void BattleSys(Character* player);

	Monster* MonsterSpawn(int level);

	int RandomValue(int min, int max);

	void LootItem(Character* player);

	int FindItem(Character* player,__int64 *a, __int64 *b);
};