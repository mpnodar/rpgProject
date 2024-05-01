#include "OrcCamp.h"
#include "EnemyAttackAction.h"
#include "characters.h"

OrcCamp::OrcCamp(GameMap* m) : Location(m)
{

	int randLevel = battleSequence::randintNear(10, 1, 20);


	description = "Wandering through the woods you stumble upon a camp of orcs. There seems to be a fight between two orcs.";

	probabilityOfMonsterEncounter = 0.05;

	EnemyAttackAction* attackMonster = new EnemyAttackAction(m);
	attackMonster->description = "Join brawl";
	enemy* monster = new orc(randLevel);
	attackMonster->setEnemy(monster);
	if (!gameMap->questDefeatOrcs->FoughtOrcs) {
		attackMonster->isOrcQuest = true;
	}
	actions->push_back(attackMonster);

	MoveTo* moveToPathThroughWoods = new MoveTo(m);
	moveToPathThroughWoods->description = "Return to path";
	moveToPathThroughWoods->moveToLocation = "PathThroughWoods";
	actions->push_back(moveToPathThroughWoods);

	addGameMenu();
}

void OrcCamp::generateActions()
{
}
