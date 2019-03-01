#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include "windows.h"
#include <string>

using namespace std;

int main()
{
	int stickCount = 13;
	string player1;
	string player2;
	bool playerNum = 1;
	int currentPlayer = 1;

	int stickChoice = 0;

	//enum stickChoice
	//{
	//	One = 1,
	//	Two = 2,
	//	Three = 3,
	//	Four = 4
	//};

	//int playerInput = 0;
	//stickChoice playerSticks = (stickChoice)playerInput;

	cout << "\tWelcome to NIM!\n\n";
	cout << "Each player will take turns taking 1-4 sticks from the pile of 13.\n\n";
	cout << "The player who takes the last stick, wins!\n";
	cout << "\n\nPlayer 1 enter your name: ";
	cin >> player1;
	cout << "\n\nPlayer 2 enter your name: ";
	cin >> player2;
	system("CLS");
	Sleep(1000);
	cout << (currentPlayer == 1 ? player1 : player2);
	cout << " how many sticks are you taking:\n";
	cin >> stickChoice;
	stickCount = (stickCount - stickChoice);

	do
	{
		if (currentPlayer == 1) currentPlayer = 2; else currentPlayer = 1;
		{
			switch (stickChoice)
			{
			case 1:
				cout << "\nThere are " << stickCount << " sticks remaining!\n\n";
				cout << (currentPlayer == 1 ? player1 : player2);
				cout << " how many sticks are you taking: \n";
				cin >> stickChoice;
				stickCount = (stickCount - stickChoice);
				break;
			case 2:
				cout << "\nThere are " << stickCount << " sticks remaining!\n\n";
				cout << (currentPlayer == 1 ? player1 : player2);
				cout << " how many sticks are you taking: \n";
				cin >> stickChoice;
				stickCount = (stickCount - stickChoice);
				break;
			case 3:
				cout << "\nThere are " << stickCount << " sticks remaining!\n\n";
				cout << (currentPlayer == 1 ? player1 : player2);
				cout << " how many sticks are you taking: \n";
				cin >> stickChoice;
				stickCount = (stickCount - stickChoice);
				break;
			case 4:
				cout << "\nThere are " << stickCount << " sticks remaining!\n\n";
				cout << (currentPlayer == 1 ? player1 : player2);
				cout << " how many sticks are you taking: \n";
				cin >> stickChoice;
				stickCount = (stickCount - stickChoice);
				break;
			default:
				cout << "You must enter a valid number! You lose your turn now NOOB!!!!\n\n";
				break;
			}
		}
		
	} while (stickCount > 0);

	cout << (currentPlayer == 1 ? player1 : player2) << "WINS!!!!";

	return 0;
}