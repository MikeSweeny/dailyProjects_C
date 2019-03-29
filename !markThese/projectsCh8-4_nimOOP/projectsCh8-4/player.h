#ifndef PLAYER_H
#define PLAYER_H

#include "pch.h"
#include <string>
#include <iostream>
#include "pile.h"
using namespace std;

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

#endif