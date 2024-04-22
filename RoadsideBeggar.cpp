#include "RoadsideBeggar.h"

RoadsideBeggar::RoadsideBeggar(std::string name) : TalkingNPC(6, name)
{
	dialogueTree[0] = new DialogueNode("Spare some change for an old beggar?\n",
		"1. Here is all I can spare.\n2. Hit the Road.\n3. Sorry I'm all out of gold.\n", 
		{1, 2, 3});
	dialogueTree[1] = new DialogueNode("Is that really it?!\n",
		"1. You dare say that to me?!\n2. That is all I have.\n",
		{4, -1});
	dialogueTree[2] = new DialogueNode("How can you be so cruel to a poor beggar?\n",
		"1. I don't have time for this!\n2. Oh fine here's some cash.\n",
		{-1, 5});
	dialogueTree[3] = new DialogueNode("But I can see your gold pouch is full and heavy.\n",
		"1. You see nothing.\n2. Oh fine here's some cash.\n",
		{ 2, 5 });
	dialogueTree[4] = new DialogueNode("Yes I dare give me more money!\n",
		"1. I don't have time for this!\n2. Oh fine here's some cash.\n",
		{ -1, 5 });
	dialogueTree[5] = new DialogueNode("Thank you master.\n",
		"1. [Leave]\n",
		{ -1});
}