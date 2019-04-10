#ifndef GOFISH_H
#define GOFISH_H
#include "Game.h"

class GoFish : public Game
{
public:
	GoFish();
	~GoFish();
	void DisplayHand();
	void Ask();
	void CheckEnemy();
	void MakePair();
	void Draw();
	bool HandValidate();
	int HandCount();
	bool HasWon();

	void DisplayInstructions();
	void Deal();
	void Play();
	void AnnounceWinner();
};


#endif