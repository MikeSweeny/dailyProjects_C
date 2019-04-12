#ifndef WAR_H
#define WAR_H
#include <vector>
#include <string>
#include "Game.h"
using namespace std;

class War : public Game
{
public:
	War();
	~War();
	void Flip(vector<string> Stack);
	void Compare();
	void GoToWar();
	void RefillHand();

	void DisplayInstructions();
	void Deal();
	void Play();
	void AnnounceWinner();

private:
	vector <string> pile;
	vector <string> pair;
};


#endif