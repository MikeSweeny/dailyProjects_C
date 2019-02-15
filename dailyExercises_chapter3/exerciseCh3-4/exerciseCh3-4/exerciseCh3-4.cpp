/// Tic-Tac-Toe Board
// Demonstrates multidimensional arrays
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void playerInput()
{
	cout << "\n1. Player vs Player\n";
	cout << "2. Player vs AI\n";
	cout << "3. Quit\n";
	cout << "\nChoose one (enter its # and hit enter).\n";
	cin >> selection;
}

int main()
{
	// The game table
	const int ROWS = 3;
	const int COLUMNS = 3;
	char board[ROWS][COLUMNS] = { {'_', '_', '_'},
								  {'_', '_', '_'},
								  {'_', '_', '_'} };

	do 
	{
		if (selection == '1')
		{
			string player1;
			string player2;
			cout << "\n\nPlayer 1 enter your name: ";
			cin >> player1;
			cout << "\n\nPlayer 2 enter your name: ";
			cin >> player2;

			if (currentPlayer == 1) currentPlayer = 2; else currentPlayer = 1;
			cout << (currentPlayer == 1 ? player1 : player2);
			int currentPlayer = 1;
			cout << "Let's play tic-tac-toe!\n";
			for (int i = 0; i < ROWS; ++i)
			{
				for (int j = 0; j < COLUMNS; ++j)
				{
					cout << board[i][j];
				}

				cout << endl;
			}
		}

	}
	// 2-Player

	cin >> selection;
	string player1;
	string player2;
	cout << "\n\nPlayer 1 enter your name: ";
	cin >> player1;
	cout << "\n\nPlayer 2 enter your name: ";
	cin >> player2;

	if (currentPlayer == 1) currentPlayer = 2; else currentPlayer = 1;
	cout << (currentPlayer == 1 ? player1 : player2);
	int currentPlayer = 1;

	

	cout << "\n'X' moves to the empty location.\n\n";
	board[1][0] = 'X';

	cout << "Now the tic-tac-toe board is:\n";
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			cout << board[i][j];
		}

		cout << endl;
	}

	return 0;
}
