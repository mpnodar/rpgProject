#include "TalkToBegger.h"

TalkToBegger::TalkToBegger() 
{
	description = "Talk to beggar";
}

ActionResponse TalkToBegger::execute(player* p)
{
	RoadsideBeggar pete("Pete the Beggar");
	return pete.printDialogue(0);
}
