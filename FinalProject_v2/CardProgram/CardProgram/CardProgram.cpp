#include "pch.h"
#include "Menu.h"
#include "War.h"
// #include "GoFish.h"
#include <iostream>

int main()
{
	Menu menu;
	system("color 2f");
	menu.FontSize(10, 18);
	//menu.WelcomePlayer();
	char replay = 'Y';
	while (replay == 'Y')
	{
		//menu.ShowGames();
		int gameToPlay = menu.SelectGame();
		if (gameToPlay == 1)
		{
			//menu.WarInstructions();
			War warGame;
			warGame.SetDeckSize();
			warGame.Play();
		}
		else if (gameToPlay == 2)
		{
			// GoFish fishGame();
			// fishGame.play();
		}
		else
		{
			menu.FontColour("error");
			menu.SlowPrint("*spark kggzztt* INVALID INPUT *fssssss*", menu.fast, menu.medium);
			menu.FontColour("body");
			cin.clear();
			cout << endl;
			continue;
		}
		menu.SlowPrint("\n\nAnother attempt?(Y/N): ", menu.medium, menu.medium);
		cin >> replay;
		replay = toupper(replay);
		if (replay != 'Y' && replay != 'N')
		{
			menu.FontColour("error");
			menu.SlowPrint("*creaak* INVALID INPUT *pop*\n", menu.fast, menu.medium);
			menu.FontColour("body");
			replay = 'Y';
			cin.clear();
		}
	}

	return 0;
}