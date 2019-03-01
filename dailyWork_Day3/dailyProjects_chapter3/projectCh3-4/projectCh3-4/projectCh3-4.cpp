#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	cout << "Oh look a dumb score chart!\n\n";
	const int scores = 5;
	const int players = 5;
	string name;

	int inputScore;

	int score;
	int scoring[players];
	string pName[5] = { "" };
	string SCORE[players][scores]
	{
		{"Sweeny\t", "5000"},
		{"Sweeny\t", "4000"},
		{"Sweeny\t", "3000"},
		{"Sweeny\t", "2000"},
		{"Sweeny\t", "1000"}

	};
	while (true)
	{
		for (int i = 0; i < players; i++)
		{
			for (int j = 0; j < scores; j++)
			{
				cout << SCORE[i][j];
			}
			cout << "\n";
		}		
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
			stringstream tmp(SCORE[m][1]);
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
			while (lmnt < lmnt2)
			{
				SCORE[lmnt2][0] = SCORE[lmnt2 - 1][0];
				SCORE[lmnt2][1] = SCORE[lmnt2 - 1][1];
				--lmnt2;
				SCORE[lmnt][0] = name + "\t";
				SCORE[lmnt][1] = highScore;
			}
		}
		else
		{
			cout << "That score is too low, yo!\n";
		}
	}
	return 0;
}