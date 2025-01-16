#ifndef SHOP_H
#define SHOP_H
#include<vector>
#include "Character.h"
#include "GameManager.h"
#include <iostream>

class Shop
{
public:
	Shop();
	~Shop();
	void DisplayItems();
	void BuyHealthPotion(int idx, Character* player);
	void BuyAttackBoost(int idx, Character* player);
	void BuyReviveStone(int idx, Character* player); // 새로 추가
	void SellItem(int idx, Character* player);

private:
	std::vector<Item*> AvailableItems;
};
#endif