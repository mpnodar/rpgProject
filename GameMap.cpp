#include "GameMap.h"

GameMap::GameMap()
{
	locations["TownSquare"] = new TownSquare(this);
	locations["Merchant"] = new Merchant(this);
	locations["RoadToWoods"] = new RoadToWoods(this);
	locations["ShadyPeople"] = new ShadyPeople(this);
	locations["Beast"] = new Beast(this);
	locations["OrcCamp"] = new OrcCamp(this);
	locations["PathThroughWoods"] = new PathThroughWoods(this);

	HT->add(new hashNode("TownSquare", {}));
	HT->add(new hashNode("Merchant", {}));
	HT->add(new hashNode("RoadToWoods", {"Goblin"}));
	HT->add(new hashNode("ShadyPeople", {}));
	HT->add(new hashNode("Beast", {"Wraith"}));
	HT->add(new hashNode("OrcCamp", {"Orc"}));
	HT->add(new hashNode("PathThroughWoods", {"Goblin", "Orc"}));
}

GameMap::~GameMap()
{
	delete locations["TownSquare"];
	delete locations["Merchant"];
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
		enemy* m = new wraith(user->getLevel());
		return m;
	}
	return nullptr;
}
