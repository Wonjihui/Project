#include "Item.h"


string HealthItem::getName() 
{
	return name = "°³ ²­";
}

void HealthItem::use(Character* character) 
{
	healthRestore = 50;
	cout << "°³ ²­À» ¸Ô¾ú½À´Ï´Ù! +HP : " << healthRestore << endl;
}

string AttackBoost::getName()
{
	return name = "»ç·á";
}

void AttackBoost::use(Character* character) 
{
	attackincrease = 10;
	cout << "»ç·á¸¦ ¸Ô¾ú½À´Ï´Ù! +ATTACK : " << attackincrease << endl;
}