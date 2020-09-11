#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // O(n^2)
    // int subarraySum(vector<int> &nums, int k)
    // {
    //     int count = 0;
    //     int sums[nums.size() + 1];
    //     sums[0] = 0;

    //     for (int i = 1; i <= nums.size(); i++)
    //     {
    //         sums[i] = sums[i - 1] + nums[i - 1];
    //     }

    //     for (int start = 0; start < nums.size(); start++)
    //     {
    //         for (int end = start + 1; end <= nums.size(); end++)
    //         {
    //             if (sums[end] - sums[start] == k)
    //                 count++;
    //         }
    //     }

    //     return count;
    // }

    //O(n)
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0, sum = 0;
        unordered_map<int, int> mp;

        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (mp[sum - k] > 0)
                count += mp[sum - k];
            mp[sum] += 1;
        }

        return count;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {1, 1, 2, 3, 4, 1, 5, 6, 3, 2};
    int k = 3;

    cout << s.subarraySum(nums, k);
}