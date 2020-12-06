#include <bits/stdc++.h>

using namespace std;

const int N = 3;
const int M = 3;

void solve(int Matrix[N][M], int i = 0, int j = 0, string str = "")
{
    if(i == (N - 1) and j == (M - 1)){
        cout<<str + to_string(Matrix[i][j])<<"\n";
    }

    if(i >= N || j >= M){
        return;
    }

    solve(Matrix, i + 1, j, str + to_string(Matrix[i][j]));
    solve(Matrix, i, j + 1, str + to_string(Matrix[i][j]));
}

int main()
{
    int Matrix[N][M];
    int counter = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            Matrix[i][j] = i + j + counter;
        }

        counter++;
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout<<Matrix[i][j]<<" ";
    //     }

    //     cout<<"\n";
    // }

    solve(Matrix);
}