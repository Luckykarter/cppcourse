// List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
using namespace std;
// list is a aimilar to a vector but design for a rapid insert and delete operations
// do not support random access (similar to SET in python)

// lists are needed to insert and remove values but not random access

template <typename T>
void printL(const list<T>& l) {
    for (auto item : l) cout << item << " ";
    cout << endl;
}

int main()
{
    list<int>l1 = { 1, 2, 3, 4, 4, 5, 6 };
    printL(l1);
    l1.push_back(47);
    printL(l1);

    // to insert or erase need iterator - to find a value
    list<int>::iterator it1 = l1.begin();

    // can remove by value
    l1.remove(4); //removes all fours in the list
    printL(l1);
    


}