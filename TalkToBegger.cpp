#include "TalkToBegger.h"

TalkToBegger::TalkToBegger() 
{
	description = "Talk to beggar";
}

void TalkToBegger::execute()
{
	RoadsideBeggar pete("Pete the Beggar");
	pete.printDialogue(0);
}
