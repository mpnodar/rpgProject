#include "ShadyPeople.h"

ShadyPeople::ShadyPeople(GameMap* m) : Location (m)
{
	description = "You move deeper into the woods and see before you some shady people sitting in some shade doing something shady.";

	probabilityOfMonsterEncounter = 0.1;

	TalkToShadyPerson* talkShady = new TalkToShadyPerson();
	actions.push_back(talkShady);

	MoveTo* moveToPathThroughWoods = new MoveTo();
	moveToPathThroughWoods->description = "Move back to path";
	moveToPathThroughWoods->moveToLocation = "PathThroughWoods";
	moveToPathThroughWoods->gameMap = m;
	actions.push_back(moveToPathThroughWoods);

	MoveTo* moveToTownSquare = new MoveTo();
	moveToTownSquare->description = "Return to town";
	moveToTownSquare->moveToLocation = "TownSquare";
	moveToTownSquare->gameMap = m;
	actions.push_back(moveToTownSquare);

	addGameMenu();
}
