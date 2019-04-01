#include "pch.h"
#include <string>
#include <iostream>
#include "pile.h"
using namespace std;


Pile::Pile(const int stickStart)
{
	m_CurrentSticks = stickStart;
}

void Pile::ReceiveMove(int stickRemove)
{
	//if the player asks to take a legal amount of sticks, allow them to and report
	if (stickRemove > m_MIN_STICKS && stickRemove <= m_MAX_TAKE)
	{
		//storing the current number of sticks temporarily so that after we remove their sticks from the pile,
		//we can report back how many they actually took even if the number they asked for would have taken
		//the pile below 0
		int *tmp = new int;
		*tmp = m_CurrentSticks;
		m_CurrentSticks -= stickRemove;
		if (m_CurrentSticks < m_MIN_STICKS)
		{
			m_CurrentSticks = m_MIN_STICKS;
		}
		cout << "You took " << (*tmp - m_CurrentSticks) << " from the pile\n";
		cout << "There are " << m_CurrentSticks << " sticks left in the pile.\n\n";
		tmp = 0;
		delete tmp;
	}
	else
	{
	}
}

bool Pile::IsWinner() const
{
	//Steven - You don't need the else.
	if (m_CurrentSticks == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}


}