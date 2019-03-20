#include "pch.h"
#include "Stack.h"
#include "Node.h"
using namespace std;

Stack::Stack()
{
	m_pHead = NULL;
	m_pTail = NULL;
}

Stack::~Stack()
{
	Clear();
}

bool Stack::IsEmpty() const
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

void Stack::Display() const
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
		Node *pNode = m_pHead;

		while (pNode != NULL)
		{
			cout << pNode->m_Data << "\n";
			pNode = pNode->m_pNext;
		}
	}
	
}

int Stack::Count() const
{
	Node *pNode = m_pHead;
	int total = 0;

	while (pNode != NULL)
	{
		++total;
		pNode = pNode->m_pNext;
	}
	return total;
}

int Stack::Top() const
{
	if (Count() == 0)
	{
		return -1;
	}
	else
	{
		return m_pTail->m_Data;
	}
}

void Stack::Push(int data)
{
	Node *pNode = new Node(data);

	if (m_pTail != NULL)
	{
		pNode->m_pPrev = m_pTail;
		m_pTail->m_pNext = pNode;
		m_pTail = m_pTail->m_pNext;
	}
	else
	{
		m_pHead = pNode;
		m_pTail = pNode;
	}
}

void Stack::Pop()
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

void Stack::Clear()
{
	while (m_pHead != NULL)
	{
		Node *pTemp = m_pHead;
		m_pHead = m_pHead->m_pNext;
		delete pTemp;
	}

	m_pHead = NULL;
	m_pTail = NULL;
}


Stack Stack::operator =(const Stack &list)
{
	Clear();
	if (list.Count() != 0)
	{
		Node *pNode = list.m_pHead;
		while (pNode != NULL)
		{
			Push(pNode->m_Data);
			pNode = pNode->m_pNext;
		}
	}
	return *this;
}


Stack::Stack(const Stack &listCopy)
{
	m_pHead = NULL;
	m_pTail = NULL;

	if (listCopy.Count() != 0)
	{
		Node *pNode = listCopy.m_pHead;
		while (pNode != NULL)
		{
			Push(pNode->m_Data);
			pNode = pNode->m_pNext;
		}
	}

}