#include <iostream>
#include "battleSequence.cpp"



int main() {

	string name;
	cout << "Please enter your name: ";
	cin >> name;

	player you(1, name);

	while (true) { // Just temporary for tests

		randomBattle(you);

		if (you.getHealth() == 0) { // Only temporary, delete after loop is gone
			break;
		}

	}
	


	return 0;
}