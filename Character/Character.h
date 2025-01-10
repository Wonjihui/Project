#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
public:
    static Character* instance;
    Character(const std::string& name);
    static Character* getInstance(const std::string& name = "");

    void displayStatus() const;
    void levelUp();
    void useItem(int index);

private:
    std::string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int experience;
    int gold;
    //std::vector<Item*> inventory;아직구현x

};

#endif