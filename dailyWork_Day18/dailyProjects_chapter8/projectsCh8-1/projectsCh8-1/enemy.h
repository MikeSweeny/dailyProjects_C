#pragma once
#ifndef ENEMY_H
#define ENEMY_H

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

#endif