#include "pch.h"
#include <iostream>
#include <string>
#include "node.h"
#include "Game.h"
using namespace std;

int main()
{
	List music1;
	cout << "\tOTHER LIST COPIER!!!!\n";
	cout << "\nList 1:\n";

	music1.Add("Rock");
	music1.Add("Techno");
	music1.Add("Rap");
	music1.Add("EDM");
	music1.Add("Jazz");
	music1.Add("Funk");
	music1.Add("Punk");

	music1.Display();

	cout << "\nList 2:\n";
	List music2;
	music2 = music1;
	music2.Display();

	return 0;
}