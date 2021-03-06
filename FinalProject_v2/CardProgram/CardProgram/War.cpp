#include "pch.h"
#include "War.h"


War::War()
{

}


War::~War()
{
}

void War::Flip(vector<string> &stack)
{
	cout << "xXx FLIP! xXx\n";
	if (PlayerMainHand.size() != 0 && CpuMainHand.size() != 0)
	{
		cout << "Your card is: " << PlayerMainHand.back();
		cout << endl;
		cout << "My  card  is: " << CpuMainHand.back();
		cout << endl;
		stack.push_back(PlayerMainHand.back());
		stack.push_back(CpuMainHand.back());
		PlayerMainHand.pop_back();
		CpuMainHand.pop_back();
	}
	else
	{
		RefillHands();
		Flip(pair);
	}
	cout << "Press any key to continue. . .";
	cin.ignore();
	cin.get();
	cout << endl;
}

void War::Compare()
{
	// Awards the player with the higher card both cards.
	if (pair.at(0) > pair.at(1)) //if player wins
	{
		PlayerSideHand.push_back(pair.at(0));
		PlayerSideHand.push_back(pair.at(1));
		pair.pop_back();
		pair.pop_back();

		// If there is a pile, there was a WAR, give this winner that pile as well.
		if (pile.size() != 0)
		{
			for (int i = 0; i < pile.size(); i++)
			{
				PlayerSideHand.push_back(pile[i]);
				pile.pop_back();
			}
		}
		cout << "The pile goes to the human.\n\n";
	}
	else if (pair.at(1) > pair.at(0)) //if cpu wins
	{
		CpuSideHand.push_back(pair.at(0));
		CpuSideHand.push_back(pair.at(1));
		pair.pop_back();
		pair.pop_back();


		if (pile.size() != 0)
		{
			for (int i = 0; i < pile.size(); i++)
			{
				PlayerSideHand.push_back(pile[i]);
				pile.pop_back();
			}
		}
		cout << "The pile goes to the superior being.\n\n";
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

void War::RefillHands()
{
	// refills the players hand if they are out of cards
	if (PlayerSideHand.size() != 0)
	{
		for (int i = 0; i < PlayerSideHand.size(); i++)
		{
			PlayerMainHand.push_back(PlayerSideHand[i]);
		}
	}
	else //out of cards? other player wins
	{
		AnnounceWinner(1);
	}
	// refills the cpu hand if they are out of cards
	if (CpuSideHand.size() != 0)
	{
		for (int i = 0; i < CpuSideHand.size(); i++)
		{
			CpuMainHand.push_back(CpuSideHand[i]);
		}
	}
	else //out of cards? other player wins
	{
		AnnounceWinner(0);
	}
	ShuffleDeck(PlayerMainHand);
	ShuffleDeck(CpuMainHand);
}

// Deals starting hand to both the player and cpu
void War::Deal()
{
	SetDeck();
	ShuffleDeck(deck);
	for (int i = 0; i < (deckSize / 2); i++)
	{
		if (Count(deck) != 0)
		{
			Transfer(deck, PlayerMainHand, 1);
		}
		if (Count(deck) != 0)
		{
			Transfer(deck, CpuMainHand, 1);
		}
	}
}

void War::AnnounceWinner(int winner)
{
	if (winner == 0)
	{
		cout << "You have won!";
	}
	if (winner == 1)
	{
		cout << "You are defeated.";
	}
	GameWon = true;
}



void War::Play()
{
	Deal();
	while (!GameWon)
	{
		Flip(pair);
		Compare();
	}
}