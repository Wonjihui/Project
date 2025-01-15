#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Character.h"
using namespace std;

class Character;

class Item {
public:
	virtual string getName() = 0;
	virtual void use(Character* character) = 0;
};

class HealthItem : public Item {
private:
	string name;
	int healthRestore;
public:

	HealthItem(string ItemName, int RestoreValue) :name(ItemName), healthRestore(RestoreValue) {}

	string getName();

	void use(Character* character);
};


class AttackBoost : public Item {
private:
	string name;
	int attackincrease;
public:

	AttackBoost(string ItemName, int BoostValue) :name(ItemName), attackincrease(BoostValue) {}

	string getName();

	void use(Character* character);
};