#include "TalkingNPC.h"

DialogueResponse TalkingNPC::printDialogue(int currentDialogue)
{
	std::cout << "\n" << name << " says: ";
	std::cout << dialogueTree[currentDialogue]->NPCDialogue << "\nSelect response:\n";
	std::cout << dialogueTree[currentDialogue]->playerChoices;
	int response;
	std::cin >> response;
	if (response > dialogueTree[currentDialogue]->nextDialogues.size()) return Ended;
	int nextDialoguesIndex = dialogueTree[currentDialogue]->nextDialogues[response - 1];
	if (nextDialoguesIndex < 0) return (DialogueResponse)nextDialoguesIndex;
	return printDialogue(nextDialoguesIndex);
}

TalkingNPC::TalkingNPC(int treeSize, std::string npcName)
{
	dialogueTree = std::vector<DialogueNode*>(treeSize);
	name = npcName;
}

TalkingNPC::~TalkingNPC()
{
	for (auto d : dialogueTree) {
		delete d;
	}
}