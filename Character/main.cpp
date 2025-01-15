#include "Character.h"
#include "../Item/Item.h"
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
    myCharacter->displayStats();

    myCharacter->gainExperience(50);
    myCharacter->displayStats();

    myCharacter->gainExperience(60);
    myCharacter->displayStats();

    HealthItem potion("�� ��", 50);
    AttackBoost sword("���", 10);

    myCharacter->useItem(&potion);
    myCharacter->displayStats();

    myCharacter->useItem(&sword);
    myCharacter->displayStats();

    return 0;
}