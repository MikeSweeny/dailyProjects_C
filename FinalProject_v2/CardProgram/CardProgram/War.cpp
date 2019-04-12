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
	if (PlayerMainHand.size() != 0 && CpuMainHand.size() != 0)
	{
		cout << "Your card is: " << PlayerMainHand.back();
		cout << "My  card  is: " << CpuMainHand.back();
		stack[0] = PlayerMainHand.back();
		stack[1] = CpuMainHand.back();
		PlayerMainHand.pop_back();
		CpuMainHand.pop_back();
	}
	else
	{
		RefillHands();
		Flip(pair);
	}
	cout << endl;
	cout << "Press any key to continue";
	cin.get();
	cin.clear();
}

void War::Compare()
{
	// Awards the player with the higher card both cards.
	if (pair[0] > pair[1]) //if player wins
	{
		PlayerSideHand.push_back(pair[0]);
		PlayerSideHand.push_back(pair[1]);

		// If there is a pile, there was a WAR, give this winner that pile as well.
		if (pile.size() != 0)
		{
			for (int i = 0; i < pile.size(); i++)
			{
				PlayerSideHand.push_back(pile[i]);
			}
		}
		cout << "The pile goes to the human.";
	}
	else if (pair[1] > pair[0]) //if cpu wins
	{
		CpuSideHand.push_back(pair[0]);
		CpuSideHand.push_back(pair[1]);

		if (pile.size() != 0)
		{
			for (int i = 0; i < pile.size(); i++)
			{
				PlayerSideHand.push_back(pile[i]);
			}
		}
		cout << "The pile goes to the superior being.";
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
	while (Count(deck) != 0)
	{
		for (int i = 0; i <= deckSize; i++)
		{
			Transfer(deck, PlayerMainHand, 1);
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