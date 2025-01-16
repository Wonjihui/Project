#include "Shop.h"
#include "Character.h"
#include "GameManager.h"

using namespace std;
Shop::Shop() {}
//���� ����â
void Shop::DisplayItems()
{
	Character* player = Character::getInstance("");
	AvailableItems = player->getInventory();
	while (true)
	{
		cout << "������ �湮�Ͽ����ϴ�." << endl;
		cout << "1. ���� �����ϱ�(50$)" << endl;
		cout << "2. ��� �����ϱ�(10$)" << endl;
		cout << "3. ��Ȱ�� �����ϱ�(100$)" << endl;
		cout << "4. ������ �Ǹ��ϱ�" << endl;
		cout << "5. �κ�� �̵��ϱ�" << endl;

		int choice; // ������� �޴� ������ ����
		cin >> choice;

		if (choice == 1) {
			BuyHealthPotion(1, player);
		}
		else if (choice == 2) {
			BuyAttackBoost(1, player);
		}
		else if (choice == 3) {
			BuyReviveStone(1, player);
		}
		else if (choice == 4) {
			SellItem(1, player);
		}
		else if (choice == 5) {
			cout << "�κ�� �̵��մϴ�." << endl;
			break;
		}
		else {
			cout << "�߸��� �����Դϴ�. 1~5�߿� �����ϼ���." << endl;
		}
	}
}

void Shop::BuyHealthPotion(int idx, Character* player)
{
	if (player->getGold() >= 50)
	{
		cout << "������ �����Ͽ����ϴ�." << endl;
		player->gainGold(-50);
		player->gainItem(1);
	}
	else
	{
		cout << "��尡 �����մϴ�." << endl;
	}

}
void Shop::BuyAttackBoost(int idx, Character* player)
{
	if (player->getGold() >= 10)
	{
		cout << "��Ḧ �����Ͽ����ϴ�." << endl;
		player->gainGold(-10);
		player->gainItem(51);

	}
	else
		cout << "��尡 �����մϴ�." << endl;
}

void Shop::BuyReviveStone(int idx, Character* player)
{
	GameManager* InvenDiplay = new GameManager();
	if (player->getGold() >= 100)
	{
		cout << "��Ȱ���� �����Ͽ����ϴ�." << endl;
		player->gainGold(-100);
		player->gainItem(101);
		InvenDiplay->DisplayInven(player);
	}
	else
		cout << "��尡 �����մϴ�." << endl;
}

void Shop::SellItem(int idx, Character* player)
{
	AvailableItems = player->getInventory();
	if (AvailableItems.empty())
	{
		cout << "�������� �������� �����ϴ�." << endl;
		cout << "�������� ���ư��ϴ�." << endl;
		return;
	}

	cout << "�������� ������ :" << endl;
	GameManager* InvenDiplay = new GameManager();
	InvenDiplay->DisplayInven(player);

	cout << "�Ǹ��� �������� �����ϼ���" << endl;
	cout << "1: �� ��" << endl;
	cout << "2: ���" << endl;
	cout << "3: ��Ȱ��" << endl;
	int choice;
	cin >> choice;
	__int64 hp;
	__int64 atk;
	__int64 rvv;
	InvenDiplay->FindItem(player, &hp, &atk, &rvv);
	switch (choice)
	{
	case 1:
		if (hp > 0)
		{
			player->gainGold(30);
			player->deleteItem(1);
			cout << "������ �ȾƼ� 30$�� ȹ���߽��ϴ�." << endl;
			InvenDiplay->DisplayInven(player);
		}
		else
			cout << "������ �����ϴ�..." << endl;
		break;
	case 2:
		if (atk > 0)
		{
			player->gainGold(5);
			player->deleteItem(51);
			cout << "��Ḧ �ȾƼ� 5$�� ȹ���߽��ϴ�." << endl;
			InvenDiplay->DisplayInven(player);
		}
		else
			cout << "���� �����ϴ�..." << endl;
		break;
	case 3:
		if (rvv > 0)
		{
			player->gainGold(60);
			player->deleteItem(101);
			cout << "��Ȱ���� �ȾƼ� 60$�� ȹ���߽��ϴ�." << endl;
			InvenDiplay->DisplayInven(player);
		}
	}

	delete InvenDiplay;
}

Shop::~Shop()
{
}