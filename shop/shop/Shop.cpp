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




//���� ����â
void Shop::DisplayItems()
{
	Shop shop;

	while (true)
	{
		cout << "������ �湮�Ͽ����ϴ�." << endl;
		cout << "1. ���� �����ϱ�(50$)" << endl;
		cout << "2. ��� �����ϱ�(10$)" << endl;
		cout << "3. ������ �Ǹ��ϱ�" << endl;
		cout << "4. �κ�� �̵��ϱ�" << endl;

		int choice; // ������� �޴� ������ ����
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
			cout << "�κ�� �̵��մϴ�." << endl;
			break;
		}
		else {
			cout << "�߸��� �����Դϴ�. 1~4�߿� �����ϼ���." << endl;
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
		cout << "������ �����Ͽ����ϴ�." << endl;
	}
	else
	{
		cout << "��尡 �����մϴ�." << endl;
	}
		
}
void Shop::BuyAttackBoost(int idx, Character* player)
{
	Item* item = AvailableItems[idx];

	if (player.getGold() >= 10)
	{
		player->setGold(player.getGold() - 10);
		player->addItem(AttackBoost());
		cout << "��Ḧ �����Ͽ����ϴ�." << endl;
	}
	else
		cout << "��尡 �����մϴ�." << endl;
}

void Shop::SellItem(int idx, Character* player)
{
	vector<Item*>& Inventory = player->GetInventory();

	if (Inventory.empty())
	{
		cout << "�������� �������� �����ϴ�." << endl;
		cout << "�������� ���ư��ϴ�." << endl;
		return;
	}

	cout << "�������� ������ :" << endl;
	for (size_t i = 0; i < Inventory.size(); i++) {
		cout << i + 1 << "." << item.getname() << endl;
	}
	cout << "�Ǹ��� �������� �����ϼ���" << endl;

	int choice;
	cin >> choice;

	if (choice == Inventory.size() + 1)
	{
		if (item.getname() == item.getname(HealthPotion))
		{
			player->setGold(player.getPrice() + 30);
			inventory.erase(inventory.begin() + 0);
			delete item;
			cout << "������ �ȾƼ� 30$�� ȹ���߽��ϴ�." << endl;
		}
		else if (item.getname() == item.getname(AttackBoost))
		{
			player->setGold(player.getPrice() + 5);
			inventory.erase(Inventory.begin() + 0);
			delete item;
			cout << "��Ḧ �ȾƼ� 5$�� ȹ���߽��ϴ�." << endl;
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