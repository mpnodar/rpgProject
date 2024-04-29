#include "EnemyAttackAction.h"
#include <chrono>
#include <thread>

void EnemyAttackAction::setEnemy(enemy* e)
{
	monster = e;
}

ActionResponse EnemyAttackAction::execute(player* p)
{
	std::system("cls");
	std::cout << monster->getName() << " attacks you!";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	battleSequence* b = new battleSequence();
	
	b->battle(p, monster);
	delete b;
	if (p->getHealth() <= 0) {
		return PlayerDied;
	}
	else if (monster->getHealth() <= 0) {
		return PlayerDefeatedEnemy;
	}
	else {
		return PlayerFled;
	}
}
