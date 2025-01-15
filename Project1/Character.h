#pragma once
#include <string>
#include <vector>
#include <iostream>

class Character;

class Item {
protected:
    std::string name_;
    std::string effectType_;
    int effectValue_;
public:
    Item(const std::string& name, const std::string& effectType, int effectValue);
    virtual ~Item() = default;

    std::string getName() const;
    std::string getEffectType() const;
    int getEffectValue() const;

    virtual void use(Character* character) = 0;
};


class HealthItem : public Item {
public:
    HealthItem(const std::string& name, int restoreValue);
    void use(Character* character) override;
};


class AttackBoost : public Item {
public:
    AttackBoost(const std::string& name, int boostValue);
    void use(Character* character) override;
};


class Character {
private:
    static Character* instance;
    const std::string name_;
    int level_;
    int health_;
    int maxHealth_;
    static const int maxLevel_ = 10;
    int attack_;
    int experience_;
    int gold_;
    std::vector<Item*> inventory;

    Character(const std::string& name, int level = 1, int health = 200, int attack = 30, int experience = 0, int gold_ = 0);

public:

    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;
    static Character* getInstance(const std::string& name);


    int getHealth() const;
    void setHealth(int health);
    int getMaxHealth() const;
    int getAttack() const;
    void setAttack(int attack);
    std::string getName();

    int getGold();
    int getLevel();
    void getDamage(int damage);
    int gainGold(int gold);

    void displayStats() const;
    int gainExperience(int expGain);
    void levelUp(int levels);
    void useItem(Item* item);

    void gainItem(int value);
    void deleteItem(int value);
    std::vector<Item*> getInventory();
};