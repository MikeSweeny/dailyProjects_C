// projectCh3-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	const int maxNum = 2;
	cout << "\t\tBinary Code Break!!\n\n\n";
	srand(static_cast<unsigned int>(time(0)));  //seed random number generator


	int secretNumber[4];
	int secretNumberGuess[4];
	const int maxTries = 5;
	int tries = 0;
	int guess;

	for (int i = 0; i < 4; i++)
	{
		secretNumber[i] = rand() % maxNum;
	}
	cout << "The computer has chosen a 4 digit number made of 1's and 0's\nEnter one value at a time to guess the 4 digits!\n\n";

	while (tries != 5)
	{
		int correctNum = 4;
		for (int m = 0; m < 4; m++)
		{
			cout << "Enter guess " << (m + 1) << ": ";
			cin >> guess;
			secretNumberGuess[m] = guess;
			if (secretNumberGuess[m] != secretNumber[m])
			{
				correctNum--;
			}
		}
		cout << "You got " << correctNum << " of the 4 numbers correct!\n\n";
		tries++;
		cout << "Tries left: " << maxTries - tries << "!\n\n";

		if (correctNum == 4)
		{
			cout << "YO YOU WON!!! Only took you " << tries << "!\n\n";
			return 0;
		}
	}

	cout << "\n\nYou're all out of tries!";

	return 0;

}