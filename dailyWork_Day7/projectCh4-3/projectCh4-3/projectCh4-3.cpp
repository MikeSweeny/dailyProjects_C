#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void welcomePlayer();
void play(int aSecretNumber);
int askNumber(int MIN_NUMBER, int MAX_NUMBER);
void randomNumber(int MIN_NUMBER, int MAX_NUMBER);

int input;
int secretNumber;
const int MAX_NUMBER = 100;
const int MIN_NUMBER = 1;

int main()
{
	randomNumber(MIN_NUMBER, MAX_NUMBER);
	welcomePlayer();
	play(input);

	return 0;
}


void welcomePlayer()
{
	cout << "\tWelcome to Guess My Number\n\n";
	cout << "Your objective is to guess the number!\n";
	cout << "Good fuckin luck.\n\n";
}
void play(int aSecretNumber)
{
	int tries = 0;
	do
	{
		askNumber(MIN_NUMBER, MAX_NUMBER);
		if (aSecretNumber > secretNumber)
		{
			cout << "Too high!\n\n";
		}
		else if (aSecretNumber < secretNumber)
		{
			cout << "Too low!\n\n";
		}
		++tries;
		cout << "Try another number: ";
		cin.clear();
		cin.ignore();
	} while (aSecretNumber != secretNumber);
	cout << "\nThat's it! You got it in " << tries << " guesses!\n";
}

int askNumber(int MIN_NUMBER, int MAX_NUMBER)
{
	while (input == NULL)
	{
		cout << "0 is considered an invalid entry.\n";
		cout << "Enter a number between " << MIN_NUMBER << " and " << MAX_NUMBER << ": ";
		cin >> input;
		if (cin.fail())
		{
			cout << "YO, I SAID ENTER A NUMBER, NUMBNUTS!!!!\n\n";
			cin.clear();
			cin.ignore();
		}
		if (!cin.fail())
		{
			if (input < MIN_NUMBER && input != 0)
			{
				cout << "That number is too low, " << MIN_NUMBER << " is the lowest valid input.\n";
				input = 0;
			}
			if (input > MAX_NUMBER && input != 0)
			{
				cout << "That number is too high, " << MAX_NUMBER << " is the highest valid input.\n";
				input = 0;
			}
			if (input >= MIN_NUMBER && input <= MAX_NUMBER && input != 0)
			{
				cout << "VALID INPUT DETECTED\n\n";
				cout << "Your number was: " << input << "\n\n";
				return input;
			}
		}
	}
}

void randomNumber(int MIN_NUMBER, int MAX_NUMBER)
{
	secretNumber = MIN_NUMBER + rand() % ((MAX_NUMBER + 1) - MIN_NUMBER);
}