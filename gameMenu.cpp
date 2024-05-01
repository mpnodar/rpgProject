#include <iostream>
#include "gameMenu.h"
#include "shop.h"
#include "battleSequence.h"
#include <cstdlib>


using namespace std;


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
        cout << "\n1. Return to Game\n2. Manage Inventory\n3. Save Game\n4. Quit Game\n" << endl;
        cin >> input;

        switch (input) {

        case 1:
            //returnToGame();
            AR = ReturnToGame;
            break;

        case 2:
            you->manageInventory();
            AR = ManageInventory;
            break;

        case 3:
            //saveGamePointer(you);
            break;

        case 5:
            b.randomBattle(you);
            AR = RandomBattle;
            break;

        case 4:
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
