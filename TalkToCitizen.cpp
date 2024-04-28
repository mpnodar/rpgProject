#include "TalkToCitizen.h"

TalkToCitizen::TalkToCitizen()
{
	description = "Talk to Citizen";
}

ActionResponse TalkToCitizen::execute(player* p)
{
	Citizen dave("Dave the panicked");
	return dave.printDialogue(0);
}
