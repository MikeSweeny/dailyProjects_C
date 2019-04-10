#ifndef GAME_H
#define GAME_H
#include "Menu.h"

class Game
{
public:
	Game();
	~Game();
	void NextPlayer();
	void ShuffleDeck(vector<string> &deck);
	void SetPlayerName();

	void Transfer(vector<string> source, vector<string> destination, int amount);
	void Add(vector<string> source, vector<string> destination, int amount);
	void Remove(vector<string> source, int amount);
	int Count(vector<string> &vToCount);
	virtual void Deal() = 0;
	virtual void Play() = 0;
	virtual void AnnounceWinner() = 0;
	virtual void DisplayInstructions() = 0;

	static const int numbers = 13;
	static const int suits = 4;
	static const int deckSize = 52;
	static const string Cards[suits][numbers];
	vector<string> deck[deckSize];
	static const int NUM_PLAYERS = 2;
	Player m_Players[NUM_PLAYERS];
	int m_Current;
	bool GameOn = true;

private:

	
};


#endif