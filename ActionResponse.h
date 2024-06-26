#pragma once
enum ActionResponse {
	Ended = -1,
	GaveGold = -2,
	Attack = -3,
	Purchase = -4,
	ReturnToGame = -5,
	RandomBattle = -6,
	ManageInventory = -7,
	DisplayGoods = -8,
	TalkToSomeone = -9,
	QuitGame = -10,
	Move = -11,
	NotSet = -12,
	AcceptQuest = -13,
	PlayerDied = -14,
	PlayerDefeatedEnemy = -15,
	PlayerFled = -16,
	LeftShop = -17,
	RecievedDirections = -18,
	CompletedQuest = -19,
	AbandonedQuest = -20
};