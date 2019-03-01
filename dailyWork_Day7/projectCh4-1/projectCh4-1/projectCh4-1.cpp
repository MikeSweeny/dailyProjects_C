
#include "pch.h"
#include <iostream>

using namespace std;

int input;
int askNumber(int low, int high);

int main()
{
    cout << "Welcome to the number validator!\n";
		askNumber(1, 10);
}

int askNumber(int low, int high)
{
	while (input == NULL)
	{
		cout << "0 is considered an invalid entry.\n";
		cout << "Enter a number between " << low << " and " << high << ".\n";
		cin >> input;
		if (cin.fail())
		{
			cout << "YO, I SAID ENTER A NUMBER, NUMBNUTS!!!!\n\n";
			cin.clear();
			cin.ignore();
		}
		if (!cin.fail())
		{
			if (input < low && input != 0)
			{
				cout << "That number is too low, " << low << " is the lowest valid input.\n";
				input = 0;
			}
			if (input > high && input != 0)
			{
				cout << "That number is too high, " << high << " is the highest valid input.\n";
				input = 0;
			}
			if (input >= low && input <= high && input != 0)
			{
				cout << "VALID INPUT DETECTED\n\n";
				cout << "Your number was: " << input << "\n\n";
				return input;
			}
		}
	}
}