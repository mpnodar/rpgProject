#include "TalkToShadyPerson.h"
#include "EnemyAttackAction.h"
#include "characters.h"

TalkToShadyPerson::TalkToShadyPerson()
{
	description = "Talk to shady person";
}

ActionResponse TalkToShadyPerson::execute(player* p)
{
	ShadyPerson jerald("Jerald the shady");
	ActionResponse response = jerald.printDialogue(0);
	if (response == Attack) {
		enemy* shady = new bandit(p->getLevel());
		EnemyAttackAction* Attack = new EnemyAttackAction();

		Attack->setEnemy(shady);
		response = Attack->execute(p);
		
		delete shady;
		delete Attack;
	}
	return response;
}