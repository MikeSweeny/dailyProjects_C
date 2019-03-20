#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node
{
	friend class Tree;

public:
	Node(const string& question, Node* pYes, Node* pNo);
	//tests if the finall question (leaf node)
	bool IsFinalQuestion() const;

public:
	string m_Question;  //question test
	Node* m_pYes;	// pointer to yes child
	Node* m_pNo;		// pointer to no child

};

#endif


