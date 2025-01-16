#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "../Character/Character.h"
class Character;

class Item
{
protected:
    int value_;
    std::string name_;
    std::string type_;

public:

    Item(const std::string& name, const std::string& effectType, int effectValue);
    virtual ~Item() = default;

    std::string getName()const;
    std::string getType() const;
    int getValue()const;
    virtual void use(Character* character) = 0;
};

class HealthItem : public Item 
{
public:
    HealthItem(const std::string& name, int restoreValue);
    void use(Character* character) override;
};


class AttackBoost : public Item 
{
public:
    AttackBoost(const std::string& name, int boostValue);
    void use(Character* character) override;
};

class ReviveStone : public Item
{

public:
    ReviveStone(const std::string& name, int ReviveValue);
    void use(Character* character) override;
};

#endif