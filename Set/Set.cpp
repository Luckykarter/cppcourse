// Set.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// set contains sorted number of unique elements
// multi-set allows duplicates

#include <iostream>
#include <string>
#include <set>
#include <unordered_set> // provides hash-values
// multiset - can contain duplicates (uses hash instead)


using namespace std;
template<typename T>
void print_set(T& s) {
    for (auto x : s) cout << x << " ";
    cout << endl;
}

int main()
{
    // ordered 
    set<string> s0;
    multiset<string> s1 = { "one", "two", "three", "three", "four" };
    print_set(s1);
    auto r = s1.insert("six");
    
    print_set(s1);
    auto it = s1.find("six"); // find iterator of element
    s1.erase(it);
    print_set(s1);
    
    // when not found - returns end iterator
    it = s1.find("blabla");
    if (it != s1.end()) s1.erase(it);
    print_set(s1);

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
