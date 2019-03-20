#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <ctime>
#include "critter.h"

const string Critter::TRICKS[NUM_TRICKS] =
{
	"Roll Over",
	"Jump",
	"Backflip"
};

Critter::Critter(int hunger, int boredom)
{
	m_Hunger = hunger;
	m_Boredom = boredom;
}

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