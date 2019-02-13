#include "pch.h"
#include <iostream>
#include "windows.h"

using namespace std;

// Declare a variable for the 3 player scores

float score1, score2, score3;

int main()
{
	cout << "\nThe team with the highest average score wins!\n";
	cout << "\nPlease, enter your scores below, one at a time.\n";
	cout << "\nFirst score please! ";
	cin >> score1;
	cout << "\nSecond score please! ";
	cin >> score2;
	cout << "\nThird score please! ";
	cin >> score3;
	system("cls");
	cout << "\nthank you! the system is calculating your team score now.";
	Sleep(1000);
	system("cls");
	cout << "\nthank you! the system is calculating your team score now..";
	Sleep(1000);
	system("cls");
	cout << "\nthank you! the system is calculating your team score now...";
	Sleep(1000);
	system("cls");

	cout << "\nYour team score is: " << ((score1 + score2 + score3) /3) << "\n\n\n";

	return 0;
}