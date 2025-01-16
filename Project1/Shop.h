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
	void BuyHealthPotion(Character* player);
	void BuyAttackBoost(Character* player);
	void SellItem(Character* player);

private:
	std::vector<Item*> AvailableItems;
};