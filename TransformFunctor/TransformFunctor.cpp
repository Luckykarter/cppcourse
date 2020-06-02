// TransformFunctor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

template<typename T>
void printV(vector<T>& item) {

		for (auto i : item) cout << i << " ";
		cout << endl;
}

int main()
{
	vector<int> v1 = { 1, 2, 3, 4 };
	vector<int> v2 = { 2, 3, 2, 2 };

	less<int> functor;
	//greater_equal<int> functor;
	//greater
	//equal_to
	//not_equal_to
	

	vector<int>v3(v2.size());

	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), functor);
	printV(v1);
	printV(v2);
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
