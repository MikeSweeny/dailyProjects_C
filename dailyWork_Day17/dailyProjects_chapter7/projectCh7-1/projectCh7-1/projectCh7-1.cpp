#include "pch.h"
#include <string>
#include <iostream>
#include <vector>;
using namespace std;

class Enemy
{

public:

	Enemy();
	~Enemy();
	static void DisplayTactics();
	static void SetNumEnemies(int addRemove);

private:

	static int numEnemies;

};

Enemy::Enemy()
{
	SetNumEnemies(1);
}

Enemy::~Enemy()
{
	SetNumEnemies(0);
}

void Enemy::SetNumEnemies(int addRemove)
{
	if (addRemove == 1)
	{
		numEnemies++;
	}
	if (addRemove == 0)
	{
		numEnemies--;
	}
}

void Enemy::DisplayTactics()
{
	if (numEnemies < 5)
	{
		cout << "Engaging Defensive Tactics Set.\n";
	}
	else
	{
		cout << "Engaging Aggressive Tactics Set.\n";
	}
}




void CreateEnemies()
{
	Enemy* nme1 = new Enemy();
	Enemy* nme2 = new Enemy();
	Enemy::DisplayTactics();
	delete nme1;
	delete nme2;
}

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