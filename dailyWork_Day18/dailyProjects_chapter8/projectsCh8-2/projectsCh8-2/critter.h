#pragma once
#ifndef CRITTER_H
#define CRITTER_H

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <ctime>

using namespace std;

class Critter
{
public:
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);
	void PerformTrick();
	int m_Hunger;
	int m_Boredom;

private:
	static const int MAX_HUNGER = 10;
	static const int MIN_HUNGER = 0;
	static const int NUM_TRICKS = 3;
	static const string TRICKS[NUM_TRICKS];
	bool m_IsAlive = true;
	int GetMood() const;
	void PassTime(int time = 1);

};

#endif