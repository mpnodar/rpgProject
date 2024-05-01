#include "TownSquare.h"
#include "MoveTo.h"
TownSquare::TownSquare(GameMap* m) : Location(m){
	description = "The town square is bustling with life, but you see someone on their knees begging the guards for something.";

	TalkToCitizen* talkCitizen = new TalkToCitizen(m);
	actions->push_back(talkCitizen);

	MoveTo* moveToArmorer = new MoveTo(m);
	moveToArmorer->description = "Enter armorer's store";
	moveToArmorer->moveToLocation = "Armorer";
	actions->push_back(moveToArmorer);

	MoveTo* moveToMerchant = new MoveTo(m);
	moveToMerchant->description = "Enter merchant's store";
	moveToMerchant->moveToLocation = "Merchant";
	actions->push_back(moveToMerchant);

	MoveTo* moveToRoadToWoods = new MoveTo(m);
	moveToRoadToWoods->description = "Move east to woods";
	moveToRoadToWoods->moveToLocation = "RoadToWoods";
	actions->push_back(moveToRoadToWoods);

	addGameMenu();
}

void TownSquare::generateActions()
{
	clearActions();
	description = "The town square is bustling with life, but you see someone on their knees begging the guards for something.";

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

