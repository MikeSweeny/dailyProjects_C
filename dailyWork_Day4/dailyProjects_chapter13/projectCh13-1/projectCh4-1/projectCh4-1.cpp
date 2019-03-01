// Word Jumble
// The classic word jumble game where the player can ask for a hint
#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	vector<string> wordList;

	wordList.push_back("wall");
	wordList.push_back("glasses");
	wordList.push_back("labored");
	wordList.push_back("persistent");
	wordList.push_back("jumble");

	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."}
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = wordList[choice];  // word to guess
	string theHint = WORDS[choice][HINT];  // hint for word

	string jumble = theWord;  // jumbled version of word
	
	random_shuffle(jumble.begin(), jumble.end());

	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "The jumble is: " << jumble;

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "Sorry, that's not it.";
		}

		cout << "\n\nYour guess: ";
		cin >> guess;
	}

	if (guess == theWord)
	{
		cout << "\nThat's it!  You guessed it!\n";
	}

	cout << "\nThanks for playing.\n";

	return 0;
}
