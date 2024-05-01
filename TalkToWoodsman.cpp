#include "TalkToWoodsman.h"
#include "GameMap.h"

TalkToWoodsman::TalkToWoodsman(GameMap* gm) : Action(gm)
{
	description = "Talk to woodsman";
}

ActionResponse TalkToWoodsman::execute(player* p)
{
	ManChoppingWood* mike = new ManChoppingWood("Mike the woodsman", gameMap);
	ActionResponse AR = mike->printDialogue(0);
	if (AR == RecievedDirections) {
		if (!gameMap->questDefeatOrcs->QuestCompleted) {
			gameMap->questDefeatOrcs->SpokeWithWoodsman = true;
		}
		else {
			gameMap->questDefeatBeast->SpokeWithWoodsman = true;
		}
	}
	return AR;
}
