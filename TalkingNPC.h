#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DialogueNode.h"

enum DialogueResponse {
	Ended = -1,
	GaveGold = -2,
	Attack = -3,
	Purchase = -4,
};

class TalkingNPC
{
public:
	std::string name;
	std::vector<DialogueNode*> dialogueTree;
	DialogueResponse printDialogue(int currentDialogue);
	TalkingNPC(int treeSize, std::string npcName);
	~TalkingNPC();
};