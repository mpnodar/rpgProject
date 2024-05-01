#include "TalkToCitizen.h"
#include "GameMap.h"

TalkToCitizen::TalkToCitizen(GameMap* gm) : Action(gm)
{
	description = "Talk to Citizen";
}

ActionResponse TalkToCitizen::execute(player* p)
{
	Citizen dave("Dave the panicked", gameMap);
	ActionResponse AR = dave.printDialogue(0);
	if (AR == AcceptQuest) {
		if (!gameMap->questDefeatOrcs->AcceptedQuest) {
			gameMap->questDefeatOrcs->AcceptedQuest = true;
		}
	}
	return AR;
}
