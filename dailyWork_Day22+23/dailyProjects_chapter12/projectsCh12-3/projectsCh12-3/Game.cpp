// Famous and Infamous - computer guesses player's famous or infamous person
// Game implementation - represents a Famous and Infamous game
#include "pch.h"
#include <iostream>
#include <string>

#include "game.h"    
#include "tree.h"

using namespace std;

Game::Game()
{}

//displays instructions
void Game::DisplayInstructions()
{
	cout << "\tWelcome to Famous and Infamous";
	cout << endl << endl;
	cout << "Think of a famous or infamous person ";
	cout << "and I'll try to guess his or her name.";
	cout << endl << endl;
}

//plays a round of game
void Game::Play()
{
	m_Tree.Reset();

	char response;
	while (m_Tree.DisplayCurrentQuestion())
	{
		response = m_Tree.AskYesNo();
		m_Tree.NextQuestion(response);
	}

	response = m_Tree.AskYesNo();

	if (response == m_Tree.YES)
	{
		cout << "I guessed it!" << endl;
	}
	else
	{
		cout << "I give up." << endl;
		m_Tree.AddPerson();
	}
}