#include <iostream>
#include <vector>
#include "SudokuGen.h"

using namespace std;


int main()
{
    int level;
    cout << "0 is test mod\n1 to 3 which level you want:";
    cin >> level;
    SudokuGen NewBoard; 
    vector <int > board = NewBoard.board_Hole(level); 
    NewBoard.print(board);
    NewBoard.userCin(board);
    vector <int > boardANS = NewBoard.board_Hole(99);
    NewBoard.print(boardANS);
}

