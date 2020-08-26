#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> A)
    {
        vector<int> newArray(A.size());
        ssize_t start = 0;
        ssize_t end = A.size() - 1;
        ssize_t counter = A.size() - 1;

        while (start <= end)
        {
            int x = A[start] * A[start];
            int y = A[end] * A[end];
            if (x < y)
            {
                newArray[counter--] = y;
                end--;
            }
            else
            {
                newArray[counter--] = x;
                start++;
            }
        }
        return newArray;
    }
};

int main()
{
    Solution s;
    vector<int> A = {0, 2};
    vector<int> B = s.sortedSquares(A);

    for (auto x : B)
    {
        cout << x << " ";
    }
}