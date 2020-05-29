// Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

template<typename T>
T pi = T(3.1415926535897932385L);

template<typename T>
T area_of_circle(const T& r) {
	return r * r * pi<T>;
}

template <typename T>
T testType(T a, T b) {
	if (typeid(a) == typeid(int))
		cout << "integer";
	else if (typeid(a) == typeid(string))
		cout << "string";
	else
		cout << "unknown";
	cout << endl;

	return (a > b ? a : b);
}




int main()
{
	string a = "znine";
	string b = "zztest";
	cout << testType<string>(a, b) << endl;
	cout << testType(5, 3) << endl;
	cout.precision(20);
	cout << pi<long double> << endl;
	cout << area_of_circle<long double>(3) << endl;
	

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
