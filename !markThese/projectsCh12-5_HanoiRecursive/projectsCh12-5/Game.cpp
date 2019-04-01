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

void Game::AnnounceWinner() const
{
	cout << "\n\n=============================================\n";
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

void Game::MakeLegalSwap()
{
	// Steven - Check your operator, | may run however its incorrect.
	if (Pegs[1].Top() == -1 | Pegs[0].Top() < Pegs[1].Top() && Pegs[0].Top() != -1)
	{
		MoveDisk(0, 1);
		DisplayPegs();
	}
	else if (Pegs[1].Top() != -1)
	{
		MoveDisk(1, 0);
		DisplayPegs();
	}
	// Steven - Check your operator, | may run however its incorrect.
	if (Pegs[2].Top() == -1 | Pegs[0].Top() < Pegs[2].Top() && Pegs[0].Top() != -1)
	{
		MoveDisk(0, 2);
		DisplayPegs();
	}
	else if (Pegs[2].Top() != -1)
	{
		MoveDisk(2, 0);
		DisplayPegs();
	}
	// Steven - Check your operator, | may run however its incorrect.
	if (Pegs[2].Top() == -1 | Pegs[1].Top() < Pegs[2].Top() && Pegs[1].Top() != -1)
	{
		MoveDisk(1, 2);
		DisplayPegs();
	}
	else if (Pegs[2].Top() != -1)
	{
		MoveDisk(2, 1);
		DisplayPegs();
	}
}

void Game::MoveDisk(int i1, int i2)
{
	bool isPegEmpty = false;
	while (!isPegEmpty)
	{
		bool validMove = false;
		Peg *tempPeg1 = &Pegs[i1];
		Peg *tempPeg2 = &Pegs[i2];
		if (!tempPeg1->IsEmpty())
		{
			while (!validMove)
			{

				if (tempPeg1->Top() < tempPeg2->Top() || tempPeg2->IsEmpty())
				{
					Pegs[i2].Push(tempPeg1->Top());
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
	Peg *tPeg = &Pegs[2];
	if (!tPeg->IsWon(Pegs[2]))
	{
		MakeLegalSwap();
		Play();
	}
}

//Steven - This could be done with a simple loop
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