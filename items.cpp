#include <iostream>
#include "characters.h"


using namespace std;


class Weapon : public inventoryItem {
public:
    int attackBonus;

    Weapon(const string& _name, int _quantity, int _attackBonus) : inventoryItem(_name, _quantity), attackBonus(_attackBonus) {}
};

class inventory {
};

class player {
private:
    Weapon* equippedWeapon;

public:
    player() : equippedWeapon(nullptr) {}

    void equipWeapon(Weapon* weapon) {
        unequipWeapon();
        equippedWeapon = weapon;
        if (equippedWeapon) {
            attackDamage += equippedWeapon->attackBonus;
        }
    }

    void unequipWeapon() {
        if (equippedWeapon) {
            attackDamage -= equippedWeapon->attackBonus;
            equippedWeapon = nullptr;
        }
    }

};