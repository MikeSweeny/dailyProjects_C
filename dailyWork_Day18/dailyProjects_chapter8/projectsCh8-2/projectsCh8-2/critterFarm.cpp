#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <ctime>
#include "critterFarm.h"


CritterFarm::CritterFarm()
{
	for (int i = 0; i < MAX_FARM_ANIMALS; ++i)
	{
		Critter *tmp = new Critter((rand() % 10), (rand() % 10));
		theFarm.push_back(*tmp);
		delete tmp;
	}
}

void CritterFarm::FarmTalk()
{
	for (int i = 0; i < MAX_FARM_ANIMALS; i++)
	{
		Critter* crit = &theFarm[i];
		crit->Talk();
	}
}

void CritterFarm::FarmEat()
{
	for (int i = 0; i < MAX_FARM_ANIMALS; i++)
	{
		Critter* crit = &theFarm[i];
		crit->Eat();
	}
}

void CritterFarm::FarmPlay()
{
	for (int i = 0; i < MAX_FARM_ANIMALS; i++)
	{
		Critter* crit = &theFarm[i];
		crit->Play();
	}
}

void CritterFarm::FarmPerformTrick()
{
	for (int i = 0; i < MAX_FARM_ANIMALS; i++)
	{
		Critter* crit = &theFarm[i];
		crit->PerformTrick();
	}
}