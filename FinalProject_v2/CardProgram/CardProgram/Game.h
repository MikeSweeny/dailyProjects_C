#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

class Game
{
public:

	Game();
	~Game();

	void ShuffleDeck(vector<string> *deck);
	void Transfer(vector<string> *source, vector<string> *destination, int amount);
	void Add(vector<string> *source, vector<string> *destination, int amount);
	void Remove(vector<string> *source, int amount);
	int Count(vector<string> *vToCount);


	virtual void SetDeck();

	virtual void Deal() = 0;
	virtual void Play() = 0;
	virtual void AnnounceWinner(int winner) = 0;

	static const int deckSize = 52;
	vector<string> *deck;
	int count;

	static const int numbers = 13;
	static const int suits = 4;
	static const string Cards[suits][numbers];

};

