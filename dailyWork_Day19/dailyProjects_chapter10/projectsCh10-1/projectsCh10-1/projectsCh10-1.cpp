#include "pch.h"
#include <iostream>
#include <string>
#include "node.h"
#include "Game.h"
using namespace std;

int main()
{
	List music;

	cout << "\tA LIST COPIER!!!!\n";
	cout << "\nList 1:\n";

	music.Add("Rock");
	music.Add("Techno");
	music.Add("Rap");
	music.Add("EDM");
	music.Add("Jazz");
	music.Add("Funk");
	music.Add("Punk");
	music.Display();

	cout << "\nList 2:\n";

	List music2 = music;
	music2.Display();

	return 0;
}