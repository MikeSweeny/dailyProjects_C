#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Ship
{
public:
	void Move(int d);
	void Status();															
	Ship(string m_Name = "Enterprise", int m_Fuel = 0);
	void Move(int distance)
	{

	}
	void Status()
	{
		cout << m_Name << "\t" << m_Fuel << "\n";
	}
private:
	string m_Name;
	int m_Fuel;
};

Ship::Ship(string name, int fuel)
{
	if (fuel < 0)
	{
		fuel = 0;
	}
	m_Name = name;
	m_Fuel = fuel;
}

int main()
{
	Ship vessel1;
	vessel1.Status();

	Ship vessel2("Voyager", 10);
	vessel2.Status();

	Ship vessel3("Millenium Falcon", -10);
	vessel3.Status();

	return 0;
}