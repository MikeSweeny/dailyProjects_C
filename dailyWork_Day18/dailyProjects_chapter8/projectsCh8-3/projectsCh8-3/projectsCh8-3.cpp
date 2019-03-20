#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "alien.h"
#include "player.h"

using namespace std;


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