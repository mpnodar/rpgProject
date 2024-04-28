#include "Location.h"
#include "MoveTo.h"
#include "GameMenuAction.h"

void Location::addGameMenu()
{
	actions.push_back(&menuAction);
}

void Location::execLocation(player* p)
{
	bool isMoveTo = false;
	int userInput;
	do{
		std::cout << "\n" << description << "\n";
		int numOfAction = 1;
		for (auto a : actions) {
			std::cout << numOfAction++ << ". " << a->description << "\n";
		}
		std::cout << "Make selection:\n";
		std::cin >> userInput;
		actions[userInput - 1]->execute(p);
		isMoveTo = typeid(*actions[userInput - 1]) == typeid(MoveTo);
	} while (!isMoveTo);
}

Location::Location(GameMap* m)
{
	gameMap = m;

}
