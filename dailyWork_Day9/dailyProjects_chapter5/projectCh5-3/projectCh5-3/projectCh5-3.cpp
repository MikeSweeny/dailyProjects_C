// Hero's Inventory 3.0
// Demonstrates iterators
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<string> inventory;
vector<string> room;
vector<string>::iterator myIterator;
vector<string>::const_iterator iter;
string itemSelection;
string roomSelect;
string choice;
string temp;
string inventorySelect;
int playerInput = 0;
int itemNumber = 1;

void inventoryPrint()
{
	cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << " " << *iter << "\n";
		itemNumber++;
	}
	itemNumber = 1;
}

void roomPrint()
{
	cout << "\nThe room contains:\n";
	for (iter = room.begin(); iter != room.end(); ++iter)
	{
		cout << " " << *iter << "\n";
		itemNumber++;
	}
	itemNumber = 1;
}

const string get()
{
	cout << "Select an item to pick up.\nItem: ";
	cin.clear();
	cin >> roomSelect;
	if (!cin.fail())
	{
		vector<string>::const_iterator roomIter = find(room.begin(), room.end(), roomSelect);
		if (roomIter != room.end())
		{
			cout << "You picked up the ";
			cout << *roomIter;
			inventory.push_back(*roomIter);
			room.erase(roomIter);
			playerInput = 0;
		}
		else
		{
			cout << "That item isn't in the room.";
		}
	}
}

void drop()
{
	cout << "Select an item to drop.\nItem: ";
	cin >> inventorySelect;
	if (!cin.fail())
	{
		vector<string>::const_iterator inventoryIter = find(inventory.begin(), inventory.end(), inventorySelect);
		if (inventoryIter != inventory.end())
		{
			cout << "You dropped the ";
			cout << *inventoryIter;
			room.push_back(*inventoryIter);
			inventory.erase(inventoryIter);
			playerInput = 0;
		}
	}
	else
	{
		cout << "That item isn't in your inventory.";
	}
}

int main()
{
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	room.push_back("chair");
	room.push_back("wand");
	room.push_back("dicks");

	while (playerInput >= 0 && playerInput < 5)
	{
		switch (playerInput)
		{
		case 0:
			cout << "\nWhat would you like to do?\n\nHint: Try \n'1' Look\n'2' Inventory\n'3' Get\n'4' Drop\n\nInput: ";
			cin >> playerInput;
			system("CLS");
			break;
		case 1:
			roomPrint();
			playerInput = 0;
			break;
		case 2:
			inventoryPrint();
			playerInput = 0;
			break;
		case 3:
			get();
			playerInput = 0;
			break;
		case 4:
			drop();
			playerInput = 0;
			break;
		default:
			break;
		}
	}
	cout << "You do nothing and die of starvation or dehydration or boredom or something...";
	return 0;
}
