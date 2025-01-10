#include "Character.h"
#include <iostream>

Character* Character::instance = nullptr;

Character::Character(const std::string& name) :
    name(name), level(1), health(200), maxHealth(200), attack(30), experience(0), gold(0) {
}

Character* Character::getInstance(const std::string& name) {
    if (instance == nullptr) {
        instance = new Character(name);
    }
    return instance;
}

void Character::displayStatus() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Health: " << health << " / " << maxHealth << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "Experience: " << experience << std::endl;
    std::cout << "Gold: " << gold << std::endl;
}

void Character::levelUp()
{
}

void Character::useItem(int index)
{
}



