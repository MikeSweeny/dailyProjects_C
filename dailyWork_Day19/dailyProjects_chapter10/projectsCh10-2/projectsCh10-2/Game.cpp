#include "pch.h"
#include "Game.h"
#include "List.h"

const string Game::NORTH = "north";
const string Game::SOUTH = "south";
const string Game::ITEMS[NUM_ITEMS] = { "fox", "chicken", "grain" };



Game::Game()
{
	SetUp();
}

bool Game::IsWon() const
{
	if (m_North.Count() == NUM_ITEMS)
	{
		cout << "You won!!!\n\n";
		return true;
	}
	return false;
}

bool Game::IsLost(const List &withoutFarmer) const
{
	for (int i = 0; i < NUM_ITEMS - 1; ++i)
	{
		if (withoutFarmer.Contains(ITEMS[i]) && withoutFarmer.Contains(ITEMS[i + 1]))
		{
			cout << "The " << ITEMS[i];
			cout << " ate the " << ITEMS[i + 1] << "!\n";
			cout << "\tYOU LOST!!!";
		}
	}
	return false;
}

bool Game::IsPlaying() const
{
	bool lost;
	if (m_FarmerBank == SOUTH)
	{
		lost = IsLost(m_North);
	}
	else
	{
		lost = IsLost(m_South);
	}
	bool won = IsWon();
	return (!lost && !won);
}

void Game::SetUp()
{
	m_South.Clear();
	m_North.Clear();

	m_FarmerBank = SOUTH;

	for (int i = 0; i < NUM_ITEMS; ++i)
	{
		m_South.Add(ITEMS[i]);
	}
}

void Game::DisplayInstructions() const
{
	cout << "\tWelcome to Fox, Chicken, and Grain\n\n";
	cout << "A farmer must get his fox, chicken, and grain safely\n";
	cout << "across the river from the south bank to the north bank.\n";
	cout << "At most the farmer can take 1 thing when he ventures across.\n";
	cout << "If the farmer leaves the fox and chicken alone, the fox will eat the chicken.\n";
	cout << "If the farmer leaves the chicken and the grain alone, the chicken will eat the grain.\n\n";
	cout << "Help the farmer by entering the name of the thing you want him to carry\n";
	cout << "on his next trip across the river.\n";
	cout << "If you want the farmer to cross without carrying anything, enter 'nothing' when prompted.\n\n";
}

void Game::DisplayBanks() const
{
	cout << "South bank:\n";
	m_South.Display();
	cout << "\n";

	cout << "North bank:\n";
	m_North.Display();
	cout << "\n";

	cout << "The farmer is on the ";
	cout << m_FarmerBank << " bank.\n\n";
}

void Game::TransportItem(List &fromBank, List &toBank)
{
	string itemName;

	cout << "What should the farmer take?: ";
	cin >> itemName;
	cout << "\n";

	if (fromBank.Remove(itemName))
	{
		toBank.Add(itemName);
		cout << "The farmer takes the ";
		cout << itemName << " across teh river.\n";
	}
	else
	{
		cout << "The farmer takes nothing.\n";
	}
	cout << "\n";
}

void Game::Play()
{
	SetUp();
	DisplayBanks();

	while (IsPlaying())
	{
		if (m_FarmerBank == SOUTH)
		{
			TransportItem(m_South, m_North);
			m_FarmerBank = NORTH;
		}
		else
		{
			TransportItem(m_North, m_South);
			m_FarmerBank = SOUTH;
		}
		DisplayBanks();
	}
}