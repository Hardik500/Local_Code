#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        unordered_map<int, int> sum_ab;

        for (auto a : A)
        {
            for (auto b : B)
            {
                ++sum_ab[a + b];
            }
        }

        int count = 0;

        for (auto c : C)
        {
            for (auto d : D)
            {
                if (sum_ab[-c - d] != 0)
                {
                    count += sum_ab[-c - d];
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution s;

    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};

    cout << s.fourSumCount(A, B, C, D) << "\n";
}