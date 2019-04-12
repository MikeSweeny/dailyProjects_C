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
#include "War.h"
#include "GoFish.h"

using namespace std;

class Menu
{

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
	
};


#endif
