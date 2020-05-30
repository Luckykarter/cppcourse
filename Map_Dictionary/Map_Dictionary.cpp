// Map_Dictionary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

// map provides key-value set (dictionary)
// each element in a map is a pair

using namespace std;
//print a pair
template<typename T1, typename T2>
void print_pair(pair<T1, T2>& p) {
    cout << p.first << ": " << p.second << endl;
}

template<typename T>
void print_map(T& m) {
    for (auto item : m) {
        print_pair(item);
    }
    cout << endl;
}

map<string, int> items;

void registerItem(const string& itemId) {
    items[itemId] += 1;
}

string getMaximum() {
    int max = 0;
    string res;
    for (pair<string, int> item : items) {
        if (item.second > max) {
            max = item.second;
            res = item.first;
        }
    }
    return res;
}

int main()
{
    map<int, string> m1 = { {1, "one"}, {2, "two"},
        {3, "three"}, {4, "four"}, {5, "five"} };
    print_map(m1);
    cout << m1[2] << endl;

    cout << m1[10] << endl;
    m1[10] = "test";
    
    print_map(m1);

    cout << "maximum purchases" << endl;
    registerItem("apple");
    registerItem("apple");
    registerItem("apple");
    registerItem("orange");
    registerItem("tomato");
    print_map(items);

    cout << getMaximum() << endl;

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
