/// Tic-Tac-Toe Board
// Demonstrates multidimensional arrays
#include "pch.h"
#include <iostream>
#include <string>
#include "BoardClass.h"

using namespace std;

//class Board
//{
//	const int maxRows = 3;
//	const int maxColumns = 3;
//	const int fullBoard = 10;
//	int numMoves;
//	int board;
//
//	Board()
//		: numMoves(0)
//	{
//		for (int row = 0; row < maxRows; ++row)
//		{
//			for (int col = 0; col < maxColumns; ++col)
//			{
//				board[row][col] = ' ';
//			}
//		}
//	}
//
//	bool playMove(int r, int c, char piece);
//
//	void printBoard(ostream& s);
//	friend ostream& operator << (ostream& s, Board const& b)
//	{
//		b.printBoard(s);
//		return s;
//	}
//};

void playerInput()
{
	cout << "\n1. Player vs Player\n";
	cout << "2. Player vs AI\n";
	cout << "3. Quit\n";
	cout << "\nChoose one (enter its # and hit enter).\n";
	cin >> selection;
}

void winCondition(int winner)
{
	board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' ||
	board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' ||
	board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' ||
	board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X' ||
	board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' ||
	board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' ||
	board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' ||
	board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'
}

int main()
{
	// The game table

	const int maxRows = 3;
	const int maxColumns = 3;
	const int fullBoard = 10;
	int numMoves;
	int board;	
	char board[maxRows][maxColumns] = { {'_', '_', '_'},
								  {'_', '_', '_'},
								  {'_', '_', '_'} };

	int currentPlayer = 1;
	int selection = 0;
	string player1;
	string player2;
	char location;
	
	playerInput;

	do 
	{
		switch (selection) 
		{
		case 1: // Player vs Player gamemode
			cout << "\n\nPlayer 1 enter your name: ";
			cin >> player1;
			cout << "\n\nPlayer 2 enter your name: ";
			cin >> player2;

			char PlayerMarker;
			if (currentPlayer = 1) 
			{
				PlayerMarker = 'X';
			}
			else 
			{
				PlayerMarker = 'O';
			}

			if (currentPlayer == 1) currentPlayer = 2; else currentPlayer = 1;
			{				
				cout << "Let's play tic-tac-toe!\n";
				cout << (currentPlayer == 1 ? player1 : player2);
				cout << " where would you like to place your mark?\n (Make your choice as 2 values eg: 12, 32.";
				cin >> location << "\n";

				for (int i = 0; i < maxRows; ++i)
				{
					for (int j = 0; j < maxColumns; ++j)
					{
						cout << board[i][j];
					}

					cout << "\n";
					break;
				}
		case 2: // Player vs AI gamemode
		case 3: // Exit
			return 0;
		default:
			cout << "Gratz you broke it...";
		}

	}

	if (currentPlayer == 1) currentPlayer = 2; else currentPlayer = 1;
	cout << (currentPlayer == 1 ? player1 : player2);
	int currentPlayer = 1;

	

	cout << "\n'X' moves to the empty location.\n\n";
	board[1][0] = 'X';

	cout << "Now the tic-tac-toe board is:\n";
	for (int i = 0; i < maxRows; ++i)
	{
		for (int j = 0; j < maxColumns; ++j)
		{
			cout << board[i][j];
		}

		cout << endl;
	}

	return 0;
}


	BoardClass::BoardClass()
	{
	}


	BoardClass::~BoardClass()
	{
	}
