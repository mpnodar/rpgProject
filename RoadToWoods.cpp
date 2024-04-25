#include "RoadToWoods.h"
#include "MoveTo.h"

RoadToWoods::RoadToWoods(GameMap* m) : Location(m)
{
	description = "Traveling along the bustling road you see a man on the side of the road begging for money.";

	TalkToBegger* talkingBegger = new TalkToBegger();
	actions.push_back(talkingBegger);

	MoveTo* townSquare = new MoveTo();
	townSquare->description = "Move west to Town Square";
	townSquare->moveToLocation = "TownSquare";
	townSquare->gameMap = m;
	actions.push_back(townSquare);
}
