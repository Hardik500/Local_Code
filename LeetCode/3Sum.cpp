#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        //TLE
        // unordered_map<int, int> x;
        // unordered_map<string, bool> y;

        // sort(nums.begin(), nums.end());

        // if (nums.size() == 0)
        //     return {};

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (x.find(nums[i]) == x.end())
        //         x[nums[i]] = i;
        // }

        // vector<vector<int>> ans;

        // for (int i = 1; i < nums.size() - 1; i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         int index = -1 * (nums[i] + nums[j]);
        //         if (x.find(index) != x.end() && x[index] < i && x[index] < j)
        //         {
        //             if (y.find(to_string(index) + to_string(nums[i]) + to_string(nums[j])) == y.end())
        //             {
        //                 ans.push_back({index, nums[i], nums[j]});
        //                 y[to_string(index) + to_string(nums[i]) + to_string(nums[j])] = true;
        //             }
        //         }
        //     }
        // }

        // return ans;

        // ##########################################################

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back)
            {
                int sum = nums[front] + nums[back];
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else
                {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && nums[front] == triplet[1])
                        front++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && nums[back] == triplet[2])
                        back--;
                }
            }

            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> sums = {0, 0, 0, 0};

    vector<vector<int>> ans = s.threeSum(sums);

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
}