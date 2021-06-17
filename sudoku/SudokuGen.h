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
    void generator(); 
    vector<int > board_Hole(int); 
    bool check_rep(vector<int>, int, int); 
    bool board_put(vector<int>&); 
    void print(vector <int > board);
    void userCin(vector <int > board);
private:
    int new_board[SIZE][SIZE]; 
    int i, j, k, l; 
    int level;
};
#endif 