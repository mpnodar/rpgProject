#include "TalkToCitizen.h"

TalkToCitizen::TalkToCitizen()
{
	description = "Talk to Citizen";
}

ActionResponse TalkToCitizen::execute(player* p)
{
	ManChoppingWood dave("Dave the Wood Chopper");
	return dave.printDialogue(0);
}
