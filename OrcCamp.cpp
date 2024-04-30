#include "OrcCamp.h"
#include "EnemyAttackAction.h"
#include "characters.h"

OrcCamp::OrcCamp(GameMap* m) : Location(m)
{

	int randLevel = battleSequence::randintNear(10, 1, 20);


	description = "Wandering through the woods you stumble upon a camp of orcs. There seems to be a fight between two orcs.";

	probabilityOfMonsterEncounter = 0.05;

	EnemyAttackAction* attackMonster = new EnemyAttackAction();
	attackMonster->description = "Join brawl";
	enemy* monster = new orc(randLevel);
	attackMonster->setEnemy(monster);
	actions.push_back(attackMonster);

	MoveTo* moveToPathThroughWoods = new MoveTo();
	moveToPathThroughWoods->description = "Return to path";
	moveToPathThroughWoods->moveToLocation = "PathThroughWoods";
	moveToPathThroughWoods->gameMap = m;
	actions.push_back(moveToPathThroughWoods);

	addGameMenu();
}
