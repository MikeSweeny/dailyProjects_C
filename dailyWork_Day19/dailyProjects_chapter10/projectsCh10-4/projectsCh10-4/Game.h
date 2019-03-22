#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include "DiskNode.h"
#include "Peg.h"

using namespace std;

class Game
{
	friend class DiskNode;
	friend class Peg;

public:

	Game();
	~Game();


	void WelcomePlayer() const;
	void DisplayInstructions() const;
	void DisplayPegs() const;
	void MoveDisk();
	void Announcewinner() const;
	void Play();

	void Reset();

private:

	Peg Pegs[3];

};

