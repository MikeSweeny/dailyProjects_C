#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "windows.h"

using namespace std;

int main()
{
	srand(time(NULL));

	int tries = 0;
	int playerNumber;
	int betweenTop = 100;
	int betweenBot = 1;
	int cpuGuess;

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

		if (playerNumber > cpuGuess)
		{
			cout << "\nHmm too low..!\n\n";
			betweenBot = cpuGuess + 1;
			Sleep(1000);
		}
		else if (playerNumber == cpuGuess+1)
		{
			cout << "\nHmm too low..!\n\n";
			cpuGuess += 1;
			Sleep(1000);
		}
		else if (playerNumber < cpuGuess)
		{
			cout << "\nHmm too high..!\n\n";
			betweenTop = cpuGuess - 1;
			Sleep(1000);
		}
		else if (playerNumber == cpuGuess-1)
		{
			cout << "\nHmm too high..!\n\n";
			cpuGuess -= 1;
			Sleep(1000);
		}
		else if (playerNumber == cpuGuess)
		{
			cout << "\nHA! I got your number in just " << tries << " tries!\n\nBeat that, human.";
			Sleep(1000);
		}


	} while (playerNumber != cpuGuess);

	return 0;
}