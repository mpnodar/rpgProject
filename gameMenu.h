#pragma once
#include "characters.h"

class gameMenu {
public:
	bool menuLoop = true;
	void returnToGame();
	void talkToSomeone();
	void quitGame();
	void menu(player*);
};