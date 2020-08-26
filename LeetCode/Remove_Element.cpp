#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int length = nums.size();

        int i = 0;

        while(i < length)
        {
            if (nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                length--;
                i--;
            }

            i ++;
        }

        return length;
    }
};

int main()
{
    Solution s;

    vector<int> a = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    s.removeElement(a, val);

    for (auto x : a)
        cout << x << " ";
}