#include "pch.h"
#include "node.h"
using namespace std;



Node::Node(const string &data)
{
	m_Data = data;
	m_pNext = NULL;
}

