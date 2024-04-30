#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include "inventory.cpp"

using namespace std;

class character {
protected:
    string name;
    string charClass;
    int level;
    int maxHealth;
    int maxMagicka;
    int maxStamina;
    int currentHealth;
    int currentMagicka;
    int currentStamina;
    int currentXp;
    int requiredXp;
    int attackDamage;
    bool attackValue;
    bool defendValue;
    int healthPotions;
    int staminaPotions;
    int magickaPotions;
    inventory characterInventory;
    bool fightingStatus;
    bool poisoned;


public:



    character();
    character(string _name, int _level);

    void setClass(string);

    string getClass();

    void openInventory();


    inventory& getInventory();

    void setPoisoned(bool);
    bool getPoisoned();

    bool& getFightingStatus();
    void setFightingStatus(bool);

    int getHealth();
    void setHealth(int);

    int getMagicka();
    void setMagicka(int);

    int getStamina();
    void setStamina(int);

    int getMaxStamina();
    void setMaxStamina(int);

    int getMaxHealth();
    void setMaxHealth(int);

    int getMaxMagicka();
    void setMaxMagicka(int);

    void setName(string);

    int getAttackDamage();
    int getStaminaPotions();
    void setStaminaPotions(int _stamina_potions);
    int getHealthPotions();
    void setHealthPotions(int _health_potions);
    int getMagickaPotions();
    void setMagickaPotions(int _magicka_potions);

    virtual void attack(character&);
    virtual void magicAttack(character&);
    void defend();
    void run();

    void restoreHealth(int _health);
    void restoreMagicka(int _magicka);
    void restoreStamina(int _stamina);

    int getCurrentXP();
    void setCurrentXP(int newXp);
    int getLevel();
    int getRequiredXP();
    void setRequiredXP(int newXp);
    void levelUp();


    string getName();


    void displayData();
    void displayFullData();
    void checkLevel();

    void setAttack(bool);
    bool getAttack();

    void setDefend(bool);
    bool getDefend();

    void addToInventory(inventoryItem*);
    void dropFromInventory(int);

};

class enemy : public character {
public:

    enemy();

    enemy(int _level);

    void restoreHealth(int);

};

class player : public character {



public:

    player();

    player(int _level, string name);

    void manageInventory();



    /* void attack(character&);*/

};

class goblin : public enemy {

public:

    goblin();

    goblin(int _level);

};


class orc : public enemy {
public:
    orc();
    orc(int _level);
};

class wraith : public enemy {
public:
    wraith();
    wraith(int _level);
    void magicAttack(character&) override;
};

class bandit : public enemy {
public:
    bandit();
    bandit(int _level);
};

#endif
