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
    std::cout << getName() << " 을(를) 사용했습니다! 체력이 " << getEffectValue() << " 만큼 회복되었습니다." << std::endl;
}

// AttackBoost class
AttackBoost::AttackBoost(const std::string& name, int boostValue)
    : Item(name, "attack", boostValue) {
}

void AttackBoost::use(Character* character) {
    int newAttack = character->getAttack() + getEffectValue();
    character->setAttack(newAttack);
    std::cout << getName() << " 을(를) 사용했습니다! 공격력이 " << getEffectValue() << " 만큼 증가했습니다." << std::endl;
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
    std::cout << "캐릭터: " << name_ << std::endl;
    std::cout << "레벨: " << level_ << std::endl;
    std::cout << "체력: " << health_ << " / " << maxHealth_ << std::endl;
    std::cout << "공격력: " << attack_ << std::endl;
    std::cout << "경험치: " << experience_ << " / 100" << std::endl;
}

void Character::gainExperience(int expGain) {
    experience_ += expGain;
    std::cout << name_ << " 은(는) 경험치 " << expGain << " 을 얻었다!" << std::endl;

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
    std::cout << name_ << " 레벨 업! Lv." << level_ << "!" << std::endl;
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
