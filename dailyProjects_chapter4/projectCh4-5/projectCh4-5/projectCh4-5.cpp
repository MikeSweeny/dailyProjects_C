// projectCh3-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

vector<string> wordList;
vector<string> guessList;
vector<string> correctList;
int choice = (rand() % wordList.size());
string theWord = wordList[choice];

void progress()
{
	cout << "So far, the word is ";
	for (int i = 0; i < theWord.size(); i++)
	{
		cout << "-";
	}
}

int main()
{
	wordList.push_back("wall");
	wordList.push_back("glasses");
	wordList.push_back("labored");
	wordList.push_back("persistent");
	wordList.push_back("jumble");



	cout << "\t\tHANGMAN!!\n\n\n";
	srand(static_cast<unsigned int>(time(0)));  //seed random number generator

	const int maxTries = 8;
	int tries = 0;
	string guess;
	int found = 0;

	progress();

	while(true)
	{
		cout << "Guess a letter: ";
		cin >> guess;
		char guess[];
		string found = theWord.find(guess);
		for (int i = 0; i > theWord.size(); i++)
		{
			found[i] = theWord.find(guess, found + 1);
		}
		while (found != -1)
		{

		}
		
	}

	
	cout << "\n\nYou're all out of tries!\n\n";

	return 0;

}