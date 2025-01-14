#include <iostream>
#include "Character.h"
#include "GameManager.h"

using namespace std;

Character* Character::instance = nullptr;


int main() {
	GameManager* gameManager = new GameManager();
	Character* player = Character::getInstance("");
	gameManager->BattleSys(player);
	return 0;
}