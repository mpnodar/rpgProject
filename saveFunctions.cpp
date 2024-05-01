#include <fstream>
#include <iostream>


static void saveGamePointer(player* p) {
	ofstream saveFile("gameData.txt");
	saveFile << p->getName() << "\n" << p->getLevel() << "\n" << p->getClass() << "\n" << p->getGold() << "\n" << p->getHealthPotions() << "\n" << p->getHealth() << "\n" << p->getStamina() << "\n" << p->getMagicka() << "\n" << p->getAttack() << "\n" << p->getCurrentXP() << "\n" << p->getCurrentWeight() << "\n" << p->getMagickaPotions() << "\n" << p->getStaminaPotions() << "\n" << p->getMaxWeight() << endl;
	saveFile.close();
}

static void loadGamePointer(player* p) {
	ifstream saveFile("gameData.txt");

	string line;
	int lineCount = 0;

	while (getline(saveFile, line)) {
		lineCount++;

		// Load Name

		if (lineCount == 1) {
			p->setName(line);
		}

		// Load Level

		else if (lineCount == 2) {
			p->setLevel(stoi(line));
		}

		// Load Class

		else if (lineCount == 3) {
			p->setClass(line);
		}

		// Load Gold

		else if (lineCount == 4) {
			p->setGold(stoi(line));
		}

		// Load Health Potions

		else if (lineCount == 5) {
			p->setHealthPotions(stoi(line));
		}

		else if (lineCount == 6) {
			p->setHealth(stoi(line));
			p->setMaxHealth(stoi(line));
		}

		else if (lineCount == 7) {
			p->setStamina(stoi(line));
		}

		else if (lineCount == 8) {
			p->setMagicka(stoi(line));
		}

		else if (lineCount == 9) {
			p->setAttack(stoi(line));
		}

		else if (lineCount == 10) {
			p->setCurrentXP(stoi(line));
		}

		else if (lineCount == 11) {
			p->setCurrentWeight(stoi(line));
		}

		else if (lineCount == 12) {
			p->setStaminaPotions(stoi(line));
		}

		else if (lineCount == 13) {
			p->setStaminaPotions(stoi(line));
		}

		else if (lineCount == 14) {
			p->setMaxWeight(stoi(line));
		}

	}

}

static void loadGameNoPointer(player& p) {
	ifstream saveFile("gameData.txt");

	string line;
	int lineCount = 0;

	while (getline(saveFile, line)) {
		lineCount++;

		// Load Name

		if (lineCount == 1) {
			p.setName(line);
		}

		// Load Level

		else if (lineCount == 2) {
			p.setLevel(stoi(line));
		}

		// Load Class

		else if (lineCount == 3) {
			p.setClass(line);
		}

		// Load Gold

		else if (lineCount == 4) {
			p.setGold(stoi(line));
		}

		// Load Health Potions

		else if (lineCount == 5) {
			p.setHealthPotions(stoi(line));
		}

		else if (lineCount == 6) {
			p.setMaxHealth(stoi(line));
			p.setHealth(stoi(line));
		}

		else if (lineCount == 7) {
			p.setMaxStamina(stoi(line));
		}

		else if (lineCount == 8) {
			p.setMaxMagicka(stoi(line));
		}

		else if (lineCount == 9) {
			p.setAttack(stoi(line));
		}

		else if (lineCount == 10) {
			p.setCurrentXP(stoi(line));
		}

		else if (lineCount == 11) {
			p.setCurrentWeight(stoi(line));
		}

		else if (lineCount == 12) {
			p.setMagickaPotions(stoi(line));
		}

		else if (lineCount == 13) {
			p.setStaminaPotions(stoi(line));
		}

		else if (lineCount == 14) {
			p.setMaxWeight(stoi(line));
		}
	}

}

static void saveGameNoPointer(player& p) {
	ofstream saveFile("gameData.txt");
	saveFile << p.getName() << "\n" << p.getLevel() << "\n" << p.getClass() << "\n" << p.getGold() << "\n" << p.getHealthPotions() << "\n" << p.getMaxHealth() << "\n" << p.getMaxStamina() << "\n" << p.getMaxMagicka() << "\n" << p.getAttack() << "\n" << p.getCurrentXP() << "\n" << p.getCurrentWeight() << "\n" << p.getMagickaPotions() << "\n" << p.getStaminaPotions() << "\n" << p.getMaxWeight() << endl;
	saveFile.close();
}

