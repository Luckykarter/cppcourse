// FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream> // read from files
#include <string>

using namespace std;
int main()
{
	ifstream inputFileA;
	ifstream inputFileB;
	string phrase;
	string supply[10];
	int qty[10];

	ofstream outputFileA;
	outputFileA.open("newSuppliers.txt", ios::app); //opens file. if not exist create and overwrite
	// ios::app - "append to the end of file"

	outputFileA << "\nPassed";
	outputFileA.close();

	inputFileA.open("test.txt");
	if (!inputFileA.fail())
	{

		while (inputFileA >> phrase) { // reading word by word
			cout << "content file is: " << phrase << endl;
		}
	}

	inputFileA.close();

	const char * fn = "testfile.txt";
	const char * str = "this is a c-string\n";
	int repeat = 5;

	//create/write the file
	// w - destroy contents
	// a - append to a file
	// r - reading
	// r+, w+, a+ read/write
	// b - binary mode
	FILE * fw = fopen(fn, "a");
	for (int i = 0; i < repeat; ++i) {
		fputs(str, fw);
	}
	fclose(fw);

	char buf[1024];
	FILE * fr = fopen(fn, "r"); // open file in read mode
	while (fgets(buf, 1024, fr)) { //1024 is a buffer to read
		fputs(buf, stdout); // put the content into console
		fputs("\nbuffer end\n", stdout);
	}
	fclose(fr);

	// binary

	struct S { //128 byte structure
		uint8_t num;
		uint8_t len;
		char str[112];
	};

	const char * fb = "test.binary";
	FILE * fwb = fopen(fb, "wb");
	static struct S buf1;

	for (int i = 0; i < 5; i++) {
		buf1.num = i;
		buf1.len = (uint8_t)strlen(str);
		if (buf1.len > 1024)
			buf1.len = 1024;
		strncpy(buf1.str, str, 1024);
		buf1.str[buf1.len] = 0;
		fwrite(&buf1, sizeof(struct S), 1, fwb);
	}

	fclose(fwb);

	// create file
	static const char * fn1 = "file1";
	FILE * fh = fopen(fn1, "w");
	fclose(fh);

	// rename file
	rename(fn1, "file_renamed");
	//remove file
	remove("file_renamed");
	const char * myString = "Hello World, blablabla\n";
	fputs(myString, stdout);
	puts(myString); //puts into console

	//read from console
	const int bufsize = 256;
	static char buffer[bufsize]; // to hold the characters
	fputs("prompt: ", stdout);
	fflush(stdout); //flushes the buffer

	fgets(buffer, bufsize, stdin); //gets characters from the console
	fputs(buffer, stdout);

	printf("length is: %zd", strlen(str));
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
