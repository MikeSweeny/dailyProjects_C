#ifndef PILE_H
#define PILE_H

#include "pch.h"
#include <string>
#include <iostream>
using namespace std;

// PILE CLASS
class Pile
{

public:

	//constructor prototype sets starter stick count to 13
	Pile(const int stickStart = 13);
	// Function to remove sticks from the pile
	void ReceiveMove(int stickRemove);
	// Function to check if the pile is empty and that player won
	bool IsWinner() const;
	// Storage for current stick count
	int m_CurrentSticks;

private:

	static const int m_MAX_STICKS = 13;
	static const int m_MIN_STICKS = 0;
	// You can only take up to 4 at a time
	static const int m_MAX_TAKE = 4;

};

#endif