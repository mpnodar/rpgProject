#include "Beast.h"

Beast::Beast(GameMap* m) : Location(m)
{
	description = "You follow the path into the woods and find resting on a big rock is a great beast. It sees you and enters into combat.";

	//TODO Enter battle with beast

	MoveTo* moveToPathThroughWoods = new MoveTo();
	moveToPathThroughWoods->description = "Return to previous part of path";
	moveToPathThroughWoods->moveToLocation = "PathThroughWoods";
	moveToPathThroughWoods->gameMap = m;
	actions.push_back(moveToPathThroughWoods);

	MoveTo* moveToOrcCamp = new MoveTo();
	moveToOrcCamp->description = "Move off path to left";
	moveToOrcCamp->moveToLocation = "OrcCamp";
	moveToOrcCamp->gameMap = m;
	actions.push_back(moveToOrcCamp);

	addGameMenu();
}
