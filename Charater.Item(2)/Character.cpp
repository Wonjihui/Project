#include "Character.h"
#include <iostream>

using namespace std;

Character * Character::instance = nullptr;


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


HealthItem::HealthItem(const std::string& name, int restoreValue)
    : Item(name, "health", restoreValue) {
}

void HealthItem::use(Character* character) {
    int newHealth = character->getHealth() + getEffectValue();
    if (newHealth > character->getMaxHealth()) {
        newHealth = character->getMaxHealth();
    }
    character->setHealth(newHealth);
    std::cout << getName() << " ��(��) ����߽��ϴ�! ü���� " << getEffectValue() << " ��ŭ ȸ���Ǿ����ϴ�." << std::endl;
}

// AttackBoost class
AttackBoost::AttackBoost(const std::string& name, int boostValue)
    : Item(name, "attack", boostValue) {
}

void AttackBoost::use(Character* character) {
    int newAttack = character->getAttack() + getEffectValue();
    character->setAttack(newAttack);
    std::cout << getName() << " ��(��) ����߽��ϴ�! ���ݷ��� " << getEffectValue() << " ��ŭ �����߽��ϴ�." << std::endl;
}


Character::Character(const std::string& name, int level, int health, int attack, int experience)
    : name_(name), level_(level), health_(health), maxHealth_(health), attack_(attack), experience_(experience) {
}

Character* Character::getInstance(const std::string& name) {
    if (instance == nullptr) {
        instance = new Character(name);
    }
    return instance;
}

int Character::getHealth() const {
    return health_;
}

void Character::setHealth(int health) {
    health_ = health;
}

int Character::getMaxHealth() const {
    return maxHealth_;
}

int Character::getAttack() const {
    return attack_;
}

void Character::setAttack(int attack) {
    attack_ = attack;
}

void Character::displayStats() const {
    std::cout << "ĳ����: " << name_ << std::endl;
    std::cout << "����: " << level_ << std::endl;
    std::cout << "ü��: " << health_ << " / " << maxHealth_ << std::endl;
    std::cout << "���ݷ�: " << attack_ << std::endl;
    std::cout << "����ġ: " << experience_ << " / 100" << std::endl;
}

void Character::gainExperience(int expGain) {
    experience_ += expGain;
    std::cout << name_ << " ��(��) ����ġ " << expGain << " �� �����!" << std::endl;

    if (experience_ >= 100) {
        levelUp(experience_ / 100);
        experience_ %= 100;
    }
}

void Character::levelUp(int levels) {
    if (level_ >= maxLevel_) {
        return;
    }

    level_ += levels;
    if (level_ > maxLevel_) {
        level_ = maxLevel_;
    }

    maxHealth_ += levels * 20;
    attack_ += levels * 5;
    health_ = maxHealth_;
    std::cout << name_ << " ���� ��! Lv." << level_ << "!" << std::endl;
}

void Character::useItem(Item* item) {
    item->use(this);
}


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
