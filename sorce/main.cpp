#include <iostream>
#include "Character.h"

int main() {
    Character* myCharacter = Character::getInstance("ġ�Ϳ�");

    myCharacter->displayStatus(); // �ʱ� ���� ���

    return 0;
}