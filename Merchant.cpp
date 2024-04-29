#include "Merchant.h"
#include "MoveTo.h"

Merchant::Merchant(GameMap* m) : Location(m){
	description = "You find an empty shop.";

	probabilityOfMonsterEncounter = 0.01;

	MoveTo* moveToTownSquare = new MoveTo();
	moveToTownSquare->description = "Leave";
	moveToTownSquare->moveToLocation = "TownSquare";
	moveToTownSquare->gameMap = m;
	actions.push_back(moveToTownSquare);

	addGameMenu();
}