#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        auto it = lower_bound(nums.begin(), nums.end(), target);

        return it - nums.begin();

    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,3,5,6};
    cout<<sol.searchInsert(nums, 0)<<"\n";
}