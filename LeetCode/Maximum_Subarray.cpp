#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int max(int a, int b) { return (a > b) ? a : b; }
    int max(int a, int b, int c) { return max(max(a, b), c); }

public:
    // Time Complexity O(n)
    // int maxSubArray(vector<int> &nums)
    // {
    //     int maxSumTillNow = 0;
    //     int maxSum = INT_MIN;

    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         maxSumTillNow += nums[i];

    //         maxSum = max(maxSum, maxSumTillNow);

    //         if(maxSumTillNow < 0){
    //             maxSumTillNow = 0;
    //         }
    //     }

    //     return maxSum;
    // }

    // Divide & Conquer: Time Complexity O(nLogn)

    int maxCrossingSum(vector<int> nums, int l, int m, int h)
    {
        int sum = 0;
        int maxSumLeft = INT_MIN;

        for (int i = m; i >= l; i--)
        {
            sum += nums[i];
            maxSumLeft = max(maxSumLeft, sum);
        }

        sum = 0;
        int maxSumRight = INT_MIN;

        for (int i = m + 1; i <= h; i++)
        {
            sum += nums[i];
            maxSumRight = max(maxSumRight, sum);
        }

        return max(maxSumLeft + maxSumRight, maxSumLeft, maxSumRight);
    }

    int maxSubArray(vector<int> &nums, int l, int h)
    {

        if (l == h)
            return nums[l];

        int m = (l + h) / 2;

        return max(maxSubArray(nums, l, m), maxSubArray(nums, m + 1, h), maxCrossingSum(nums, l, m, h));
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, -2, 3, 4, -6, -1, 5};
    int l = 0,
        h = nums.size() - 1;
    cout << s.maxSubArray(nums, l, h);
}