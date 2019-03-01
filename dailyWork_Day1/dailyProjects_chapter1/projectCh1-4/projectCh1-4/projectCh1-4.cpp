#include "pch.h"
#include <iostream>
#include "windows.h"

using namespace std;

// Declare how many cards in the deck and variable to store the player count

const int fullDeck = 52;
int playerCount;

int main()
{
	cout << "This is a card game. Everyone gets the same number of cards.\n";
	cout << "\nHow many players will there be today? ";
	cin >> playerCount;
	system("CLS");
	cout << "Dealing.\n";
	Sleep(10);
	system("CLS");
	cout << "Dealing..\n";
	Sleep(10);
	system("CLS");
	cout << "Dealing...\n";
	Sleep(10);
	system("CLS");
	cout << "Each player has " << (fullDeck / playerCount) << " cards!\n";
	cout << "There are " << (fullDeck % playerCount) << " cards remaining in the deck\n\n";

	return 0;
}