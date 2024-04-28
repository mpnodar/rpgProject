#include "TalkToBegger.h"

TalkToBegger::TalkToBegger() 
{
	description = "Talk to beggar";
}

void TalkToBegger::execute(player* p)
{
	RoadsideBeggar pete("Pete the Beggar");
	pete.printDialogue(0);
}
