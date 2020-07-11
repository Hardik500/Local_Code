#include <bits/stdc++.h>

using namespace std;

const int N = 8;
const int solveX[N] = {2, 1, -1, -2, -2, -1, 1, 2};
const int solveY[N] = {1, 2, 2, 1, -1, -2, -2, -1};

void printSolution(int chess_board[N][N])
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << chess_board[i][j] << " ";
        }
        cout << "\n";
    }
}

int isSafe(int chess_board[N][N], int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && chess_board[x][y] == -1);
}

int solveKTUtil(int chess_board[N][N], int moves = 1, int prevX = 0, int prevY = 0)
{
    if (moves == N * N)
        return 1;
    else
    {
        int k, nextX, nextY;

        for (size_t k = 0; k < N; k++)
        {
            nextX = prevX + solveX[k];
            nextY = prevY + solveY[k];

            if (isSafe(chess_board, nextX, nextY))
            {
                chess_board[nextX][nextY] = moves;

                if (solveKTUtil(chess_board, moves + 1, nextX, nextY))
                    return 1;
                else
                    chess_board[nextX][nextY] = -1;
            }
        }
    }

    return 0;
}

int solveKT()
{

    int chess_board[N][N];

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            chess_board[i][j] = -1;
        }
    }

    chess_board[0][0] = 0;

    if (solveKTUtil(chess_board))
    {
        printSolution(chess_board);
        return 1;
    }
    else
    {
        cout << "Solution doesn't exist";
    }

    return 0;
}

int main()
{
    solveKT();
}