#include "pch.h"
#include "DiskNode.h"
using namespace std;



DiskNode::DiskNode(const int data)
{
	m_diskSize = data;
	m_pNext = NULL;
}

