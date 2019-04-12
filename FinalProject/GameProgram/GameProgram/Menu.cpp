#include "pch.h"
#include "Menu.h"

Menu::Menu()
{
	Game theGame;
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
		SetConsoleTextAttribute(dosHandleOut, 14 | BACKGROUND_GREEN);
	}
	if (preset == "error")
	{
		HANDLE dosHandleOut;
		dosHandleOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(dosHandleOut, 12 | BACKGROUND_GREEN);
	}

}

void Menu::SlowPrint(string toType, float minDelay, float maxDelay)
{
	int len = toType.size();
	int max = maxDelay * 1000;
	int min = minDelay * 1000;
	srand(time(NULL));
	for (int i = 0; i < len; i++)
	{
		float sleepyTime = rand() % max + min;
		cout << toType[i];
		Sleep(sleepyTime);
	}
}

void Menu::WelcomePlayer()
{
	FontColour("body");
	SlowPrint("Hello User, welcome to ", 0.1, 0.1);
	FontColour("title");
	SlowPrint("THE CARD PROGRAM\n\n", 0.1, 0.1);
	Sleep(1000);
	FontColour("body");
	SlowPrint("Loading simulated gambling entertainment software", 0.1, 0.1);
	Sleep(600);
	SlowPrint("...", 0.6, 0.6);
	cout << "COMPLETE!";
	Sleep(1000);
	system("CLS");
}

void Menu::SelectGame(int select)
{
	if (select == 1)
	{
		warGame.Play();
	}
	if (select == 2)
	{
		fishGame.Play();
	}
}

void Menu::ShowMenu()
{
	while (m_IsPlaying)
	{
		enum m_Options { Exit, War, GoFish };
		SlowPrint("There are currently two games that can be played:", 0.1, 0.1);
		cout << "\n - 1. War";
		cout << "\n - 2. Go Fish\n";
		Sleep(600);
		SlowPrint("Please select an option by number: ", 0.1, 0.1);
		int input;
		cin >> input;
		if (!cin.fail())
		{
			switch (input)
			{
			case Exit:
				m_IsPlaying = false;
				break;
			case War:
				SelectGame(1);
				break;
			case GoFish:
				SelectGame(2);
				break;
			default:
				break;
			}
		}
	}
}


