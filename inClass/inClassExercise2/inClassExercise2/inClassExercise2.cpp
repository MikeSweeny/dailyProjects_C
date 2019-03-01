

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x = 25;
	string y = "Hello";
	float z = 321.123;

	int *p;
	string *q;
	float *r;

	p = &x;
	q = &y;
	r = &z;

	cout << *p << "\n";
	cout << *q << "\n";
	cout << *r << "\n\n";
}