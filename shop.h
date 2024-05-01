#pragma once

class shop {
private:
	bool val = true, val2 = true, val3 = true;
	int gold = 0;
	void weapons();
	void armor();
	void potions();
	void misc();
public:
	bool isArmorer = false;
	void displayGoods(player* _player);
};