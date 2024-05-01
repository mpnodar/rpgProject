#include "Beast.h"
#include "characters.h"
#include "EnemyAttackAction.h"
#include "GameMap.h"

Beast::Beast(GameMap* m) : Location(m)
{
	generateActions();
}

void Beast::generateActions()
{
	clearActions();
	if (!gameMap->questDefeatBeast->FoughtBeast) {
		description = "You follow the path into the woods and find resting on a big rock is a great beast.";
	}
	else {
		description = "The woods are quiet now that the beast is gone.";
	}

	if (!gameMap->questDefeatBeast->FoughtBeast) {
		EnemyAttackAction* attackMonster = new EnemyAttackAction(gameMap);
		attackMonster->isBeastQuest = true;
		attackMonster->description = "Fight beast";
		enemy* monster = new wraith(1);
		attackMonster->setEnemy(monster);
		actions->push_back(attackMonster);
	}

	MoveTo* moveToPathThroughWoods = new MoveTo(gameMap);
	moveToPathThroughWoods->description = "Return to previous part of path";
	moveToPathThroughWoods->moveToLocation = "PathThroughWoods";
	actions->push_back(moveToPathThroughWoods);

	MoveTo* moveToOrcCamp = new MoveTo(gameMap);
	moveToOrcCamp->description = "Move off path to left";
	moveToOrcCamp->moveToLocation = "OrcCamp";
	actions->push_back(moveToOrcCamp);

	addGameMenu();
}
