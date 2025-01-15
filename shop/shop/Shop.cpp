#include "Shop.h"
#include <iostream>
#include "Item.h"
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

using namespace std;


Shop::Shop()
{
	AvailableItems.push_back(new HealthPotion());
	AvailableItems.push_back(new AttackBoost());
}




//상점 선택창
void Shop::DisplayItems()
{
	Shop shop;

	while (true)
	{
		cout << "상점에 방문하였습니다." << endl;
		cout << "1. 개껌 구매하기(50$)" << endl;
		cout << "2. 사료 구매하기(10$)" << endl;
		cout << "3. 아이템 판매하기" << endl;
		cout << "4. 로비로 이동하기" << endl;

		int choice; // 사용자의 메뉴 선택을 저장
		cin >> choice;

		if (choice == 1) {
			shop.BuyHealthPotion();
		}
		else if (choice == 2) {
			shop.BuyAttackBoost();
		}
		else if (choice == 3) {
			shop.SellItem();
		}
		else if (choice == 4) {
			cout << "로비로 이동합니다." << endl;
			break;
		}
		else {
			cout << "잘못된 접근입니다. 1~4중에 선택하세요." << endl;
		}
	}
}

void Shop::BuyHealthPotion(int idx, Character* player)
{
	Item* item = AvailableItems[idx];

	if (player.getGold() >= 50)
	{
		player.setGold(player.getGold() - 50);
		player.addItem(HealthPotion());
		cout << "개껌을 구매하였습니다." << endl;
	}
	else
	{
		cout << "골드가 부족합니다." << endl;
	}
		
}
void Shop::BuyAttackBoost(int idx, Character* player)
{
	Item* item = AvailableItems[idx];

	if (player.getGold() >= 10)
	{
		player->setGold(player.getGold() - 10);
		player->addItem(AttackBoost());
		cout << "사료를 구매하였습니다." << endl;
	}
	else
		cout << "골드가 부족합니다." << endl;
}

void Shop::SellItem(int idx, Character* player)
{
	vector<Item*>& Inventory = player->GetInventory();

	if (Inventory.empty())
	{
		cout << "보유중인 아이템이 없습니다." << endl;
		cout << "상점으로 돌아갑니다." << endl;
		return;
	}

	cout << "보유중인 아이템 :" << endl;
	for (size_t i = 0; i < Inventory.size(); i++) {
		cout << i + 1 << "." << item.getname() << endl;
	}
	cout << "판매할 아이템을 선택하세요" << endl;

	int choice;
	cin >> choice;

	if (choice == Inventory.size() + 1)
	{
		if (item.getname() == item.getname(HealthPotion))
		{
			player->setGold(player.getPrice() + 30);
			inventory.erase(inventory.begin() + 0);
			delete item;
			cout << "개껌을 팔아서 30$를 획득했습니다." << endl;
		}
		else if (item.getname() == item.getname(AttackBoost))
		{
			player->setGold(player.getPrice() + 5);
			inventory.erase(Inventory.begin() + 0);
			delete item;
			cout << "사료를 팔아서 5$를 획득했습니다." << endl;
		}

	}

}

Shop::~Shop()
{
	for (Item* item : AvailableItems)
	{
		delete item;
	}
}