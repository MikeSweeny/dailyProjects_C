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
	void PerformTrick();

private:
	int m_Hunger;
	int m_Boredom;
	static const int MAX_HUNGER = 10;
	static const int NUM_TRICKS = 3;
	static const string TRICKS[NUM_TRICKS];
	bool m_IsAlive = true;
	int GetMood() const;
	void PassTime(int time = 1);

};

const string Critter::TRICKS[NUM_TRICKS] =
{
	"Roll Over",
	"Jump",
	"Backflip"
};

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
	if (m_Hunger >= 10)
	{
		m_IsAlive = false;
		cout << "The critter is dead. From neglect. You're a monster.\n";
	}
	else
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
		PassTime();
	}	
}

void Critter::Eat(int food)
{
	if (!m_IsAlive)
	{
		system("CLS");
		cout << "\nWhat are you going to do, shove the food into its limp mouth?\nMassage it down its flaccid gullet?\n\n";
	}
	else
	{
		cout << "Brruppp.\n";

		m_Hunger -= food;
		if (m_Hunger < 0)
		{
			m_Hunger = 0;
		}
	}
	PassTime();
}

void Critter::Play(int fun)
{
	if (!m_IsAlive)
	{
		system("CLS");
		cout << "\nOh for the love of God! Leave it alone, its lifeless body deflated on the ground.\nShame on you.\n\n";
	}
	else
	{
		cout << "Wheee!\n";

		m_Boredom -= fun;
		if (m_Boredom < 0)
		{
			m_Boredom = 0;
		}
	}
	PassTime();
}

void Critter::PerformTrick()
{
	if (GetMood() > 5)
	{
		cout << "I don't feel like doing a trick\n";
	}
	else
	{
		int choice = (rand() % NUM_TRICKS);
		string trick = TRICKS[choice];
		cout << "I " << trick << ".\n";
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
		cout << "3 - Play with your critter\n";
		cout << "4 - Ask your critter to perform a trick!\n\n";

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
			crit.PerformTrick();
			break;
		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	} while (choice != 0);

	return 0;
}

