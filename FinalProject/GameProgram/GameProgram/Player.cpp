#include "pch.h"
#include "Player.h"

Player::Player()
{}

Player::~Player()
{
}

string Player::GetName() const
{
	return m_Name;
}

void Player::SetName(string name)
{
	m_Name = name;
} 

int Player::GetScore()
{
	cout << "Player score is: " << m_Score << endl;
	return m_Score;
}

void Player::SetScore(int data)
{
	m_Score = data;
}