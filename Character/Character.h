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

    Character(const std::string& name, int level = 1, int health = 200, int attack = 30, int experience = 0, int gold = 0);



public:

    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;
    static Character* getInstance(const std::string& name);

    void displayStats() const;
    void gainExperience(int expGain);
    void levelUp();

    int getHealth() const;
    int getAttack() const;
	int getLevel() const;
    void takeDamage(int damage);


    void setHealth(int health);
    int getMaxHealth() const;
    void setAttack(int attack);
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

        std::cout << "개 껌을 먹었습니다! +HP : " << healthRestore_ << std::endl;
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
        std::cout << "사료를 먹었습니다! +ATTACK : " << attackIncrease_ << std::endl;
    }
};

