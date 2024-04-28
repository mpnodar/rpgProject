#include "Citizen.h"

Citizen::Citizen(std::string name) : TalkingNPC(4, name)
{
	dialogueTree[0] = new DialogueNode("HELP! HELP!\n",
		"1. What is wrong?\n2. What are you blabbering about!\n3. Leave.\n",
		{ 1, 1, Ended });
	dialogueTree[1] = new DialogueNode("My friend was attacked by the beast!\n",
		"1. A beast?\n2. Where is your friend?\n3. Leave.\n",
		{ 2, 3, Ended });
	dialogueTree[2] = new DialogueNode("Yes just outside of town to the east there is a great beast and we were attack suddenly! Hurry he needs aid!\n",
		"1. I fight the beast off!\n2. Leave me out of this.\n",
		{ AcceptQuest, Ended });
	dialogueTree[3] = new DialogueNode("We were traveling peacefully to this town when we were attacked! I ran quickly for help and I had though my friend was close behind me but when I looked back he was gone! The beast is to the east just out side of town!\n",
		"1. I will fight the beast off!\n2. Leave me out of this.\n",
		{ AcceptQuest, Ended });
}
