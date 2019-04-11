#ifndef MENU_H
#define MENU_H
#include <Windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <wincon.h>
#include <cwchar>
#include <vector>
#include <array>
#include <algorithm>
#include "GoFish.h"
#include "War.h"
using namespace std;

class Menu
{
	friend class Game;

public:
	Menu();
	~Menu();
	void FontSize(int a, int b);
	void FontColour(string preset);
	void SlowPrint(string toType, float minDelay, float maxDelay);
	void WelcomePlayer();
	void SelectGame(int select);
	void ShowMenu();

private:
	bool m_IsPlaying = true;
	War warGame;
	GoFish fishGame;
	
};

#endif
