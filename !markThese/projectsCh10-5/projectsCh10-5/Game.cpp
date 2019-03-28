#include "pch.h"
#include "Game.h"

using namespace std;


Game::Game()
{
	Pegs[0] = *new Peg;
	Pegs[1] = *new Peg;
	Pegs[2] = *new Peg;
}

Game::~Game()
{
}

void Game::WelcomePlayer() const
{
	cout << "\tTOWER OF HANNOI";
	cout << "\nEnjoy this small puzzle game by Michael Sweeny\n\n";
}

void Game::DisplayInstructions() const
{
	cout << "The object of the game is to move all 4 'disks' from Peg 1 to Peg 3.\n";
	cout << "-> You can only move one 'disk' at a time.\n";
	cout << "-> You can only move the topmost 'disk' from a peg.\n";
	cout << "-> You cannot place any 'disk' on top of a smaller 'disk'.\n";
	cout << "-> You win by replicating the original stack on Peg 3.\n\n";
}

void Game::DisplayPegs() const
{
	cout << "\nPeg1:\n";
	Pegs[0].Display();
	cout << "\nPeg2:\n";
	Pegs[1].Display();
	cout << "\nPeg3:\n";
	Pegs[2].Display();
	cout << "\n\n";
}

void Game::Announcewinner() const
{
	system("CLS");
	cout << "=============================================\n";
	cout << "<<<<<<<<  CONGRATULATIONS! YOU WON!  >>>>>>>>\n";
	cout << "=============================================\n\n";
	cout << "\nPeg1:\n";
	Pegs[0].Display();
	cout << "\nPeg2:\n";
	Pegs[1].Display();
	cout << "\nPeg3:\n";
	Pegs[2].Display();
	cout << "\n\n";
	cout << "=============================================\n";
	cout << "<<<<<<<<  CONGRATULATIONS! YOU WON!  >>>>>>>>\n";
	cout << "=============================================\n\n";
}

void Game::MoveDisk()
{
	bool isPegEmpty = false;
	while (!isPegEmpty)
	{
		bool validMove = false;
		int choice1;
		int choice2;
		cout << "Select a peg by number to take the top disk from it: ";
		cin >> choice1;
		choice1 = choice1 - 1;
		cout << "\nSelect a peg to place the disk on: ";
		cin >> choice2;
		choice2 = choice2 - 1;
		Peg *tempPeg1 = &Pegs[choice1];
		Peg *tempPeg2 = &Pegs[choice2];
		if (!tempPeg1->IsEmpty())
		{
			while (!validMove)
			{

				if (tempPeg1->Top() < tempPeg2->Top() || tempPeg2->IsEmpty())
				{
					Pegs[choice2].Push(tempPeg1->Top());
					tempPeg1->Pop();
					validMove = true;
					isPegEmpty = true;
				}
				else
				{
					cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
					cout << "You cannot place bigger 'disks' on smaller 'disks'!\n";
					cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
					validMove = true;
				}
			}
		}
		else
		{
			cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
			cout << "The first peg you chose is empty, please try again.\n";
			cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
		}
	}
	

}

void Game::Play()
{
	WelcomePlayer();
	DisplayInstructions();
	Peg *tPeg = &Pegs[2];
	while (!tPeg->IsWon(Pegs[2]))
	{
		DisplayPegs();
		MoveDisk();
	}
	Announcewinner();
}


void Game::Reset()
{
	//Clear all pegs
	Pegs[0].Clear();
	Pegs[1].Clear();
	Pegs[2].Clear();
	
	//Put all 4 DiskNodes on the 1st Peg
	Pegs[0].Push(4);
	Pegs[0].Push(3);
	Pegs[0].Push(2);
	Pegs[0].Push(1);
}