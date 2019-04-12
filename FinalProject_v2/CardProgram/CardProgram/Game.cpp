#include "pch.h"
#include "Game.h"

Game::Game()
{


}

Game::~Game()
{
}

void Game::SetDeckSize()
{
	int input;
	cin >> input;
	playerDeckSize = input;
}

void Game::SetDeck()
{	
	string currentCard;
	const string Cards[suits][numbers] =
	{
		{"2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "Tc", "Jc", "Qc", "Kc", "Ac"},
		{"2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "Th", "Jh", "Qh", "Kh", "Ah"},
		{"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "Ts", "Js", "Qs", "Ks", "As"},
		{"2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "Td", "Jd", "Qd", "Kd", "Ad"}
	};
		for (int i = 0; i < suits; i++)
		{
			for (int j = 0; j < numbers; j++)
			{
				currentCard = Cards[i][j];
				if (deck.size() < playerDeckSize)
				{
					deck.push_back(currentCard);
				}
			}
		}


}

void Game::ShuffleDeck(vector<string> &deck)
{
	srand(time(0));
	random_shuffle(deck.begin(), deck.end());
	cout << "Deck has been shuffled!\n";
}

void Game::Transfer(vector<string> &source, vector<string> &destination, int amount)
{
	Add(source, destination, amount);
	Remove(source, amount);
}

void Game::Add(vector<string> &source, vector<string> &destination, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		destination.push_back(source.back());
	}
}

void Game::Remove(vector<string> &source, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		source.pop_back();
	}
}

int Game::Count(vector<string> &vToCount)
{
	return vToCount.size();
}