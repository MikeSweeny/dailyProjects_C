#include "pch.h"
#include <string>
#include <iostream>
#include "player.h"
using namespace std;


Player::Player()
{}

string Player::GetName() const
{
	return m_Name;
}

void Player::TakeSticks(Pile &aPile)//Steven - aPile should be a const.
{
	// Announce who's turn it is
	cout << m_Name << " it is your turn to take sticks.\n";
	// Ask the player how many sticks they want to take, up to 4
	cout << "How many sticks would you like to take from Nim?\n";
	//tmp is a pointer to address allocated for an int
	//input goes to pointer address
	//m_StickChoice is set to address of tmp
	//tmp value set to 0
	//tmp pointer deleted....no danglers...this is good, right?
	int *tmp = new int;
	cin >> *tmp;
	m_StickChoice = *tmp;
	bool legalMove = false;

	while (!legalMove)
	{
		if (m_StickChoice < 0 || m_StickChoice > 4)
		{
			cout << "That is not a valid stick amount to take from Nim. Please try again: ";
			int *tmp = new int;
			cin >> *tmp;
			m_StickChoice = *tmp;
		}
		else
		{
			legalMove = true;
		}
	}
	tmp = 0;
	delete tmp;
	aPile.ReceiveMove(m_StickChoice);
}

void Player::SetName(string name)
{
	m_Name = name;
}

