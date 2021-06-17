#include "SudokuGen.h"


SudokuGen::SudokuGen() 
{
    srand(time(NULL)); 
    generator(); 
}

void SudokuGen::generator() 
{
    int tmp; 
    int numtmp[9] = { 1,2,3,4,5,6,7,8,9 }; 
    vector <int> board(81); 
    bool check = false; 

    for (i = 0; i < 81; i++) { board[i] = 0; } 

    for (i = 0; i < 9; i++) 
        board[i / 3 * 9 + i % 3] = numtmp[i];

    while (!check) 
        check = board_put(board);

    for (i = 0; i < 9; i++) 
    {
        j = rand() % 9;
        tmp = numtmp[i];
        numtmp[i] = numtmp[j];
        numtmp[j] = tmp;
    }

    for (i = 0; i < 81; i++) 
        board[i] = numtmp[board[i] - 1];
    

    for (i = 0; i < SIZE; i++) 
        for (j = 0; j < SIZE; j++)
            new_board[i][j] = board[i * SIZE + j];
}

vector <int > SudokuGen::board_Hole(int level) 
{
    vector < int > out_board(SIZE * SIZE);
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            out_board[i * SIZE + j] = new_board[i][j];

    srand(time(NULL));//難度
    switch (level)
    {
    case 0:
        level = 1;
        break;
    case 1:
        level = 20;
        break;
    case 2:
        level = 40;
        break;
    case 3:
        level = 60;
        break;
        case 99:
        level = 0;
        break;
    }

    for (int i = 1; i <= level; i++)
        out_board[rand() % 81] = 0;


    return out_board;
}

bool SudokuGen::check_rep(vector<int> board, int pos, int n)
{
    int i;
    for (i = 0; i < 9; i++)
    {
        if (board[pos / 9 * 9 + i] == n) 
            return true; 
        
        if (board[i * 9 + pos % 9] == n) 
            return true; 
    }
    return false;  
}

bool SudokuGen::board_put(vector<int >& board) 
{
    int pos;
    int count1, count2; 
    bool check = true; 

    for (j = 0; j < 9; j++) 
    {
        count2 = 0; 
        for (i = 1; i < 9; i++) 
        {
            pos = i / 3 * 27 + i % 3 * 3; 
            count1 = 0; 
            while (check == true)
            {
                k = rand() % 9;
                check = check_rep(board, pos + k / 3 * 9 + k % 3, j + 1);
                ++count1;
                ++count2;
                if (board[pos + k / 3 * 9 + k % 3] == 0 && check == false) 
                {
                    board[pos + k / 3 * 9 + k % 3] = j + 1;
                    check = true;
                    break;
                }
                else
                    check = true;

                if (count1 > 100) 
                {
                    for (l = 0; l < 81; l++)
                        if (board[l] == j + 1)
                            board[l] = 0;
                    board[j / 3 * 9 + j % 3] = j + 1;
                    i = 0;
                    break;
                }
                if (count2 > 1000) 
                    return false;
            }
        }
    }
    return true; 
}
void SudokuGen::print(vector <int > board) 
{
    for (int i = 0; i < board.size(); i++)
    {
        cout << board[i] << ' ';
        if ((i + 1) % 3 == 0)
            cout << " ";
        if ((i + 1) % 9 == 0)
            cout << endl;
        if ((i + 1) % 27 == 0)
            cout << endl;
    }
    cout << endl;
}


void SudokuGen::userCin(vector <int > board)
{
    int tot = 0;
    for (int i = 0; i < 81; i++)
    {
        if (board[i] == 0)
        {
            cout << endl << i / 9+1 << "-" << i % 9+1 << " : ";
            cin >> board[i];
        }
    }
    for (int i = 0; i < 81; i++)
        tot += board[i];
    if (tot == 405)
        cout << "correct\n";
    else
        cout << "error\n";
}