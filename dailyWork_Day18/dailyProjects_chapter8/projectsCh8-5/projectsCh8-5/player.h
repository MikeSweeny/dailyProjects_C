#ifndef PLAYER_H
#define PLAYER_H

#include "pch.h"
#include <string>
#include <iostream>
using namespace std;

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

#endif