#include <bits/stdc++.h>

using namespace std;

const int N = 5;

void printSolution(int maze[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << maze[i][j] << " ";
        }

        cout << "\n";
    }
}

int solveRiaM(int maze[N][N], int posX, int posY)
{
    if (posX == N - 1 and posY == N - 1)
    {
        return 1;
    }
    else
    {
        if (maze[posX + 1][posY])
        {
            maze[posX + 1][posY] = 2;

            if (not solveRiaM(maze, posX + 1, posY))
                maze[posX + 1][posY] = 1;
            else
                return 1;
        }
        else if (maze[posX][posY + 1])
        {
            maze[posX][posY + 1] = 2;

            if (not solveRiaM(maze, posX, posY + 1))
                maze[posX][posY + 1] = 1;
            else
                return 1;
        }
    }

    return 0;
}

int solveRiaM(int maze[N][N])
{
    int x = 0, y = 0;

    maze[x][y] = 2;

    if (solveRiaM(maze, x, y))
        printSolution(maze);
    else
        cout << "No can do babydoll\n";
    return 0;
}

int main()
{
    int maze[N][N] = {{1, 0, 1, 1, 1},
                      {1, 1, 1, 1, 1},
                      {0, 0, 0, 0, 1},
                      {0, 0, 0, 0, 1},
                      {1, 1, 1, 1, 1}};

    solveRiaM(maze);
}