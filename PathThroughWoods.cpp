#include "PathThroughWoods.h"
#include "MoveTo.h"
#include "GameMap.h"

PathThroughWoods::PathThroughWoods(GameMap* m) : Location(m)
{
	generateActions();
}

void PathThroughWoods::generateActions()
{
	clearActions();
	description = "You see a man chopping some logs by a cabin in the woods just beyond the path.";

	probabilityOfMonsterEncounter = 0.35;

	TalkToWoodsman* talkToMike = new TalkToWoodsman(gameMap);
	actions->push_back(talkToMike);

	MoveTo* moveToRoadToWoods = new MoveTo(gameMap);
	moveToRoadToWoods->description = "Move west back to road outside of town";
	moveToRoadToWoods->moveToLocation = "RoadToWoods";
	actions->push_back(moveToRoadToWoods);

	if (gameMap->questDefeatOrcs->SpokeWithWoodsman) {
		MoveTo* moveToOrcCamp = new MoveTo(gameMap);
		moveToOrcCamp->description = "Move off path to the left";
		moveToOrcCamp->moveToLocation = "OrcCamp";
		actions->push_back(moveToOrcCamp);
	}

	MoveTo* moveToShadyPeople = new MoveTo(gameMap);
	moveToShadyPeople->description = "Move off path to the right";
	moveToShadyPeople->moveToLocation = "ShadyPeople";
	actions->push_back(moveToShadyPeople);

	if (gameMap->questDefeatBeast->SpokeWithWoodsman) {
		MoveTo* moveToBeast = new MoveTo(gameMap);
		moveToBeast->description = "Follow the path";
		moveToBeast->moveToLocation = "Beast";
		actions->push_back(moveToBeast);
	}
	
	addGameMenu();
}
