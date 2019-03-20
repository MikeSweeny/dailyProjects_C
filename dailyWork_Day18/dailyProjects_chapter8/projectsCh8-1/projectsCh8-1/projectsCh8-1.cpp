
#include "pch.h"
#include <iostream>
#include "enemy.h"

using namespace std;

void CreateEnemies();
int Enemy::numEnemies = 0;

int main()
{
	// Number of entires to create
	const int NUM1 = 3;
	cout << "In main()\n";
	cout << "Creating \n" << NUM1 << " enemy objects.\n";
	Enemy group1[NUM1];
	// Should display defensive tactics
	Enemy::DisplayTactics();
	// Should display aggressive tactics
	CreateEnemies();

	cout << "\nBack in main().\n";
	// Should display defensive tactics
	Enemy::DisplayTactics();

	return 0;
}


void CreateEnemies()
{
	Enemy* nme1 = new Enemy();
	Enemy* nme2 = new Enemy();
	Enemy::DisplayTactics();
	delete nme1;
	delete nme2;
}
