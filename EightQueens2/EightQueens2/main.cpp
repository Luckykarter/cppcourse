//
//  main.cpp
//  EightQueens2
//
//  Created by Egor Wexler on 08/06/2020.
//  Copyright © 2020 Egor Wexler. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int Q = 8;
int board[8];


bool isSafe(int, int);
void printBoard();

void placeQueen(int row) {

    for (int col = 1; col <= Q; ++col ) {

        if(isSafe(row, col)) {
            board[row] = col;
            if(row == Q)
            printBoard();
            else
            placeQueen(row + 1);
        };
    }
}

bool isSafe(int row, int col) {
        for (int j = 1;j <= row - 1;j++){
            if (board[j] == col ||
                (abs(board[j] - col) == abs(j - row)))
            return false;
        }
        return true;
    }

void printBoard(){

    cout << "print board: " << endl;
for (int i = 1; i <= Q; i++){
    for (int j = 1; j <= Q; j++){
        if (board[i] != j)
            cout << "\t_";
        else
            cout << "\tQ";
    }
    cout << endl;
}
}

int main(int argc, const char * argv[]) {
    placeQueen(1);
//    printBoard();
    
}
