// Famous and Infamous - computer guesses player's famous or infamous person
// Game definition - represents a Famous and Infamous game

#ifndef GAME_H        
#define GAME_H 

#include "pch.h"
#include <string>

#include "tree.h"

using namespace std;

class Game
{
public:
	Game();
	//displays instructions
	void DisplayInstructions();
	//plays a round of game
	void Play();

private:
	//binary tree, stores questions
	Tree m_Tree;
};

#endif  