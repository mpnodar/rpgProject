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


int main() {

	player p;

	gameMenu menu;
	menu.menu(&p);

	GameMap map;
	map.play();

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