// Exception.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <exception>
using namespace std;

//class E : public exception {
//	const char * msg;
//	E();
//public:
//	E(const char * s) throw() : msg(s) {}
//	const char * what() const throw() {return msg; }
//};

const exception e_ouch("ouch!!");
const exception e_bad("very bad code!");

void broken() {
	cout << "this is a broken function" << endl;
	throw e_bad;
}

int main()
{
	try
	{
		broken();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	
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
