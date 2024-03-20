#include <iostream>
#include <random>
#include "characters.cpp"

using namespace std;

int battle (player &you) {

    you.setStamina(80);

    int enemyRandomizer = getRandomInt(1,13);
    
    bool loop = true;

    // Goblin fight 

    if (enemyRandomizer <= 5) {

    goblin sareReal;

    while (true) {

        cout << "\n\n";

        sareReal.displayData();

        cout << "\n\n";

        you.displayData();

        cout << "\n\n";

        you.selectAttack();

        cout << "\n";

        if (you.getAction() != "run") {
            sareReal.selectAttack();
        }

    // Player Attack / Enemy Damage

    if (you.getAction() == "attack" && sareReal.getAction() != "defend") {
            sareReal.setHealth(sareReal.getHealth() - you.getAttackDamage());
        }

    // Enemy Attack / Player Damage

        if (sareReal.getAction() == "attack" && you.getAction() != "defend") {
            you.setHealth(you.getHealth() - sareReal.getAttackDamage());
        }

    // Enemy Attack / Player Defend

        if (sareReal.getAction() == "attack" && you.getAction() == "defend" && you.getStamina() > 0) {
            you.setStamina( (you.getStamina() - sareReal.getAttackDamage()) );
        }

    // Player Attack / Enemy Defend

        if (you.getAction() == "attack" && sareReal.getAction() == "defend") {
            sareReal.setStamina( (sareReal.getStamina() - you.getAttackDamage()) );
        }

    // Enemy Attack / Player Defend but No Stamina

        if (sareReal.getAction() == "attack" && you.getAction() == "defend" && you.getStamina() <= 0) {
            you.setHealth(you.getHealth() - sareReal.getAttackDamage());
        }

    // Stamina Lower Limit - Player

        if (you.getStamina() < 0) {
            you.setStamina(0);
        }

    // Health Lower Limit - Player

        if (you.getHealth() < 0) {
            you.setHealth(0);
        }

    // Stamina Lower Limit - Enemy

        if (sareReal.getStamina() < 0) {
            sareReal.setStamina(0);
        }

    // Health Lower Limit - Enemy

        if (sareReal.getHealth() < 0) {
            sareReal.setHealth(0);
        }

    // Health Upper Limit - Enemy

        if (sareReal.getHealth() > 60) {
            sareReal.setHealth(60);
        }

    // Stamina Upper Limit - Enemy

        if (sareReal.getStamina() > 60) {
            sareReal.setStamina(60);
        }

    // Health Upper Limit - Player

        if (you.getHealth() > 100) {
            you.setHealth(100);
        }

    // Stamina Upper Limit - Player

        if (you.getStamina() > 80) {
            you.setStamina(80);
        }


    // Enemy Defeated

        if (sareReal.getHealth() <= 0) {
            cout << "\n\n";
            sareReal.displayData();
            cout << "\n\n";
            you.displayData();
            cout << "\n\n";
            cout << "\n\nYou have defeated the " << sareReal.getName() << "!\n\n " << endl;
            you.addXP(75);
            cout << "75xp Earned!" << endl;
            if (you.getXP() >= 100) {
            you.levelUp();
            }
            cout << "Total XP: " << you.getXP() << endl;
            cout << "Level: " << you.getLevel() << endl;
            cout << "XP Required for Next Level: " << you.getXpRequired() << endl;
            break;
        }

    // Player defeated

        if (you.getHealth() <= 0) {
            cout << "\n\n";
            sareReal.displayData();
            cout << "\n\n";
            you.displayData();
            cout << "\n\n";
            cout << "\n\nYou have died." << endl;
            you.setAction("dead");
            break;
        }

    // Flee end-battle

        if (sareReal.getFlee() == true) {
            break;
        }

        if (you.getAction() == "run") {
            break;
        }

    }

    }

    // Orc Fight

    else if (enemyRandomizer > 5 && enemyRandomizer <= 10) {

    orc sareReal;

    while (true) {

        cout << "\n\n";

        sareReal.displayData();

        cout << "\n\n";

        you.displayData();

        cout << "\n\n";

        you.selectAttack();

        cout << "\n";

        if (you.getAction() != "run") {
            sareReal.selectAttack();
        }

        if (you.getAction() == "attack" && sareReal.getAction() != "defend") {
            sareReal.setHealth(sareReal.getHealth() - you.getAttackDamage());
        }

        if (sareReal.getAction() == "attack" && you.getAction() != "defend") {
            you.setHealth(you.getHealth() - sareReal.getAttackDamage());
        }

    // Enemy Attack / Player Defend

        if (sareReal.getAction() == "attack" && you.getAction() == "defend" && you.getStamina() > 0) {
            you.setStamina( (you.getStamina() - sareReal.getAttackDamage()) );
        }

    // Player Attack / Enemy Defend

        if (you.getAction() == "attack" && sareReal.getAction() == "defend") {
            sareReal.setStamina( (sareReal.getStamina() - you.getAttackDamage()) );
        }

    // Enemy Attack / Player Defend but No Stamina

        if (sareReal.getAction() == "attack" && you.getAction() == "defend" && you.getStamina() <= 0) {
            you.setHealth(you.getHealth() - sareReal.getAttackDamage());
        }

    // Stamina Lower Limit - Player

        if (you.getStamina() < 0) {
            you.setStamina(0);
        }

    // Health Lower Limit - Player

        if (you.getHealth() < 0) {
            you.setHealth(0);
        }

    // Stamina Lower Limit - Enemy

        if (sareReal.getStamina() < 0) {
            sareReal.setStamina(0);
        }

    // Health Lower Limit - Enemy

        if (sareReal.getHealth() < 0) {
            sareReal.setHealth(0);
        }

    // Health Upper Limit - Enemy

        if (sareReal.getHealth() > 150) {
            sareReal.setHealth(150);
        }

    // Stamina Upper Limit - Enemy

        if (sareReal.getStamina() > 125) {
            sareReal.setStamina(125);
        }

    // Health Upper Limit - Player

        if (you.getHealth() > 100) {
            you.setHealth(100);
        }

    // Stamina Upper Limit - Player

        if (you.getStamina() > 80) {
            you.setStamina(80);
        }

    // Enemy defeated

        if (sareReal.getHealth() <= 0) {
            cout << "\n\n";
            sareReal.displayData();
            cout << "\n\n";
            you.displayData();
            cout << "\n\n";
            cout << "\n\nYou have defeated the " << sareReal.getName() << "!\n\n " << endl;
            you.addXP(150);
            cout << "150xp Earned!\nTotal xp: " << you.getXP() << endl;
            if (you.getXP() > 100) {
                you.levelUp();
            }
            cout << "Level: " << you.getLevel() << endl;
            cout << "XP Required for Next Level: " << you.getXpRequired() << endl;
            break;
        }

    // Player defeated

        if (you.getHealth() <= 0) {
            cout << "\n\n";
            sareReal.displayData();
            cout << "\n\n";
            you.displayData();
            cout << "\n\n";
            cout << "\n\nYou have died." << endl;
            break;
        }

        if (sareReal.getFlee() == true) {
            break;
        }

        if (you.getAction() == "run") {
            break;
        }

    }

    }


    // Wraith Fight

    else if (enemyRandomizer > 10 && enemyRandomizer <= 13) {

    wraith sareReal;

    while (true) {

        cout << "\n\n";

        sareReal.displayData();

        cout << "\n\n";

        you.displayData();

        cout << "\n\n";

        you.selectAttack();

        cout << "\n";

        if (you.getAction() != "run") {
            sareReal.selectAttack();
        }

        if (you.getAction() == "attack" && sareReal.getAction() != "defend") {
            sareReal.setHealth(sareReal.getHealth() - you.getAttackDamage());
        }

        if (sareReal.getAction() == "attack" && you.getAction() != "defend") {
            you.setHealth(you.getHealth() - sareReal.getAttackDamage());
        }

    // Enemy Attack / Player Defend

        if (sareReal.getAction() == "attack" && you.getAction() == "defend" && you.getStamina() > 0) {
            you.setStamina( (you.getStamina() - sareReal.getAttackDamage()) );
        }

    // Player Attack / Enemy Defend

        if (you.getAction() == "attack" && sareReal.getAction() == "defend") {
            sareReal.setStamina( (sareReal.getStamina() - you.getAttackDamage()) );
        }

    // Enemy Attack / Player Defend but No Stamina

        if (sareReal.getAction() == "attack" && you.getAction() == "defend" && you.getStamina() <= 0) {
            you.setHealth(you.getHealth() - sareReal.getAttackDamage());
        }

    // Stamina Lower Limit - Player

        if (you.getStamina() < 0) {
            you.setStamina(0);
        }

    // Health Lower Limit - Player

        if (you.getHealth() < 0) {
            you.setHealth(0);
        }

    // Stamina Lower Limit - Enemy

        if (sareReal.getStamina() < 0) {
            sareReal.setStamina(0);
        }

    // Health Lower Limit - Enemy

        if (sareReal.getHealth() < 0) {
            sareReal.setHealth(0);
        }

    // Health Upper Limit - Enemy

        if (sareReal.getHealth() > 200) {
            sareReal.setHealth(200);
        }

    // Stamina Upper Limit - Enemy

        if (sareReal.getStamina() > 250) {
            sareReal.setStamina(250);
        }

    // Health Upper Limit - Player

        if (you.getHealth() > 100) {
            you.setHealth(100);
        }

    // Stamina Upper Limit - Player

        if (you.getStamina() > 80) {
            you.setStamina(80);
        }

    // Enemy defeated

        if (sareReal.getHealth() <= 0) {
            cout << "\n\n";
            sareReal.displayData();
            cout << "\n\n";
            you.displayData();
            cout << "\n\n";
            cout << "\n\nYou have defeated the " << sareReal.getName() << "!\n\n " << endl;
            you.addXP(300);
            cout << "300xp Earned!\nTotal xp: " << you.getXP() << endl;
            if (you.getXP() >= you.getXpRequired()) {
            you.levelUp();
            }
            cout << "Level: " << you.getLevel() << endl;
            cout << "XP Required for Next Level: " << you.getXpRequired() << endl;
            break;
        }

    // Player defeated

        if (you.getHealth() <= 0) {
            cout << "\n\n";
            sareReal.displayData();
            cout << "\n\n";
            you.displayData();
            cout << "\n\n";
            cout << "\n\nYou have died." << endl;
            break;
        }

    // Enemy Flee        

        if (sareReal.getFlee() == true) {
            break;
        }

    // Player Flee

        if (you.getAction() == "run") {
            break;
        }

    }

    }



    return 0;
}