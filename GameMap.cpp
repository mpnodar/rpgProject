#include "GameMap.h"


/* int randintNearLevel(int target, int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	int mean = target;
	int stddev = (max - min) / 3;
	stddev = stddev < 1 ? 1 : stddev;
	std::normal_distribution<> distrib(mean, stddev);
	int result;
	do {
		result = distrib(gen);
	} while (result < min || result > max);
	return result;
} */



GameMap::GameMap()
{
	questDefeatOrcs = new QuestDefeatOrcs();

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
	HT->add(new hashNode("RoadToWoods", {"Goblin", "Orc"}));
	HT->add(new hashNode("ShadyPeople", {"Bandit"}));
	HT->add(new hashNode("Beast", {}));
	HT->add(new hashNode("OrcCamp", {"Orc"}));
	HT->add(new hashNode("PathThroughWoods", {"Goblin", "Orc", "Bandit" }));
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
	delete questDefeatOrcs;
}

void GameMap::play(player* p)
{
	user = p;
	locations["TownSquare"]->execLocation(p);
}

enemy* GameMap::getRandomMonster(std::string locationName) {

	int randLevel = battleSequence::randintNear(user->getLevel(), 1, (user->getLevel() + 20));

	hashNode* monsterNode = HT->search(locationName);
	if (monsterNode->getData().size() == 0) {
		return nullptr;
	}
	else {
		int randomNumber = rand() % monsterNode->getData().size();
		std::string monster = monsterNode->getData()[randomNumber];
		if (monster == "Goblin") {
			enemy* m = new goblin(randLevel);
			return m;
		}
		else if (monster == "Orc") {
			enemy* m = new orc(randLevel);
			return m;
		}
		else if (monster == "Bandit") {
			enemy* m = new bandit(randLevel);
			return m;
		}
		enemy* m = new wraith(randLevel);
		return m;
	}
	return nullptr;
}
