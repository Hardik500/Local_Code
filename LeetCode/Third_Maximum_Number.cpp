#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> nums)
    {
        long long int a = INT64_MIN, b = INT64_MIN, c = INT64_MIN;
        long long int size = nums.size();

        for (int i = 0; i < size; i++)
        {
            if (nums[i] > c && (nums[i] != a && nums[i] != b && nums[i] != c))
            {
                c = nums[i];

                if (b < c)
                {
                    swap(b, c);

                    if (a < b)
                        swap(a, b);
                }
            }
        }

        if (size >= 3 && (c != INT64_MIN))
            return c;
        else
            return a;
    }
};

int main()
{
    Solution s;

    cout << s.thirdMax({1,1, 2});
}