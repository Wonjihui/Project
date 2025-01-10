// Copyright Epic Games, Inc. All Rights Reserved.

#include <iostream>
#include <string>
using namespace std;

class character {
private:
    static character* instance;
    string name;
    int level = 1;
    int health = 0;
    int maxhealth = 200;
    int attak = 30;
    int gold = 0;
    int experience = 0;

public:
    character(string name)
    {
        this->name = name;
        cout << "캐릭터의 닉네임은 " << name << "입니다." << endl;
    }

    // 정적 메서드: 유일한 캐릭터 인스턴스를 반환
    static character* getInstance() {

    }

    void displayStatus()
    {
        cout << "<status>" << endl;
        cout << "name : " << name << endl;
        cout << "level : " << level << endl;
        cout << "health : " << health << endl;
        cout << "attak : " << attak << endl;
        cout << "gold : " << gold << endl;
        cout << "experience : " << experience << endl;
    }
    void levelup()
    {
        level++;
    }
    void useitem(int index)
    {

    }
};


int main()
{

    string name;
    cout << "캐릭터의 닉네임을 입력해주세요 : ";
    cin >> name;
    cout << "캐릭터의 이름은 :" << name << "입니다." << endl;

    return 0;

}
