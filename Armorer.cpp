#include "Armorer.h"
#include "MoveTo.h"
#include "ShoppingAction.h"
#include "shop.h"

Armorer::Armorer(GameMap* m) : Location(m) {
	description = "In the armorer's store you find the weapons are lining the walls on all sides.";

	probabilityOfMonsterEncounter = 0;

	ShoppingAction* buy = new ShoppingAction(m);
	buy->description = "Browse goods";
	shop* store = new shop();
	store->isArmorer = true;
	buy->setShop(store);
	actions->push_back(buy);

	MoveTo* moveToTownSquare = new MoveTo(m);
	moveToTownSquare->description = "Leave";
	moveToTownSquare->moveToLocation = "TownSquare";
	actions->push_back(moveToTownSquare);

	addGameMenu();
}

void Armorer::generateActions()
{
}
