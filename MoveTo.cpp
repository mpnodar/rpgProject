#include "MoveTo.h"
#include "GameMap.h"
#include <chrono>
#include <thread>
#include "EnemyAttackAction.h"

MoveTo::MoveTo(GameMap* gm) : Action(gm)
{
}

ActionResponse MoveTo::execute(player* p)
{
	int encounterChance = gameMap->locations[moveToLocation]->probabilityOfMonsterEncounter * 100;

	int roll = (rand() % 100) + 1;

	if (roll <= encounterChance) {
		enemy* monster = gameMap->getRandomMonster(moveToLocation);
		if (monster != nullptr) {
			ActionResponse AR;
			EnemyAttackAction attackAction(gameMap);
			attackAction.setEnemy(monster);
			AR = attackAction.execute(p);
			delete monster;
			if (AR == PlayerDied) return AR;
		}
	}

	return gameMap->locations[moveToLocation]->execLocation(p);
}
