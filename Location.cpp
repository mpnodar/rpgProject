#include "Location.h"

void Location::execLocation()
{
	std::cout << description << "\n";
	int numOfAction = 1;
	for (auto a : actions) {
		std::cout << numOfAction++ << ". " << a->description << "\n";
	}
	std::cout << "Make selection:\n";
	int userInput;
	std::cin >> userInput;
	actions[userInput - 1]->execute();
}

Location::Location(GameMap* m)
{
	gameMap = m;
}

