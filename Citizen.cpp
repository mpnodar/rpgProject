#include "Citizen.h"
#include "GameMap.h"

Citizen::Citizen(std::string name, GameMap* gm) : TalkingNPC(4, name, gm)
{
	if (!gm->questDefeatOrcs->AcceptedQuest) {
		dialogueTree[0] = new DialogueNode("HELP! HELP!\n",
			"1. What is wrong?\n2. What are you blabbering about!\n3. Leave.\n",
			{ 1, 1, Ended });
		dialogueTree[1] = new DialogueNode("My friend was attacked by an Orc!\n",
			"1. An Orc?\n2. Where is your friend?\n3. Leave.\n",
			{ 2, 3, Ended });
		dialogueTree[2] = new DialogueNode("Yes just outside of town to the east there is an orc camp and we were attacked suddenly! Hurry, he needs aid!\n",
			"1. I will fight the Orc off!\n2. Leave me out of this.\n",
			{ AcceptQuest, Ended });
		dialogueTree[3] = new DialogueNode("We were traveling peacefully to this town when we were attacked! I ran quickly for help and I had thought my friend was close behind me, but when I looked back he was gone! The Orc Camp is to the east just outside of town!\n",
			"1. I will fight the Orc off!\n2. Leave me out of this.\n",
			{ AcceptQuest, Ended });
	}
	else if (gm->questDefeatOrcs->AcceptedQuest && !gm->questDefeatOrcs->QuestCompleted){
		dialogueTree[0] = new DialogueNode("Thank you for helping me! If you need any help talk to the woodsman.\n",
			"1. Leave\n",
			{ Ended });
	}
	else if (!gm->questDefeatOrcs->QuestCompleted && gm->questDefeatOrcs->FoughtOrcs) {
		dialogueTree[0] = new DialogueNode("Thank you for helping me! Here is 100 gp and a health potion as your reward.\n",
			"1. Accept\n",
			{ Ended });
		gm->questDefeatOrcs->QuestCompleted = true;
		gm->user->getInventory().getItemByName("Gold")->quantity += 100;
		gm->user->getInventory().getItemByName("Health Potions")->quantity += 1;
	}


	else if (!gm->questDefeatBeast->AcceptedQuest) {
		dialogueTree[0] = new DialogueNode("Have you heard about the beast?\n",
			"1. The Beast?\n2. What are you blabbering about!\n3. Leave.\n",
			{ 1, 1, Ended });
		dialogueTree[1] = new DialogueNode("My friend was attacked by the Beast!\n",
			"1. A Beast?\n2. Where is your friend?\n3. Leave.\n",
			{ 2, 3, Ended });
		dialogueTree[2] = new DialogueNode("Yes just outside of town to the east there is a beast and we were attacked suddenly! Hurry, he needs aid!\n",
			"1. I will fight the beast off!\n2. Leave me out of this.\n",
			{ AcceptQuest, Ended });
		dialogueTree[3] = new DialogueNode("We were traveling peacefully to this town when we were attacked! I ran quickly for help and I had thought my friend was close behind me, but when I looked back he was gone! The beast is to the east just outside of town!\n",
			"1. I will fight the beast off!\n2. Leave me out of this.\n",
			{ AcceptQuest, Ended });
	}
	else if (gm->questDefeatBeast->AcceptedQuest && !gm->questDefeatBeast->FoughtBeast) {
		dialogueTree[0] = new DialogueNode("Thank you for helping me! If you need any help talk to the woodsman.\n",
			"1. Leave\n",
			{ Ended });
	}
	else if (!gm->questDefeatBeast->QuestCompleted && gm->questDefeatBeast->FoughtBeast) {
		dialogueTree[0] = new DialogueNode("Thank you for helping me! Here is 100 gp as your reward. And here is an extra 200 gp as your reward for helping me twice.\n",
			"1. Accept\n",
			{ Ended });
		gm->questDefeatBeast->QuestCompleted = true;
		gm->user->getInventory().getItemByName("Gold")->quantity += 300;
	}
	else {
		dialogueTree[0] = new DialogueNode("Thank you for helping me! Your such a great citizen that I will be voting you for mayor.\n",
			"1. Accept\n",
			{ Ended });
	}
}
