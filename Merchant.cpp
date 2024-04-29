#include "Merchant.h"
#include "MoveTo.h"
#include "ShoppingAction.h"
#include "shop.h"

Merchant::Merchant(GameMap* m) : Location(m){
	description = "You enter the store and find many goods layed out in an orderly fashion.";

	probabilityOfMonsterEncounter = 0.01;

	ShoppingAction* buy = new ShoppingAction();
	buy->description = "Browse goods";
	shop* store = new shop();
	buy->setShop(store);
	actions.push_back(buy);

	MoveTo* moveToTownSquare = new MoveTo();
	moveToTownSquare->description = "Leave";
	moveToTownSquare->moveToLocation = "TownSquare";
	moveToTownSquare->gameMap = m;
	actions.push_back(moveToTownSquare);

	addGameMenu();
}