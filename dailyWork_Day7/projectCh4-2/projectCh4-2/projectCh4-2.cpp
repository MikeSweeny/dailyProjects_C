
#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int randomNumber(int high);
int randomNumber(int low, int high);
int number;

int main()
{
    cout << "\t\tWelcome to the range identifier.\n"; 
	for (int i = 0; i < 10; i++)
	{
		randomNumber(5);
		cout << "\n";
	}
	cout << "\n\n";
	for (int i = 0; i < 10; i++)
	{
		randomNumber(3, 6);
		cout << "\n";
	}
}

int randomNumber(int high)
{
	number = rand() % high;
	cout << number;
	return number;
}
int randomNumber(int low, int high)
{
	number = low + rand() % ((high + 1) - low);
	cout << number;
	return number;
}