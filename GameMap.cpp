#include "GameMap.h"

GameMap::GameMap()
{
	locations["TownSquare"] = new TownSquare(this);
	locations["Merchant"] = new Merchant(this);
	locations["Armorer"] = new Armorer(this);
	locations["RoadToWoods"] = new RoadToWoods(this);
	locations["ShadyPeople"] = new ShadyPeople(this);
	locations["Beast"] = new Beast(this);
	locations["OrcCamp"] = new OrcCamp(this);
	locations["PathThroughWoods"] = new PathThroughWoods(this);

	HT->add(new hashNode("TownSquare", {}));
	HT->add(new hashNode("Merchant", {"Bandit"}));
	HT->add(new hashNode("Armorer", {}));
	HT->add(new hashNode("RoadToWoods", {"Goblin", "Orc", "Bandit"}));
	HT->add(new hashNode("ShadyPeople", {"Bandit"}));
	HT->add(new hashNode("Beast", {}));
	HT->add(new hashNode("OrcCamp", {"Orc"}));
	HT->add(new hashNode("PathThroughWoods", {"Goblin", "Orc"}));
}

GameMap::~GameMap()
{
	delete locations["TownSquare"];
	delete locations["Merchant"];
	delete locations["Armorer"];
	delete locations["RoadToWoods"];
	delete locations["ShadyPeople"];
	delete locations["Beast"];
	delete locations["OrcCamp"];
	delete locations["PathThroughWoods"];
	delete HT;
}

void GameMap::play(player* p)
{
	user = p;
	locations["TownSquare"]->execLocation(p);
}

enemy* GameMap::getRandomMonster(std::string locationName)
{
	hashNode* monsterNode = HT->search(locationName);
	if (monsterNode->getData().size() == 0) {
		return nullptr;
	}
	else {
		int randomNumber = rand() % monsterNode->getData().size();
		std::string monster = monsterNode->getData()[randomNumber];
		if (monster == "Goblin") {
			enemy* m = new goblin(user->getLevel());
			return m;
		}
		else if (monster == "Orc") {
			enemy* m = new orc(user->getLevel());
			return m;
		}
		else if (monster == "Bandit") {
			enemy* m = new bandit(user->getLevel());
			return m;
		}
		enemy* m = new wraith(user->getLevel());
		return m;
	}
	return nullptr;
}
