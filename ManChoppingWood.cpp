#include "ManChoppingWood.h"
#include "GameMap.h"

ManChoppingWood::ManChoppingWood(std::string name, GameMap* gm) : TalkingNPC(7, name, gm)
{
	if (!gameMap->questDefeatOrcs->AcceptedQuest) {
		dialogueTree[0] = new DialogueNode("What brings you out here into the woods?\n",
			"1. I am lost could you guide me out of these woods?\n2. It's none of your business.\n",
			{ 1, 2 });
		dialogueTree[1] = new DialogueNode("How could you have gotten lost? We are not that far from the city.\n",
			"1. It's not your business.\n2. I have a terrible sense of direction.\n",
			{ 2, 3 });
		dialogueTree[2] = new DialogueNode("Well I need to know before I can let you go. There have been some shady people around lately.\n",
			"1. I am lost. Could you guide me out of these woods?\n2. What kind of shady people?\n",
			{ 1, 4 });
		dialogueTree[3] = new DialogueNode("If you need to know the road is just that way past the ridge.\n",
			"1. Thank you.\n",
			{ Ended });
		dialogueTree[4] = new DialogueNode("People you don't want to meet.\n",
			"1. I have another question.\n",
			{ 0 });
	}
	else if (gameMap->questDefeatOrcs->AcceptedQuest && !gameMap->questDefeatOrcs->SpokeWithWoodsman) {
		dialogueTree[0] = new DialogueNode("What brings you out here into the woods?\n",
			"1. I am lost could you guide me out of these woods?\n2. I'm out hunting Orcs.\n3. It's none of your business.\n",
			{ 1, 2, 3 });
		dialogueTree[1] = new DialogueNode("How could you have gotten lost? We are not that far from the city.\n",
			"1. It's not your business.\n2. I have a terrible sense of direction.\n",
			{ 3, 4 });
		dialogueTree[2] = new DialogueNode("You're here to fight the Orcs then? If you wish to know I could tell you where he is for a price.\n",
			"1. I don't need your services.\n2. I could use the direction.\n",
			{ Ended, 5 });
		dialogueTree[3] = new DialogueNode("Well I need to know before I can let you go. There have been some shady people around lately.\n",
			"1. I am lost. Could you guide me out of these woods?\n2. I'm out hunting Orcs.\n3. What kind of shady people?\n",
			{ 1, 2, 6 });
		dialogueTree[4] = new DialogueNode("If you need to know the road is just that way past the ridge.\n",
			"1. Thank you.\n",
			{ Ended });
		dialogueTree[5] = new DialogueNode("The Orcs is just over yonder to the left.\n",
			"1. Thank you.\n",
			{ RecievedDirections });
		dialogueTree[6] = new DialogueNode("People you don't want to meet.\n",
			"1. I have another question.\n",
			{ 0 });
	}
	else if (gameMap->questDefeatOrcs->AcceptedQuest && gameMap->questDefeatOrcs->SpokeWithWoodsman && !gameMap->questDefeatOrcs->QuestCompleted) {
		dialogueTree[0] = new DialogueNode("The Orcs are to the left.\n",
			"1. Leave\n",
			{ Ended });
	}
	else if (!gm->questDefeatBeast->AcceptedQuest) {
		dialogueTree[0] = new DialogueNode("Good job with those Orcs.\n",
			"1. Leave\n",
			{ Ended });
	}


	else if (gameMap->questDefeatBeast->AcceptedQuest && !gameMap->questDefeatBeast->SpokeWithWoodsman) {
		dialogueTree[0] = new DialogueNode("What brings you out here into the woods?\n",
			"1. I am lost could you guide me out of these woods?\n2. I'm out hunting the Beast.\n3. It's none of your business.\n",
			{ 1, 2, 3 });
		dialogueTree[1] = new DialogueNode("How could you have gotten lost? We are not that far from the city.\n",
			"1. It's not your business.\n2. I have a terrible sense of direction.\n",
			{ 3, 4 });
		dialogueTree[2] = new DialogueNode("You're here to fight the Beast then? If you wish to know I could tell you where he is for a price.\n",
			"1. I don't need your services.\n2. I could use the direction.\n",
			{ Ended, 5 });
		dialogueTree[3] = new DialogueNode("Well I need to know before I can let you go. There have been some shady people around lately.\n",
			"1. I am lost. Could you guide me out of these woods?\n2. I'm out hunting the Beast.\n3. What kind of shady people?\n",
			{ 1, 2, 6 });
		dialogueTree[4] = new DialogueNode("If you need to know the road is just that way past the ridge.\n",
			"1. Thank you.\n",
			{ Ended });
		dialogueTree[5] = new DialogueNode("If ya wanna find the beast just follow the path.\n",
			"1. Thank you.\n",
			{ RecievedDirections });
		dialogueTree[6] = new DialogueNode("People you don't want to meet.\n",
			"1. I have another question.\n",
			{ 0 });
	}
	else if (gameMap->questDefeatBeast->AcceptedQuest && gameMap->questDefeatBeast->SpokeWithWoodsman && !gameMap->questDefeatBeast->QuestCompleted) {
		dialogueTree[0] = new DialogueNode("The Beast is just up ahead.\n",
			"1. Leave\n",
			{ Ended });
	}
	else {
		dialogueTree[0] = new DialogueNode("Good job with the Beast.\n",
			"1. Leave\n",
			{ Ended });
	}
}
