#include "pch.h"
#include "tree.h"
#include "node.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

//builds minimal starting tree
Tree::Tree()
{
	
	Node* pNodeGandhi = new Node("Are you thinking of Gandhi?", NULL, NULL);
	Node* pNodeSanta = new Node("Are you thinking of Santa Claus?", NULL, NULL);
	Node* pNodeQuestion = new Node("Is/was the person real?", pNodeGandhi, pNodeSanta);
	m_pRoot = pNodeQuestion;
	m_pCurrent = m_pRoot;
	m_pCurrentParent = NULL;

	fstream myFile;
	myFile.open("treeFile.txt");



}

//deletes node and all descendants
void Tree::Delete(Node* pNode)
{
	if (pNode != NULL)
	{
		Delete(pNode->m_pYes);  //recursive call
		Delete(pNode->m_pNo);   //recursive call
		delete pNode;
		pNode = NULL;
	}
}

//frees allocated memory
Tree::~Tree()
{
	Delete(m_pRoot);
}

//resets current position to root
void Tree::Reset()
{
	m_pCurrent = m_pRoot;
	m_pCurrentParent = NULL;
}



//displays question at current position
bool Tree::DisplayCurrentQuestion()
{
	//never called when m_pCurrent is NULL, but just in case...
	if (m_pCurrent == NULL)
	{
		return false;
	}

	cout << m_pCurrent->m_Question;

	return (!m_pCurrent->IsFinalQuestion());
}

//advances current position to next question
void Tree::NextQuestion(char answer)
{
	//never called when m_pCurrent is NULL, but just in case...
	if (m_pCurrent == NULL)
	{
		return;
	}

	//never called when m_pCurrent points to final question, but just in case...
	if (m_pCurrent->IsFinalQuestion())
	{
		return;
	}

	m_pCurrentParent = m_pCurrent;

	if (answer == YES)
	{
		m_pCurrent = m_pCurrent->m_pYes;
	}
	else
	{
		m_pCurrent = m_pCurrent->m_pNo;
	}
}

//adds person to tree, based on current position
void Tree::AddPerson()
{
	//get name of new person
	cout << "Who are you thinking of?: ";
	string name;
	cin.ignore();
	getline(cin, name);

	//get question to distinguish new person
	cout << "What question would distinguish these two people?:" << endl;
	string question;
	getline(cin, question);

	//create new nodes
	Node* pNodePerson = new Node("Are you thinking of " + name + "?", NULL, NULL);
	Node* pNodeQuestion = new Node(question, NULL, NULL);

	//get answer to question that distinguishes new person
	char answer = AskYesNo("What would the answer be for " + name + "?");

	//connect new question node to new person node
	if (answer == YES)
	{
		pNodeQuestion->m_pYes = pNodePerson;
		pNodeQuestion->m_pNo = m_pCurrent;
	}
	else
	{
		pNodeQuestion->m_pYes = m_pCurrent;
		pNodeQuestion->m_pNo = pNodePerson;
	}

	//insert new question node into tree
	if (m_pCurrentParent->m_pYes == m_pCurrent)
	{
		m_pCurrentParent->m_pYes = pNodeQuestion;
	}
	else
	{
		m_pCurrentParent->m_pNo = pNodeQuestion;
	}
}

//asks yes or no question
char Tree::AskYesNo(const string& question)
{
	char response;
	do
	{
		cout << question;
		cout << " (" << YES << "/" << NO << "): ";
		cin >> response;
	} while (response != YES && response != NO);

	return response;
}