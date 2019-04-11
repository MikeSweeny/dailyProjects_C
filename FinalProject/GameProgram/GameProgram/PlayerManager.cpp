#include "pch.h"
#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

string PlayerManager::GetPlayerName(int playerNum)
{
	m_Players[playerNum].GetName();
}

void PlayerManager::SetPlayerName(int playerNum, string name)
{
	m_Players[playerNum].SetName(name);
}

int PlayerManager::GetPlayerScore(int playerNum)
{
	m_Players[playerNum].GetScore();
}

void PlayerManager::SetPlayerScore(int playerNum, int num)
{
	m_Players[playerNum].SetScore(num);
}
