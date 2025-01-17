#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster
{
public:
    virtual std::string getName() const = 0;
    virtual int getHealth() const = 0;
    virtual int getAttack() const = 0;
    virtual void takeDamage(int damage) = 0;
    virtual ~Monster() {}
};

//maltese, Pomeranian, Malamute, Samoyed class
class Maltese : public Monster
{
private:
    std::string name;
    int health;
    int attack;

public:
    Maltese(int level);
    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
};

class Pomeranian : public Monster
{
private:
    std::string name;
    int health;
    int attack;

public:
    Pomeranian(int level);
    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
};

class Malamute : public Monster
{
private:
    std::string name;
    int health;
    int attack;

public:
    Malamute(int level);
    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
};

class Samoyed : public Monster
{
private:
    std::string name;
    int health;
    int attack;

public:
    Samoyed(int level);
    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
};

class Human : public Monster
{
private:
    std::string name;
    int health;
    int attack;

public:
    Human(int level);
    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
};


#endif 

