#include "pch.h"
#include "enemy.h"
#include <iostream>

using namespace std;

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
