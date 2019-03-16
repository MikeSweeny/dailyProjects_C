#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Ship
{
public:
	Ship(string m_Name = "Enterprise", int m_Fuel = 0, int m_MaxFuel = 50);
	void Move(int distance)
	{
		if(distance <= 0)
		{
			cout << "That is not a valid move command.\n";
		}
		else if (distance > m_Fuel)
		{
			cout << "This ship does not have enough fuel to move that distance.\n";
		}
		else
		{
			cout << m_Name << " has moved " << distance << " Space Units from its original position.\n";
			m_Fuel = (m_Fuel - distance);
		}
		Status();
	}
	void Refuel(int additionalFuel)
	{
		if (additionalFuel <= 0)
		{
			cout << "That is not a valid additionalFuel amount.\n";
		}
		else if (m_Fuel == m_MaxFuel)
		{
			cout << "This ship already has a full tank of fuel.\n";
		}
		else
		{
			m_Fuel = (m_Fuel + additionalFuel);
			if (m_Fuel > m_MaxFuel)
			{
				m_Fuel = m_MaxFuel;
			}
			cout << "Added " << additionalFuel << " Space Fuelz to " << m_Name << "'s tank.\n";
		}
		Status();
	}
	void Status()
	{
		cout << "Ship Name: " << m_Name << "\nShip Fuelz: " << m_Fuel << "sU\nShip Tankz: " << m_MaxFuel << "sU\n\n";
	}
private:
	string m_Name;
	int m_Fuel;
	int m_MaxFuel;
};

Ship::Ship(string name, int fuel, int maxFuel)
{
	if (fuel < 0)
	{
		fuel = 0;
	}
	if (fuel > maxFuel)
	{
		fuel = maxFuel;
	}
	m_Name = name;
	m_Fuel = fuel;
	m_MaxFuel = maxFuel;
}

int main()
{
	cout << "\tWelcome to the starship viewer.\n\nAll measurements are made in standard Space Units as mandated by the\nAstroGalactic Structural Stability Society, or ASSS for short.\n\n\n";
	
	Ship enterprise("Enterprise", 10);

	enterprise.Status();
	enterprise.Move(5);
	enterprise.Move(50);
	enterprise.Move(-10);
	enterprise.Refuel(10);
	enterprise.Refuel(-10);

	cout << "\n\n";

	return 0;
}