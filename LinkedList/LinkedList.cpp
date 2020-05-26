// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *link;
};

typedef Node* nodePtr; // redefining what node pointer looks like
void insert(nodePtr& head, int data);

int main()
{
	nodePtr head;
	head = new Node;
	head->data = 20;
	head->link = NULL;

	insert(head, 30);
	insert(head, 10);
	nodePtr tmp;
	tmp = head;

	while (tmp != NULL)
	{
		cout << tmp->data << endl;
		tmp = tmp->link;
	}
	return 0;
}

void insert(nodePtr& head, int data)
{
	if (head->link != NULL)
	{
		insert(head->link, data);
	}
	else
	{
		nodePtr temp;
		temp = new Node;
		temp->data = data;
		temp->link = NULL;
		head->link = temp;
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
