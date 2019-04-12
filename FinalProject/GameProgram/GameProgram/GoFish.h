#ifndef GOFISH_H
#define GOFISH_H
#include <vector>
#include <string>
using namespace std;

class GoFish
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