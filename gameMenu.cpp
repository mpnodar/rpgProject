#include <iostream>
#include "battleSequence.cpp"


using namespace std;

bool menuLoop = true;

void returnToGame() {
    cout << "Return to Game..." << endl;
}

void enterShop(player you) {
    shop(you);
}

void talkToSomeone() {
    cout << "Talk to someone..." << endl;
}

void quitGame() {
    cout << "Exiting game..." << endl;
    menuLoop = false;
}


void menu(player& you) {

    int input;

    do {


        cout << "\n1. Return to Game\n2. Enter Battle\n3. Manage Inventory\n4. Enter Shop\n5. Talk to Someone\n6. Quit Game\n" << endl;
        cin >> input;

        switch (input) {

        case 1:
            returnToGame();
            break;

        case 2:
            randomBattle(you);
            break;

        case 3:
            you.manageInventory();
            break;

        case 4:
            enterShop(you);
            break;

        case 5:
            talkToSomeone();
            break; 

        case 6:
            quitGame();
            break;

        default:
            cout << "\nInvalid input!\n" << endl;
        }
    } while (menuLoop == true);

}