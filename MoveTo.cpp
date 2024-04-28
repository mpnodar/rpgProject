#include "MoveTo.h"
#include "GameMap.h"
#include <chrono>
#include <thread>
ActionResponse MoveTo::execute(player* p)
{
	int encounterChance = gameMap->locations[moveToLocation]->probabilityOfMonsterEncounter * 100;

	int roll = (rand() % 100) + 1;

	if (roll <= encounterChance) {
		enemy* monster = gameMap->getRandomMonster(moveToLocation);
		if (monster != nullptr) {
			std::system("cls");
			std::cout << "A " << monster->getName() << " attacks you!";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			battleSequence* b = new battleSequence();
			b->battle(p, monster);
			delete monster;
			delete b;
			if (p->getHealth() <= 0) {
				return PlayerDied;
			}
		}
	}

	return gameMap->locations[moveToLocation]->execLocation(p);
}
