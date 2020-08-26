#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void shiftRight(int index, vector<int> &arr)
    {
        for (int i = arr.size() - 2; i >= index; i--)
            arr[i + 1] = arr[i];
    }

    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size();

        // for (int i = n; i >= 0; i--)
        // {
        //     if (arr[i] == 0)
        //     {
        //         for (int index = n - 2; index >= i; index--)
        //             arr[index + 1] = arr[index];
        //     }
        // }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                arr.insert(arr.begin() + i, 0);
                arr.erase(arr.end() - 1);
                i++;
            }
        }
    }
};

int main()
{
    Solution s;

    vector<int> x = {0, 1, 7, 6, 0, 2, 0, 7};

    s.duplicateZeros(x);

    for (auto y : x)
    {
        cout << y << "\n";
    }
}