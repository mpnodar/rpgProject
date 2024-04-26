#include <iostream>
#include "gameMenu.h"
#include "shop.h"
#include "battleSequence.h"


using namespace std;

void gameMenu::returnToGame() {
    cout << "Return to Game..." << endl;
}

void gameMenu::talkToSomeone() {
    cout << "Talk to someone..." << endl;
}

void gameMenu::quitGame() {
    cout << "Exiting game..." << endl;
    menuLoop = false;
}


void gameMenu::menu(player* you) {

    int input;
    shop s;
    battleSequence b;

    do {


        cout << "\n1. Return to Game\n2. Enter Battle\n3. Manage Inventory\n4. Enter Shop\n5. Talk to Someone\n6. Quit Game\n" << endl;
        cin >> input;

        switch (input) {

        case 1:
            returnToGame();
            break;

        case 2:
            b.randomBattle(you);
            break;

        case 3:
            you->manageInventory();
            break;

        case 4:
            s.displayGoods(you);
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
    } while (menuLoop);

}
