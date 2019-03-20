#include "node.h"


Node::Node(const string& question, Node* pYes, Node* pNo) :
	m_Question(question),
	m_pYes(pYes),
	m_pNo(pNo)

{}

//Tests if is final question (leaf node)
bool Node::IsFinalQuestion() const
{
	return (m_pYes == NULL && m_pNo == NULL);
}
