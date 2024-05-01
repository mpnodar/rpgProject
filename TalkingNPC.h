#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DialogueNode.h"
#include "ActionResponse.h"

class GameMap;

class TalkingNPC
{
public:
	std::string name;
	std::vector<DialogueNode*> dialogueTree;
	GameMap* gameMap;
	ActionResponse printDialogue(int currentDialogue);
	TalkingNPC(int treeSize, std::string npcName, GameMap* gm);
	~TalkingNPC();
};