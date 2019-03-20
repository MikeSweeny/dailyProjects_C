#ifndef PLAYER_H
#define PLAYER_H

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "alien.h"
using namespace std;

// CLASS FOR PLAYER
class Player
{

public:

	//constructor prototype sets innitial ammo level
	Player(int ammo = 3);
	// Function prototype for shooting
	void Blast(Alien& anAlien);
	// Function for reloading
	void Reload();

private:

	//storage for amount of ammo
	int m_Ammo;

};

#endif