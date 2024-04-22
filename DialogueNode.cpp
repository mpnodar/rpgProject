#include "DialogueNode.h"

DialogueNode::DialogueNode(std::string npcTalk, std::string playerChoiceList, std::vector<int> nextList) {
	NPCDialogue = npcTalk;
	playerChoices = playerChoiceList;
	nextDialogues = nextList;
}