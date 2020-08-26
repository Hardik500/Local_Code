#include <bits/stdc++.h>

using namespace std;

vector<int> sortArrayByParity(vector<int> A)
{
    int i = 0;
    int j = A.size() - 1;
    while (i < j)
    {
        if (A[i] % 2)
        {
            swap(A[i], A[j]);
            --j;
        }
        else
        {
            ++i;
        }
    }
    return A;
}

int main()
{
    sortArrayByParity({2, 1, 2, 4});
}