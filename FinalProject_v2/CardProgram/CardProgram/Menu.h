#include <Windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <wincon.h>
#include <cwchar>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Menu
{

	friend class War;

public:

	Menu();
	~Menu();

	void FontSize(int a, int b);
	void FontColour(string preset);
	void SlowPrint(string toType, float minDelay, float maxDelay);

	void SetPlayerName();
	void WelcomePlayer();
	void ShowGames();
	void WarInstructions();
	void FishInstructions();
	int SelectGame();

	int gameChoice;

	float fast = 0.04;
	float medium = 0.08;
	float slow = 0.6;

private:

	string m_playerName;

};