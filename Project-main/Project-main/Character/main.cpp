#include "Character.h"
#include "../Item/Item.h"
#include "../Monster/Monster.h"
#include "../GameManager/GameManager.h"
#include <iostream>

using namespace std;


int main() {
    std::string name;

    std::cout << "======================================================================================================================== " << std::endl;
    std::cout << "                                                 Level Up! Wawa!                                                     " << std::endl;
    std::cout << "======================================================================================================================== " << std::endl;

    while (true) {
        std::cout << "ĳ���� �̸��� �Է��� �ּ���: ";
        std::getline(std::cin, name);

        if (name.empty()) {
            std::cout << "�̸��� �Էµ��� �ʾҽ��ϴ�...! �ٽ� �Է��� �ּ���...!" << std::endl;
        }
        else {
            break;
        }
    }

    Character* myCharacter = Character::getInstance(name);
    GameManager gameManager;

	gameManager.battle(myCharacter);
 
    return 0;
}