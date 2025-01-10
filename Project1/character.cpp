#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(const std::string& name, int level, int health, int attack, int experience)
	:name_(name), level_(level), health_(health), attack_(attack), experience_(experience_)
{}

void Character::displayStats() const
{
	cout << "ĳ����:" << name_ << endl;
	cout << "����:" << level_ << endl;
	cout << "ü��:" << health_ << endl;
	cout << "���ݷ�:" << attack_ << endl;
	cout << "����ġ:" << experience_ << endl;
}

int main() {
    string name;
    
	cout << "======================================================================================================================== " << endl;
	cout << "                                                 Level Up! Wawa!                                                     " << endl;
	cout << "======================================================================================================================== " << endl;

	cout << "ĳ���� �̸��� �Է��� �ּ���: ";
    getline(std::cin, name);

	Character myCharacter(name);
	myCharacter.displayStats();

    return 0;
}
