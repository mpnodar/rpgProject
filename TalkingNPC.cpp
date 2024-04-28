#include "TalkingNPC.h"
#include <cstdlib>

ActionResponse TalkingNPC::printDialogue(int currentDialogue)
{
	std::system("cls");
	std::cout << "\n" << name << " says: ";
	std::cout << dialogueTree[currentDialogue]->NPCDialogue << "\nSelect response:\n";
	std::cout << dialogueTree[currentDialogue]->playerChoices << "\n:";
	int response;
	std::cin >> response;
	if (response > dialogueTree[currentDialogue]->nextDialogues.size()) return Ended;
	int nextDialoguesIndex = dialogueTree[currentDialogue]->nextDialogues[response - 1];
	if (nextDialoguesIndex < 0) return (ActionResponse)nextDialoguesIndex;
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
