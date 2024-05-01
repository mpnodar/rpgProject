#include "ShadyPeople.h"

ShadyPeople::ShadyPeople(GameMap* m) : Location (m)
{
	generateActions();
}

void ShadyPeople::generateActions()
{
	clearActions();
	description = "You move deeper into the woods and see before you some shady people sitting in some shade doing something shady.";

	probabilityOfMonsterEncounter = 0.1;

	TalkToShadyPerson* talkShady = new TalkToShadyPerson(gameMap);
	actions->push_back(talkShady);

	MoveTo* moveToPathThroughWoods = new MoveTo(gameMap);
	moveToPathThroughWoods->description = "Move back to path";
	moveToPathThroughWoods->moveToLocation = "PathThroughWoods";
	actions->push_back(moveToPathThroughWoods);

	MoveTo* moveToTownSquare = new MoveTo(gameMap);
	moveToTownSquare->description = "Return to town";
	moveToTownSquare->moveToLocation = "TownSquare";
	actions->push_back(moveToTownSquare);

	addGameMenu();
}
