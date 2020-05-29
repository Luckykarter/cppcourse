// PairAndTuple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility> // pair
#include <string>
#include <tuple>
using namespace std;

template<typename T, typename P>
void printP(const pair<T, P> & p) {
    cout << p.first << " " << p.second << endl;
}

int main()
{
    pair<int, string> p1(10, "ten");
    pair<int, string> p2 = { 5, "five" };
    pair<int, string> p3;
    p3 = make_pair(6, "six");
    printP(p1);
    printP(p2);
    printP(p3);

    tuple<int, int, string> t1 = { 12, 45, "one" };




    
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
