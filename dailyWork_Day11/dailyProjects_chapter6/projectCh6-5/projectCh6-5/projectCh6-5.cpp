#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

class Handheld
{
public:
	Handheld(bool power = false, int gameDefault = 0, int volDefault = 5);
	void TogglePower();
	void DisplayGames() const;
	void Play() const;
	void SetGameNumber(int newGameNumber);
	void RaiseVolume();
	void LowerVolume();
private:
	static const int NUM_GAMES = 3;
	static const string Games[NUM_GAMES];
	static const int MIN_VOLUME = 0;
	static const int MAX_VOLUME = 10;
	bool m_IsOn;
	int m_GameNumber;
	int m_Volume;
};

Handheld::Handheld(bool power, int gameDefault, int volDefault)
{
	m_IsOn = power;
	m_GameNumber = gameDefault;
	m_Volume = volDefault;
}

const string Handheld::Games[NUM_GAMES] =
{
	"Super Mario Bros",
	"Candy Crush Racer",
	"Derivative Bejewelled"
};

void Handheld::TogglePower()
{
	system("CLS");
	if (!m_IsOn)
	{
		m_IsOn = true;
		cout << "Power is ON.\n\n";
	}
	else
	{
		m_IsOn = false;
		cout << "Power is OFF.\n\n";
	}
}

void Handheld::DisplayGames() const
{
	if (m_IsOn)
	{
		for (int i = 0; i < NUM_GAMES; i++)
		{
			cout << i << " - " << Games[i];
			cout << "\n";
		}
		cout << "\n";
	}
	else
	{
		system("CLS");
		cout << "The console needs to be on to do that.\n\n";
	}
}

void Handheld::Play() const
{
	system("CLS");
	if (m_IsOn)
	{
		cout << Games[m_GameNumber] << " Launching";
		for (int i = 0; i < 3; i++)
		{
			cout << ".";
			Sleep(1000);
		}	
		cout << "Gratz you played " << Games[m_GameNumber] << " SOOOOOOO WELLLL!!!!!\n\n\n";
	}
	else
	{
		cout << "The console needs to be on to do that.\n\n";
	}
	
}

void Handheld::SetGameNumber(int newGameNumber)
{
	system("CLS");
	if (m_IsOn)
	{
		m_GameNumber = newGameNumber;
		cout << "Game is set to " << Games[m_GameNumber] << "\n\n";
	}
	else
	{
		cout << "The console needs to be on to do that.\n\n";
	}
	
}

void Handheld::RaiseVolume()
{
	system("CLS");
	if (m_IsOn)
	{
		m_Volume++;
		if (m_Volume > 10)
		{
			cout << "VOLUME AT MAX!\n\n";
			m_Volume = 10;
		}
		cout << "Volume is " << m_Volume << "\n\n";
	}
	else
	{
		cout << "The console needs to be on to do that.\n\n";
	}
	
}

void Handheld::LowerVolume()
{
	system("CLS");
	if (m_IsOn)
	{
		m_Volume--;
		if (m_Volume < 0)
		{
			cout << "VOLUME AT MIN!\n\n";
			m_Volume = 0;
		}
		cout << "Volume is " << m_Volume << "\n\n";
	}
	else
	{
		cout << "The console needs to be on to do that.\n\n";
	}
	
}





int main()
{
	Handheld gameboy;
	int choice = 0;
	int game = 0;
	bool quit = false;

	cout << "\tWelcome to the gameboy simulator!\n\n";

	while (!quit)
	{
		cout << "0 - Quit\n";
		cout << "1 - Toggle System Power\n";
		cout << "2 - Select a game for the system\n";
		cout << "3 - Raise the system volume\n";
		cout << "4 - Lower the system volume\n";
		cout << "5 - Play the selected game\n\n";
		cout << "Choice: ";
		cin >> choice;
		if (choice == 0)
		{
			quit = true;
		}
		if (choice == 1)
		{
			gameboy.TogglePower();
			cin.clear();
			cin.ignore();
		}
		if (choice == 2)
		{
			cin.clear();
			cin.ignore();
			gameboy.DisplayGames();
			cout << "Select a game to set as active: ";
			cin >> game;
			if (!cin.fail() && game > -1 && game < 3)
			{
				gameboy.SetGameNumber(game);
				cin.clear();
				cin.ignore();
			}
			else
			{
				cout << "Not a valid game choice";
			}			
		}
		if (choice == 3)
		{
			gameboy.RaiseVolume();
			cin.clear();
			cin.ignore();
		}
		if (choice == 4)
		{
			gameboy.LowerVolume();
			cin.clear();
			cin.ignore();
		}
		if (choice == 5)
		{
			gameboy.Play();
		}
	}
	
	return 0;
}