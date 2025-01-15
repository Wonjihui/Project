#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "../Character/Character.h"

class Item
{
protected:
    std::string name_;
    int value_;

public:

    void useItem(Item* item);

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
#endif