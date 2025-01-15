#pragma once
#include<vector>
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Character.h"
#include <iostream>

class Character;

class Shop 
{
public:
	Shop();
	~Shop();
	void DisplayItems();
	void BuyHealthPotion(int idx, Character* player);
	void BuyAttackBoost(int idx, Character* player);
	void SellItem(int idx, Character* player);

private:
	vector<Item*> AvailableItems;
};