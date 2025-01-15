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
        std::cout << "캐릭터 이름을 입력해 주세요: ";
        std::getline(std::cin, name);

        if (name.empty()) {
            std::cout << "이름이 입력되지 않았습니다...! 다시 입력해 주세요...!" << std::endl;
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

    HealthItem potion("개 껌", 50);
    AttackBoost sword("사료", 10);

    myCharacter->useItem(&potion);
    myCharacter->displayStats();

    myCharacter->useItem(&sword);
    myCharacter->displayStats();

    return 0;
}