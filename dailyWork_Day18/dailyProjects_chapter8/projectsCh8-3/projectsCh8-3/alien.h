#ifndef ALIEN_H
#define ALIEN_H

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// CLASS FOR ALIEN
class Alien
{

public:

	//constructor prototype sets initial health value
	Alien(int health = 5);
	// Function for taking damage
	void TakeDamage();
	// Function for regenerating
	void Regenerate();

private:

	//storage for ammount of health
	int m_Health;

};

#endif
