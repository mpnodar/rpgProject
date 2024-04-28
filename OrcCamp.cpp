#include "OrcCamp.h"

OrcCamp::OrcCamp(GameMap* m) : Location(m)
{
	description = "Wondering through the woods you stubmle apon a camp of orcs. There seems to be a fight between two orcs.";

	//TODO Fight with orcs

	MoveTo* moveToPathThroughWoods = new MoveTo();
	moveToPathThroughWoods->description = "Return to path";
	moveToPathThroughWoods->moveToLocation = "PathThroughWoods";
	moveToPathThroughWoods->gameMap = m;
	actions.push_back(moveToPathThroughWoods);

	addGameMenu();
}
