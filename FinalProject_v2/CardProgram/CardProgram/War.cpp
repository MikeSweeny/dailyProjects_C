#include "pch.h"
#include "War.h"


War::War()
{

}


War::~War()
{
}

void War::Flip(vector<string> *stack)
{	
	if (GameWon) return;
	vector<string>* temp = &pair;
	if (PlayerMainHand.size() != 0 && CpuMainHand.size() != 0)
	{
		cout << "\nYour card is: " << PlayerMainHand.back();
		cout << "\nMy  card  is: " << CpuMainHand.back();
		stack->push_back(PlayerMainHand.back());
		stack->push_back(CpuMainHand.back());
		PlayerMainHand.pop_back();
		CpuMainHand.pop_back();
	}
	else
	{
		RefillHands();
		Flip(temp);
	}

	cout << endl;
	cout << "Press any key to continue\n";
	cin.get();
	cin.clear();
}

void War::Compare()
{
	if (GameWon) return;
	// Awards the player with the higher card both cards.
	if (pair[0] > pair[1]) //if player wins
	{
		pile.push_back(pair[0]);
		pile.push_back(pair[1]);
		pair.clear();

		// If there is a pile, there was a WAR, give this winner that pile as well.
		if (pile.size() != 0)
		{
			for (int i = 0; i < pile.size(); i++)
			{
				PlayerSideHand.push_back(pile[i]);
			}
			pile.clear();
			cout << "\nThe pile goes to the human.\n";
		}
	}
	else if (pair[1] > pair[0]) //if cpu wins
	{
		pile.push_back(pair[0]);
		pile.push_back(pair[1]);
		pair.clear();

		if (pile.size() != 0)
		{
			for (int i = 0; i < pile.size(); i++)
			{
				PlayerSideHand.push_back(pile[i]);
				pile.clear();
				cout << "\nThe pile goes to the superior being.\n";
			}
		}
	}
	// If neither card is higher, then they must be equal, time to GoToWar!
	else
	{
		pair.clear();
		GoToWar();
	}
}

void War::GoToWar()
{
	vector<string>* temp = &pile;
	// Flip into the pile 3x then flip a normal comparative pair
	for (int i = 0; i > 3; i++)
	{
		Flip(temp);
	}
	Flip(temp);
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
		PlayerSideHand.clear();
	}
	else //out of cards? other player wins
	{
		AnnounceWinner(1);
		return;
	}
	// refills the cpu hand if they are out of cards
	if (CpuSideHand.size() != 0)
	{
		for (int i = 0; i < CpuSideHand.size(); i++)
		{
			CpuMainHand.push_back(CpuSideHand[i]);
		}
		CpuSideHand.clear();
	}
	else //out of cards? other player wins
	{
		AnnounceWinner(0);
		return;
	}
	vector<string>* temp1 = &PlayerMainHand;
	vector<string>* temp2 = &CpuMainHand;
	ShuffleDeck(temp1);
	ShuffleDeck(temp2);
}

// Deals starting hand to both the player and cpu
void War::Deal()
{
	SetDeck();
	ShuffleDeck(deck);
	while (Count(deck) != 0)
	{
		vector<string> * temp1 = new vector<string>;
		vector<string> * temp2 = new vector<string>;
		temp1 = &PlayerMainHand;
		temp2 = &CpuMainHand;
		for (int i = 0; i < deckSize; i++)
		{
			Transfer(deck, temp1, 1);
			Transfer(deck, temp2, 1);
		}
		deck->clear();
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
	vector<string>* temp = &pair;
	while (!GameWon)
	{
		Flip(temp);
		Compare();
	}
}