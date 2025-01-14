#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
public:
	Character(const std::string& name, int level = 1, int health = 200, int attack = 30, int experience = 0); 

	void displayStats() const;
	void gainExperience(int exp);
	void levelUp();
	int getLevel() const;
	int getHealth() const;
	int getAttack() const;
	void takeDamage(int damage);

private:
	std::string name_;
	int level_;
	int health_;
	int maxHealth_;
	int attack_;
	int experience_;
};

#endif
