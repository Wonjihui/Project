#include "Item.h"
#include <iostream>



Item::Item(const std::string& name, const std::string& effectType, int effectValue)
    : name_(name), effectType_(effectType), effectValue_(effectValue) {
}

std::string Item::getName() const {
    return name_;
}

std::string Item::getEffectType() const {
    return effectType_;
}

int Item::getEffectValue() const {
    return effectValue_;
}

void HealthItem::use(Character* character) {
    int newHealth = character->getHealth() + getEffectValue();
    if (newHealth > character->getMaxHealth()) {
        newHealth = character->getMaxHealth();
    }
    character->setHealth(newHealth);
    std::cout << getName() << "을(를) 먹었습니다! 체력이" << getEffectValue() << "만큼 회복 되었습니다!" << std::endl;
}

void AttackBoost::use(Character* character) {
    int newAttack = character->getAttack() + getEffectValue();
    character->setAttack(newAttack);
    std::cout << getName() << "을(를) 먹었습니다! 공격력이" << getEffectValue() << "만큼 증가 되었습니다!" << std::endl;
}

void Item::useItem(Item* item) {
    item->use(this);
}
