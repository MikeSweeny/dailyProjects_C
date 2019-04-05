#pragma once
class Stack
{
public:
	Stack();
	~Stack();
	bool IsEmpty() const;
	void Display() const;
	int Count();
	int Top();
	void SetStack();
	void TakeFromStack();
private:
	char stack[];
	StackNode *m_pHead;
	StackNode *m_pTail;
};

