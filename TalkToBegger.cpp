#include "TalkToBegger.h"

TalkToBegger::TalkToBegger(GameMap* gm) : Action(gm)
{
	description = "Talk to beggar";
}

ActionResponse TalkToBegger::execute(player* p)
{
	RoadsideBeggar pete("Pete the Beggar", gameMap);
	return pete.printDialogue(0);
}
