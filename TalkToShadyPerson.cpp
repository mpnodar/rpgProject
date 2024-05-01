#include "TalkToShadyPerson.h"
#include "EnemyAttackAction.h"
#include "characters.h"
#include "GameMap.h"

TalkToShadyPerson::TalkToShadyPerson(GameMap* gm) : Action(gm)
{
	description = "Talk to shady person";
}

ActionResponse TalkToShadyPerson::execute(player* p)
{
	ShadyPerson jerald("Jerald the shady", gameMap);
	ActionResponse response = jerald.printDialogue(0);
	if (response == Attack) {
		enemy* shady = new bandit(p->getLevel());
		EnemyAttackAction* Attack = new EnemyAttackAction(gameMap);
		Attack->isBeggarQuest = gameMap->questHelpBeggar->AcceptedQuest && !gameMap->questHelpBeggar->FoughtShadyPeople;
		Attack->setEnemy(shady);
		response = Attack->execute(p);
		
		delete shady;
		delete Attack;
	}
	else if (response == GaveGold) {
		p->getInventory().getItemByName("Gold")->quantity += 500;
		gameMap->questHelpBeggar->RecievedMoney = true;
	}
	return response;
}