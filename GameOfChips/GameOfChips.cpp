// GameOfChips.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

struct player
{
	string name;
	int numberOfWins;
};

string GetPlayerName(player [], bool);
void GetUserNames(player []);
int GetChipsTaken(int, bool);
void addWin(player[], bool);

const int MAX_CHIPS = 100;
const float MAX_TURN = 0.5;
int main()
{
	bool player1Turn = true;
	bool gameOver;

	int chipsInPile = 0;
	int chipsTaken = 0;
	int canTake = 0;
	string plyr;
	char prompt;
	ofstream winners;

	// array of players (structs)
	player Players[2];
	GetUserNames(Players);

	do {
		int movesToWin = 0;
		gameOver = false;

		srand(time(0));

		chipsInPile = (rand() % MAX_CHIPS) + 1;
		cout << "This round starts with " << chipsInPile << " chips in pile" << endl;


		while (!gameOver) {
			
			plyr = player1Turn ? Players[0].name : Players[1].name;
			cout << plyr << ", how many chips would you like?\n";
			chipsTaken = GetChipsTaken(chipsInPile, plyr == "AI");
			chipsInPile = chipsInPile - chipsTaken;
			movesToWin++;
			cout << "There are " << chipsInPile << " left in the pile \n";
			// and &&
			// or ||
			if (chipsInPile == 0) {
				gameOver = true;
				cout << plyr << " wins\n";
				winners.open("gameOfChipsResults.txt", ios::app);
				winners << "Winner is: " << plyr << ". It took " << movesToWin << " moves\n";
				addWin(Players, player1Turn);
				winners.close();
			}
			else
			{
				player1Turn = !player1Turn;
			}

		}
		do {
			cout << "Play again? (y/n)\n";
			cin >> prompt;
			prompt = toupper(prompt);
			string test = "test";
		} while (prompt != 'N' && prompt != 'Y');

	} while (prompt == 'Y');

	for (auto p: Players) {
		cout << p.name << " had " << p.numberOfWins << " total wins\n";
	}
}

string GetPlayerName(player names[], bool player1)
{
	return player1 ? names[0].name : names[1].name;
}

void addWin(player playerName[], bool player1Turn)
{
	if (player1Turn)
		playerName[0].numberOfWins++;
	else
		playerName[1].numberOfWins++;
}

int GetChipsTaken(int chipsInPile, bool ai)
{
	int chipsTaken = 0;
	int canTake = chipsInPile * MAX_TURN;
	do
	{
		if (ai)
		{
			if (chipsInPile == 1) 
				chipsTaken = 1;
			else
				chipsTaken = (rand() % canTake) + 1;
			cout << "AI took " << chipsTaken << endl;
		}
		else 
		{
			cout << "You can take up to ";
			if (chipsInPile == 1)
				cout << "1" << endl;
			else
				cout << canTake << endl;

			cin >> chipsTaken;
		}
	} while ((chipsTaken > canTake && chipsInPile > 1) || chipsTaken <= 0);

	return chipsTaken;
}

void GetUserNames(player playerName[]) {
	cout << "Player 1, please enter your name: \n";
	cin >> playerName[0].name;
	playerName[0].numberOfWins = 0;
	cout << "Player 2, please enter your name. To play against computer - type AI \n";
	cin >> playerName[1].name;
	playerName[1].numberOfWins = 0;
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


