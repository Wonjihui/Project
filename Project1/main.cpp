#include <iostream>
#include "GameManager.h"
using namespace std;

int main() {
	string name = "";
	cout << "ĳ������ �̸��� �Է����ּ���: ";
	cin >> name;
	GameManager* gameManager = new GameManager();
	Character* player = Character::getInstance(name);
	gameManager->BattleSys(player);
	return 0;
}