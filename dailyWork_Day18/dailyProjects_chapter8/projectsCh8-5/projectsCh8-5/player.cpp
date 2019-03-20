#include "pch.h"
#include <string>
#include <iostream>
#include "player.h"
using namespace std;


Player::Player()
{
}

int Player::ThrowHand()
{
	// Announce who's turn it is
	cout << m_Name << " it is your turn to input your throw.\n";
	//tmp is a pointer to address allocated for an int
	//input goes to pointer address
	//m_StickChoice is set to address of tmp
	//tmp value set to 0
	//tmp pointer deleted....no danglers...this is good, right?
	int *tmp = new int;
	cin >> *tmp;
	m_ThrowChoice = *tmp;
	bool legalMove = false;

	while (!legalMove)
	{
		if (m_ThrowChoice < 0 || m_ThrowChoice > 4)
		{
			cout << "That is not a valid throw selection. Please try again: ";
			int *tmp = new int;
			cin >> *tmp;
			m_ThrowChoice = *tmp;
		}
		else
		{
			legalMove = true;
		}
	}
	tmp = 0;
	delete tmp;
	return m_ThrowChoice;
}

string Player::GetName() const
{
	return m_Name;
}

void Player::SetName(string name)
{
	m_Name = name;
}
