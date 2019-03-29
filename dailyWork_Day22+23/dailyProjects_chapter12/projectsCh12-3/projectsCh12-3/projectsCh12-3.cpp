// Famous and Infamous - computer guesses player's famous or infamous person
// Main function
#include "pch.h"
#include "game.h"

#include <iostream>    

using namespace std;

int main()
{
	Game famousInfamous;
	char again;

	famousInfamous.DisplayInstructions();

	do
	{
		famousInfamous.Play();
		cout << endl << "Play again? (y/n): ";
		cin >> again;
	} while (again == 'y');

	return 0;
}