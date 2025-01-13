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

//ĳ���� �޼���
void Character::displayStats() const
{
	cout << "ĳ����:" << name_ << endl;
	cout << "����:" << level_ << endl;
	cout << "ü��:" << health_ << endl;
	cout << "���ݷ�:" << attack_ << endl;
	cout << "����ġ:" << experience_ << " / 100" << endl;
}
//����ġ �޼���
void Character::gainExperience(int expGain)
{
	experience_ += expGain;
	cout << name_ << " ��(��) ����ġ" << expGain << "�� �����!" << endl;

	if (experience_ >= 100)
	{
		levelUp(experience_ / 100);
		experience_ %= 100;
	}
}
//������ �޼���
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
	cout << name_ << " ���� ��! Lv." << level_ << "!" << endl;
}

int main() {
	string name;

	cout << "======================================================================================================================== " << endl;
	cout << "                                                 Level Up! Wawa!                                                     " << endl;
	cout << "======================================================================================================================== " << endl;

	while (true)
	{
		cout << "ĳ���� �̸��� �Է��� �ּ���: ";
		getline(std::cin, name);

		if (name.empty())
		{
			cout << "�̸��� �Է� ���� �ʾҽ��ϴ�...! �ٽ� �Է��� �ּ���...!" << endl;
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