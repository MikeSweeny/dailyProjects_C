// I am going to start trying to comment my code more, partly because I haven't done a great job adding any comments so far,
// and because the complex nature of what we are learning is starting to get harder and I hope this will help me organize my thoughts.
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






int main()
{
    // Main objectives are:
	// - spawn 1 player and 1 alien 
	Player player1;
	Alien enemy1;
	// - have the player shoot 4 times
	player1.Blast(enemy1);
	player1.Blast(enemy1);
	player1.Blast(enemy1);
	player1.Blast(enemy1);
	// - have the alien regen once
	enemy1.Regenerate();
	// - have the player reload 4 times
	player1.Reload();
	player1.Reload();
	player1.Reload();
	player1.Reload();
	// - have the player shoot 4 times
	player1.Blast(enemy1);
	player1.Blast(enemy1);
	player1.Blast(enemy1);
	player1.Blast(enemy1);

	return 0;
}