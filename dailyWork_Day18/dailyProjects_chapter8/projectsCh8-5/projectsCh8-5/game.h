#ifndef GAME_H
#define GAME_H

#include "pch.h"
#include <string>
#include <iostream>
#include "player.h"
using namespace std;

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

#endif