#pragma once
#include "pch.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <wincon.h>
#include <cwchar>
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
	void SelectGame(int select) const;
	void ShowMenu();

private:
	bool m_IsPlaying = true;
	
};

