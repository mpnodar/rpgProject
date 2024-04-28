#include "GameMenuAction.h"
GameMenuAction::GameMenuAction() {
	description = "Open game menu";
}

ActionResponse GameMenuAction::execute(player* p)
{
	gameMenu m;
	return m.menu(p);
}
