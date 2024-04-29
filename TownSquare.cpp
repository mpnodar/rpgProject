#include "TownSquare.h"
#include "MoveTo.h"
TownSquare::TownSquare(GameMap* m) : Location(m){
	description = "The town square is busling with life, but you see someone on their knees begging the guards for something.";

	TalkToCitizen* talkCitizen = new TalkToCitizen();
	actions.push_back(talkCitizen);

	MoveTo* moveToArmorer = new MoveTo();
	moveToArmorer->description = "Enter armorer's store";
	moveToArmorer->moveToLocation = "Armorer";
	moveToArmorer->gameMap = m;
	actions.push_back(moveToArmorer);

	MoveTo* moveToMerchant = new MoveTo();
	moveToMerchant->description = "Enter merchant's store";
	moveToMerchant->moveToLocation = "Merchant";
	moveToMerchant->gameMap = m;
	actions.push_back(moveToMerchant);

	MoveTo* moveToRoadToWoods = new MoveTo();
	moveToRoadToWoods->description = "Move east to woods";
	moveToRoadToWoods->moveToLocation = "RoadToWoods";
	moveToRoadToWoods->gameMap = m;
	actions.push_back(moveToRoadToWoods);

	addGameMenu();
}

