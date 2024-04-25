#include "characters.cpp"
#include "shop.cpp"
#include <iostream>
#include <random>

using namespace std;



// Random Functions

int randint(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}
int randintLow(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Triangular distribution
    std::uniform_int_distribution<> distrib(min, max);
    int lower = distrib(gen);
    int upper = distrib(gen);
    return lower < upper ? lower : upper;
}
int randintHigh(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Triangular distribution biased towards higher values
    std::uniform_int_distribution<> distrib(min, max);
    int lower = distrib(gen);
    int upper = distrib(gen);
    return lower > upper ? lower : upper;
}
int randintNear(int target, int min, int max) {
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






// Display Battle Options

int displayBattleOptions() {

    int choice;

    cout << "\n\n1. Attack" << endl;
    cout << "2. Defend" << endl;
    cout << "3. Open Inventory" << endl;
    cout << "4. Run Away\n\n" << endl;
    cout << "----------------------\n" << endl;

    cin >> choice;
    return choice;

}




// General Battle Structure

void battle(player& _player, enemy& _enemy) {

    // Set Fighting Status to True

    _player.setFightingStatus(true);

    // Battle Loop

    while (_player.getHealth() > 0 && _enemy.getHealth() > 0 && _player.getFightingStatus()) {

        // Initial Display Data
            
            
            _enemy.displayData();
            _player.displayData();

            
            int enemyChoice = randint(1, 3);

            if (enemyChoice == 2) {
                _enemy.setDefend(true);
            }
            else {
                _enemy.setDefend(false);
            }


        // Player Select Action

            switch (displayBattleOptions()) {
                case 1:
                    _player.attack(_enemy);
                    break;
                case 2:
                    _player.defend();
                    break;
                case 3:
                    _player.manageInventory();
                    break;
                case 4:
                    _player.run();                   
                    break;
            }


        // Enemy Select Action

            if (_enemy.getHealth() > 0 && _player.getFightingStatus()) {
                switch (enemyChoice) {
                    case 1:
                        _enemy.attack(_player);
                        break;
                    case 2:
                        _enemy.defend();
                        break;
                    case 3:
                        _enemy.restoreHealth(5);
                        break;
                    case 4:
                        cout << "\nRun" << endl;
                        break;
                    }
            }




        // Set Floor Limits on Attribute Values

            if (_player.getHealth() <= 0) {
                
                _player.setHealth(0);
            }
            if (_enemy.getHealth() <= 0) {
                _enemy.setHealth(0);
            }

            if (_player.getStamina() <= 0) {
                _player.setStamina(0);
            }
            if (_enemy.getStamina() <= 0) {
                _enemy.setStamina(0);
            }




    }





    // Post-battle Display Data

        _enemy.displayData();
        _player.displayData();






    // Check Who Has Died

        if (_player.getHealth() == 0) {
            cout << "\nYou have died." << endl;
        }

        else if (_enemy.getHealth() == 0) {

            vector<string>lootItems;
            lootItems.push_back("Health Potions");

            cout << "You have defeated the " << _enemy.getName() << "!" << endl;


            _player.setCurrentXP(_player.getCurrentXP() + (20 * _enemy.getLevel()));
            cout << "XP Earned: " << (20 * _enemy.getLevel()) << endl;
            
            while (_player.getCurrentXP() >= _player.getRequiredXP()) {
                _player.checkLevel();
            }

            _player.getInventory().getItemByName(lootItems[0])->quantity += 1;
            cout << "Acquired 1 Health Potion!" << endl;

            _player.displayFullData();

        }

}







// Full Battle with Enemy Randomization

void randomBattle(player& _player) {

    int randLevel = randintNear(_player.getLevel(), 1, (_player.getLevel() + 20));

    goblin nilbog(randLevel);
    orc bum(randLevel);
    wraith dumbass(randLevel);

    int randEnemy = randint(1, 100);
    
    if (randEnemy <= 50) {
        battle(_player, nilbog);
    }

    else if (randEnemy > 50 && randEnemy <= 90) {
        battle(_player, bum);
    }

    else if (randEnemy > 90) {
        battle(_player, dumbass);
    }
    


}