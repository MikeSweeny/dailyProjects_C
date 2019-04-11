#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Player
{
public:
	Player();
	~Player();
	int GetScore();
	void SetScore(int data);

	void SetName(string name);
	string GetName() const;

	vector<string> MainHand;
	vector<string> SideHand;

private:

	string m_Name;
	int m_Score;
};


#endif