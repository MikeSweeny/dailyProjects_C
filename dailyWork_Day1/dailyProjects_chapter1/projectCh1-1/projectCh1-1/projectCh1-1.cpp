#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

char selection = '3';
void playerInput();
bool isInputGood = true;
int selectionValid = '-1';

void playerInput()
{
	cout << "\n1. One Player\n";
	cout << "2. Two Player\n";
	cout << "3. Main Menu\n";
	cout << "4. Quit\n";
	cout << "\nChoose one (enter its # and hit enter).\n";

	cin >> selection;

}


int main()
{
	cout << "MAIN MOFUQIN MENU!\n\n";
	playerInput();

	while (isInputGood)
	{
		if (selection == '1')
		{
			system("CLS");
			cout << "Welcome to single player!\n";
			playerInput();
		}
		else if (selection == '2')
		{
			system("CLS");
			cout << "Welcome to two player!\n";
			playerInput();
		}
		else if (selection == '3')
		{
			system("CLS");
			cout << "MAIN MOFUQIN MENU!\n\n";
			playerInput();
		}
		else if (selection == '4')
		{
			system("CLS");
			return 0;
		}
		else
		{
			system("CLS");
			cout << "YO YOU SUCK! \nTry one of the keys I told you to next time...\n";
			selection = '3';
			playerInput();
		}
		cout << selection << endl;
	}
	return 0;
}
