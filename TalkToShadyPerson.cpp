#include "TalkToShadyPerson.h"
#include "EnemyAttackAction.h"
#include "characters.h"

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

		Attack->setEnemy(shady);
		response = Attack->execute(p);
		
		delete shady;
		delete Attack;
	}
	return response;
}