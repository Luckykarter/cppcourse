// Deque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// deque is optimize for push and pop from ends

#include <iostream>
#include <deque>
#include <string>
using namespace std;
template <typename T>
void reportdeq(T& d) {
    size_t sz = d.size();
    cout << "size: " << sz;
    if (sz) cout << " front: " << d.front() << " back: " << d.back();
    cout << endl;
}

template<typename T>
void printD(T& d) {
    for (auto v : d) {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    deque<string> d1 = { "one", "two", "three" };
    d1.push_back("four");
    d1.push_front("zero");
    printD(d1);
    d1.pop_front();
    printD(d1);
    d1.pop_back();
    printD(d1);
    
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
