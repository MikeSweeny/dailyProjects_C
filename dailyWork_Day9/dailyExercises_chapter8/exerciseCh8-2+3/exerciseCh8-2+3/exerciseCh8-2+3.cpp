// Question 2. The code below.
// Question 3. The GetHunger() function returns a constant value, this means it should be in the private class permissions. 
//			   If you were to move it to private as it should be though, it will no longer be accessible in the main function below.
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Critter
{
public:
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);
	void Hack();

private:
	int m_Hunger;
	int m_Boredom;

	int GetMood() const;
	void PassTime(int time = 1);

};

void Critter::Hack()
{
	int mood = GetMood();
	cout << mood;
}

Critter::Critter(int hunger, int boredom) :
	m_Hunger(hunger),
	m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Talk()
{
	cout << "I'm a critter and I feel ";

	int mood = GetMood();
	if (mood > 15)
	{
		cout << "mad.\n";
	}
	else if (mood > 10)
	{
		cout << "frustrated.\n";
	}
	else if (mood > 5)
	{
		cout << "okay.\n";
	}
	else
	{
		cout << "happy.\n";
	}
	if (m_Hunger > 8)
	{
		cout << "\nAre you going to let me starve and die?\n";
	}
	else if (m_Hunger > 4)
	{
		cout << "\nMy tummy hurts!\n";
	}
	if (m_Boredom > 8)
	{
		cout << "\nHoly shit you're more boring than Steve's lectures...\n";
	}
	else if (m_Boredom > 4)
	{
		cout << "\nYaaaaaaaaawnnnn...\n";
	}

	PassTime();
}

void Critter::Eat(int food)
{
	cout << "Brruppp.\n";

	m_Hunger -= food;
	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}

	PassTime();
}

void Critter::Play(int fun)
{
	cout << "Wheee!\n";

	m_Boredom -= fun;
	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}

	PassTime();
}

int main()
{
	Critter crit;
	crit.Talk();

	int choice;
	do
	{
		cout << "\nCritter Caretaker\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critter\n";
		cout << "2 - Feed your critter\n";
		cout << "3 - Play with your critter\n\n";

		cout << "Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Good-bye.\n";
			break;
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		case 4:
			crit.Hack();
			break;
		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	} while (choice != 0);

	return 0;
}

