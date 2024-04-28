#include "Location.h"
#include "MoveTo.h"
#include "GameMenuAction.h"

void Location::addGameMenu()
{
	actions.push_back(&menuAction);
}

ActionResponse Location::execLocation(player* p)
{
	int userInput;
	ActionResponse AR;
	do{
		std::cout << "\n" << description << "\n";
		int numOfAction = 1;
		for (auto a : actions) {
			std::cout << numOfAction++ << ". " << a->description << "\n";
		}
		std::cout << "Make selection:\n";
		std::cin >> userInput;
		AR = actions[userInput - 1]->execute(p);
	} while (AR != Move and AR != QuitGame);

	return AR;
}

Location::Location(GameMap* m)
{
	gameMap = m;

}
