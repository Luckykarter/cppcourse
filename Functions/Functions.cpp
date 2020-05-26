// Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

// function prototype because main does not know about function below
void PrintHBD(); // can be functions with different parameters 
int PrintHBD(string);
void PrintReceipt(string, float&); //may specify only datatype
void printOpt(int, ...);

struct A {
	int ia;
	int ib;
	int ic;
};

class T {
private:
	int ia = 0;
	string sb = "";
	int ic = 0;
public:
	// string passed by reference to avoid allocating new variable
	T(const int a, const string& b, const int c) {
		ia = a;
		sb = b;
		ic = c;
	}
	void describe() {
		printf("a: %d, b: %s, c: %d", ia, sb.c_str(), ic);
	}
};

class C1 {
private:
	int i = 0;
public:
	void setvalue(int value) { i = value; }
	int getvalue() { return i;  }
};


int main()
{
 //   cout << "Hello World!\n"; 

	//float grandTotal = 0;
	//PrintReceipt("test", grandTotal);
	//cout << "your total: " << grandTotal << endl;
	//PrintHBD();
	//cout << PrintHBD("Egor") << endl;

	A a = { 1, 2, 3 };
	printf("%d\n", a.ia);

	T t(5, "blabla0hoho", 10);
	t.describe();

	//printOpt(3, "test", "blabla", "tt", "string", "bb");

}

void PrintHBD() {
	cout << "Happy Birthday anonymous\n";
}

int PrintHBD(string name)
{
	int age;
	cout << "Happy Birthday to " << name << endl;
	cout << "Enter your age: \n";
	cin >> age;
	return age;
}

void printOpt(int times, ...) {
	va_list ap;
	__crt_va_start(ap, times);

	for (int i = 0; i < times; ++i) {
		printf("%s\n", __crt_va_arg(ap, string));
	}
	__crt_va_end(ap);

}

// two types of passing variable:
// 1. by value
// 2. by reference - instead of sharing the value - share memory location
// !!Arrays by default are passed by reference!!

void PrintReceipt(string name, float& total)
{
	cout << "Thank you for using " << name << endl;
	total = total + 1;
}

