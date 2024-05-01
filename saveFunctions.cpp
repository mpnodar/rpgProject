#include <fstream>
#include <iostream>


static void saveGamePointer(player* p) {
	ofstream saveFile("gameData.txt");
	saveFile << p->getName() << "\n" << p->getLevel() << "\n" << p->getClass() << "\n" << p->getGold() << "\n" << p->getHealth() << p->getStamina() << p->getMagicka() << p->getAttackDamage() << endl;
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
			p->setHealth(line)
		}

		else if (lineCount == 7) {
			p->setStamina(line);
		}

		else if (lineCount == 8) {
			p->setMagicka(line);
		}

		else if (lineCount == 9) {
			p->setAttackDamage(line);
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
			p.setHealth(stoi(line));
		}

		else if (lineCount == 7) {
			p.setStamina(stoi(line));
		}

		else if (lineCount == 8) {
			p.setMagicka(stoi(line))
		}

		else if (lineCount == 9) {
			p.setAttackDamage(stoi(line))
		}
	}

}

static void saveGameNoPointer(player& p) {
	ofstream saveFile("gameData.txt");
	saveFile << p.getName() << "\n" << p.getLevel() << "\n" << p.getClass() << "\n" << p.getGold() << "\n" << p.getHealthPotions() << "\n" << p.getHealth() << "\n" << p.getStamina() << "\n" << p.getMagicka() << "\n" << p.getAttackDamage() << endl;
	saveFile.close();
}

