#include "TalkToCitizen.h"

TalkToCitizen::TalkToCitizen()
{
	description = "Talk to Citizen";
}

void TalkToCitizen::execute(player* p)
{
	ManChoppingWood dave("Dave the Wood Chopper");
	dave.printDialogue(0);
}
