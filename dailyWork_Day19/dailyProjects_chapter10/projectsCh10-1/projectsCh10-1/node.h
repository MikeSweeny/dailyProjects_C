#pragma once
#include "pch.h"
#include <string>
using namespace std;

class Node
{
	friend class List;

public:

	Node(const string &data);

private:

	string m_Data;
	Node *m_pNext;

};

