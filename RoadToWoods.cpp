#include "RoadToWoods.h"
#include "MoveTo.h"

RoadToWoods::RoadToWoods(GameMap* m) : Location(m)
{
	description = "Traveling along the bustling road you see a man on the side of the road begging for money.";

	TalkToBegger* talkingBegger = new TalkToBegger();
	actions.push_back(talkingBegger);

	MoveTo* moveToTownSquare = new MoveTo();
	moveToTownSquare->description = "Move west to Town Square";
	moveToTownSquare->moveToLocation = "TownSquare";
	moveToTownSquare->gameMap = m;
	actions.push_back(moveToTownSquare);

	MoveTo* moveToPathThroughWoods = new MoveTo();
	moveToPathThroughWoods->description = "Follow the path";
	moveToPathThroughWoods->moveToLocation = "PathThroughWoods";
	moveToPathThroughWoods->gameMap = m;
	actions.push_back(moveToPathThroughWoods);

	addGameMenu();
}
