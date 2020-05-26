// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string s1 = "this is a string";
	string::iterator it;
	// size and length are the same:
	cout << "size: " << s1.size() << endl;
	cout << "length: " << s1.length() << endl;

	// concatenation using +
	cout << s1 + " additional" << endl;

	//iterator usage
	it = s1.begin() + 5;

	s1.erase(it);
	cout << s1 << endl;
	// replace
	s1.replace(5, 2, "blabla");
	cout << s1 << endl;

	//substr
	cout << s1.substr(5, 5) << endl;

	//find
	size_t pos = s1.find("s");
	cout << "find first s " << pos << endl;
	pos = s1.rfind("s");
	cout << "find last s " << pos << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
