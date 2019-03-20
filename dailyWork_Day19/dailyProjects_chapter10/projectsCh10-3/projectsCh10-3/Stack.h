#pragma once
#include <string>
#include <iostream>
using namespace std;

class Node;

class Stack
{
public:

	Stack();
	~Stack();
	bool IsEmpty() const;
	void Display() const;
	int Count() const;
	int Top() const;
	void Push(int data);
	void Pop();
	void Clear();

	Stack(const Stack &listCopy);
	Stack operator =(const Stack &list);

private:

	static const int ERROR = -1;

	Node *m_pHead;
	Node *m_pTail;

};

