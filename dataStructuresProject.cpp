#include <iostream>
#include "RoadsideBeggar.h"
#include "TalkingNPC.h"
#include "DialogueNode.h"
#include "ManChoppingWood.h"
#include "TownSquare.h"
#include "Action.h"
#include "TalkingNPC.h"
#include "Location.h"
#include "Merchant.h"
#include "GameMap.h"
#include "gameMenu.h"
#include "characters.h"
#include <iostream>
#include <random>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment (lib, "winmm.lib")

using namespace std;


void selectSound() {
	PlaySound(TEXT("C:/Users/mpnod/OneDrive/Documents/Classes - Spring 2024/PlayerSelect.wav"), NULL, SND_FILENAME | SND_SYNC);
}

void playSelectSound() {
	thread soundThread(selectSound);
	soundThread.detach();
	if (soundThread.joinable()) {
		soundThread.join();
	}
}



static void characterSelect(player& you_) {

	int input;
	string name;

	cout << "Please select your character: \n\n----------------------\n\n1. Warrior\nHealth: 70\nMagicka: 30\nStamina: 60\nAttack Damage: 15" << endl;
	cout << "\n----------------------\n\n2. Mage\nHealth: 40\nMagicka: 90\nStamina: 50\nAttack Damage: 5" << endl;
	cout << "\n----------------------\n\n3. Scout\nHealth: 55\nMagicka: 50\nStamina: 70\nAttack Damage: 9\n\n----------------------\n" << endl;

	cin >> input;

	switch (input) {
	case 1:
		playSelectSound();
		you_.setMaxHealth(70);
		you_.setHealth(70);
		you_.setMaxMagicka(30);
		you_.setMaxStamina(60);
		you_.setStamina(60);
		you_.setAttack(15);
		you_.setClass("Warrior");

		cout << "Please enter a name for your character: ";
		cin >> name;
		you_.setName(name);
		break;
	case 2:
		playSelectSound();
		you_.setMaxHealth(40);
		you_.setHealth(40);
		you_.setMaxMagicka(90);
		you_.setMaxStamina(50);
		you_.setStamina(50);
		you_.setAttack(5);
		you_.setClass("Mage");

		cout << "Please enter a name for your character: ";
		cin >> name;
		you_.setName(name);
		break;


	case 3:
		playSelectSound();
		you_.setMaxHealth(55);
		you_.setHealth(55);
		you_.setMaxMagicka(30);
		you_.setMaxStamina(50);
		you_.setStamina(50);
		you_.setAttack(9);
		you_.setClass("Scout");

		cout << "Please enter a name for your character: ";
		cin >> name;
		playSelectSound();
		you_.setName(name);
		break;


	}

}


int main() {

	srand(time(0));

	player p;

	characterSelect(p);

	/*gameMenu menu;
	menu.menu(&p);*/

	GameMap map;
	map.play(&p); 

	/*RoadsideBeggar jim("Jim");
	jim.printDialogue(0);*/

	/*ManChoppingWood dave("Dave the Wood Chopper");
	dave.printDialogue(0);*/

	/*string name;
	cout << "Please enter your name: ";
	cin >> name;
	cout << "\n\n";*/

	//player you(1, name);

	//menu(you);



	return 0;
}
