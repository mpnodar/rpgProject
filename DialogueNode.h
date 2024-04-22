#pragma once
#include <string>
#include <vector>

class DialogueNode
{
public:
	std::string NPCDialogue = "";
	std::string playerChoices = "";
	std::vector<int> nextDialogues = {};
	DialogueNode(std::string npcTalk, std::string playerChoiceList, std::vector<int> nextList);

};

