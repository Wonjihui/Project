#include "Monster.h"
#include <iostream>
#include <cstdlib>

int generateRandomValue(int min, int max) // 체력, 공격력 범위 지정을 위한 랜덤값 생성 함수
{
    return rand() % (max - min + 1) + min;
}

Maltese::Maltese(int level)
{
    name = "maltese";
    health = generateRandomValue(level * 20, level * 30);
    attack = generateRandomValue(level * 5, level * 10);
}

std::string Maltese::getName() const
{
    return name;
}

int Maltese::getHealth()
{
    if (health < 0)
    {
        health = 0;
    }
    return health;
}

int Maltese::getAttack() const
{
    return attack;
}

void Maltese::takeDamage(int damage)
{
    health -= damage;
}

//////////////////////
Pomeranian::Pomeranian(int level)
{
    name = "Pomeranian";
    health = generateRandomValue(level * 20, level * 30);
    attack = generateRandomValue(level * 5, level * 10);
}

std::string Pomeranian::getName() const
{
    return name;
}

int Pomeranian::getHealth()
{
    if (health < 0)
    {
        health = 0;
    }
    return health;
}

int Pomeranian::getAttack() const
{
    return attack;
}

void Pomeranian::takeDamage(int damage)
{
    health -= damage;
}

//////////////////////
Malamute::Malamute(int level)
{
    name = "Malamute";
    health = generateRandomValue(level * 20, level * 30);
    attack = generateRandomValue(level * 5, level * 10);
}

std::string Malamute::getName() const
{
    return name;
}

int Malamute::getHealth()
{
    if (health < 0)
    {
        health = 0;
    }
    return health;
}

int Malamute::getAttack() const
{
    return attack;
}

void Malamute::takeDamage(int damage)
{
    health -= damage;
}

Samoyed::Samoyed(int level)
{
    name = "Samoyed";
    health = generateRandomValue(level * 20, level * 30);
    attack = generateRandomValue(level * 5, level * 10);
}

std::string Samoyed::getName() const
{
    return name;
}

int Samoyed::getHealth()
{
    if (health < 0)
    {
        health = 0;
    }
    return health;
}

int Samoyed::getAttack() const
{
    return attack;
}

void Samoyed::takeDamage(int damage)
{
    health -= damage;
}