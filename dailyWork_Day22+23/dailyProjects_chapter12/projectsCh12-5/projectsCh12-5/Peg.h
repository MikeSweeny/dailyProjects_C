#pragma once
#include <string>
#include <iostream>
#include "DiskNode.h"
using namespace std;

class DiskNode;

class Peg
{

	friend class Game;
	friend class DiskNode;

public:

	Peg();
	~Peg();
	bool IsEmpty() const;
	void Display() const;
	int Count() const;
	int Top() const;
	bool IsLegalMove() const;
	bool IsWon(Peg &aPeg) const;
	void Push(int data);
	void Pop();
	void Clear();

private:

	static const int ERROR = -1;

	int m_pegNum;

	DiskNode *m_HandDisk;
	DiskNode *m_pHead;
	DiskNode *m_pTail;

};

