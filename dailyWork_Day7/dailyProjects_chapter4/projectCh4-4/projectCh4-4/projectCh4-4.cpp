#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string randomWord(string aWord);
string mixUp(string aWord);
void welcomePlayer(const string aJumble);
void play(string aWord, const string aHint);
int getChoice();

const int NUM_WORDS = 5;
int choice = getChoice();

string h = "h";
string w = "w";


int main()
{
	string word = randomWord(w);
	string hint = randomWord(h);
	string jumble = mixUp(word);
	welcomePlayer(jumble);
	play(word, hint);

	return 0;
}

int getChoice()
{
	srand(static_cast<unsigned int>(time(0)));
	return (rand() % NUM_WORDS);
}

string randomWord(string aWord)
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."}
	};

	string theWord = WORDS[choice][WORD];  // word to guess
	string theHint = WORDS[choice][HINT];  // hint for word
	if (aWord == w)
	{
		return theWord;
	}
	if (aWord == h)
	{
		return theHint;
	}

}


string mixUp(const string aWord)
{
	string jumble = aWord;  // jumbled version of word
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	return jumble;
}

void welcomePlayer(const string aJumble)
{
	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "The jumble is: " << aJumble;
}

void play(string aWord, const string aHint)
{
	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != aWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << aHint;
		}
		else
		{
			cout << "Sorry, that's not it.";
		}

		cout << "\n\nYour guess: ";
		cin >> guess;
	}

	if (guess == aWord)
	{
		cout << "\nThat's it!  You guessed it!\n";
	}

	cout << "\nThanks for playing.\n";
}