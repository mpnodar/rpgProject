#include <iostream>
#include <random>
#include "characters.h"

using namespace std;


character::character() {
    name = "No Name";
    level = 0;
    maxHealth = (40 + (level * 5));
    maxStamina = (50 + (level * 5));
    maxMagicka = (30 + (level * 5));
    attackDamage = 5 + (level * 3);
    currentHealth = maxHealth;
    currentMagicka = maxMagicka;
    currentStamina = maxStamina;
    currentXp = 0;
    requiredXp = 100 + level * 20;
    attackValue = false;
    defendValue = false;
    healthPotions = 3;
    inventory characterInventory;
}

character::character(string _name, int _level) {
    name = _name;
    level = _level;
    maxHealth = (40 + (level * 5));
    maxStamina = (50 + (level * 5));
    maxMagicka = (30 + (level * 5));
    attackDamage = 5 + (level * 3);
    currentHealth = maxHealth;
    currentMagicka = maxMagicka;
    currentStamina = maxStamina;
    currentXp = 0;
    requiredXp = 100 + level * 20;
    attackValue = false;
    defendValue = false;
    healthPotions = 3;
    inventory characterInventory;
}

enemy::enemy() {
    name = "Enemy";
    level = 0;

}

enemy::enemy(int _level) {
    name = "Enemy";
    level = _level;

}

goblin::goblin() : enemy() {
    name = "Goblin";
    level = 3;
    maxHealth = (30 + (level * 5));
    maxStamina = (30 + (level * 5));
    maxMagicka = (20 + (level * 5));
    attackDamage = 5 + (level * 3);
    currentHealth = maxHealth;
    currentMagicka = maxMagicka;
    currentStamina = maxStamina;
}

goblin::goblin(int _level) : enemy() {
    name = "Goblin";
    level = _level;
    maxHealth = (30 + (level * 5));
    maxStamina = (30 + (level * 5));
    maxMagicka = (20 + (level * 5));
    attackDamage = 5 + (level * 3);
    currentHealth = maxHealth;
    currentMagicka = maxMagicka;
    currentStamina = maxStamina;
}

orc::orc() {
    name = "Orc";
    level = 10;
    maxHealth = (50 + (level * 5));
    maxStamina = (50 + (level * 5));
    maxMagicka = (30 + (level * 5));
    attackDamage = 15 + (level * 2);
    currentHealth = maxHealth;
    currentMagicka = maxMagicka;
    currentStamina = maxStamina;
}

orc::orc(int _level) {
    name = "Orc";
    level = _level;
    maxHealth = (50 + (level * 5));
    maxStamina = (50 + (level * 5));
    maxMagicka = (30 + (level * 5));
    attackDamage = 15 + (level * 3);
    currentHealth = maxHealth;
    currentMagicka = maxMagicka;
    currentStamina = maxStamina;
}

wraith::wraith() {
    name = "Wraith";
    level = 20;
    maxHealth = (70 + (level * 5));
    maxStamina = (70 + (level * 5));
    maxMagicka = (100 + (level * 5));
    attackDamage = 25 + (level * 3);
    currentHealth = maxHealth;
    currentMagicka = maxMagicka;
    currentStamina = maxStamina;
}

wraith::wraith(int _level) {
    name = "Wraith";
    level = _level;
    maxHealth = (70 + (level * 5));
    maxStamina = (70 + (level * 5));
    maxMagicka = (100 + (level * 5));
    attackDamage = 25 + (level * 3);
    currentHealth = maxHealth;
    currentMagicka = maxMagicka;
    currentStamina = maxStamina;
}


player::player() {
    name = "Player";
    level = 0;
    getInventory().addItem("Gold", 100);
    getInventory().addItem("Health Potions", 3);
}

player::player(int _level, string _name) {
    name = _name;
    level = _level;
    maxHealth = (50 + (level * 5));
    maxStamina = (50 + (level * 5));
    maxMagicka = (30 + (level * 5));
    attackDamage = 5 + (level * 3);
    currentHealth = maxHealth;
    currentMagicka = maxMagicka;
    currentStamina = maxStamina;
    getInventory().addItem("Health Potions", 3);
    getInventory().addItem("Gold", 100);

}





int character::getHealth() {
    return currentHealth;
}

void character::setHealth(int _health) {
    currentHealth = _health;
}

int character::getAttackDamage() {
    return attackDamage;
}

void character::attack(character& defender) {

    setDefend(false);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 5);
    int criticalHit = distrib(gen);

    if (((defender.getDefend()) != true) || (defender.getStamina() <= 0)) {

        if (criticalHit < 5) {
            cout << "\n" << name << " attacks!\n" << endl;
            defender.setHealth(defender.getHealth() - getAttackDamage());
        }
        else if (criticalHit == 5) {
            cout << "\n" << name << " critical attacks!\n" << endl;
            defender.setHealth(defender.getHealth() - getAttackDamage() * 2);
        }
    }
    else if ((defender.getDefend() == true) && (defender.getStamina() > 0)) {
        if (criticalHit < 5) {
            cout << "\n" << name << " attacks, but " << defender.getName() << " defends!\n" << endl;
            defender.setStamina(defender.getStamina() - getAttackDamage());
        }
        else if (criticalHit == 5) {
            cout << "\n" << name << " critical attacks! " << defender.getName() << " defends!\n" << endl;
            defender.setStamina(defender.getStamina() - getAttackDamage() * 2);
        }
    }
}

/* void character::attack(character& defender) {

    setDefend(false);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 5);
    int criticalHit = distrib(gen);

    if (( (defender.getDefend()) != true) || (defender.getStamina() <= 0) ) {

        if (criticalHit < 5) {
            cout << "\n" << name << " attacks!\n" << endl;
            // cout << "----------------------\n\n" << endl;
            defender.setHealth(defender.getHealth() - getAttackDamage());
        }
        else if (criticalHit == 5) {
            cout << "\n" << name << " critical attacks!\n" << endl;
            // cout << "----------------------\n\n" << endl;
            defender.setHealth(defender.getHealth() - getAttackDamage() * 2);
        }
    }
    else if ( (defender.getDefend() == true) && (defender.getStamina() > 0) ) {
        if (criticalHit < 5) {
            cout << "\n" << name << " attacks, but " << defender.getName() << " defends!\n" << endl;
            defender.setStamina(defender.getStamina() - getAttackDamage());
        }
        else if (criticalHit == 5) {
            cout << "\n" << name << " critical attacks! " << defender.getName() << " defends!\n" << endl;
            defender.setStamina(defender.getStamina() - getAttackDamage() * 2);
        }
    }
} */

/* void player::attack(character& defender) {
    
    setDefend(false);

    if ((defender.getDefend()) != true) {

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(1, 5);
        int criticalHit = distrib(gen);

        if (criticalHit < 5) {
            cout << "\n" << name << " attacks!\n\n" << endl;
            cout << "----------------------\n\n" << endl;
            defender.setHealth(defender.getHealth() - getAttackDamage());
        }
        else if (criticalHit == 5) {
            cout << "\n" << name << " critical attacks!\n\n" << endl;
            cout << "----------------------\n\n" << endl;
            defender.setHealth(defender.getHealth() - getAttackDamage() * 2);
        }
    }

    else if (defender.getDefend() == true) {
        cout << name << " attacks!" << endl;
    }



} */

bool character::getDefend() {
    return defendValue;
}
void character::setDefend(bool _defend) {
    defendValue = _defend;
}

bool character::getAttack() {
    return attackValue;
}
void character::setAttack(bool _attack) {
    attackValue = _attack;
}

void character::defend() {

    if (getStamina() > 0) {
        cout << getName() << " defends!\n" << endl;
        setDefend(true);
    }

    else if (getStamina() == 0) {
        cout << getName() << " tries to defend but is out of stamina!\n" << endl;
    }
}

void character::run() {
    setFightingStatus(false);
    cout << "\n" << name << " runs away." << endl;
}


string character::getName() {
    return name;
}

int character::getHealthPotions() {
    return healthPotions;
}

void character::setHealthPotions(int _healthPotions) {
    healthPotions = _healthPotions;
}

int character::getMagickaPotions() {
    return currentMagicka;
}

int character::getStamina() {
    return currentStamina;
}

int character::getStaminaPotions() {
    return currentStamina;
}

void character::setStamina(int _stamina) {
    currentStamina = _stamina;
}

void character::restoreHealth(int _health) {
    setHealthPotions(getHealthPotions() - 1);
    setDefend(false);
    currentHealth += _health;
}

void enemy::restoreHealth(int _health) {
    setDefend(false);
    setHealthPotions(getHealthPotions() - 1);
    currentHealth += _health;
    cout << "\n" << name << " restores health.\n" << endl;
    cout << getHealthPotions();
}

void character::restoreMagicka(int _magicka) {
    setDefend(false);
    currentMagicka += _magicka;
}

void character::restoreStamina(int _stamina) {
    setDefend(false);
    currentStamina += _stamina;
}

int character::getCurrentXP() {
    return currentXp;
}
void character::setCurrentXP(int newXp) {
    currentXp = newXp;
}

int character::getRequiredXP() {
    return requiredXp;
}
void character::setRequiredXP(int newXp) {
    requiredXp = newXp;
}

int character::getLevel() {
    return level;
}

void character::levelUp() {
    level += 1;
    currentXp -= requiredXp;
    requiredXp += 20;
    maxHealth += 5;
    maxStamina += 5;
    maxMagicka += 5;
    attackDamage += 5;
    currentHealth = maxHealth;
    currentMagicka = maxMagicka;
    currentStamina = maxStamina;
}

void character::checkLevel() {
    if (getRequiredXP() <= getCurrentXP()) {
        levelUp();
    }
}

bool& character::getFightingStatus() {
    return fightingStatus;
}

void character::setFightingStatus(bool status) {
    fightingStatus = status;
}

inventory& character::getInventory() {
    return characterInventory;
}

void character::openInventory() {
    getInventory().displayInventory();
}

void player::manageInventory() {
    
    int choice = 0;



    while (choice != 3) {

        inventoryItem* item;
        openInventory();

        cout << "1. Use Item" << endl;
        cout << "2. Drop Item" << endl;
        cout << "3. Back" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            item = getInventory().useItem();
            if (item->name == "Health Potions" && item->quantity > 0) {
                item->quantity = item->quantity - 1;
                restoreHealth(25);
            }
            else if (item->name == "Health Potions" && item->quantity <= 0) {
                cout << "No Health Potions Left!";
            }




            break;
        case 2:
            getInventory().dropItem();
            break;
        case 3:
            cout << "\n\n-----------------------\n" << endl;

        }
    }
}


void character::displayData() {
    cout << "----------------------" << endl;
    cout << name << "\nLevel: " << level << endl;
    cout << "  - - - - - - - - - - " << endl;
    cout << "Health: " << currentHealth << "\nStamina: " << currentStamina << "\nMagicka: " << currentMagicka << endl;
    cout << "----------------------" << endl;
}

void character::displayFullData() {
    cout << "----------------------" << endl;
    cout << name << endl;
    cout << "Level: " << level << endl << endl;
    cout << "Current XP: " << currentXp << endl;
    cout << "XP Required for Next Level: " << requiredXp << endl;

    if (currentXp < requiredXp) { cout << "XP Until Next Level: " << requiredXp - currentXp << "\n" << endl; }
    else { cout << "Ready to Level Up" << "\n" << endl; }

    cout << "Health: " << currentHealth << "\nStamina: " << currentStamina << "\nMagicka: " << currentMagicka << "\nAttack Damage: " << attackDamage << endl;
    cout << "----------------------" << endl;
}