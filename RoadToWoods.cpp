#include "RoadToWoods.h"
#include "MoveTo.h"

RoadToWoods::RoadToWoods(GameMap* m) : Location(m)
{
	generateActions();
}

void RoadToWoods::generateActions()
{
	clearActions();
	description = "Traveling along the bustling road you see a man on the side of the road begging for money.";

	probabilityOfMonsterEncounter = 0.2;

	TalkToBegger* talkingBegger = new TalkToBegger(gameMap);
	actions->push_back(talkingBegger);

	MoveTo* moveToTownSquare = new MoveTo(gameMap);
	moveToTownSquare->description = "Move west to Town Square";
	moveToTownSquare->moveToLocation = "TownSquare";
	actions->push_back(moveToTownSquare);

	MoveTo* moveToPathThroughWoods = new MoveTo(gameMap);
	moveToPathThroughWoods->description = "Follow the path";
	moveToPathThroughWoods->moveToLocation = "PathThroughWoods";
	actions->push_back(moveToPathThroughWoods);

	addGameMenu();
}
