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
		system("CLS");
		HanoiGame.WelcomePlayer();
		HanoiGame.DisplayInstructions();
		HanoiGame.Reset();
		HanoiGame.DisplayPegs();
		HanoiGame.Play();
		HanoiGame.AnnounceWinner();

		cout << "Would you like to play again? (Y/N): ";
		char choice;
		cin >> choice;
		replay = toupper(choice);
	}
	return 0;
}