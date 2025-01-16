#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <iostream>
#include "../Item/Item.h"

class Item;

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
	int totalKillMonster_;
    std::vector<Item*> inventory_;

    Character(const std::string& name, int level = 1, int health = 200, int attack = 30, int experience = 0, int gold = 0, int totalKillMonster=0);



public:

    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;

    static Character* getInstance(const std::string& name);

    void displayStats() const;
    void gainExperience();
    void levelUp(int levels);

    int getHealth() const;
    int getAttack() const;
    int getLevel() const;
    int getGold() const;
	int getExp() const;

    void addItem(Item* item) { inventory_.push_back(item); }//test
    void gainGold(int amount);
    std::string getName() const;
    void takeDamage(int damage);
    void setTotalKillMonster();
    void useItem(Item* item);

    void setHealth(int health);
    int getMaxHealth() const;
    void setAttack(int attack);

    void gainItem(int value);
    void deleteItem(int value);
    std::vector<Item*>& getInventory();
};
#endif