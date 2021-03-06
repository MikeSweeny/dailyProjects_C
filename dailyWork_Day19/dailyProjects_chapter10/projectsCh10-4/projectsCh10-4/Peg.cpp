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
	if (m_pHead == NULL)
	{
		cout << "<EMPTY>\n";
		return;
	}
	DiskNode *pDiskNode = m_pTail;

	while (pDiskNode != NULL)
	{
		cout << pDiskNode->m_diskSize << "\n";
		pDiskNode = pDiskNode->m_pPrev;
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
if (aPeg.Count() == 4)
	{
		if (m_pHead->m_diskSize == 4 &
			m_pHead->m_pNext->m_diskSize == 3 &
			m_pTail->m_pPrev->m_diskSize == 2 &
			m_pTail->m_diskSize == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}


void Peg::Push(int data)
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