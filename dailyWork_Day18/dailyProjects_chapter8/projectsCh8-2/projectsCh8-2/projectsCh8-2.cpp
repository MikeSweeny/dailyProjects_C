
#include "pch.h"
#include <iostream>
#include "critterFarm.h"

int main()
{
	srand(time(NULL));
	CritterFarm crits;

	int choice;
	do
	{
		cout << "\nCritter Caretaker\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critters\n";
		cout << "2 - Feed your critters\n";
		cout << "3 - Play with your critters\n";
		cout << "4 - Ask your critters to perform a trick!\n\n";

		cout << "Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Good-bye.\n";
			break;
		case 1:
			crits.FarmTalk();
			break;
		case 2:
			crits.FarmEat();
			break;
		case 3:
			crits.FarmPlay();
			break;
		case 4:
			crits.FarmPerformTrick();
			break;
		case -1:
			cout << crits.m_Hunger << "\t" << crits.m_Boredom << "\n\n";
		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	} while (choice != 0);

	return 0;
}