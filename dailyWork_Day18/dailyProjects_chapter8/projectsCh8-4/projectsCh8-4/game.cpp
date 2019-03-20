#include "pch.h"
#include <string>
#include <iostream>
#include "game.h"
using namespace std;


Game::Game()
{
	m_Current = FIRST;
}

void Game::DisplayInstructions() const
{
	cout << "\tWelcome to NIM\n\n....you know the rules...\n\n";
}

bool Game::IsPlaying() const
{
	if (m_Pile.m_CurrentSticks != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Game::AnnounceWinner() const
{
	cout << "\n\nTHE WINNER IS " << m_Players[((m_Current + 1) % NUM_PLAYERS)].GetName() << "\n\n";
}

void Game::NextPlayer()
{
	m_Current = (m_Current + 1) % NUM_PLAYERS;
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
		NextPlayer(); //this should make it so after the first loop it asks again for player 2, and then sets player back to 1 for the game.
		tmp = 0;
		delete tmp;
	}

}

void Game::Play()
{
	DisplayInstructions();
	SetPlayerNames();

	while (IsPlaying())
	{
		m_Players[m_Current].TakeSticks(m_Pile);
		NextPlayer();
	}
	AnnounceWinner();
}