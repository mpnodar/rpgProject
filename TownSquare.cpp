#include "TownSquare.h"
#include "MoveTo.h"
#include "GameMap.h"

TownSquare::TownSquare(GameMap* m) : Location(m){
	generateActions();
}

void TownSquare::generateActions()
{
	clearActions();
	if (gameMap->questDefeatBeast->QuestCompleted) {
		description = "The town square is bustling with life and you see a happy looking citizen hugging his friend.";
	}
	else {
		description = "The town square is bustling with life, but you see someone on their knees begging the guards for something.";
	}

	TalkToCitizen* talkCitizen = new TalkToCitizen(gameMap);
	actions->push_back(talkCitizen);

	MoveTo* moveToArmorer = new MoveTo(gameMap);
	moveToArmorer->description = "Enter armorer's store";
	moveToArmorer->moveToLocation = "Armorer";
	actions->push_back(moveToArmorer);

	MoveTo* moveToMerchant = new MoveTo(gameMap);
	moveToMerchant->description = "Enter merchant's store";
	moveToMerchant->moveToLocation = "Merchant";
	actions->push_back(moveToMerchant);

	MoveTo* moveToRoadToWoods = new MoveTo(gameMap);
	moveToRoadToWoods->description = "Move east to woods";
	moveToRoadToWoods->moveToLocation = "RoadToWoods";
	actions->push_back(moveToRoadToWoods);

	addGameMenu();
}

