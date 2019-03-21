#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ofstream editNewFile("newFileBishes.txt");
	if (editNewFile.is_open())
	{
		editNewFile << "Check out this line of text!\n";
		editNewFile << "Check out this other line of text!\n";
		editNewFile.close();
	}
	else
	{
		cout << "Unable to open file!";
	}

	ifstream readOldFile("newFileBishes.txt");
	string line;

	if (readOldFile.is_open())
	{
		while (getline(readOldFile, line))
		{
			cout << line << "\n";
		}
		readOldFile.close();

	}
	else
	{
		cout << "Unable to open file!";
	}

}
