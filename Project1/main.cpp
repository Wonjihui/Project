#include <iostream>
#include "GameManager.h"
using namespace std;

int main() {
	string name = "";
	cout << "캐릭터의 이름을 입력해주세요: ";
	cin >> name;
	GameManager* gameManager = new GameManager();
	Character* player = Character::getInstance(name);
	gameManager->BattleSys(player);
	return 0;
}