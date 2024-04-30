#include "characters.h"
#include "battleSequence.h"
#include <iostream>
#include <random>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;



// Random Functions

int battleSequence::randint(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}
int battleSequence::randintLow(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Triangular distribution
    std::uniform_int_distribution<> distrib(min, max);
    int lower = distrib(gen);
    int upper = distrib(gen);
    return lower < upper ? lower : upper;
}
int battleSequence::randintHigh(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Triangular distribution biased towards higher values
    std::uniform_int_distribution<> distrib(min, max);
    int lower = distrib(gen);
    int upper = distrib(gen);
    return lower > upper ? lower : upper;
}
int battleSequence::randintNear(int target, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    int mean = target;
    int stddev = (max - min) / 3;
    stddev = stddev < 1 ? 1 : stddev;
    std::normal_distribution<> distrib(mean, stddev);
    int result;
    do {
        result = distrib(gen);
    } while (result < min || result > max);
    return result;
}

int battleSequence::randintEnemyAttack() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 100);

    int randomNumber = distrib(gen);

    if (randomNumber <= 99) { 
        return randomNumber % 4 + 1;
    }
    else { 
        return 5; 
    }
}






// Display Battle Options

int battleSequence::displayBattleOptions() {

    int choice;

    cout << "\n\n1. Attack" << endl;
    cout << "2. Defend" << endl;
    cout << "3. Open Inventory" << endl;
    cout << "4. Run Away\n\n" << endl;
    cout << "----------------------\n" << endl;

    cin >> choice;
    return choice;

}

int battleSequence::displayAttacks() {

    int choice;

    cout << "\n----------------------" << endl;
    cout << "1. Standard Attack" << endl;
    cout << "2. Magic Attack" << endl;
    cout << "----------------------\n" << endl;

    cin >> choice;
    return choice;

}




// General Battle Structure

void battleSequence::battle(player* _player, enemy* _enemy) {

    // Set Fighting Status to True

    _player->setFightingStatus(true);
    _enemy->setFightingStatus(true);

    _player->setStamina(_player->getMaxStamina());
    _player->setMagicka(_player->getMaxMagicka());


    // Battle Loop



    while (_player->getHealth() > 0 && _enemy->getHealth() > 0 && _player->getFightingStatus() && _enemy->getFightingStatus()) {

        std::system("cls");

        // Initial Display Data



            _enemy->displayData();
            _player->displayData();


        int enemyChoice = randintEnemyAttack();

        if (enemyChoice == 2) {
            _enemy->setDefend(true);
        }
        else {
            _enemy->setDefend(false);
        }


        // Player Select Action




        switch (displayBattleOptions()) {
        case 1:
            switch (displayAttacks()) {
            case 1:
                _player->attack(*_enemy);
                break;
            case 2:
                _player->magicAttack(*_enemy);
                break;
            }
            break;
        case 2:
            _player->defend();
            break;
        case 3:
            _player->manageInventory();
            break;
        case 4:
            _player->run();
            break;
        }


        // Enemy Select Action

        if (_enemy->getHealth() > 0 && _player->getFightingStatus()) {
            switch (enemyChoice) {
            case 1:
                _enemy->attack(*_player);
                break;
            case 2:
                _enemy->defend();
                break;
            case 3:
                _enemy->restoreHealth(5);
                break;
            case 4:
                _enemy->magicAttack(*_player);
                break;
            case 5:
                _enemy->run();
                break;
            }
        }      

        this_thread::sleep_for(chrono::seconds(2));


        if (_player->getPoisoned() == true) {
            _player->setHealth(_player->getHealth() - 8);
        }


        // Set Floor Limits on Attribute Values

        if (_player->getHealth() <= 0) {

            _player->setHealth(0);
        }
        if (_enemy->getHealth() <= 0) {
            _enemy->setHealth(0);
        }

        if (_player->getStamina() <= 0) {
            _player->setStamina(0);
        }
        if (_enemy->getStamina() <= 0) {
            _enemy->setStamina(0);
        }

        if (_player->getMagicka() <= 0) {
            _player->setMagicka(0);
        }
        if (_enemy->getMagicka() <= 0) {
            _enemy->setMagicka(0);
        }

        

      
    }




    // Post-battle Display Data

    if (_enemy->getFightingStatus() && _player->getFightingStatus()) {
        _enemy->displayData();
        _player->displayData();
    }
    std::system("cls");




    // Check Who Has Died

    if (_player->getHealth() == 0) {
        cout << "\nYou have died." << endl;
    }

    else if (_enemy->getHealth() == 0) {

        vector<string>lootItems;
        lootItems.push_back("Health Potions");
        lootItems.push_back("Gold");
        lootItems.push_back("Stamina Potions");
        lootItems.push_back("Magicka Potions");

        cout << "You have defeated the " << _enemy->getName() << "!" << endl;


        _player->setCurrentXP(_player->getCurrentXP() + (20 * _enemy->getLevel()));
        cout << "XP Earned: " << (20 * _enemy->getLevel()) << endl;

        while (_player->getCurrentXP() >= _player->getRequiredXP()) {
            _player->checkLevel();
        }

        int lootDrop = randint(1, 4);
        int potionAmount = randintLow(1, 5);
        int goldAmount = randintNear(_enemy->getLevel(), 10, 100);

        switch (lootDrop) {
        case 1:
            _player->getInventory().getItemByName(lootItems[0])->quantity += potionAmount;
            cout << "Acquired " << potionAmount << " Health Potions!" << endl;
            break;
        case 2:
            _player->getInventory().getItemByName(lootItems[1])->quantity += goldAmount;
            cout << "Acquired " << goldAmount << " gold!" << endl;
            break;
        case 3:
            _player->getInventory().getItemByName(lootItems[2])->quantity += potionAmount;
            cout << "Acquired " << potionAmount << " Stamina Potions!" << endl;
            break;
        case 4:
            _player->getInventory().getItemByName(lootItems[3])->quantity += potionAmount;
            cout << "Acquired " << potionAmount << " Magicka Potions!" << endl;
            break;
        }

        _player->displayFullData();


    }

    this_thread::sleep_for(chrono::seconds(7));
    std::system("cls");
    _player->setPoisoned(false);

}







// Full Battle with Enemy Randomization

void battleSequence::randomBattle(player* _player) {

    int randLevel = randintNear(_player->getLevel(), 1, (_player->getLevel() + 20));

    goblin nilbog(randLevel);
    orc bum(randLevel);
    wraith dumbass(randLevel);

    int randEnemy = randint(1, 100);

    if (randEnemy <= 50) {
        battle(_player, &nilbog);
    }

    else if (randEnemy > 50 && randEnemy <= 90) {
        battle(_player, &bum);
    }

    else if (randEnemy > 90) {
        battle(_player, &dumbass);
    }



}
