#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class HighScoreTable
{
public:
	HighScoreTable();
	void Display(const int r, const int c) const;
	void SetDefaultEntries(const int r, const int c);
	void InsertEntry(const string& aName, int aScore, const int r, const int c);
private:
	static const int NUM_ENTRIES = 5;
	int scoring[NUM_ENTRIES];
	string m_Names[NUM_ENTRIES];
	string m_Scores[NUM_ENTRIES];
};

HighScoreTable::HighScoreTable()
{
	
}
void HighScoreTable::Display(const int r, const int c) const
{
	for (int i = 0; i < r; i++)
	{
		cout << m_Names[i] << "\t" << m_Scores[i] << "\n";
	}
}
void HighScoreTable::SetDefaultEntries(const int r, const int c)
{
	for (int i = 0; i < r; i++)
	{
		stringstream tt;
		tt << i;
		string num = tt.str();
		m_Names[i] = "SWEENY" + num;
		m_Scores[i] = "1000";
	}
}
void HighScoreTable::InsertEntry(const string& aName, int aScore, const int r, const int c)
{
	system("CLS");
	stringstream ss;
	ss << aScore;
	string highScore = ss.str();
	for (int m = 0; m < r; m++)
	{
		stringstream tmp(m_Scores[m]);
		tmp >> scoring[m];
	}

	int lmnt = (r - 1);
	int lmnt2 = (r - 1);


	if (!(aScore < scoring[lmnt]))
	{
		for (lmnt; lmnt >= 0; lmnt--)
		{
			if (aScore > scoring[lmnt] && lmnt != 0)
			{
				m_Scores[lmnt] = m_Scores[lmnt - 1];
				m_Names[lmnt] = m_Names[lmnt - 1];
			}
			else if (aScore <= scoring[lmnt])
			{
				m_Scores[lmnt + 1] = highScore;
				m_Names[lmnt + 1] = aName;
			}
			else if (lmnt <= 0)
			{
				m_Scores[lmnt] = highScore;
				m_Names[lmnt] = aName;
			}
		}
	}
	else
	{
		cout << "That score is too low, yo!\n";
	}
}

int main()
{
	const int rows = 5;
	const int columns = 2;
	string name;
	int inputScore;

	HighScoreTable MyTable;
	MyTable.SetDefaultEntries(rows, columns);

	cout << "\tOh look a dumb score chart!\n";
	while (bool play = true)
	{
		int choice = 0;
		if (choice == 0)
		{
			cout << "\n1 - Quit\n";
			cout << "2 - Display Table\n";
			cout << "3 - Insert New Entry\n\n";
			cout << "Select an option: ";
			cin >> choice;
			cout << "\n";
		}
		if (choice == 1)
		{
			return 0;
		}
		if (choice == 2)
		{
			MyTable.Display(rows, columns);
			choice = 0;
		}
		if (choice == 3)
		{
			cout << "\nWhat is your player name?\n";
			cout << "Name: ";
			cin >> name;
			cout << "\nWhat is your player score?\n";
			cout << "Score: ";
			cin >> inputScore; 
			MyTable.InsertEntry(name, inputScore, rows, columns);
			choice = 0;
		}
	}
	return 0;
}