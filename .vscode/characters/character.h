#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>

using namespace std;

class character {

    protected:

    string name;
    string action;
    int currentHealth;
    int currentMagicka;
    int currentStamina;
    int maxHealth;
    int maxMagicka;
    int maxStamina;
    int currentXp;
    int requiredXp;
    int level;
    int attackDamage;

    public:

    character () {
        currentHealth = 0;
        currentMagicka = 0;
        currentStamina = 0;
        attackDamage = 0;
    }

    character (string _name, int _health, int _magicka, int _stamina, int _attackDamage) {
        name = _name;
        maxHealth = _health;
        maxMagicka = _magicka;
        maxStamina = _stamina;
        currentHealth = maxHealth;
        currentMagicka = maxMagicka;
        currentStamina = maxStamina;
        attackDamage = _attackDamage;
    }

    int getHealth() {}

    void setHealth(int _health) {}

    int getStamina () {}

    void setStamina (int _stamina) {}

    int getAttackDamage () {}

    int getStaminaPotions () {}

    void setStaminaPotions (int _stamina_potions) {}

    int getHealthPotions () {}

    void setHealthPotions (int _health_potions) {}

    int getMagickaPotions () {}

    void setMagickaPotions (int _magicka_potions) {}

    virtual void attack () {}

    virtual void defend () {}

    virtual void run () {}

    virtual void restoreHealth () {}

    virtual void restoreMagicka () {}

    virtual void restoreStamina () {}

    string getName () {
        return name;
    }

    void displayData() {}

};


#endif