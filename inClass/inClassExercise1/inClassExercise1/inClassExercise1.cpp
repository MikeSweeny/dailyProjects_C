// inClassExercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

void displayAge(int);
void getAge(int &age);
int age = 0;

int main()
{
	getAge(age);
	displayAge(age);

	return 0;
}

void getAge(int &age)
{
	cout << "How old are you: ";
	cin >> age;
}

void displayAge(int years)
{
	cout << "You are " << years << " old.\n";
}