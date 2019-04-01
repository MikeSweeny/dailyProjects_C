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
	//Steven - else isn't needed, you just return false.
	else
	{
		return false;
	}
}

void Peg::Display() const
{
	if (m_pHead == NULL)
	{
		cout << "   |\n";
		cout << "   |\n";
		cout << "   |\n";
		cout << "   |\n";
		return;
	}

	DiskNode *pDiskNode = m_pTail;

	while (pDiskNode != NULL)
	{
		if (Count() < 4)
		{
			for (int i = 0; i < (4 - Count()); i++)
			{
				cout << "   |\n";
			}
		}
		/*Steven - When you check to see if pDiskNode is not NULL you should contain the rest of your code
				   within that if statement This could also be broken down to a smaller function.
		*/
		if (pDiskNode != NULL)
		{
			if (pDiskNode->m_diskSize == 1)
			{
				cout << "   *\n";
				pDiskNode = pDiskNode->m_pPrev;
			}
		}
		if (pDiskNode != NULL)
		{
			if (pDiskNode->m_diskSize == 2)
			{
				cout << "  ***\n";
				pDiskNode = pDiskNode->m_pPrev;
			}
		}
		if (pDiskNode != NULL)
		{
			if (pDiskNode->m_diskSize == 3)
			{
				cout << " *****\n";
				pDiskNode = pDiskNode->m_pPrev;
			}
		}
		if (pDiskNode != NULL)
		{
			if (pDiskNode->m_diskSize == 4)
			{
				cout << "*******\n";
				pDiskNode = pDiskNode->m_pPrev;
			}
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
	/* Steven - What if you were to try != and return your m_diskSize
		if (Count() != 0)
		{
			return m_pTail->m_diskSize;
		}
		return -1;
	*/
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

bool Peg::IsWon(/*Const*/Peg &aPeg) const //Steven - Peg doesn't change it should be a const
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


void Peg::Push(int data)//Steven - Should be a const and probably a reference?
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