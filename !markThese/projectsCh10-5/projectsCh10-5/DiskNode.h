#pragma once
#include "pch.h"
#include <string>
#include "Peg.h"
using namespace std;

class DiskNode
{
	friend class Peg;

public:

	DiskNode(const int data);

private:

	int m_diskSize;
	DiskNode *m_pNext;
	DiskNode *m_pPrev;

};

