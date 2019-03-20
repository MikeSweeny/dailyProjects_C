#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "alien.h"


//constructor definition
Alien::Alien(int health)
{
	m_Health = health;
}

// Function definition for taking damage
void Alien::TakeDamage()
{
	//if hp is more than 1, take 1 damage and report
	if (m_Health > 1)
	{
		m_Health--;
		cout << "The alien took 1 damage from your space gun\n";
	}
	//if hp is 1, take 1 damage, die, and report
	else if (m_Health == 1)
	{
		m_Health--;
		cout << "The alien dies in a violent explosion!\n";
	}
	else
	{
		cout << "The alien is already dead... why did you waste that ammo?.. There could be more alien baddies afoot!\n";
	}
}

void Alien::Regenerate()
{
	//super simple, if they ain't dead, heal, report
	if (m_Health != 0)
	{
		m_Health++;
		cout << "The nasty alien regenerates some of its flesh by molting....ew\n";
	}
}