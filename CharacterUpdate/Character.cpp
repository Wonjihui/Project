#include "Character.h"
#include <iostream>

using namespace std;

Character* Character::instance = nullptr;

Character::Character(const std::string& name, int level, int health, int attack, int experience)
	:name_(name), level_(level), maxHealth_(health), health_(health), attack_(attack), experience_(experience)
{
}

Character* Character::getInstance(const std::string& name)
{
	if (instance == nullptr)
	{
		instance = new Character(name);
	}
	return instance;
}

//캐릭터 메서드
void Character::displayStats() const
{
	cout << "캐릭터:" << name_ << endl;
	cout << "레벨:" << level_ << endl;
	cout << "체력:" << health_ << endl;
	cout << "공격력:" << attack_ << endl;
	cout << "경험치:" << experience_ << " / 100" << endl;
}
//경험치 메서드
void Character::gainExperience(int expGain)
{
	experience_ += expGain;
	cout << name_ << " 은(는) 경험치" << expGain << "을 얻었다!" << endl;

	if (experience_ >= 100)
	{
		levelUp(experience_ / 100);
		experience_ %= 100;
	}
}
//레벨업 메서드
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
	cout << name_ << " 레벨 업! Lv." << level_ << "!" << endl;
}

int main() {
	string name;

	cout << "======================================================================================================================== " << endl;
	cout << "                                                 Level Up! Wawa!                                                     " << endl;
	cout << "======================================================================================================================== " << endl;

	while (true)
	{
		cout << "캐릭터 이름을 입력해 주세요: ";
		getline(std::cin, name);

		if (name.empty())
		{
			cout << "이름이 입력 되지 않았습니다...! 다시 입력해 주세요...!" << endl;
		}
		else
		{
			break;
		}
	}


	Character* myCharacter = Character::getInstance(name);
	myCharacter->displayStats();

	myCharacter->gainExperience(50);
	myCharacter->displayStats();

	myCharacter->gainExperience(60);
	myCharacter->displayStats();

	return 0;
}