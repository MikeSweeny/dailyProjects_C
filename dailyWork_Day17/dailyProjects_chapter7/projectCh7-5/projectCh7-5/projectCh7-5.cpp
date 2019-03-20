#include "pch.h"
#include <string>
#include <iostream>
using namespace std;

class Game;

// PLAYER CLASS
class Player
{

public:

	//default constructor
	Player();
	// Function for selecting rock, paper, or scissors
	int ThrowHand();
	// Function for setting m_Name;
	void SetName(string name);
	string GetName() const;

private:

	int m_ThrowChoice;
	string m_Name;

};


Player::Player()
{
}

int Player::ThrowHand()
{
	// Announce who's turn it is
	cout << m_Name << " it is your turn to input your throw.\n";
	//tmp is a pointer to address allocated for an int
	//input goes to pointer address
	//m_StickChoice is set to address of tmp
	//tmp value set to 0
	//tmp pointer deleted....no danglers...this is good, right?
	int *tmp = new int;
	cin >> *tmp;
	m_ThrowChoice = *tmp;
	bool legalMove = false;

	while (!legalMove)
	{
		if (m_ThrowChoice < 0 || m_ThrowChoice > 4)
		{
			cout << "That is not a valid throw selection. Please try again: ";
			int *tmp = new int;
			cin >> *tmp;
			m_ThrowChoice = *tmp;
		}
		else
		{
			legalMove = true;
		}
	}
	tmp = 0;
	delete tmp;
	return m_ThrowChoice;
}

string Player::GetName() const
{
	return m_Name;
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
	// Function to store players moves for comparison and picks a winner
	int ReceiveMove(int newThrow, int oldThrow);
	// Function for announcing a winner
	void AnnounceWinner(int newThrow, int oldThrow) const;
	// Function for changing between players
	void NextPlayer();

private:
	//number of players in a game
	static const int NUM_PLAYERS = 2;
	//first + second player number
	static const int FIRST = 0;
	static const int SECOND = 1;
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

//int Game::ReceiveMove(int newThrow, int oldThrow)
//{
//	// 1rock, 2paper, 3scissors
//	// 1>3 2>1 3>2
//
//	if (newThrow == oldThrow)
//	{
//		cout << "It's a tie!!!!!!!!!\n\n\n";
//	}
//	else
//	{
//		const int difference = newThrow - oldThrow;
//		if (difference == 1)
//		{
//			return 1;
//		}
//		if (difference == -1)
//		{
//			return 0;
//		}
//		if (difference == -2 || difference == 2)
//		{
//			return 1;
//		}			
//	}
//	
//
//}

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



int main()
{
	Game rpsGame;
	rpsGame.Play();

}