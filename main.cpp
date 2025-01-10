#include <iostream>
#include "Character.h"

int main() {
    Character* myCharacter = Character::getInstance("치와와");

    myCharacter->displayStatus(); // 초기 상태 출력

    return 0;
}