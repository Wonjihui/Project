#include "Item.h"
#include <iostream>
#include "../Character/Character.h"



Item::Item(const std::string& name, const std::string& effectType, int effectValue)
    : name_(name), type_(effectType), value_(effectValue) {}

std::string Item::getName() const
{
    return name_;
}
std::string Item::getType() const
{
    return type_;
}
int Item::getValue() const
{
    return value_;
}

HealthItem::HealthItem(const std::string& name, int restoreValue)
    : Item(name, "health", restoreValue) {
}

void HealthItem::use(Character* character) {
    int newHealth = character->getHealth() + getValue();
    if (newHealth > character->getMaxHealth()) {
        newHealth = character->getMaxHealth();
    }
    character->setHealth(newHealth);
    std::cout << getName() << " 을(를) 사용했습니다! 체력이 " << getValue() << " 만큼 회복되었습니다." << std::endl;
}

// AttackBoost class
AttackBoost::AttackBoost(const std::string& name, int boostValue)
    : Item(name, "attack", boostValue) {
}

void AttackBoost::use(Character* character) {
    int newAttack = character->getAttack() + getValue();
    character->setAttack(newAttack);
    std::cout << getName() << " 을(를) 사용했습니다! 공격력이 " << getValue() << " 만큼 증가했습니다." << std::endl;
}



