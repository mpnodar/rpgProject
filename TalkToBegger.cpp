#include "TalkToBegger.h"
#include "GameMap.h"

TalkToBegger::TalkToBegger(GameMap* gm) : Action(gm)
{
	description = "Talk to beggar";
}

ActionResponse TalkToBegger::execute(player* p)
{
	RoadsideBeggar pete("Pete the Beggar", gameMap);
	ActionResponse AR = pete.printDialogue(0);
	if (AR == AcceptQuest) {
		gameMap->questHelpBeggar->AcceptedQuest = true;
	}
	if (AR == AbandonedQuest) {
		gameMap->questHelpBeggar->QuestCompleted = true;
		p->setName(p->getName() + " the Horrible");
	}
	if (AR == CompletedQuest) {
		gameMap->questHelpBeggar->QuestCompleted = true;
		p->setName("Good Mayor " + p->getName());
		p->getInventory().getItemByName("Gold")->quantity -= 500;
	}
	return AR;
}
