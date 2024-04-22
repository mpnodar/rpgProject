#include "TalkToCitizen.h"

TalkToCitizen::TalkToCitizen()
{
	description = "Talk to Citizen";
}

void TalkToCitizen::execute()
{
	ManChoppingWood dave("Dave the Wood Chopper");
	dave.printDialogue(0);
}
