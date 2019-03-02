#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;
vector<int>::const_iterator iter;
vector<int> pScores;

void listFunction()
{
	for (iter = pScores.begin(); iter != pScores.end(); ++iter)
	{
		cout << *iter << "\n";
	}
}

int main()
{
	cout << "Oh look a dumb score chart!\n\n";
	const int scores = 5;
	const int players = 5;
	string name;
	int inputScore;
	int scoring[players];

	pScores.push_back(1111);
	pScores.push_back(4200);
	pScores.push_back(2000);
	pScores.push_back(3500);
	pScores.push_back(4999);

	sort(pScores.begin(), pScores.end(), greater<int>());

	listFunction();

	while (true)
	{
		cout << "\nWhat is your player score?\n";
		cout << "Score: ";
		cin >> inputScore;
		if (!cin.fail())
		{
			pScores.push_back(inputScore);
			sort(pScores.begin(), pScores.end(), greater<int>());
			listFunction();
		}
		else
		{
			cout << "\n\nScores should be numbers yo...\n\n";
			cin.clear();
			cin.ignore();
		}
	}
	return 0;
}