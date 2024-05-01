#include "Action.h"

Action::Action(GameMap* gm)
{
	gameMap = gm;
}

ActionResponse Action::execute(player*)
{
	return ActionResponse();
}
