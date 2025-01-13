#pragma once
#include <string>
class Character
{
private:
	static Character* instance;
	std::string name_;
	int level_;
	int health_;
	int maxHealth_;
	static const int maxLevel_ = 10; //최대 10레벨로 제한 
	int attack_;
	int experience_;

	Character(const std::string& name, int level = 1, int health = 200, int attack = 30, int experience = 0);

public:

	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

	static Character* getInstance(const std::string& name);

	void displayStats() const;
	void gainExperience(int expGain);
	void levelUp(int expGain);


};