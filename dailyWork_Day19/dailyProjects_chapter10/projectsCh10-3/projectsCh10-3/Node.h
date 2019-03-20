#pragma once
#include "pch.h"
#include <string>
using namespace std;

class Node
{
	friend class Stack;

public:

	Node(const int data);

private:

	int m_Data;
	Node *m_pNext;
	Node *m_pPrev;

};

