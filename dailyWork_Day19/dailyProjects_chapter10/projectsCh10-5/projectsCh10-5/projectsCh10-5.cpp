#include "pch.h"
#include <iostream>
#include <ctype.h>
#include "Peg.h"
#include "Game.h"


int main()
{
	Game HanoiGame;
	string replay = "Y";
	while (replay == "Y")
	{
		HanoiGame.Reset();
		HanoiGame.Play();

		cout << "Would you like to play again? (Y/N): ";
		char choice;
		cin >> choice;
		replay = toupper(choice);
	}
	   	 
}