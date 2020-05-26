// Scratch3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

string func() {
	return string("this is a string");
}



int main()
{
	auto x = func(); //automatically assign type

	int x1 = 0;
	int y = 5;

	printf("%d\n", x1++);
	printf("%d\n", x1++);

	x1 = 0;

	printf("%d\n", ++x1);
	printf("%d\n", ++x1);

	//typecast - convert type into compatible type
	double floatN = 5555.5;
	int intY;
	intY = (int) floatN;
	size_t sizN = sizeof floatN; //size_t is a size in bytes
	printf("size: %zd\n", sizN);
	if (typeid(floatN) == typeid(float))
		puts("yes");
	else
		puts("no");

    
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
