// HeaderImpact.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;

int main()
{
    try {
        Stack<int> stint = Stack<int>(1000);
        cout << stint.isEmpty() << endl;
        stint.push(4);
        stint.push(5);
        stint.push(25);
        stint.push(30);
        while (!stint.isEmpty()) {
            cout << "top element: " << stint.top() << endl;
            cout << "element " << stint.pop() << " popped" << endl;
        }
        auto ststr = Stack<string>(1000);
        cout << stint.isEmpty() << endl;
        ststr.push("my");
        ststr.push("name");
        ststr.push("is");
        ststr.push("Vasya");
        while (!ststr.isEmpty()) {
            cout << "top element: " << ststr.top() << endl;
            cout << "element " << ststr.pop() << " popped" << endl;
        }


    }
    catch(const exception& e) {
        cout << "exception test" << endl;
        cout << e.what() << endl;
    }
  


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
