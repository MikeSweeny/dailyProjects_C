#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "player.h"
using namespace std;


//constructor definition
Player::Player(int ammo)
{
	m_Ammo = ammo;
}

// Function definition for shooting
void Player::Blast(Alien& anAlien)
{
	//if ammo is 1 or more, shoot, otherwise say no ammo
	if (m_Ammo >= 1)
	{
		//if you shot successfully the alien needs to take damage
		anAlien.TakeDamage();
		m_Ammo--;
	}
	else
	{
		cout << "I'm out of ammo!\n";
	}
}

// Function definition for reloading
void Player::Reload()
{
	// No maximum magazine size is required so we just have to add 1 to the mag every time the reload function is called
	m_Ammo++;
	// I also like to tell the player when things happen successfully in text based interactions
	cout << "You load 1 more bullet into the space gun\n";
}