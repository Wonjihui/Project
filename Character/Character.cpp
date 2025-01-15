#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(const std::string& name, int level, int health, int attack, int experience, int gold)
	:name_(name), level_(level), health_(health), maxHealth_(health), attack_(attack), experience_(experience), gold_(gold)
{
}

void Character::displayStats() const
{
	cout << "캐릭터:" << name_ << endl;
	cout << "레벨:" << level_ << endl;
	cout << "체력:" << health_ << endl;
	cout << "공격력:" << attack_ << endl;
	cout << "경험치:" << experience_ << endl;
}

void Character::gainExperience(int exp)
{
	experience_ += exp;
}

void Character::levelUp()
{
	if (experience_ >= level_ * 100)
	{
		experience_ = 0;
		++level_;
		health_ = maxHealth_ + 50 * level_;
		maxHealth_ = health_;
		attack_ = attack_ + 5 * level_;
		cout << "레벨업!" << endl;
	}
}

int Character::getLevel() const
{
	return level_;
}

int Character::getHealth() const
{
	return health_;
}

int Character::getAttack() const
{
	return attack_;
}

void Character::takeDamage(int damage)
{
	health_ -= damage;
	if (health_ <= 0)
	{
		cout << "패배했습니다!" << endl;
	}
}

