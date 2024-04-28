#include "GameMenuAction.h"
GameMenuAction::GameMenuAction() {
	description = "Open game menu";
}

void GameMenuAction::execute(player* p)
{
	gameMenu m;
	m.menu(p);
}
