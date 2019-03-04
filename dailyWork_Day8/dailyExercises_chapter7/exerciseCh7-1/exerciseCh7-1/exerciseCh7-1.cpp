#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;



int main()
{
	string object = "YO";
	string *anObject = &object;
	string *aPointer = &*anObject;
	cout << *aPointer;
}