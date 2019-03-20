#pragma once
#include <string>
#include <iostream>
#include "List.h"
using namespace std;

class Game
{
public:

	Game();
	bool IsWon() const;
	bool IsLost(const List &withoutFarmer) const;
	bool IsPlaying() const;
	void SetUp();
	void DisplayInstructions() const;
	void DisplayBanks() const;
	void TransportItem(List &FromBank, List &toBank);
	void Play();

private:

	static const string NORTH;
	static const string SOUTH;

	static const int NUM_ITEMS = 3;
	static const string ITEMS[NUM_ITEMS];

	List m_North;
	List m_South;

	string m_FarmerBank;

};

