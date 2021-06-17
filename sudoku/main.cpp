#include <iostream>
#include <vector>
#include "SudokuGen.h"

using namespace std;


int main()
{
    int level;
    cout << "0 is test mod\n1 to 3 which level you want:";
    cin >> level;//難度
    SudokuGen NewBoard; //產生棋盤物件
    vector <int > board = NewBoard.board_Hole(level); //取得題目
    NewBoard.print(board);//輸出題目
    NewBoard.userCin(board);//輸入答案並檢查
    vector <int > boardANS = NewBoard.board_Hole(99);//取得答案
    NewBoard.print(boardANS);//輸出答案
}

