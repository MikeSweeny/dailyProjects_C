#ifndef WAR_H
#define WAR_H
#include "Game.h"

class War : public Game, public Menu
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