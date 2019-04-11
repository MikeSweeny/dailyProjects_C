#include "pch.h"
#include "War.h"

War::War()
{
}


War::~War()
{
}

void War::Flip(vector<string> stack)
{
	
	for (int i = 0; i >= 1; i++)
	{
		if (manager.m_Players[m_Current].MainHand.size() != 0)
		{
			cout << manager.m_Players[m_Current].MainHand.back() << "\t";
			stack[i] = manager.m_Players[m_Current].MainHand.back();
			manager.m_Players[m_Current].MainHand.pop_back();
			NextPlayer();
		}
		else
		{
			RefillHand();
			ShuffleDeck(manager.m_Players[m_Current].MainHand);
			Flip(pair);
		}
		cout << endl;
	}


}

void War::Compare()
{
	// Awards the player with the higher card both cards.
	if (pair[0] > pair[1])
	{
		manager.m_Players[0].SideHand.push_back(pair[0]);
		manager.m_Players[0].SideHand.push_back(pair[1]);
		// If there is a pile, there was a WAR, give this winner that pile as well.
		if (pile.size() != 0)
		{
			for (int i = 0; i < pile.size(); i++)
			{
				manager.m_Players[0].SideHand.push_back(pile[i]);
			}
		}
		cout << "Player " << manager.m_Players->GetName() << " has won the stack!";
	}
	else if (pair[1] > pair[0])
	{
		manager.m_Players[1].SideHand.push_back(pair[0]);
		manager.m_Players[1].SideHand.push_back(pair[1]);

		if (pile.size() != 0)
		{
			for (int i = 0; i < pile.size(); i++)
			{
				manager.m_Players[1].SideHand.push_back(pile[i]);
			}
		}
		cout << "Player " << manager.m_Players->GetName() << " has won the stack!";
	}
	// If neither card is higher, then they must be equal, time to GoToWar!
	else
	{
		GoToWar();
	}
}

void War::GoToWar()
{
	// Flip into the pile 3x then flip a normal comparative pair
	for (int i = 0; i > 3; i++)
	{
		Flip(pile);
	}
	Flip(pair);
}

void War::RefillHand()
{
	// refills the players hand if they are out of cards
	if (manager.m_Players[m_Current].SideHand.size() != 0)
	{
		for (int i = 0; i < manager.m_Players[m_Current].SideHand.size(); i++)
		{
			manager.m_Players[m_Current].MainHand.push_back(manager.m_Players[m_Current].SideHand[i]);
		}
	}
	else
	{
		NextPlayer();
		AnnounceWinner();
	}

}

void War::DisplayInstructions()
{
	SlowPrint("Welcome to ", 0.1, 0.1);
	FontColour("title");
	SlowPrint("WAR!", 0.1, 0.1);
	FontColour("body");
	SlowPrint(" The classic card game of domination...\n\n", 0.1, 0.1);
	SlowPrint("The object of the game is to flip the top card of your deck and compare it to the top card of the opponent.\n", 0.1, 0.1);
	SlowPrint("The player with the higher card gets to keep both cards.\n", 0.1, 0.1);
	SlowPrint("The player who runs out of cards first, loses.\n", 0.1, 0.1);
	SlowPrint("Ties are determined by ", 0.1, 0.1);
	FontColour("title");
	SlowPrint("GOING TO WAR!\n\n", 0.1, 0.1);
}

void War::Deal()
{
	ShuffleDeck(*deck);
	while (Count(*deck) != 0)
	{
		for (int i = 0; i <= deckSize; i++)
		{
			Transfer(*deck, manager.m_Players[m_Current].MainHand, 1);
			NextPlayer();
		}
	}
}

void War::AnnounceWinner()
{
	cout << "\n\nConratulations " << manager.m_Players[m_Current].GetName() << " is the Ultimate Commander!\n";
	GameOn = false;
}



void War::Play()
{
	DisplayInstructions();
	while (GameOn)
	{
		Flip(pair);
		Compare();
	}
}