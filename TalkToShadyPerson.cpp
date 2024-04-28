#include "TalkToShadyPerson.h"

TalkToShadyPerson::TalkToShadyPerson()
{
	description = "Talk to shady person";
}

ActionResponse TalkToShadyPerson::execute(player* p)
{
	ShadyPerson jerald("Jerald the shady");
	return jerald.printDialogue(0);
}
