#include <iostream>
#include "gameMenu.h"
#include "shop.h"
#include "battleSequence.h"
#include <cstdlib>
#include <fstream>


using namespace std;

static void saveGamePointerMenu(player* p) {
    ofstream saveFile("gameData.txt");
    saveFile << p->getName() << "\n" << p->getLevel() << "\n" << p->getClass() << "\n" << p->getGold() << "\n" << p->getHealthPotions() << "\n" << p->getHealth() << "\n" << p->getStamina() << "\n" << p->getMagicka() << "\n" << p->getAttack() << "\n" << p->getCurrentXP() << "\n" << p->getCurrentWeight() << "\n" << p->getMagickaPotions() << "\n" << p->getStaminaPotions() << "\n" << p->getMaxWeight() << endl;
    saveFile.close();
}


void gameMenu::quitGame() {
    cout << "Exiting game..." << endl;
}


ActionResponse gameMenu::menu(player* you) {

    ActionResponse AR = NotSet;
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
            saveGamePointerMenu(you);
            break;

        /*case 5:
            b.randomBattle(you);
            AR = RandomBattle;
            break;*/

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
