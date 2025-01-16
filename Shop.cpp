#include "Shop.h"
#include "Character.h"
#include "GameManager.h"

using namespace std;
Shop::Shop() {}
//상점 선택창
void Shop::DisplayItems()
{
	Character* player = Character::getInstance("");
	AvailableItems = player->getInventory();
	while (true)
	{
		cout << "상점에 방문하였습니다." << endl;
		cout << "1. 개껌 구매하기(50$)" << endl;
		cout << "2. 사료 구매하기(10$)" << endl;
		cout << "3. 부활석 구매하기(100$)" << endl;
		cout << "4. 아이템 판매하기" << endl;
		cout << "5. 로비로 이동하기" << endl;

		int choice; // 사용자의 메뉴 선택을 저장
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
			cout << "로비로 이동합니다." << endl;
			break;
		}
		else {
			cout << "잘못된 접근입니다. 1~5중에 선택하세요." << endl;
		}
	}
}

void Shop::BuyHealthPotion(int idx, Character* player)
{
	if (player->getGold() >= 50)
	{
		cout << "개껌을 구매하였습니다." << endl;
		player->gainGold(-50);
		player->gainItem(1);
	}
	else
	{
		cout << "골드가 부족합니다." << endl;
	}

}
void Shop::BuyAttackBoost(int idx, Character* player)
{
	if (player->getGold() >= 10)
	{
		cout << "사료를 구매하였습니다." << endl;
		player->gainGold(-10);
		player->gainItem(51);

	}
	else
		cout << "골드가 부족합니다." << endl;
}

void Shop::BuyReviveStone(int idx, Character* player)
{
	GameManager* InvenDiplay = new GameManager();
	if (player->getGold() >= 100)
	{
		cout << "부활석을 구매하였습니다." << endl;
		player->gainGold(-100);
		player->gainItem(101);
		InvenDiplay->DisplayInven(player);
	}
	else
		cout << "골드가 부족합니다." << endl;
}

void Shop::SellItem(int idx, Character* player)
{
	AvailableItems = player->getInventory();
	if (AvailableItems.empty())
	{
		cout << "보유중인 아이템이 없습니다." << endl;
		cout << "상점으로 돌아갑니다." << endl;
		return;
	}

	cout << "보유중인 아이템 :" << endl;
	GameManager* InvenDiplay = new GameManager();
	InvenDiplay->DisplayInven(player);

	cout << "판매할 아이템을 선택하세요" << endl;
	cout << "1: 개 껌" << endl;
	cout << "2: 사료" << endl;
	cout << "3: 부활석" << endl;
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
			cout << "개껌을 팔아서 30$를 획득했습니다." << endl;
			InvenDiplay->DisplayInven(player);
		}
		else
			cout << "개껌은 없습니다..." << endl;
		break;
	case 2:
		if (atk > 0)
		{
			player->gainGold(5);
			player->deleteItem(51);
			cout << "사료를 팔아서 5$를 획득했습니다." << endl;
			InvenDiplay->DisplayInven(player);
		}
		else
			cout << "사료는 없습니다..." << endl;
		break;
	case 3:
		if (rvv > 0)
		{
			player->gainGold(60);
			player->deleteItem(101);
			cout << "부활석을 팔아서 60$를 획득했습니다." << endl;
			InvenDiplay->DisplayInven(player);
		}
	}

	delete InvenDiplay;
}

Shop::~Shop()
{
}