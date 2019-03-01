// QUESTION 1: See the code below.
// QUESTION 2: X is set to 0 so the loop will never start as it returns false in the while(x) statemtnt.

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Difficulty Levels\n\n";
	cout << "1 - Easy\n";
	cout << "2 - Normal\n";
	cout << "3 - Hard\n\n";

	enum userChoice 
	{ 
		Easy, 
		Normal, 
		Hard 
	};

	int input;
	cout << "Choice: ";
	cin >> input;

	userChoice choice = (userChoice)input;

	//int choice;
	//cout << "Choice: ";
	//cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "You picked Easy.\n";
		break;
	case 2:
		cout << "You picked Normal.\n";
		break;
	case 3:
		cout << "You picked Hard.\n";
		break;
	default:
		cout << "You made an illegal choice.\n";
	}

	return 0;
}