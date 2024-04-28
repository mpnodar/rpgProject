#include "PathThroughWoods.h"
#include "MoveTo.h"

PathThroughWoods::PathThroughWoods(GameMap* m) : Location(m)
{
	description = "You see a man chopping some logs by a cabin in the woods just beyond the path.";
	
	probabilityOfMonsterEncounter = 1;

	TalkToWoodsman* talkToMike = new TalkToWoodsman();
	actions.push_back(talkToMike);

	MoveTo* moveToRoadToWoods = new MoveTo();
	moveToRoadToWoods->description = "Move west back to road outside of town";
	moveToRoadToWoods->moveToLocation = "RoadToWoods";
	moveToRoadToWoods->gameMap = m;
	actions.push_back(moveToRoadToWoods);

	MoveTo* moveToOrcCamp = new MoveTo();
	moveToOrcCamp->description = "Move off path to the left";
	moveToOrcCamp->moveToLocation = "OrcCamp";
	moveToOrcCamp->gameMap = m;
	actions.push_back(moveToOrcCamp);

	MoveTo* moveToShadyPeople = new MoveTo();
	moveToShadyPeople->description = "Move off path to the right";
	moveToShadyPeople->moveToLocation = "ShadyPeople";
	moveToShadyPeople->gameMap = m;
	actions.push_back(moveToShadyPeople);

	MoveTo* moveToBeast = new MoveTo();
	moveToBeast->description = "Follow the path";
	moveToBeast->moveToLocation = "Beast";
	moveToBeast->gameMap = m;
	actions.push_back(moveToBeast);

	addGameMenu();
}
