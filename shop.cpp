#include <iostream>
#include "characters.h"

using namespace std;

bool val = true, val2 = true, val3 = true;

int gold = 200;

void weapons() {

    int select;

    cout << "\nWhat kind of weapon would you like? You have " << gold << " gold.\n\n";

    while (val == true) {

        val3 = true;

        cout << "1. Longsword - 30 Gold\n2. Single-Handed War-Axe - 25 Gold\n3. Longbow - 35 Gold\n4. Back to Menu";
        cout << " \n\n";

        while (val3 == true) {

            cin >> select;

            switch (select) {
            case 1:
                if (gold >= 30) {
                    gold = gold - 30;
                    cout << "\n\nThank you for purchasing the longsword! You now have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n\nYou do not have enough gold, dimwit! You only have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }

            case 2:
                if (gold >= 25) {
                    gold = gold - 25;
                    cout << "\n\nThank you for purchasing the single-handed war-axe! You now have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n\nYou do not have enough gold, dimwit! You only have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }

            case 3:
                if (gold >= 35) {
                    gold = gold - 35;
                    cout << "\n\nThank you for purchasing the longbow! You now have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n\nYou do not have enough gold, dimwit! You only have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }

            case 4:
                val = false;
                val3 = false;
                break;

            default:
                cout << "\n\nInvalid input! Please try again: \n";

            }

        }

    }

}

void armor() {


    int select;

    cout << "\nWhat kind of armor would you like? You have " << gold << " gold.\n\n";

    while (val == true) {

        val3 = true;

        cout << "1. Steel Breastplate - 60 Gold\n2. Iron Greeves - 40 Gold\n3. Dragonbone Helmet - 125 Gold\n4. Back to Menu";
        cout << " \n\n";

        while (val3 == true) {

            cin >> select;

            switch (select) {
            case 1:
                if (gold >= 60) {
                    gold = gold - 60;
                    cout << "\n\nThank you for purchasing the steel breastplate! You now have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n\nYou do not have enough gold, dimwit! You only have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }

            case 2:
                if (gold >= 40) {
                    gold = gold - 40;
                    cout << "\n\nThank you for purchasing the iron greeves! You now have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n\nYou do not have enough gold, dimwit! You only have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }

            case 3:
                if (gold >= 125) {
                    gold = gold - 125;
                    cout << "\n\nThank you for purchasing the dragonbone helmet! You now have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n\nYou do not have enough gold, dimwit! You only have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }

            case 4:
                val = false;
                val3 = false;
                break;

            default:
                cout << "\n\nInvalid input! Please try again: \n";

            }

        }

    }


}

void potions() {

    int select;

    cout << "\nWhat type of potion would you like? You have " << gold << " gold.\n\n";

    while (val == true) {

        val3 = true;

        cout << "1. Health Potion - 25 Gold\n2. Magika Potion - 35 Gold\n3. Stamina Potion - 20 Gold\n4. Back to Menu";
        cout << " \n\n";

        while (val3 == true) {

            cin >> select;

            switch (select) {
            case 1:
                if (gold >= 25) {
                    gold = gold - 25;
                    cout << "\n\nThank you for purchasing the health potion! You now have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n\nYou do not have enough gold, dimwit! You only have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }

            case 2:
                if (gold >= 35) {
                    gold = gold - 35;
                    cout << "\n\nThank you for purchasing the magika potion! You now have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n\nYou do not have enough gold, dimwit! You only have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }

            case 3:
                if (gold >= 20) {
                    gold = gold - 20;
                    cout << "\n\nThank you for purchasing the stamina potion! You now have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n\nYou do not have enough gold, dimwit! You only have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }

            case 4:
                val = false;
                val3 = false;
                break;

            default:
                cout << "\n\nInvalid input! Please try again: \n";

            }

        }

    }

}

void misc() {

    int select;

    cout << "\nWhat kind of armor would you like? You have " << gold << " gold.\n\n";

    while (val == true) {

        val3 = true;

        cout << "1. Wolf Hide - 35 Gold\n2. Iron Ingot - 15 Gold\n3. Leather Straps - 10 Gold\n4. Back to Menu";
        cout << " \n\n";

        while (val3 == true) {

            cin >> select;

            switch (select) {
            case 1:
                if (gold >= 35) {
                    gold = gold - 35;
                    cout << "\n\nThank you for purchasing a wolf hide! You now have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n\nYou do not have enough gold, dimwit! You only have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }

            case 2:
                if (gold >= 20) {
                    gold = gold - 20;
                    cout << "\n\nThank you for purchasing the iron ingot! You now have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n\nYou do not have enough gold, dimwit! You only have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }

            case 3:
                if (gold >= 10) {
                    gold = gold - 10;
                    cout << "\n\nThank you for purchasing the leather straps! You now have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n\nYou do not have enough gold, dimwit! You only have " << gold << " gold. Would you like to buy anything else?\n";
                    val3 = false;
                    cout << "\n";
                    break;
                }

            case 4:
                val = false;
                val3 = false;
                break;

            default:
                cout << "\n\nInvalid input! Please try again: \n";

            }

        }

    }


}


void shop(player _player) {

    while (val2 == true) {

        int select;

        cout << "What are you buying?\n\n1. Weapons\n2. Armor\n3. Potions\n4. Miscellaneous\n5. Exit the Shop\n\n(Please enter the corresponding number)\n";
        cout << " \n";

        cin >> select;

        cout << " \n";
        val = true;


        while (val == true) {

            switch (select) {
            case 1:
                weapons();
                break;

            case 2:
                armor();
                break;

            case 3:
                potions();
                break;

            case 4:
                misc();
                break;

            case 5:
                cout << "Good doing business with you. Please come again!";
                cout << " \n\n";
                val = false;
                val2 = false;
                val3 = false;
                break;

            default:
                cout << "Not a valid option. Please try again: ";
                val = false;
                val2 = true;
                break;
            }

        }

    }

}