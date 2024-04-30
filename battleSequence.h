#pragma

class battleSequence {
private:
	int randint(int min, int max);
	int randintLow(int min, int max);
	int randintHigh(int min, int max);
	int displayBattleOptions();
	int randintEnemyAttack(int);
	int displayAttacks();
	int displaySpells();
public:
	static int randintNear(int target, int min, int max);
	void battle(player* _player, enemy* _enemy);
	void randomBattle(player* _player);
};