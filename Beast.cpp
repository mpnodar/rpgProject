#include "Beast.h"
#include "characters.h"
#include "EnemyAttackAction.h"

Beast::Beast(GameMap* m) : Location(m)
{
	description = "You follow the path into the woods and find resting on a big rock is a great beast.";

	EnemyAttackAction* attackMonster = new EnemyAttackAction(m);
	attackMonster->description = "Fight beast";
	enemy* monster = new wraith(15);
	attackMonster->setEnemy(monster);
	actions->push_back(attackMonster);

	MoveTo* moveToPathThroughWoods = new MoveTo(m);
	moveToPathThroughWoods->description = "Return to previous part of path";
	moveToPathThroughWoods->moveToLocation = "PathThroughWoods";
	actions->push_back(moveToPathThroughWoods);

	MoveTo* moveToOrcCamp = new MoveTo(m);
	moveToOrcCamp->description = "Move off path to left";
	moveToOrcCamp->moveToLocation = "OrcCamp";
	actions->push_back(moveToOrcCamp);

	addGameMenu();
}

void Beast::generateActions()
{
}
