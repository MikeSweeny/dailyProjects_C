#include "pch.h"
#include <iostream>
using namespace std;

char scoreInput;


int main()
{
	cout << "Score Rating Machine!\n";
	cout << "Enter your score now!\n\n";
	cout << "Score: ";

	char*userIn = new char[10];
	cin >> userIn;
	int scoreInput = strtol(userIn, NULL, 10);
	delete userIn;

	while (scoreInput < 2147483647 && scoreInput > -2147483647)
	{
		if (scoreInput < 0)
		{
			cout << "That's not a legal score, or are you just that noob?\n\n";
			return 0;
		}
		else if (scoreInput > 0 && scoreInput < 999)
		{
			cout << "\nWhat a noob score!\n\n";
			return 0;
		}
		else if (scoreInput > 1000 && scoreInput < 9999)
		{
			cout << "\nThat's a pretty good score, for a pleb!\n\n";
			return 0;
		}
		else if (scoreInput >= 10000)
		{
			cout << "\nWoo! Very impressive yo!\n\n";
			return 0;
		}
		else
		{
			cout << "\n\n\n\nYo, scores are in numbers, what are you some kind of idiot?!?\n\n";
			return 0;
		}
	} 
	return 0;

}