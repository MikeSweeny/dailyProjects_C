// projectCh3-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "A deck of cards!\n\n"; 

	const int suits = 4;
	const int values = 13;
	const char SUITS[suits]
	{
		'c',
		'h',
		's',
		'd'
	};
	const string VALUES[values]
	{
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"10",
		"J",
		"Q",
		"K",
		"A"
	};

	for (int j = 0; j < values; j++)	
	{
		for (int i = 0; i < suits; i++)
		{
		cout << VALUES[j];
		cout << SUITS[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}