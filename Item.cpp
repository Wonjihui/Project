#include "Item.h"


string HealthItem::getName() 
{
	return name = "�� ��";
}

void HealthItem::use(Character* character) 
{
	healthRestore = 50;
	cout << "�� ���� �Ծ����ϴ�! +HP : " << healthRestore << endl;
}

string AttackBoost::getName()
{
	return name = "���";
}

void AttackBoost::use(Character* character) 
{
	attackincrease = 10;
	cout << "��Ḧ �Ծ����ϴ�! +ATTACK : " << attackincrease << endl;
}