// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void printV(const vector<T>& v) {
	for (auto item : v) cout << item << ' ';
	cout << endl;
}

int main()
{
	vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7 };
	vi1.push_back(100);
	cout << "size: " << vi1.size() << endl;
	cout << "front: " << vi1.front() << endl;
	cout << "back: " << vi1.back() << endl;
	
	

	//iterator

	auto itbegin = vi1.begin();
	auto itend = vi1.end();
	for (auto it = itbegin; it < itend; ++it) {
		cout << *it << ' ';
	}

	vi1.insert(vi1.begin() + 4, 99); //insert at position
	vi1.push_back(55); //at the end
	cout << endl;
	for (auto it : vi1) {
		cout << it << ' ';
	}
	vi1.pop_back();

	vi1.insert(vi1.end(), 88);
	cout << endl;
	cout << "range-based by reference:" << endl;
	for (auto &i : vi1) {
		cout << i << ' ';
	}


	// index
	cout << endl << "Index: " << endl;
	cout << "element at 5: " << vi1[5] << endl;
	cout << "element at 5: " << vi1.at(5) << endl;
	cout << endl;
	// create vector with repeated values:
	vector <int> vi2(10, 0);
	vector<string> viS(4, "string");
	printV(vi2);
	printV(vi1);
	printV(viS);
	auto v3(viS);
	printV(v3);

	auto v5(move(v3));
	printV(v5);
	cout << "moved" << endl;
	printV(v3);


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
