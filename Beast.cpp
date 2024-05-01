#include "Beast.h"
#include "characters.h"
#include "EnemyAttackAction.h"

Beast::Beast(GameMap* m) : Location(m)
{
	description = "You follow the path into the woods and find resting on a big rock is a great beast.";

	EnemyAttackAction* attackMonster = new EnemyAttackAction();
	attackMonster->description = "Fight beast";
	enemy* monster = new wraith(15);
	attackMonster->setEnemy(monster);
	actions.push_back(attackMonster);

	MoveTo* moveToPathThroughWoods = new MoveTo();
	moveToPathThroughWoods->description = "Return to previous part of path";
	moveToPathThroughWoods->moveToLocation = "PathThroughWoods";
	moveToPathThroughWoods->gameMap = m;
	actions.push_back(moveToPathThroughWoods);

	MoveTo* moveToOrcCamp = new MoveTo();
	moveToOrcCamp->description = "Move off path to left";
	moveToOrcCamp->moveToLocation = "OrcCamp";
	moveToOrcCamp->gameMap = m;
	actions.push_back(moveToOrcCamp);

	addGameMenu();
}
