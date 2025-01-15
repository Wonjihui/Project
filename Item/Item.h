#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "../Character/Character.h"

class Item
{
protected:
    std::string name_;
    int value_;
    std::string type_;

public:

    Item(const std::string& name, const std::string& effectType, int effectValue);

    void useItem(Character* character);

    Item(const std::string& name, int value) : name_(name), value_(value) {}
    virtual ~Item() {}

    std::string getName()const;

    int getValue()const;

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

    void use(Character* Character) override;
};

class AttackBoost : public Item
{
private:
    int attackIncrease_;

public:
    AttackBoost(const std::string& name, int value, int attackIncrease)
        : Item(name, value), attackIncrease_(attackIncrease) {
    }

    void use(Character* Character) override;
};
#endif