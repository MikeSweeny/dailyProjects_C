#pragma once
#include <string>
#include <iostream>
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
	void Announcewinner() const;
	void Play() const;

	void Reset();

private:

	Peg *peg1;
	Peg *peg2;
	Peg *peg3;

};

