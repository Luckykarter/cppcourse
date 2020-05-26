// CStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	const static size_t maxbuf = 128; //buffer size
	const char * s1 = "String one";
	const char * s2 = "String two_";
	char sd1[maxbuf];
	char sd2[maxbuf];
	char * cp = nullptr;
	
	strncpy(sd1, s1, maxbuf);
	printf("sd1 is %s\n", sd1);

	char c = 'n';
	cout << strchr(sd1, c) << endl;
	cout << strchr(sd1, c) - sd1 << endl; //position

	//strstr find a string in string


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
