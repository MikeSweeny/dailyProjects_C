#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

vector<string> wordList;
vector<char> guessList;
int pickWord;

void progress(string correctList)
{
	cout << "So far, the word is ";
	for (int i = 0; i < correctList.size(); i++)
	{
		cout << correctList[i];
	}
	cout << "\n";
}

void guessHistory(char guess)
{
	guessList.push_back(guess);
	for (int i = 0; i < guessList.size(); i++)
	{
		cout << guessList[i];
	}	
}

void makeGuess(string theWord, char guess, string &correctList, int &tries)
{
	size_t found;	
	found = theWord.find(guess);
	if (found == -1)
	{
		cout << "That letter isn't in the word!\n";
		tries++;
	}
	while (found != -1)
	{
		for (int j = 0; j < theWord.size(); j++)
		{
			if (guess == theWord[j])
			{
				correctList[j] = guess;
			}
		}
		found = -1;
		cout << "That letter IS in the word. Great guess!\n\n";
	}	
}

int main()
{
	string theWord;
	wordList.push_back("WALL");
	wordList.push_back("GLASSES");
	wordList.push_back("LABORED");
	wordList.push_back("PERSISTENT");
	wordList.push_back("JUMBLE");


	cout << "\t\tHANGMAN!!\n\n";
	srand(static_cast<unsigned int>(time(0)));  //seed random number generator
	pickWord = (rand() % wordList.size());
	theWord = wordList[pickWord];
	int length = theWord.size();

	string correctList;

	for (int i = 0; i < length; i++)
	{
		correctList.push_back('-');
	}
	cout << "\n";

	int maxTries = 8;
	int tries = 0;
	string guess;

	while (correctList != theWord)
	{
		cout << "Remaining incorrect guesses: " << (maxTries - tries) << "\n";
		progress(correctList);
		cout << "Guess a letter: ";
		
		char guess = 0;
		cin >> guess;
		cout << "\n";
		guess = toupper(guess);
		makeGuess(theWord, guess, correctList, tries);
		
		if (tries >= 0 && tries <= 2)
		{
			cout << "I--- \n";
			cout << "I    \n";
			cout << "I    \n";
			cout << "I    \n";
			cout << "_____\n\n";
			cout << "Guesses so far: ";
			guessHistory(guess);
			cout << "\n";
		}
		if (tries >= 2 && tries <= 4)
		{
			cout << "I--- \n";
			cout << "I  O \n";
			cout << "I    \n";
			cout << "I    \n";
			cout << "_____\n\n";
			cout << "Guesses so far: ";
			guessHistory(guess);
			cout << "\n";
		}
		if (tries >= 4 && tries <= 6)
		{
			cout << "I--- \n";
			cout << "I  O \n";
			cout << "I -|-\n";
			cout << "I    \n";
			cout << "_____\n\n";
			cout << "Guesses so far: ";
			guessHistory(guess);
			cout << "\n";
		}
		if (tries >= 8)
		{
			cout << "I--- \n";
			cout << "I  O \n";
			cout << "I -|-\n";
			cout << "I // \n";
			cout << "_____\n\n";
			cout << "I YOU ARE DEAD\n";
			cout << "\n\nYou're all out of tries!\n\n";
			break;
		}
	}
	if (correctList == theWord)
	{
		cout << "\nYo you win!\n\n";
	}		
	return 0;
}