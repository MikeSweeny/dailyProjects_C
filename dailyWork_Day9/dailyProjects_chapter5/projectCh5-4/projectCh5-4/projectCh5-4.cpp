#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Shuffle(vector<const string*> &deck);
void DisplayDeck(const int *deckSize, const int *numbers, vector<const string*> deck);


int main()
{
	cout << "A deck of cards!\n\n";
	bool play = true;
	const int numbers = 13;
	const int suits = 4;
	const int deckSize = 52;
	const string Cards[suits][numbers] =
	{
		{"2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "10c", "Jc", "Qc", "Kc", "Ac"},
		{"2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "10h", "Jh", "Qh", "Kh", "Ah"},
		{"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "10s", "Js", "Qs", "Ks", "As"},
		{"2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "10d", "Jd", "Qd", "Kd", "Ad"}
	};
	vector<const string*> deck;
	for (int i = 0; i < suits; i++)
	{
		for (int j = 0; j < numbers; j++)
		{
			deck.push_back(&Cards[i][j]);
		}
	}
	while (play)
	{
		int input;
		cout << "1 - Quit\n";
		cout << "2 - Shuffle Deck\n";
		cout << "3 - Display Deck\n";
		cout << "\nChoose one: ";
		cin >> input;
		int choice = (input - 1);
		switch (choice)
		{
		case 0:
			play = false;
		case 1:
			Shuffle(deck);
			break;
		case 2:
			DisplayDeck(&deckSize, &numbers, deck);
			break;
		}
	}		
	return 0;
}


void DisplayDeck(const int *deckSize, const int *numbers, vector<const string*> deck)
{
	for (int j = 0; j < *deckSize; j++)
	{
		cout << *deck[j] << "  ";
		if (j == 12)
		{
			cout << "\n";
		}
		if (j == 25)
		{
			cout << "\n";
		}
		if (j == 38)
		{
			cout << "\n";
		}
		if (j == 51)
		{
			cout << "\n";
		}
	}
	cout << "\n";
}

void Shuffle(vector<const string*> &deck)
{
	random_shuffle(deck.begin(), deck.end());
	cout << "Deck has been shuffled!\n";
}
