#include "GameMenuAction.h"

GameMenuAction::GameMenuAction(GameMap* gm) : Action(gm)
{
	description = "Open game menu";
}

ActionResponse GameMenuAction::execute(player* p)
{
	gameMenu m;
	return m.menu(p);
}
