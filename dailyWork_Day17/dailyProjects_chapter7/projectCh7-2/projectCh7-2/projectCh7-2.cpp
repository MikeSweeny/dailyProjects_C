#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <ctime>

using namespace std;

class Critter
{
public:
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);
	void PerformTrick();
	int m_Hunger;
	int m_Boredom;

private:
	static const int MAX_HUNGER = 10;
	static const int MIN_HUNGER = 0;
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

class CritterFarm : public Critter
{
public:
	friend class Critter;
	CritterFarm();
	void FarmTalk();
	void FarmEat();
	void FarmPlay();
	void FarmPerformTrick();
private:
	static const int MAX_FARM_ANIMALS = 5;
	vector<Critter> theFarm;
};

CritterFarm::CritterFarm()
{
	for (int i = 0; i < MAX_FARM_ANIMALS; ++i)
	{
		Critter *tmp = new Critter((rand() % 10), (rand() % 10));
		theFarm.push_back(*tmp);
		delete tmp;
	}
}

void CritterFarm::FarmTalk()
{
	for (int i = 0; i < MAX_FARM_ANIMALS; i++)
	{
		Critter* crit = &theFarm[i];
		crit->Talk();
	}
}

void CritterFarm::FarmEat()
{
	for (int i = 0; i < MAX_FARM_ANIMALS; i++)
	{
		Critter* crit = &theFarm[i];
		crit->Eat();
	}
}

void CritterFarm::FarmPlay()
{
	for (int i = 0; i < MAX_FARM_ANIMALS; i++)
	{
		Critter* crit = &theFarm[i];
		crit->Play();
	}
}

void CritterFarm::FarmPerformTrick()
{
	for (int i = 0; i < MAX_FARM_ANIMALS; i++)
	{
		Critter* crit = &theFarm[i];
		crit->PerformTrick();
	}
}

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

