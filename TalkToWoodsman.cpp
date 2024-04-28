#include "TalkToWoodsman.h"

TalkToWoodsman::TalkToWoodsman()
{
	description = "Talk to woodsman";
}

ActionResponse TalkToWoodsman::execute(player* p)
{
	ManChoppingWood* mike = new ManChoppingWood("Mike the woodsman");
	return mike->printDialogue(0);
}
