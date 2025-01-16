#include "Character.h"
#include "../Item/Item.h"
#include "../Monster/Monster.h"
#include "../GameManager/GameManager.h"
#include <iostream>

using namespace std;

int main() {
    int choice;
    bool isRunning = true;


    cout << "=========================================================================================================================================\n" << endl;
    cout << "         ___      _______  __   __  _______  ___        __   __  _______  __     _     _  _______  _     _  _______  __" << endl;
    cout << "        |   |    |       ||  | |  ||       ||   |      |  | |  ||       ||  |   | | _ | ||   _   || | _ | ||   _   ||  |" << endl;
    cout << "        |   |    |    ___||  |_|  ||    ___||   |      |  | |  ||    _  ||  |   | || || ||  |_|  || || || ||  |_|  ||  |" << endl;
    cout << "        |   |    |   |___ |       ||   |___ |   |      |  |_|  ||   |_| ||  |   |       ||       ||       ||       ||  |" << endl;
    cout << "        |   |___ |    ___||       ||    ___||   |___   |       ||    ___||__|   |       ||       ||       ||       ||__|" << endl;
    cout << "        |       ||   |___  |     | |   |___ |       |  |       ||   |     __    |   _   ||   _   ||   _   ||   _   | __" << endl;
    cout << "        |_______||_______|  |___|  |_______||_______|  |_______||___|    |__|   |__| |__||__| |__||__| |__||__| |__||__|" << endl;
    cout << "==========================================================================================================================================\n" << endl;

    while (isRunning) {

        cout << "\n";
        cout << "     1. 세계 정복하러 가기!\n";
        cout << "     2. 쉬기....\n";
        cout << "\n";
        cout << "     오늘은 뭘 할까?!: ";


        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            cout << "\n세계 최강 강아지가 될거야!\n";


            string name;
            while (true) {
                cout << "\n캐릭터 이름을 입력해 주세요:\ ";
                getline(cin, name);

                if (name.empty()) {
                    cout << "이름이 입력되지 않았습니다...! 다시 입력해 주세요...!" << endl;
                }
                else {
                    break;
                }
            }

            Character* myCharacter = Character::getInstance(name);
            GameManager gameManager;


gameManager.battle(myCharacter);
            break;
        }

        case 2:
            cout << "\n세계 정복은 내일...\n";
            isRunning = false;
            break;

        default:
            cout << "\n잘못된 선택입니다. 1 또는 2를 선택해주세요.\n";
            break;
        }
        cout << "\n";
    }

    return 0;
}