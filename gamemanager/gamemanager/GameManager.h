#pragma once

#include <string>

using namespace std;

class Monster;
class Character;

class GameManager
{
public:
	Monster* generateMonster(int level);
	void battle(Character* player);
	void displayInventory(Character* player);

	int totalGold = 0;
	int totaluseitem = 0;
	int totalKillMonster = 0;
};