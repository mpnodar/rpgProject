#include <iostream>
#include <random>

using namespace std;

int getRandomInt(int min, int max) {
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

class character {

    protected:

    string action;
    string name;
    int health;
    int magicka;
    int stamina;
    int attackDamage;
    int health_potions;
    int stamina_potions;
    int magicka_potions;


    public:

    character () {
        health = 0;
        magicka = 0;
        stamina = 0;
        attackDamage = 0;
    }

    character (string _name, int _health, int _magicka, int _stamina, int _attackDamage, int _health_potions, int _magicka_potions, int _stamina_potions) {
        name = _name;
        health = _health;
        magicka = _magicka;
        stamina = _stamina;
        attackDamage = _attackDamage;
        health_potions = _health_potions;
        magicka_potions = _magicka_potions;
        stamina_potions = _stamina_potions;
    }

    void setAction (string _action) {
        action = _action;
    }

    void selectAttack () {
        int choice;

        if (choice == 1) {
            attack();
        }

        else if (choice == 2) {
            defend();
        }

        else if (choice == 3) {
            run();
        }
    }

    int getHealth() {
        return health;
    }

    void setHealth(int _health) {
        health = _health;
    }

    int getStamina () {
        return stamina;
    }

    void setStamina (int _stamina) {
        stamina = _stamina;
    }

    int getAttackDamage () {
        return attackDamage;
    }

    int getStaminaPotions () {
        return stamina_potions;
    }
    void setStaminaPotions (int _stamina_potions) {
        stamina_potions = _stamina_potions;
    }

    int getHealthPotions () {
        return health_potions;
    }
    void setHealthPotions (int _health_potions) {
        health_potions = _health_potions;
    }

    int getMagickaPotions () {
        return magicka_potions;
    }
    void setMagickaPotions (int _magicka_potions) {
        magicka_potions = _magicka_potions;
    }

    virtual void attack () {}

    virtual void defend () {}

    virtual void run () {}

    virtual void restoreHealth () {
        health += 15;
    }

    virtual void restoreMagicka () {
        magicka += 15;
    }

    virtual void restoreStamina () {
        stamina += 15;
    }

    string getAction () {
        return action;
    }

    string getName() {
        return name;
    }

    void displayData () {
        cout << "-------------------------" << endl;
        cout << name << ": " << endl;
        cout << "Health: " << health << endl;
        cout << "Magicka: " << magicka << endl;
        cout << "Stamina: " << stamina << endl;
        cout << "-------------------------" << endl;
    }

};

class enemy : public character {

    bool flee = false;

    public:
    
    enemy () {
        name = "Unknown Enemy";
        health = 0;
        magicka = 0;
        stamina = 0;
        attackDamage = 0;
    }

    enemy (string _name, int _health, int _magicka, int _stamina, int _attackDamage, int _health_potions, int _magicka_potions, int _stamina_potions) {
        name = _name;
        health = _health;
        magicka = _magicka;
        stamina = _stamina;
        attackDamage = _attackDamage;
        health_potions = _health_potions;
        magicka_potions = _magicka_potions;
        stamina_potions = _stamina_potions;

    }

    void selectAttack () {
        int choice = getRandomInt(1, 100);

        if (choice <= 33) {
            attack();
            action = "attack";
        }

        if (choice <= 66 && choice > 33 && stamina > 0) {
            defend();
            action = "defend";
        }
        else if (choice <= 66 && choice > 33 && stamina == 0) {
            cout << "   The " << name << " tries to defend but is out of stamina.";
            action = "Null";
        }

        if (choice >= 67 && choice < 83 && health_potions > 0) {
            cout << "   " << name << " heals." << endl;
            restoreHealth();
            action = "restoreHealth";
            health_potions--;
        }
        else if (choice >= 67 && choice <= 83 && health_potions == 0) {
            choice = choice - 10 * (getRandomInt(1,6));
        }

        
        // Restore Stamina

        if (choice >= 84 && choice <= 97 && stamina_potions > 0) {
            cout << "   " << name << " restores stamina." << endl;
            restoreStamina();
            action = "restoreStamina";
            stamina_potions--;
        }
        else if (choice >= 84 && choice <= 97 && stamina_potions == 0) {
            choice = choice - 10 * (getRandomInt(1,8));
        }



        if (choice >= 98 && choice <= 100) {
            run();
            action = "run";
            setFlee(true);
        }
    }

    bool getFlee () {
        return flee;
    }

    void setFlee (bool _flee) {
        flee = _flee;
    }

};

class goblin : public enemy {

    public:

    goblin () : enemy("Goblin", 100, 30, 60, 18, 3, 3, 3) {};

    void attack () {
        cout << "   The goblin attacks." << endl;
    }

    void run () {
        cout << "   The goblin runs away." << endl;
    }

    void defend () {
        cout << "   The goblin defends." << endl;
    }
};

class orc : public enemy {

    public:

    orc () : enemy("Orc", 150, 50, 125, 30, 3, 3, 3) {};

    void attack () {
        cout << "   The orc attacks." << endl;
    }

    void run () {
        cout << "   The orc runs away." << endl;
    }

    void defend () {
        cout << "   The orc defends." << endl;
    }
};

class wraith : public enemy {

    public:

    wraith () : enemy("Wraith", 200, 250, 250, 45, 3, 3, 3) {};

    void attack () {
        cout << "   The wraith attacks." << endl;
    }

    void run () {
        cout << "   The wraith flees." << endl;
    }

    void defend () {
        cout << "   The wraith defends." << endl;
    }
};

class player : public character {

    public:

    int gold = 250;
    int xp = 0;
    
    player () : character ("You", 100, 80, 80, 25, 3, 3, 3) {};

    virtual void attack () {
        cout << "   You attack." << endl;
        action = "attack";
    }

    virtual void defend () {
        cout << "   You defend." << endl;
        action = "defend";
    }

    virtual void run () {
        cout << "   You run away.\n\nXP Earned: 0\nTotal XP: " << xp << endl;
        action = "run";
    }

    void selectAttack() {
    int choice;
    cout << "What would you like to do?\n\n1. Attack\n2. Defend\n3. Use Health Potion (" << getHealthPotions() << " remaining)\n4. Use Stamina Potion (" << stamina_potions << " remaining)\n5. Run" << endl;
    cin >> choice;
    cout << "\n\n\n";

    if (choice == 1) {
        attack();
    }

    if (choice == 2 && stamina != 0) {
        defend();
    } else if (choice == 2 && stamina == 0) {
        cout << "   You try to defend but you are out of stamina." << endl;
    }

    if (choice == 3 && health_potions > 0) {
        restoreHealth();
        setHealthPotions(health_potions - 1);
        cout << "   You restore health." << endl;
    } else if (choice == 3 && health_potions == 0) {
        cout << "   You try to restore health but you are out of health potions." << endl;
    }

    if (choice == 4 && stamina_potions > 0) {
        cout << "   You restore stamina." << endl;
        restoreStamina();
        setStaminaPotions(stamina_potions - 1);
    } else if (choice == 4 && stamina_potions == 0) {
        cout << "   You try to restore stamina but you are out of stamina potions." << endl;
    }

    if (choice == 5) {
        run();
    }
}


};