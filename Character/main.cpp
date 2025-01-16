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
        cout << "     1. ���� �����Ϸ� ����!\n";
        cout << "     2. ����....\n";
        cout << "\n";
        cout << "     ������ �� �ұ�?!: ";


        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            cout << "\n���� �ְ� �������� �ɰž�!\n";


            string name;
            while (true) {
                cout << "\nĳ���� �̸��� �Է��� �ּ���:\ ";
                getline(cin, name);

                if (name.empty()) {
                    cout << "�̸��� �Էµ��� �ʾҽ��ϴ�...! �ٽ� �Է��� �ּ���...!" << endl;
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
            cout << "\n���� ������ ����...\n";
            isRunning = false;
            break;

        default:
            cout << "\n�߸��� �����Դϴ�. 1 �Ǵ� 2�� �������ּ���.\n";
            break;
        }
        cout << "\n";
    }

    return 0;
}