#include <iostream>
#include "C:\Users\mpnod\C++ Files\.vscode\RPG-Project\battleSequence.cpp"
#include "C:\Users\mpnod\C++ Files\.vscode\RPG-Project\inventory.cpp"
#include "C:\Users\mpnod\C++ Files\.vscode\RPG-Project\shop.cpp"

using namespace std;

bool menuLoop = true;

void returnToGame () {
    cout << "Return to Game...";
}

void enterShop () {
    shop();
}

void talkToSomeone () {
    cout << "Talk to someone...";
}

void quitGame () {
    cout << "Exiting game..." << endl;
    menuLoop = false;
}


int menu (player &you) {

    Stack newInventory;
    createInventory(newInventory);
    int input;

    do {  

        if (you.getAction() == "dead") {
            return 0;
        }
    
    cout << "1. Return to Game\n2. Enter Battle\n3. Manage Inventory\n4. Enter Shop\n5. Talk to Someone\n6. Quit Game" << endl;
    cin >> input;

    switch (input) {

        case 1: 
            returnToGame();
            break;
        
        case 2: 
            battle(you);
            you.setStamina(80);
            break;

        case 3: 
            inventory(newInventory);
            break;

        case 4: 
            enterShop();
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
    }
    while (menuLoop == true);

    return 0;
}