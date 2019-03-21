#include "pch.h"
#include "Game.h"


Game::Game()
{
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
	cout << "The object of the game is to move all 4 pegs from Peg 1 to Peg 3.\n";
	cout << "You can only move one peg at a time.\n";
	cout << "You can only move the topmost disk from a peg.\n";
	cout << "You cannot place a disk on top of a smaller disk.\n";
	cout << "You win by replicating the original stack on Peg 3.\n\n";
}

void Game::Announcewinner() const
{
	cout << "============================================\n";
	cout << "<<<<<<<< CONGRATULATIONS! YOU WON!  >>>>>>>>\n";
	cout << "============================================\n\n";
}

void Game::Play() const
{
	WelcomePlayer();
	DisplayInstructions();
	while (!peg3->IsWon(*peg3))
	{

	}
}


void Game::Reset()
{
	//Clear all pegs
	peg1->Clear();
	peg2->Clear();
	peg3->Clear();

	//Make the 4 basic DiskNodes
	DiskNode node1(1);
	DiskNode node2(2);
	DiskNode node3(3);
	DiskNode node4(4);

	//Put all 4 DiskNodes on the 1st Peg
	peg1->Push(node4);
	peg1->Push(node3);
	peg1->Push(node2);
	peg1->Push(node1);
}