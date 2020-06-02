// Lambda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "title-case.h"
#include "camel-case.h"
#include "numword.h"

using namespace std;

template<typename T>
void printV(vector<T>& v) {
    for (auto item : v) cout << item << " ";
    cout << endl;
}

int main()
{
    int acc = 0;
    auto x = [acc](int d) mutable -> int {return acc += d;}; // x is lambda function
    vector<int> v1 = { 122, 2, 3, 4, 111111 };
    printV(v1);

    vector<int> v2(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), x);

    printV(v2);

    // strings transformation
    string s1 = "this is a string";
    cout << s1 << endl;

    string s2(s1.size(), '.');
    cout << s2 << endl;
    camel_case t;
    transform(s1.begin(), s1.end(), s2.begin(), t);
    cout << s2 << endl;

    bw::numword s;
    vector<string>w(v1.size());
    transform(v1.begin(), v1.end(), w.begin(), s);
    printV(w);

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
