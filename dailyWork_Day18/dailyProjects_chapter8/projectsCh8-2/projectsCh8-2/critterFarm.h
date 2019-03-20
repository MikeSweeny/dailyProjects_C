#pragma once
#ifndef CRITTERFARM_H
#define CRITTERFARM_H

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <ctime>
#include "critter.h"

class CritterFarm : public Critter
{
public:
	friend class Critter;
	CritterFarm();
	void FarmTalk();
	void FarmEat();
	void FarmPlay();
	void FarmPerformTrick();
private:
	static const int MAX_FARM_ANIMALS = 5;
	vector<Critter> theFarm;
};


#endif