#pragma once
#include <string>
#include <vector>
#include <iostream>

class Character {
private:
    static Character* instance;
    std::string name_;
    int level_;
    int health_;
    int maxHealth_;
    static const int maxLevel_ = 10;
    int attack_;
    int experience_;
    int gold_;

    Character(const std::string& name, int level = 1, int health = 200, int attack = 30, int experience = 0, gold=0);



public:
 
    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;
    static Character* getInstance(const std::string& name);


    int getHealth() const;
    void setHealth(int health);
    int getMaxHealth() const;
    int getAttack() const;
    void setAttack(int attack);

    void displayStats() const;
    void gainExperience(int expGain);
    void levelUp(int levels);
    void useItem(Item* item);
};

class Character;

class Item
{
protected:
    std::string name_;
    int value_;

public:
    Item(const std::string& name, int value) : name_(name), value_(value) {}

    virtual ~Item() {}

    std::string getName() const { return name_; }

    int getValue() const { return value_; }

    virtual void use(Character* character) = 0;
};

class HealthItem : public Item
{
private:
    int healthRestore_;

public:
    HealthItem(const std::string& name, int value, int healthRestore)
        : Item(name, value), healthRestore_(healthRestore) {
    }

    void use(Character* Character) override
    {

        std::cout << "°³ ²­À» ¸Ô¾ú½À´Ï´Ù! +HP : " << healthRestore_ << std::endl;
    }
};

class AttackBoost : public Item
{
private:
    int attackIncrease_;

public:
    AttackBoost(const std::string& name, int value, int attackIncrease)
        : Item(name, value), attackIncrease_(attackIncrease) {
    }

    void use(Character* Character) override
    {
        std::cout << "»ç·á¸¦ ¸Ô¾ú½À´Ï´Ù! +ATTACK : " << attackIncrease_ << std::endl;
    }
};

