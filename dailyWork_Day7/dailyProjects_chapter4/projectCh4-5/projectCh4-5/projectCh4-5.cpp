#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int scores = 2;
const int players = 5;
string Score[players][scores];
void SetDefaultEntries(string s[players][scores]);
void DisplayTable(string s[players][scores]);
void InsertEntry();


int main()
{
	int choice = 0;
	SetDefaultEntries(Score);
	cout << "\tOh look a dumb score chart!\n";
	while (bool play = true)
	{
		if (choice == 0)
		{
			cout << "\n1 - Quit\n";
			cout << "2 - Display Table\n";
			cout << "3 - Insert New Entry\n\n";
			cout << "Select an option: ";
			cin >> choice;
			cout << "\n";
		}
		if (choice == 1)
		{
			return 0;
		}
		if (choice == 2)
		{
			DisplayTable(Score);
			choice = 0;
		}
		if (choice == 3)
		{
			InsertEntry();
			choice = 0;
		}
	}
	return 0;
}

void SetDefaultEntries(string s[players][scores])
{
	for (int i = 0; i < players; i++)
	{
		Score[i][0] = "SWEENY";
		Score[i][1] = "1000";
	}
}

void DisplayTable(string s[players][scores])
{
	for (int i = 0; i < players; i++)
	{
		for (int j = 0; j < scores; j++)
		{
			cout << Score[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

void InsertEntry()
{
	string name;
	int inputScore;
	int score;
	int scoring[players];
	// Set your name and score
	cout << "\nWhat is your player name?\n";
	cout << "Name: ";
	cin >> name;
	cout << "\nWhat is your player score?\n";
	cout << "Score: ";
	cin >> inputScore;

	stringstream ss;
	ss << inputScore;
	string highScore = ss.str();

	for (int m = 0; m < players; m++)
	{
		stringstream tmp(Score[m][1]);
		tmp >> scoring[m];
	}

	int lmnt = (players - 1);
	int lmnt2 = (players - 1);

	if (!(inputScore < scoring[players - 1]))
	{
		while (inputScore > scoring[lmnt - 1] && lmnt > 0)
		{
			--lmnt;
		}
		if (Score[lmnt][1] > Score[lmnt2][1])
		{
			Score[lmnt2][0] = Score[lmnt2 - 1][0];
			Score[lmnt2][1] = Score[lmnt2 - 1][1];
			--lmnt2;
		}
		if (lmnt < lmnt2)
		{
			Score[lmnt][0] = name;
			Score[lmnt][1] = highScore; 
		}
		lmnt = (players - 1);
		lmnt2 = (players - 1);
	}
	else
	{
		cout << "That score is too low, yo!\n";
	}
}