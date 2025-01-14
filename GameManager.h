#pragma once

#include <iostream>
#include <string>
#include <random>
#include "Character.h"
#include "Monster.h"
using namespace std;

class Charater;

class GameManager
{
public:
	void DisplayInven(Character* player);

	void BattleSys(Character* player);
	
	Monster* MonsterSpawn(int level);

	int RandomValue(int min, int max);
};