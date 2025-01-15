#include "Item.h"
#include <iostream>



Item::Item(const std::string& name, const std::string& effectType, int effectValue)
    : name_(name), type_(effectType), value_(effectValue) {
}

std::string Item::getName() const {
    return name_;
}
int Item::getValue() const {
    return value_;
}

void HealthItem::use(Character* character) {
    int newHealth = character->getHealth() + getValue();
    if (newHealth > character->getMaxHealth()) {
        newHealth = character->getMaxHealth();
    }
    character->setHealth(newHealth);
    std::cout << getName() << "��(��) �Ծ����ϴ�! ü����" << getValue() << "��ŭ ȸ�� �Ǿ����ϴ�!" << std::endl;
}

void AttackBoost::use(Character* character) {
    int newAttack = character->getAttack() + getValue();
    character->setAttack(newAttack);
    std::cout << getName() << "��(��) �Ծ����ϴ�! ���ݷ���" << getValue() << "��ŭ ���� �Ǿ����ϴ�!" << std::endl;
}

void Item::useItem(Character* character) {
    this->use(character);
}
