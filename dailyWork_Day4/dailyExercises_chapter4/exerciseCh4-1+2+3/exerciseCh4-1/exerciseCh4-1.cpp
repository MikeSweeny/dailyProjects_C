// 1. Favourite games list program - Code found below
// 2. The problem with this loop is that you increment iter twice, meaning it will end up counting/scanning through the vector 2 at a time.
/*
   3. 
 - declare miltudimensional array for Words and Hints
 - randomly select a word from the list and store its position for the hint
 - jumble the letters in the string for the word
 - take the players input for hint, guess, or quit
 - display the appropriate hint, whether the guess was corerct, or quit
 - congratulate the player
 */


#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> gamesList;
vector<string>::iterator myIterator;
vector<string>::const_iterator iter;
int gameCount = 1;
int selection;
int choice;
string newGame;

void listFunction()
{
	for (iter = gamesList.begin(); iter != gamesList.end(); ++iter)
	{
		cout << gameCount << " - " << *iter << "\n";
		gameCount++;
	}
	gameCount = 1;
}

int main()
{
	gamesList.push_back("League of Legends");
	gamesList.push_back("Apex Legends");
	gamesList.push_back("Overwatch");
	gamesList.push_back("Minecraft");
	gamesList.push_back("SSB Ultimate");
	
	while (true)
	{
		system("CLS");
		cout << "\t\tThese are my favourite games!!!!\n\n";
		cout << "Games list:\n";
		listFunction();

		cout << "\nWould you like to add or remove a game from the list??\n1 - Add\n2 - Remove\nChoice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "You chose to add a new game!\nWhat is your new game name?\n\nGame: ";
			cin >> newGame;
			gamesList.insert(gamesList.end(), newGame);
			break;
		case 2:
			while (!gamesList.empty())
			{
				cout << "You chose to remove a new game!\nWhat is the game you wish to remove??\n\nGame #: ";
				cin >> selection;
				if (selection == 1 || selection == 2)
				{
					gamesList.erase(gamesList.begin() + (selection - 1));
					break;
				}
				else
				{
					break;
				}
			}
			break;
		default:
			cout << "You broke it";
			return 0;
		}
	}
	return 0;
}