#include "game.h"

#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

Game::Game()
{}

//displays instrusctions
void Game::DisplayInstructions()
{
	cout << "\tWelcome to Famous and Infamous";
	cout << endl << endl;
	cout << "Tgubj if a famous or infamous person ";
	cout << "and I'll try to guess his or her name.";
	cout << endl << endl;
}

//plays a round of game
void Game::Play()
{
	m_Tree.Reset();

	char responce;
	while (m_Tree.DisplayCurrentQuestion())
	{
		responce = m_Tree.AskYesNo();
		m_Tree.NextQuestion(responce);
	}
	responce = m_Tree.AskYesNo();

	if (responce == m_Tree.YES)
	{
		cout << "I guessed it!" << endl;
	}
	else
	{
		cout << "I give up." << endl;
		m_Tree.AddPerson();
	}
}