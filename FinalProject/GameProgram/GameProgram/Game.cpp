#include "pch.h"
#include "Game.h"


Game::Game()
{
	string Cards[suits][numbers] =
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
			deck->push_back(Cards[i][j]);
		}
	}
}
Game::~Game()
{
}

void Game::SetPlayerName()
{
	string *tmp = new string;
	cout << "Player " << (m_Current + 1) << ", what is your name: ";
	cin >> *tmp;
	m_Players[m_Current].SetName(*tmp);
	tmp = 0;
	delete tmp;
}

void Game::NextPlayer()
{
	m_Current = (m_Current + 1) % NUM_PLAYERS;
}

void Game::ShuffleDeck(vector<string> &deck)
{
	random_shuffle(deck.begin(), deck.end());
	cout << "Deck has been shuffled!\n";
}

void Game::Transfer(vector<string> source, vector<string> destination, int amount)
{
	Add(source, destination, amount);
	Remove(source, amount);
}

void Game::Add(vector<string> source, vector<string> destination, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		destination.push_back(source[source.size() - (1 + i)]);
	}
}

void Game::Remove(vector<string> source, int amount)
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
