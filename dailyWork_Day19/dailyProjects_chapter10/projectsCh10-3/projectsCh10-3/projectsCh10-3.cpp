#include "pch.h"
#include <iostream>
#include "Stack.h"


int main()
{
	cout << "Welcome to the stacker\n\n";
	Stack theStack;

	theStack.Display(); //throws error

	theStack.Push(1); //no error
	theStack.Push(2); //no error
	theStack.Push(3); //no error

	theStack.Display(); //no error

	theStack.Pop();
	theStack.Pop();
	theStack.Pop();
	theStack.Pop();

}