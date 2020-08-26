#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> missingNums;
        /*  
             0 1 2 3 4 5 6 7
            [4,3,2,7,8,2,3,1]
        */
        for (int i = 0; i < (int)nums.size(); i++)
        {
            int num = abs(nums[i]);
            int numIndex = num - 1;

            if (nums[numIndex] > 0)
                nums[numIndex] = -nums[numIndex];
        }

        for (int i = 0; i < (int)nums.size(); i++)
        {
            int num = nums[i];
            if (num > 0)
                missingNums.push_back(i + 1);
        }
        return missingNums;
    }
};

int main()
{
    Solution s;
    vector<int> x = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> y = s.findDisappearedNumbers(x);

    for (auto z : y)
        cout << z << "\n";
}