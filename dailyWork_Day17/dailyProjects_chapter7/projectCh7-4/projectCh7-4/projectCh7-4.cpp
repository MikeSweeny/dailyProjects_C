#include "pch.h"
#include <string>
#include <iostream>

using namespace std;

// PILE CLASS
class Pile
{

public:

	//constructor prototype sets starter stick count to 13
	Pile(const int stickStart = 13);
	// Function to remove sticks from the pile
	void ReceiveMove(int stickRemove);
	// Function to check if the pile is empty and that player won
	bool IsWinner() const;
	// Storage for current stick count
	int m_CurrentSticks;

private:

	static const int m_MAX_STICKS = 13;
	static const int m_MIN_STICKS = 0;
	// You can only take up to 4 at a time
	static const int m_MAX_TAKE = 4;

};

Pile::Pile(const int stickStart)
{
	m_CurrentSticks = stickStart;
}

void Pile::ReceiveMove(int stickRemove)
{
	//if the player asks to take a legal amount of sticks, allow them to and report
	if (stickRemove > m_MIN_STICKS && stickRemove <= m_MAX_TAKE)
	{
		//storing the current number of sticks temporarily so that after we remove their sticks from the pile,
		//we can report back how many they actually took even if the number they asked for would have taken
		//the pile below 0
		int *tmp = new int;
		*tmp = m_CurrentSticks;
		m_CurrentSticks -= stickRemove;
		if (m_CurrentSticks < m_MIN_STICKS)
		{
			m_CurrentSticks = m_MIN_STICKS;
		}		
		cout << "You took " << (*tmp - m_CurrentSticks) << " from the pile\n";
		cout << "There are " << m_CurrentSticks << " sticks left in the pile.\n\n";
		tmp = 0;
		delete tmp;
	}
	else
	{
	}
}

bool Pile::IsWinner() const
{
	if (m_CurrentSticks == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}


}

// PLAYER CLASS
class Player
{

public:

	//default constructor
	Player();
	// Function for taking sticks
	void TakeSticks(Pile &aPile);
	// Function for setting m_Name;
	void SetName(string name);
	string GetName() const;
	
private:

	int m_StickChoice;
	string m_Name;

};


Player::Player()
{}

string Player::GetName() const
{
	return m_Name;
}

void Player::TakeSticks(Pile &aPile)
{
	// Announce who's turn it is
	cout << m_Name << " it is your turn to take sticks.\n";
	// Ask the player how many sticks they want to take, up to 4
	cout << "How many sticks would you like to take from Nim?\n";
	//tmp is a pointer to address allocated for an int
	//input goes to pointer address
	//m_StickChoice is set to address of tmp
	//tmp value set to 0
	//tmp pointer deleted....no danglers...this is good, right?
	int *tmp = new int;
	cin >> *tmp;
	m_StickChoice = *tmp;
	bool legalMove = false;

	while (!legalMove)
	{
		if (m_StickChoice < 0 || m_StickChoice > 4)
		{
			cout << "That is not a valid stick amount to take from Nim. Please try again: ";
			int *tmp = new int;
			cin >> *tmp;
			m_StickChoice = *tmp;
		}
		else
		{
			legalMove = true;
		}
	}
	tmp = 0;
	delete tmp;
	aPile.ReceiveMove(m_StickChoice);
}

void Player::SetName(string name)
{
	m_Name = name;
}


// GAME CLASS
class Game
{

public:

	//default constructor
	Game();
	// Function for playing the game
	void Play();
	// Function for displaying the rules of the game
	void DisplayInstructions() const;
	// Function for setting players names at the beginning of a game
	void SetPlayerNames();
	// Function for deciding if the game is over
	bool IsPlaying() const;
	// Function for announcing a winner
	void AnnounceWinner() const;
	// Function for changing between players
	void NextPlayer();

private:
	//number of players in a game
	static const int NUM_PLAYERS = 2;
	//first + second player number
	static const int FIRST = 0;
	static const int SECOND = 1;
	Pile m_Pile;
	Player m_Players[NUM_PLAYERS];
	//storage for current player number
	int m_Current;

};

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



int main()
{
	Game nim;
	nim.Play();

	return 0;
}