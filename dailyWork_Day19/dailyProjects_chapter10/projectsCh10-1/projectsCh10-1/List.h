#pragma once
#include <string>
#include <iostream>
using namespace std;

class Node;

class List
{
public:

	List();
	~List();
	List(const List &listCopy);
	bool Contains(const string &data) const;
	int Count() const;
	void Display() const;
	void Add(const string &data);
	bool Remove(const string &data);
	void Clear();

private:

	Node *m_pHead;
	Node *m_pTail;

};

