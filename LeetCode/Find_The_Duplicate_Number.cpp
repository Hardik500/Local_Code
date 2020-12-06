#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // O(n) Space Complexity
    // int findDuplicate(vector<int>& nums) {
    //     unordered_map<int, int> mp;

    //     for(auto x:nums){
    //         mp[x]++;

    //         if(mp[x] > 1){
    //             return x;
    //         }
    //     }

    //     return -1;
    // }

    // O(1) Space Complexity
    int findDuplicate(vector<int> &nums)
    {
        int tortoise = nums[0];
        int hare = nums[0];
        do
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        tortoise = nums[0];
        while (tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 2};

    cout << s.findDuplicate(nums);
}