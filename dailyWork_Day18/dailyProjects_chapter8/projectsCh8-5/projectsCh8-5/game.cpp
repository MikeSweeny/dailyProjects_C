#include "pch.h"
#include <string>
#include <iostream>
#include "game.h"
#include "player.h"
using namespace std;


Game::Game()
{
	m_Current = FIRST;
}

void Game::DisplayInstructions() const
{
	cout << "\tWelcome to Rock, Paper, Scissors.\n\n";
	cout << "To throw:\n";
	cout << "1 - Rock\n";
	cout << "2 - Paper\n";
	cout << "3 - Scissors\n\n";
}

void Game::SetPlayerNames()
{
	//rotate through players ask player their name, set, and report!
	for (int i = 0; i < NUM_PLAYERS; i++)
	{
		string *tmp = new string;
		cout << "Player " << (m_Current + 1) << ", what is your name: ";
		cin >> *tmp;
		m_Players[m_Current].SetName(*tmp);
		cout << "Excellent, player " << (m_Current + 1) << " set to: " << *tmp << "\n\n";
		NextPlayer(); //this should make it so after the first loop it asks again for player 2, and then sets player back to 1 for the game to start.
		tmp = 0;
		delete tmp;
	}

}

void Game::NextPlayer()
{
	m_Current = (m_Current + 1) % NUM_PLAYERS;
}

void Game::Play()
{
	system("CLS");
	DisplayInstructions();
	SetPlayerNames();
	int p1C = m_Players[m_Current].ThrowHand();
	NextPlayer();
	system("CLS");
	int p2C = m_Players[m_Current].ThrowHand();


	AnnounceWinner(p1C, p2C);
}

void Game::AnnounceWinner(int newThrow, int oldThrow) const
{
	// 1rock, 2paper, 3scissors
	// 1>3 2>1 3>2

	if (newThrow == oldThrow)
	{
		cout << "It's a tie!!!!!!!!!\n\n\n";
	}
	else
	{
		cout << "\n\nTHE WINNER IS ";
		const int difference = newThrow - oldThrow;
		if (difference == 1)
		{
			cout << m_Players[0].GetName() << "\n\n";
		}
		if (difference == -1)
		{
			cout << m_Players[1].GetName() << "\n\n";
		}
		if (difference == -2 || difference == 2)
		{
			cout << m_Players[1].GetName() << "\n\n";
		}
	}

}
