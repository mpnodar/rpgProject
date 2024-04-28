#include <iostream>
#include "gameMenu.h"
#include "shop.h"
#include "battleSequence.h"
#include <cstdlib>


using namespace std;

void gameMenu::returnToGame() {
    cout << "Return to Game..." << endl;
}

void gameMenu::talkToSomeone() {
    cout << "Talk to someone..." << endl;
}

void gameMenu::quitGame() {
    cout << "Exiting game..." << endl;
}


ActionResponse gameMenu::menu(player* you) {

    ActionResponse AR;
    int input;
    shop s;
    battleSequence b;

    do {
        std::system("cls");
        cout << "\n1. Return to Game\n2. Enter Battle\n3. Manage Inventory\n4. Enter Shop\n5. Talk to Someone\n6. Quit Game\n" << endl;
        cin >> input;

        switch (input) {

        case 1:
            returnToGame();
            AR = ReturnToGame;
            break;

        case 2:
            b.randomBattle(you);
            AR = RandomBattle;
            break;

        case 3:
            you->manageInventory();
            AR = ManageInventory;
            break;

        case 4:
            s.displayGoods(you);
            AR = DisplayGoods;
            break;

        case 5:
            talkToSomeone();
            AR = TalkToSomeone;
            break; 

        case 6:
            quitGame();
            AR = QuitGame;
            break;

        default:
            cout << "\nInvalid input!\n" << endl;
            AR = NotSet;
        }
    } while (AR != QuitGame and AR != ReturnToGame);

    return AR;
}
