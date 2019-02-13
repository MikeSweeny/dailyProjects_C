#include "pch.h"
#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

// Declare integers for how many people were saved and how many aliens died.
int citizenSaved, aliensKilled;
// Declare constants for point values.
const int savedPoints = 100;
const int killPoints = 50;

int main()
{
	cout << "Welcome to the galaxy shootout payout station!";
	cout << "\nVerify your kills and the number of civilians you have saved below to get your government mandated payout!";
	cout << "\n*Cough* Filthy Bounty Hunter *Cough*\n";
	cout << "\n\nEnter the number of aliens you killed now, please: ";
	cin >> aliensKilled;
	cout << "\n\nEnter the number of civilians you saved now, please: ";
	cin >> citizenSaved;
	system("CLS");
	cout << "Calculating payout.\n";
	Sleep(1000);
	system("CLS");
	cout << "Calculating payout..\n";
	Sleep(1000);
	system("CLS");
	cout << "Calculating payout...\n";
	Sleep(1000);
	cout << "Total Tax Deductable Payout:" << ((citizenSaved * savedPoints) + (aliensKilled * killPoints)) << "$$!\n\nThank you for your service.\n";

	return 0;

}