#include "characters.h"
#include "battleSequence.h"
#include <iostream>
#include <random>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>


using namespace std;

#pragma comment (lib, "winmm.lib")


// Death Sound

void playDeathSound() {
    PlaySound(TEXT("C:/Users/mpnod/OneDrive/Documents/Classes - Spring 2024/mixkit-arcade-retro-game-over-213.wav"), NULL, SND_FILENAME | SND_SYNC);
}



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

int battleSequence::randintEnemyAttack(int parameter, int max_parameter) {

        // Define probability weights for each number
        double weights[] = { 2.0, 2.0, 0.5, 0.5, 0.05 }; // 1 and 2 are likely, 3 and 4 initially very rare, 5 initially rare

        // Calculate the probability increase for 5
        double increase_rate = (0.15 - 0.02) / max_parameter;

        // Adjust weights based on the parameter
        for (int i = 0; i < 5; ++i) {
            weights[i] += (max_parameter - parameter) * increase_rate; // Increase weights for higher numbers as parameter decreases towards 0
        }

        // Ensure 3 is not generated unless parameter is less than half of max_parameter
        if (parameter > max_parameter / 2) {
            weights[3] = 0.0;
        }

        if (parameter <= max_parameter / 2) {
            weights[3] = 1.5;
        }

        if (parameter <= max_parameter * 0.4) {
            weights[2] = 1.5;
        }

        if (parameter <= max_parameter * 0.2) {
            weights[4] = 0.5;
        }

        // Normalize weights to ensure they sum up to 1
        double total_weight = 0.0;
        for (int i = 0; i < 5; ++i) {
            total_weight += weights[i];
        }
        for (int i = 0; i < 5; ++i) {
            weights[i] /= total_weight;
        }

        // Generate random number using discrete distribution
        std::random_device rd;
        std::mt19937 gen(rd());
        std::discrete_distribution<> dist(std::begin(weights), std::end(weights));

        // Return the randomly generated number (adding 1 to make it between 1 and 5)
        return dist(gen) + 1;
    }










// Display Battle Options

int battleSequence::displayBattleOptions() {

    int choice;

    cout << "\n\n1. Attack" << endl;
    cout << "2. Magic Spells" << endl;
    cout << "3. Defend" << endl;
    cout << "4. Open Inventory" << endl;
    cout << "5. Run Away\n\n" << endl;
    cout << "----------------------\n" << endl;

    cin >> choice;
    return choice;

}

int battleSequence::displayAttacks() {

    int choice;

    cout << "\n----------------------" << endl;
    cout << "1. Standard Attack" << endl;
    cout << "2. Fireball Attack [-20 Magicka]" << endl;
    cout << "----------------------\n" << endl;

    cin >> choice;
    return choice;

}

int battleSequence::displaySpells() {

    int choice;

    cout << "\n----------------------" << endl;
    cout << "1. Fireball Attack [-20 Magicka]" << endl;
    cout << "2. Slow Healing [-25 Magicka]" << endl;
    cout << "3. Slow Stamina Healing [-20 Magicka]" << endl;
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

    bool playerRun = false;


    while (_player->getHealth() > 0 && _enemy->getHealth() > 0 && _player->getFightingStatus() && _enemy->getFightingStatus()) {

        std::system("cls");

        // Initial Display Data



            _enemy->displayData();
            _player->displayData();


        int enemyChoice = randintEnemyAttack(_enemy->getHealth(), _enemy->getMaxHealth());

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
            switch (displaySpells()) {
            case 1:
                _player->magicAttack(*_enemy);
                break;
            case 2:
                _player->setHealing(true);
                break;
            case 3:
                _player->setStaminaHealing(true);
                break;
            }
            break;
        case 3:
            _player->defend();
            break;
        case 4:
            _player->manageInventory();
            break;
        case 5:
            _player->run();
            playerRun = true;
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
                _enemy->magicAttack(*_player);
                break;
            case 4:
                _enemy->restoreHealth(5);
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

        if (_player->getHealing() == true) {
            _player->setHealth(_player->getHealth() + 8);
        }

        if (_enemy->getHealing() == true) {
            _enemy->setHealth(_enemy->getHealth() + 8);
        }

        if (_player->getStaminaHealing() == true) {
            _player->setStamina(_player->getStamina() + 8);
        }

        if (_enemy->getStaminaHealing() == true) {
            _enemy->setStamina(_enemy->getStamina() + 8);
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


        // Set Ceiling Limits on Attributes

        if (_player->getHealth() >= _player->getMaxHealth()) {
            _player->setHealth(_player->getMaxHealth());
        }

        if (_enemy->getHealth() >= _enemy->getMaxHealth()) {
            _enemy->setHealth(_enemy->getMaxHealth());
        }

        if (_player->getStamina() >= _player->getMaxStamina()) {
            _player->setStamina(_player->getMaxStamina());
        }
        if (_enemy->getStamina() >= _enemy->getMaxStamina()) {
            _enemy->setStamina(_enemy->getMaxStamina());
        }

        if (_player->getMagicka() >= _player->getMaxMagicka()) {
            _player->setMagicka(_player->getMaxMagicka());
        }
        if (_enemy->getMagicka() >= _enemy->getMaxMagicka()) {
            _enemy->setMagicka(_enemy->getMaxMagicka());
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
        std::thread soundThread(playDeathSound);


        cout << "\nYou have died." << endl;

        soundThread.join();

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

    if (!playerRun) {
        this_thread::sleep_for(chrono::seconds(7));
    }

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
