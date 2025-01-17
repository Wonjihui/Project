﻿#include "Character.h"
#include <iostream>

using namespace std;


Character* Character::instance = nullptr;

Character::Character(const std::string& name, int level, int health, int attack, int experience, int gold, int totalKillMonster)
	: name_(name), level_(level), health_(health), maxHealth_(health), attack_(attack), experience_(experience), gold_(gold), totalKillMonster_(totalKillMonster) {
}


Character* Character::getInstance(const std::string& name) 
{
	if (instance == nullptr) 
	{
		instance = new Character(name);
	}
	return instance;
}

void Character::displayStats() const 
{
	std::cout << "캐릭터: " << name_ << std::endl;
	std::cout << "레벨: " << level_ << std::endl;
	std::cout << "체력: " << health_ << " / " << maxHealth_ << std::endl;
	std::cout << "공격력: " << attack_ << std::endl;
	std::cout << "경험치: " << experience_ << " / 100" << std::endl;
	std::cout << "처치한 몬스터 수: " << totalKillMonster_ << std::endl;
}

void Character::gainExperience() 
{
	experience_ += 50;
	if (experience_ >= 100) 
	{
		levelUp(experience_ / 100);
		experience_ %= 100;
	}
}

void Character::levelUp(int levels) 
{
	if (level_ >= maxLevel_) 
	{
		return;
	}

	level_ += levels;
	if (level_ > maxLevel_)
	{
		level_ = maxLevel_;
	}

	maxHealth_ += levels * 20;
	attack_ += levels * 5;
	health_ = maxHealth_;
	std::cout << name_ << " 레벨 업! Lv." << level_ << "!" << std::endl;
}

int Character::getHealth() const 
{
	return health_;
}

void Character::setHealth(int health) 
{
	health_ = health;
}

int Character::getMaxHealth() const
{
	return maxHealth_;
}

int Character::getAttack() const 
{
	return attack_;
}

int Character::getLevel() const
{
	return level_;
}

int Character::getGold() const 
{
	return gold_;
}

void Character::gainGold(int amount)
{
	gold_ += amount;
}

std::string Character::getName() const
{
	return name_;
}

int Character::getExp() const
{
	return experience_;
}

void Character::setAttack(int attack) 
{
	attack_ = attack;
}

void Character::takeDamage(int damage)
{
	health_ -= damage;
	if (health_ <= 0)
	{

		cout << "캐릭터가 사망했습니다!" << endl;

		auto it = find_if(inventory_.begin(), inventory_.end(), [](Item* i) { return dynamic_cast<ReviveStone*>(i) != nullptr; });

		if (it != inventory_.end())
		{
			Item* reviveStone = *it;
			reviveStone->use(this);  //사용
			inventory_.erase(it);    //인벤에서 삭제
			delete reviveStone;

			cout << "인벤토리에 부활석을 사용하였습니다" << endl;
			if (health_ <= 0)
			{
				health_ = 200;
			}
			cout << "체력: " << health_ << "로 부활하였습니다." << endl;
		}
		else {
			health_ = 0;
			cout << "부활석이 없어 게임 오버입니다." << endl;
			exit(0);
		}

	}
}

void Character::setTotalKillMonster()
{
	++totalKillMonster_;
}

void Character::useItem(Item* item)
{
	item->use(this);
}

std::vector<Item*>& Character::getInventory()
{
    return inventory_;
}

void Character::gainItem(int value) {
	{
		if (value <= 50) {
			inventory_.emplace_back(new HealthItem("개 껌", 50));
			cout << "개 껌 획득" << endl;
		}
		else if (value > 50 && value <= 100)
		{
			inventory_.emplace_back(new AttackBoost("사료", 10));
			cout << "사료 획득" << endl;
		}
		else
		{
			inventory_.emplace_back(new ReviveStone("부활석", 100));
			cout << "부활석 획득" << endl;
		}
	}
}
void Character::deleteItem(int value)
{
	if (value <= 50) {
		auto it = find_if(inventory_.begin(), inventory_.end(), [](Item* i) { return dynamic_cast<HealthItem*>(i) != nullptr; });
		if (it != inventory_.end()) {
			inventory_.erase(it);
		}
	}
	else if (value > 50 && value <= 100)
	{
		auto it = find_if(inventory_.begin(), inventory_.end(), [](Item* i) { return dynamic_cast<AttackBoost*>(i) != nullptr; });
		if (it != inventory_.end()) {
			inventory_.erase(it);
		}
	}
	else
	{
		auto it = find_if(inventory_.begin(), inventory_.end(), [](Item* i) { return dynamic_cast<ReviveStone*>(i) != nullptr; });
		if (it != inventory_.end()) {
			inventory_.erase(it);
		}
	}
}