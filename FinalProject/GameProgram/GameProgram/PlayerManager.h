#include "Player.h"

class PlayerManager
{
	friend class Game;

public:
	PlayerManager();
	~PlayerManager();

	string GetPlayerName(int playerNum);
	void SetPlayerName(int playerNum, string name);

	int GetPlayerScore(int playerNum);
	void SetPlayerScore(int playerNum, int num);

	static const int NUM_PLAYERS = 2;
	Player m_Players[NUM_PLAYERS];

};

