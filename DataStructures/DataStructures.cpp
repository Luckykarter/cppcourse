// DataStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
// Struct stores data
// class stores data + methods


struct students
{
	string name;
	float GPA;
};

class BankAccount {
private:
	float balance;

public:
	BankAccount(); //constructor
	void Deposit(float);
	void WithDraw();
	float getBalance();

};
BankAccount::BankAccount() //default constructor
{
	balance = 0;
}

float BankAccount::getBalance() {
	return balance;
}

void BankAccount::Deposit(float dep)
{
	balance = balance + dep;
}

int main()
{
	students student;
	student.name = "Egor";
	student.GPA = 88.99;

	//array of structs 
	students firstPeriod[10];
	firstPeriod[0].name = "Tom";
	firstPeriod[0].GPA = 4.8;

	BankAccount checking;
	BankAccount savings;
	cout << "Checking balance is: " << checking.getBalance() << endl;
	cout << "Savings balance is: " << savings.getBalance() << endl;
	
	checking.Deposit(100);
	savings.Deposit(500);

	cout << "Checking balance is: " << checking.getBalance() << endl;
	cout << "Savings balance is: " << savings.getBalance() << endl;

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
