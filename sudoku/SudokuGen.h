#ifndef SudokuGen_h
#define SudokuGen_h
#define SIZE 9
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

class SudokuGen
{
public:
    SudokuGen();
    void generator();//亂數法(產生新棋盤)
    vector<int > board_Hole(int);//輸出有洞的棋盤至vector變數
    bool check_rep(vector<int>, int, int);//偵測填入數字是否重複及是否符合規則，若不符合會回傳false值
    bool board_put(vector<int>&);//填入數字函式，嘗試失敗超過1000次則會回傳false值
    void print(vector <int > board);//輸出
    void userCin(vector <int > board);//輸入答案並檢查
private:
    int new_board[SIZE][SIZE];//棋盤
    int i, j, k, l;//迴圈用變數
    int level;//難度
};
#endif 
