#include "TownSquare.h"
#include "MoveTo.h"
TownSquare::TownSquare(GameMap* m) : Location(m){
	description = "The town square is busling with life, but you see someone on their knees begging the guards for something.";

	TalkToCitizen* talkCitizen = new TalkToCitizen();
	actions.push_back(talkCitizen);
	MoveTo* moveToMerchant = new MoveTo();
	moveToMerchant->description = "Move north to merchant";
	moveToMerchant->moveToLocation = "Merchant";
	moveToMerchant->gameMap = m;
	actions.push_back(moveToMerchant);
}

