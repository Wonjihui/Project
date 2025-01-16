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
    std::cout << getName() << " ��(��) ����߽��ϴ�! ü���� " << getValue() << " ��ŭ ȸ���Ǿ����ϴ�." << std::endl;
}

// AttackBoost class
AttackBoost::AttackBoost(const std::string& name, int boostValue)
    : Item(name, "attack", boostValue) {
}

void AttackBoost::use(Character* character) {
    int newAttack = character->getAttack() + getValue();
    character->setAttack(newAttack);
    std::cout << getName() << " ��(��) ����߽��ϴ�! ���ݷ��� " << getValue() << " ��ŭ �����߽��ϴ�." << std::endl;
}



