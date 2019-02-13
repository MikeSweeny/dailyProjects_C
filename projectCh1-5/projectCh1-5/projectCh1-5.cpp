#include "pch.h"
#include <iostream>
#include "windows.h"
#include <string>

using namespace std;

// Declare integers for the number of spells the player has after how much practice.

int spellMin, spellCostHours;



int main() {

	string lastName;
	string pet;
	string colour;


	cout << "Hello, young wizard. It is time for you to embark on an epic (mad libs style) story!!\n\n";
	cout << "Describe yourself wizard!\n";
	cout << "Enter your last name: ";
	cin >> lastName;
	cout << "\nPick a positive number: ";
	cin >> spellMin;
	cout << "\nPick a larger positive number: ";
	cin >> spellCostHours;
	cout << "\nWhat is your favourite animal?!: ";
	cin >> pet;
	cout << "\nWhat is your favourite colour!?: ";
	cin >> colour;

	system("CLS");
	cout << "\n\nGenerating story.";
	Sleep(1000);
	system("CLS");
	cout << "\n\nGenerating story..";
	Sleep(1000);
	system("CLS");
	cout << "\n\nGenerating story...";
	Sleep(1000);
	system("CLS");

	if (spellMin * spellCostHours <= 50)
	{
		cout << "The wizard leaves his house ready to represent house " << lastName << " at the wizard trials.\n";
		cout << "Having practiced at least " << spellMin << " spells, they were confident they could compete for honor and glory.\n";
		cout << "But the wizard had only studied for " << (spellMin * spellCostHours) << " hours. Not nearly enough effort was given to each spell to properly master it.\n\n";
		cout << "The " << lastName << " wizard champion was overthrown by the competition early in the match.\n";
		cout << "You explode violently in a black and " << colour << " eruption of lava created by a wizard from House Sweeny.";
		cout << "\n\nYOU LOSE!\n\n\n\n";
	}

	if (spellMin * spellCostHours >= 51)
	{
		cout << "The wizard leaves his house ready to represent house " << lastName << " at the wizard trials.\n";
		cout << "Having practiced at least " << spellMin << " spells, they were confident they could compete for honor and glory.\n";
		cout << "The wizard studied tirelessly, at least " << (spellMin * spellCostHours) << " hours between the " << spellMin << " spells they mastered.\n\n";
		cout << "The " << lastName << " wizard champion fought valiantly, destroying the final combatant in the Battle Royal class exams.\n";
		cout << "Summoning a giant " << colour << " " << pet << " you kill the wizard of Coverdale house. Watching as your " << pet << " chews on his throat.";
		cout << "\n\nYOU WIN!\n\n\n\n";
	}


	return 0;
}