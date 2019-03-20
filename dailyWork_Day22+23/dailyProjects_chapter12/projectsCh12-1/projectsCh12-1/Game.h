#ifndef GAME_H
#define GAME_H

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

