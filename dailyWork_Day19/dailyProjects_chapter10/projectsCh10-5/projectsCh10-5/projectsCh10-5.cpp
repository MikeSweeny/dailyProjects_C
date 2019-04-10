#include "pch.h"
#include <iostream>
#include <ctype.h>
#include "Peg.h"
#include "Game.h"
#include <string>
#include <io.h>
#include <fcntl.h>

#define WSPADE L"\u2664"
#define WCLUB L"\u2667"
#define WHEART L"\u2661"
#define WDIAMOND L"\u2662"
#define BSPADE L"\u2660"
#define BCLUB L"\u2663"
#define BHEART L"\u2665"
#define BDIAMOND L"\u2666"

enum SUIT { wspade = 1, wclub, wheart, wdiamond, bspade, bclub, bheart, bdiamond
};
void printSuit(int suitToSelect) {
	_setmode(_fileno(stdout), _O_U16TEXT);
	switch (suitToSelect) {
	case wspade:
		wcout << WSPADE;
		break;
	case wclub:
		wcout << WCLUB;
		break;
	case wheart:
		wcout << WHEART;
		break;
	case wdiamond:
		wcout << WDIAMOND;
		break;
	case bspade:
		wcout << BSPADE;
		break;
	case bclub:
		wcout << BCLUB;
		break;
	case bheart:
		wcout << BHEART;
		break;
	case bdiamond:
		wcout << BDIAMOND;
		break;
	}
	_setmode(_fileno(stdout), _O_TEXT);
}


int main()
{
	Game HanoiGame;
	string replay = "Y";
	while (replay == "Y")
	{
		system("CLS");
		
		printSuit(bspade);
		printSuit(bheart);
		printSuit(bclub);
		printSuit(bdiamond);
		printSuit(wspade);
		printSuit(wheart);
		printSuit(wclub);
		printSuit(wdiamond);
		cout << "\n";
		system("pause");


		//HanoiGame.Reset();
		//HanoiGame.Play();

		

		cout << "Would you like to play again? (Y/N): ";
		char choice;
		cin >> choice;
		replay = toupper(choice);
	}
	return 0;
}