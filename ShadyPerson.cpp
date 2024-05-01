#include "ShadyPerson.h"

ShadyPerson::ShadyPerson(std::string name, GameMap* gm) : TalkingNPC(5, name, gm)
{
	dialogueTree[0] = new DialogueNode("Stop starin' and keep movin'.\n",
		"1. What are you doing just sitting in the woods?\n2. I will not be told what to do!\n3. Leave.\n",
		{ 1, 2, Ended });
	dialogueTree[1] = new DialogueNode("It aint none of your buisness.\n",
		"1. I must know if any crime is being commited. \n2. You are clearly up to something. Prepare for combat!\n3. Leave.\n",
		{ 3, Attack, Ended });
	dialogueTree[2] = new DialogueNode("If you don't move we'll just make ya move!\n",
		"1. Fight\n2. Run Away\n",
		{ Attack, Ended });
	dialogueTree[3] = new DialogueNode("What makes you think we'll tell ya if we be doing a crime.\n",
		"1. I don't know I thought that you simply would tell me.\n2. Enough talking, it's time to fight!\n3. Leave.\n",
		{ 4, Attack, Ended });
	dialogueTree[4] = new DialogueNode("Well if ya simply have to know then we be simple travelers restin in the shade.\n",
		"1. I see then have a good day.\n2. You are too shady I will simply have to take you in by force!\n",
		{ Ended, Attack });
}
