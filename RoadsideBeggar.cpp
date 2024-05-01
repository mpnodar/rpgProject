#include "RoadsideBeggar.h"
#include "GameMap.h"

RoadsideBeggar::RoadsideBeggar(std::string name, GameMap* gm) : TalkingNPC(6, name, gm)
{
	if (!gm->questHelpBeggar->AcceptedQuest) {
		dialogueTree[0] = new DialogueNode("Spare some change for an old beggar?\n",
			"1. Here is all I can spare.\n2. Hit the Road.\n3. Sorry I'm all out of gold.\n",
			{ 1, 2, 3 });
		dialogueTree[1] = new DialogueNode("Is that really it?!\n",
			"1. You dare say that to me?!\n2. That is all I have.\n",
			{ 4, 5 });
		dialogueTree[2] = new DialogueNode("How can you be so cruel to a poor beggar?\n",
			"1. I don't have time for this!\n2. Oh fine here's some cash.\n",
			{ Ended, 5 });
		dialogueTree[3] = new DialogueNode("But I can see your gold pouch is full and heavy.\n",
			"1. You see nothing.\n2. Oh fine, here's some cash.\n",
			{ 2, 5 });
		dialogueTree[4] = new DialogueNode("Yes I dare! Give me more money!\n",
			"1. I don't have time for this!\n2. Oh fine, here's some cash.\n",
			{ Ended, 5 });
		dialogueTree[5] = new DialogueNode("Thank you, mister your such a nice man all of my money was stolen by some shady characters. If you would defeat them and return my money I'm sure fortune would smile upon you.\n",
			"1. Leave\n",
			{ AcceptQuest });
	}
	else if (gm->questHelpBeggar->AcceptedQuest && !gm->questHelpBeggar->RecievedMoney){
		dialogueTree[0] = new DialogueNode("Those shady people are up the road.\n",
			"1. Leave\n",
			{ Ended});
	}
	else {
		dialogueTree[0] = new DialogueNode("Thank you for defeating the shady people will you please return my money?\n",
			"1. Here ya go bud.\n2. I think I'll just keep it.\n",
			{ 1, 2 });
		dialogueTree[1] = new DialogueNode("Thank you I happen to be the mayor and for your generosity I dub thee the new mayor!\n",
			"1. Complete Quest\n",
			{ CompletedQuest });
		dialogueTree[2] = new DialogueNode("You're horrible.\n",
			"1. Complete Quest\n",
			{ AbandonedQuest });
	}
}
