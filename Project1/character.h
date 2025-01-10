#pragma once
#include <string>

class Character
{
public:
	Character(const std::string& name, int level = 1, int health = 200,int attack = 30 ,int experience = 0 ); //기본값 설정

	void displayStats() const;
	void gainExperience(int exp);
	void levelUp();

private:
	std::string name_;
	int level_;
	int health_;
	int maxHealth_;
	int attack_;
	int experience_;
};