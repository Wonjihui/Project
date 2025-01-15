#pragma once
#include<vector>
#include "Character.h"
#include <iostream>

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
	std::vector<Item*> AvailableItems;
};