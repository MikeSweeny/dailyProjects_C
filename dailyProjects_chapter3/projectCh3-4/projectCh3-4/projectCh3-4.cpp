#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	while (true)
	{
		// Setting up the board
		cout << "Oh look a dumb score chart!\n";
		const int scores = 5;
		const int players = 5;
		string name;
		string pName[5]  = { "" };
		string pScore[5] = { "" };
		string SCORE[players][scores]
		{
			{"Sweeny\t", "1000"},
			{"Sweeny\t", "1000"},
			{"Sweeny\t", "1000"},
			{"Sweeny\t", "1000"},
			{"Sweeny\t", "1000"}

		};

		for (int i = 0; i < players; i++)
		{
			for (int j = 0; j < scores; j++)
			{
				cout << SCORE[i][j];
			}
			cout << "\n";
		}

		// Select your number
		cout << "What is your player number? (1-5 only)\n\n";
		cout << "Number: ";
		int input;
		cin >> input;
		int choice = (input - 1);

		
		// Set your name and score
		cout << "\nWhat is your player name?\n";
		cout << "Name: ";
		cin >> name;
		pName[choice] = name + "\t";
		SCORE[choice][0] = pName[choice];

		cout << "\nWhat is your player score?\n";
		cout << "Score: ";
		cin >> pScore[choice];
		SCORE[choice][1] = pScore[choice];
		stringstream playerScore(pScore[choice]);
		int x = 0;
		playerScore >> x;
		int scoreValues[scores];

		for (int l; l < scores; l++)
		{
			stringstream tmp(SCORE[l][1]);
			tmp >> scoreValues;
		}

		// Acceptance criteria
		if (x > 500 && x < 5000)
		{
			// Clear the screen and print the scoreboard
			system("CLS");
			for (int i = 0; i < players; i++)
			{
				for (int j = 0; j < scores; j++)
				{
					cout << SCORE[i][j];
				}
				cout << "\n";
			}
		}
		else
		{
			cout << "That is an invalid score, yo!";
		}
	}
	return 0;
}