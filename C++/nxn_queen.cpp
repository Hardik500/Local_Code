#include <bits/stdc++.h>

using namespace std;

int n = 4;

int main()
{
    int A[n][n], count = 0;
    bool diagonal = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = 0;
        }
    }

    for (int i1 = 0; i1 < n; i1++)
    {
        for (int j1 = 0; j1 < n; j1++)
        {
            A[i1][j1] = 1;

            diagonal = false;

            for (int i2 = 0; i2 < n; i2++)
            {
                for (int j2 = 0; j2 < n; j2++)
                {
                    if (A[i2][j2] != 1)
                    {
                        if (i1 == j1 and i2 == j2)
                        {
                            diagonal = false;
                        }
                        else
                        {
                            diagonal = true;
                        }

                        if(i1 == j2 and j1 == i2){
                            diagonal = false;
                        }

                        if (i1 != i2 and j1 != j2 and diagonal)
                        {
                            count += 1;
                        }
                    }
                }
            }

            A[i1][j1] = 0;
        }
    }

    cout << count << "\n";
}