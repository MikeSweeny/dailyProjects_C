#include "pch.h"
#include "Peg.h"
#include "DiskNode.h"
using namespace std;

Peg::Peg()
{
	m_pHead = NULL;
	m_pTail = NULL;
}

Peg::~Peg()
{
}

bool Peg::IsEmpty() const
{
	if (m_pHead == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Peg::Display() const
{
	if (Top() == ERROR)
	{
		cout << "ERROR - The stack is empty\n";
	}
	else
	{
		if (m_pHead == NULL)
		{
			cout << "<EMPTY>\n";
			return;
		}
		DiskNode *pDiskNode = m_pHead;

		while (pDiskNode != NULL)
		{
			cout << pDiskNode->m_diskSize << "\n";
			pDiskNode = pDiskNode->m_pNext;
		}
	}

}

int Peg::Count() const
{
	DiskNode *pDiskNode = m_pHead;
	int total = 0;

	while (pDiskNode != NULL)
	{
		++total;
		pDiskNode = pDiskNode->m_pNext;
	}
	return total;
}

int Peg::Top() const
{
	if (Count() == 0)
	{
		return -1;
	}
	else
	{
		return m_pTail->m_diskSize;
	}
}

void Peg::TakeDisk(Peg &aPeg)
{
	if (Top() == ERROR)
	{
		cout << "ERROR - The stack is empty\n";
	}
	else
	{
		m_HandDisk = m_pTail;
		aPeg.Pop();
		cout << "You picked up " << m_HandDisk << " from Peg: " << aPeg.m_pegNum << "\n";
	}
}

void Peg::DropDisk(Peg &aPeg)
{
	if (IsLegalMove())
	{
		aPeg.Push(*m_HandDisk);
		cout << "You place " << m_HandDisk << " on Peg: " << "\n";
		m_HandDisk = NULL;
	}
	else
	{
		cout << "You cannot place a disk on top of a smaller disk\n";
	}
}

bool Peg::IsLegalMove() const
{
	if (!m_HandDisk->m_diskSize > Top())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Peg::IsWon(Peg &aPeg) const
{
	DiskNode *pDiskNode1 = aPeg.m_pHead;
	DiskNode *pDiskNode2 = aPeg.m_pHead->m_pNext;
	DiskNode *pDiskNode3 = aPeg.m_pTail->m_pPrev;
	DiskNode *pDiskNode4 = aPeg.m_pTail;
	if (pDiskNode1->m_diskSize == 4 &&
		pDiskNode2->m_diskSize == 3 &&
		pDiskNode3->m_diskSize == 2 &&
		pDiskNode4->m_diskSize == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void Peg::Push(DiskNode &data)
{
	DiskNode *pDiskNode = new DiskNode(data);

	if (m_pTail != NULL)
	{
		pDiskNode->m_pPrev = m_pTail;
		m_pTail->m_pNext = pDiskNode;
		m_pTail = m_pTail->m_pNext;
	}
	else
	{
		m_pHead = pDiskNode;
		m_pTail = pDiskNode;
	}
}


void Peg::Pop()
{
	if (Top() == ERROR)
	{
		cout << "ERROR - The stack is empty\n";
	}
	else
	{
		if (m_pTail->m_pPrev == NULL)
		{
			delete m_pHead;
			m_pTail = NULL;
			m_pHead = NULL;
		}
		else
		{
			m_pTail = m_pTail->m_pPrev;
			delete m_pTail->m_pNext;
			m_pTail->m_pNext = NULL;
		}
	}

}

void Peg::Clear()
{
	while (m_pHead != NULL)
	{
		DiskNode *pTemp = m_pHead;
		m_pHead = m_pHead->m_pNext;
		delete pTemp;
	}

	m_pHead = NULL;
	m_pTail = NULL;
}