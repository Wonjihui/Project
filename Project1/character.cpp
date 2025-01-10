#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(const std::string& name, int level, int health, int attack, int experience)
	:name_(name), level_(level), health_(health), attack_(attack), experience_(experience_)
{}

void Character::displayStats() const
{
	cout << "캐릭터:" << name_ << endl;
	cout << "레벨:" << level_ << endl;
	cout << "체력:" << health_ << endl;
	cout << "공격력:" << attack_ << endl;
	cout << "경험치:" << experience_ << endl;
}

int main() {
    string name;
    
	cout << "======================================================================================================================== " << endl;
	cout << "                                                 Level Up! Wawa!                                                     " << endl;
	cout << "======================================================================================================================== " << endl;

	cout << "캐릭터 이름을 입력해 주세요: ";
    getline(std::cin, name);

	Character myCharacter(name);
	myCharacter.displayStats();

    return 0;
}
