#pragma once
#include "characters.h"
#include "ActionResponse.h"

class gameMenu {
public:
	void returnToGame();
	void talkToSomeone();
	void quitGame();
	ActionResponse menu(player*);
};