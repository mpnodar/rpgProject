#include <fstream>
#include <iostream>
#include "saveFunctions.h"


void saveGamePointer(player* p) {
	ofstream saveFile("gameData.txt");
	saveFile << p->getName() << "\n" << p->getLevel() << "\n" << p->getClass() << "\n" << p->getGold() << "\n" << p->getHealthPotions() << endl;
	saveFile.close();
}

void loadGamePointer(player* p) {
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


	}

}

void saveGameNoPointer(player& p) {
	ofstream saveFile("gameData.txt");
	saveFile << p.getName() << "\n" << p.getLevel() << "\n" << p.getClass() << "\n" << p.getGold() << "\n" << p.getHealthPotions() << endl;
	saveFile.close();
}

void loadGameNoPointer(player& p) {
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


	}

}