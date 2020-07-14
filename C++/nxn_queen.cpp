#include <bits/stdc++.h>

using namespace std;

const int N = 4;

/* ld is an array where its indices indicate row-col+N-1 
 (N-1) is for shifting the difference to store negative  
 indices */
int ld[30] = {0};
/* rd is an array where its indices indicate row+col 
   and used to check whether a queen can be placed on  
   right diagonal or not*/
int rd[30] = {0};
/*column array where its indices indicates column and  
  used to check whether a queen can be placed in that 
    row or not*/
int cl[30] = {0};

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

bool isSafeOptimized(int chess_board[N][N], int row, int col)
{
    return (ld[row - col + N - 1] != 1 && rd[row + col] != 1) && cl[row] != 1;
}

int solveNQUtil(int chess_board[N][N], int col = 0)
{
    if (col >= N)
        return 1;

    for (int i = 0; i < N; i++)
    {
        // if (isSafe(chess_board, i, col))
        // {
        //     chess_board[i][col] = 1;

        //     if(solveNQUtil(chess_board, col + 1)){
        //         return 1;
        //     }
        //     else{
        //         chess_board[i][col] = 0;
        //     }
        // }

        if (isSafeOptimized(chess_board, i, col))
        {
            chess_board[i][col] = 1;
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

            /* recur to place rest of the queens */
            if (solveNQUtil(chess_board, col + 1))
                return true;

            /* If placing queen in board[i][col] 
               doesn't lead to a solution, then 
               remove queen from board[i][col] */
            chess_board[i][col] = 0; // BACKTRACK
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
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