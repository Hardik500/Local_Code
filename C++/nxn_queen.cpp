#include <bits/stdc++.h>

using namespace std;

const int N = 4;

void printSolution(int chess_board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << chess_board[i][j] << " ";
        }

        cout << "\n";
    }
}

bool isSafe(int chess_board[N][N], int row, int col)
{
    int i, j; 
  
    for (i = 0; i < col; i++) 
        if (chess_board[row][i]) 
            return false; 
  
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (chess_board[i][j]) 
            return false; 

    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (chess_board[i][j]) 
            return false; 
  
    return true;
}

int solveNQUtil(int chess_board[N][N], int col = 0)
{
    if(col >= N)
        return 1;
    
    for (int i = 0; i < N; i++)
    {
        if (isSafe(chess_board, i, col))
        {
            chess_board[i][col] = 1;

            if(solveNQUtil(chess_board, col + 1)){
                return 1;
            }
            else{
                chess_board[i][col] = 0;
            }
        }
    }

    return 0;
}

void solveNQ()
{
    int chess_board[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            chess_board[i][j] = 0;
        }
    }

    if (solveNQUtil(chess_board))
        printSolution(chess_board);
    else
        cout << "Nope\n";    
}

int main()
{
    solveNQ();
}