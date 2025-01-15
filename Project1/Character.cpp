#include "Character.h"
#include <iostream>

using namespace std;

Character* Character::instance = nullptr;


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


Character::Character(const std::string& name, int level, int health, int attack, int experience,int gold)
    : name_(name), level_(level), health_(health), maxHealth_(health), attack_(attack), experience_(experience), gold_(gold)
{
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

std::string Character::getName()
{
    return name_;
}

int Character::getGold()
{
    return gold_;
}

int Character::getLevel()
{
    return level_;
}

void Character::getDamage(int damage)
{
    health_-=damage;
}

int Character::gainGold(int gold)
{
    gold_ += gold;
    cout << name_ << "��(��) " << gold << "��带 �����!" << endl;
    return gold;
}

void Character::displayStats() const {
    std::cout << "ĳ����: " << name_ << std::endl;
    std::cout << "����: " << level_ << std::endl;
    std::cout << "ü��: " << health_ << " / " << maxHealth_ << std::endl;
    std::cout << "���ݷ�: " << attack_ << std::endl;
    std::cout << "����ġ: " << experience_ << " / 100" << std::endl;
}

int Character::gainExperience(int expGain) {
    experience_ += expGain;
    std::cout << name_ << "��(��) ����ġ " << expGain << " �� �����!" << std::endl;

    if (experience_ >= 100) {
        levelUp(experience_ / 100);
        experience_ %= 100;
    }
    return expGain;
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

void Character::gainItem(int value)
{
    if (value <= 50) {
        inventory.emplace_back(new HealthItem("�� ��", 50));
        cout << "�� �� ȹ��" << endl;
    }
    else if(value > 50)
    {
        inventory.emplace_back(new AttackBoost("���", 10));
        cout << "��� ȹ��" << endl;
    }
}

void Character::deleteItem(int value)
{
    if (value <= 50) {
        inventory.erase(remove_if(inventory.begin(), inventory.end(), [](Item* i) {return dynamic_cast<HealthItem*>(i) != nullptr; }));

    }
    else if (value > 50)
    {
        inventory.erase(remove_if(inventory.begin(), inventory.end(), [](Item* i) {return dynamic_cast<AttackBoost*>(i) != nullptr; }));
    }
}

std::vector<Item*> Character::getInventory()
{
    return inventory;
}