#include "Game.h"
using namespace std;


class War : public Game
{

	friend class Menu;

public:

	War();
	~War();
	void Flip(vector<string> Stack);
	void Compare();
	void GoToWar();
	void RefillHands();

	void Deal();
	void Play();
	void AnnounceWinner(int winner);
	bool GameWon = false;

	vector<string> PlayerMainHand;
	vector<string> PlayerSideHand;
	vector<string> CpuMainHand;
	vector<string> CpuSideHand;
	vector<string> pile;
	vector<string> pair;

private:

};

