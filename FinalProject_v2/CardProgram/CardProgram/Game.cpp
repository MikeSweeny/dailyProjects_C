#include "pch.h"
#include "Game.h"

Game::Game()
{
	deck = new vector<string>;

}

Game::~Game()
{
	delete deck;
	deck = NULL;
}

void Game::SetDeck()
{	
	string currentCard;
	int count;
	const string Cards[suits][numbers] =
	{
		{"2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "10c", "Jc", "Qc", "Kc", "Ac"},
		{"2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "10h", "Jh", "Qh", "Kh", "Ah"},
		{"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "10s", "Js", "Qs", "Ks", "As"},
		{"2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "10d", "Jd", "Qd", "Kd", "Ad"}
	};
	for (int i = 0; i < suits; i++)
	{
		for (int j = 0; j < numbers; j++)
		{
			currentCard = Cards[i][j];
			deck->push_back(currentCard);
		}
	}
}

void Game::ShuffleDeck(vector<string> *deck)
{
	random_shuffle(deck->begin(), deck->end());
	cout << "Deck has been shuffled!\n";
}

void Game::Transfer(vector<string> *source, vector<string> *destination, int amount)
{
	Add(source, destination, amount);
	Remove(source, amount);
}

void Game::Add(vector<string> *source, vector<string> *destination, int amount)
{
	int subIter = 0;
	for (std::vector<string>::reverse_iterator it = source->rbegin(); it != source->rend() ; ++it )
	{
		if (subIter < amount)
		{
			destination->push_back(*it);
			subIter++;
		}
	}
}

void Game::Remove(vector<string> *source, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		if (!source->empty()) 
		{
			source->pop_back();
		}
	}
}

int Game::Count(vector<string> *vToCount)
{
	return vToCount->size();
}