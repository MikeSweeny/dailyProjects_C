// Question 3: Pseudo code for the guess my number game where cpu guess and player tells the cpu about their choices.
//  - Should include the same loop as previous.
//  - Each if statement should include another cin call looking for the player to tell the cpu if the guess was too high, low, or correct.
//  - Each if statement should also include an && statement asking for the player's input.
//  - If statements changed to a switch.

//Question 4: The code below.

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
	int tries = 0;
	int playerNumber;
	int betweenTop = 100;
	int betweenBot = 1;
	int cpuGuess;

	enum userChoice
	{
		Low = 1,
		High,
		Correct
	};

	int playerInput = 0;
	userChoice playerResponse = (userChoice)playerInput;
	srand(time(NULL));

	cout << "\tWelcome to I Guess YOUR Number\n\n";
	cout << "I will show you how superior the computer is to a human mind.\n\n\n";
	cout << "Enter a number: ";
	cin >> playerNumber;
	system("CLS");
	cout << "The computer is making its first guess.";
	Sleep(1000);

	do
	{
		cpuGuess = rand() % (betweenTop - betweenBot) + betweenBot;
		cout << "\nComputer's guess: ";
		cout << cpuGuess;
		++tries;
		cout << "\nWas this guess good?";
		Sleep(1000);
		cout << "\n\nEnter 1 for too low!\nEnter 2 for too high!\nEnter 3 for CORRECT!!!\n\n";
		cin >> playerInput;
		Sleep(1000);
		switch (playerInput)
		{
			case 1:
				cout << "\nHmm too low..!\n\n";
				betweenBot = cpuGuess + 1;
				cpuGuess = rand() % (betweenTop - betweenBot) + betweenBot;
				cout << "\nComputer's new guess: ";
				cout << cpuGuess;
				++tries;
				cout << "\nWas this guess good?";
				Sleep(1000);
				cout << "\n\nEnter 0 for too low!\nEnter 1 for too high!\nEnter 2 for CORRECT!!!\n\n";
				cin >> playerInput;
				Sleep(1000);
				break;
			case 2:
				cout << "\nHmm too high..!\n\n";
				betweenTop = cpuGuess - 1;
				cpuGuess = rand() % (betweenTop - betweenBot) + betweenBot;
				cout << "\nComputer's new guess: ";
				cout << cpuGuess;
				++tries;
				cout << "\nWas this guess good?";
				Sleep(1000);
				cout << "\n\nEnter 0 for too low!\nEnter 1 for too high!\nEnter 2 for CORRECT!!!\n\n";
				cin >> playerInput;
				Sleep(1000);
				break;
			case 3:
				cout << "\nHA! I got your number in just " << tries << " tries!\n\nBeat that, human.";
				Sleep(1000);
				break;
			default:
				cout << "You must enter a number!";
				break;
		}
	}
	while (playerNumber != cpuGuess);
	return 0;
}