#include "pch.h"
#include "Menu.h"


Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::FontSize(int a, int b) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}

void Menu::FontColour(string preset)
{
	if (preset == "title")
	{
		HANDLE dosHandleOut;
		dosHandleOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(dosHandleOut, 1 | COMMON_LVB_UNDERSCORE | BACKGROUND_GREEN);
	}
	if (preset == "body")
	{
		HANDLE dosHandleOut;
		dosHandleOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(dosHandleOut, 0 | BACKGROUND_GREEN);
	}
	if (preset == "error")
	{
		HANDLE dosHandleOut;
		dosHandleOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(dosHandleOut, 12 | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	}
	if (preset == "surprise")
	{
		HANDLE dosHandleOut;
		dosHandleOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(dosHandleOut, 5 | BACKGROUND_GREEN);
	}

}

void Menu::SlowPrint(string toType, float minDelay, float maxDelay)
{
	int len = toType.size();
	int max = maxDelay * 500;
	int min = minDelay * 500;
	srand(time(NULL));
	for (int i = 0; i < len; i++)
	{
		float sleepyTime = rand() % max + min;
		cout << toType[i];
		Sleep(sleepyTime);
	}
}

void Menu::WarInstructions()
{
	SlowPrint("Welcome to ", medium, medium);
	FontColour("title");
	SlowPrint("WAR!", medium, medium);
	FontColour("body");
	SlowPrint(" The classic card game of domination...\n\n", fast, medium);
	SlowPrint("The object of the game is to flip the top card of your deck and compare it to the top card of the opponent.\n", fast, medium);
	SlowPrint("The player with the higher card gets to keep both cards.\n", fast, medium);
	SlowPrint("The player who runs out of cards first, loses.\n", fast, medium);
	SlowPrint("Ties are determined by ", fast, medium);
	FontColour("title");
	SlowPrint("GOING TO WAR!\n\n", medium, medium);
}

void Menu::FishInstructions()
{
	SlowPrint("Welcome to ", medium, medium);
	FontColour("title");
	SlowPrint("GO FISH!", medium, medium);
	FontColour("body");
	SlowPrint(" You may be a pathetic human, but even you must know the rules of this game... ask for pairs, getting pairs makes you win!", fast, medium);
	SlowPrint("If the other player doesn't have the card they yell ", fast, medium);
	FontColour("title");
	SlowPrint("GO FISH!\n\n", medium, medium);
}

void Menu::SetPlayerName()
{
	string playerName;
	bool validInput = false;
	while (!validInput)
	{
		cin >> playerName;
		if (!cin.fail())
		{
			m_playerName = playerName;
			SlowPrint("Thank you for your compliance, ", medium, medium);
			SlowPrint(playerName, medium, medium);
			cout << ".\n\n";
			cin.clear();
			validInput = true;
		}
		else
		{
			FontColour("error");
			SlowPrint("*zzzztt* INVALID INPUT *sparks*", fast, fast);
			FontColour("body");
			system("CLS");
			cin.clear();
			SetPlayerName();
		}

	}

}

void Menu::WelcomePlayer()
{
	FontColour("body");
	SlowPrint("Hello human, this is ", medium, medium);
	FontColour("title");
	SlowPrint("THE CARD PROGRAM\n\n", medium, medium);
	Sleep(1000);
	FontColour("body");
	SlowPrint("Submit your personal identification signature: ", medium, medium);
	SetPlayerName();
	SlowPrint("Loading simulated gambling entertainment software", medium, medium);
	Sleep(600);
	SlowPrint("...", slow, slow);
	FontColour("surprise");
	cout << R"(
============================================
Load Complete!                             |
              __                           |
        _..-''--'----_.                    |
      ,''.-''| .---/ _`-._                 |
    ,' \ \  ;| | ,/ / `-._`-.              |
  ,' ,',\ \( | |// /,-._  / /              |
  ;.`. `,\ \`| |/ / |   )/ /               |
 / /`_`.\_\ \| /_.-.'-''/ /                |
/ /_|_:.`. \ |;'`..')  / /                 |
`-._`-._`.`.;`.\  ,'  / /                  |
    `-._`.`/    ,'-._/ /       THE         |
      : `-/     \`-.._/                    |
      |  :      ;._ (         CARD         |
      :  |      \  ` \                     |
       \         \   |     PROGRAM         |
        :        :   ;                     |
        |           /                      |
        ;         ,'                       |
       /         /                         |
      /         /                          |
               /                           |
============================================
STARTING GAME.)";
	Sleep(3000);
	FontColour("body");
	system("CLS");
}

int Menu::SelectGame()
{
	bool validInput = false;
	while (!validInput)
	{
		int input;
		cin >> input;
		if (!cin.fail())
		{
			return input;
			cin.clear();
		}
		else
		{
			FontColour("error");
			SlowPrint("*sputters* INVALID INPUT *zzt zzzt*", fast, fast);
			FontColour("body");
			cin.clear();
			SelectGame();
		}
	}
}

void Menu::ShowGames()
{
	SlowPrint("There are currently two games that can be played:", medium, medium);
	Sleep(600);
	cout << "\n - 1. War";
	cout << "\n - 2. Go Fish\n";
	Sleep(600);
	SlowPrint("Please select an option by number: ", medium, medium);
}