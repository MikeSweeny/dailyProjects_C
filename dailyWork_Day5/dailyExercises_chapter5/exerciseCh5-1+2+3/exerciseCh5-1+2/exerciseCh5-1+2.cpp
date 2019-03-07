// Question 1. Once you define a default argument for a parameter, you must define arguments for all following parameters.
// Question 2. Reference chapter 13 project 5.
// Question 3. The code below.

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int number();
int number(string prompt);
string yo = "Yo ";


int main()
{
	number();
	if (number(yo) == 1)
	{
		cout << "\nSecret level unlocked!\n\n";
	}
	return 0;
}

int number()
{
	int number;
	cout << ">> ";
	cin >> number;
	return number;
}

int number(string prompt)
{
	int number;
	cout << prompt << ">> ";
	cin >> number;
	return number;
}