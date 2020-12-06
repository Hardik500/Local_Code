#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // void sortColors(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     vector<int> newArr(3);

    //     for (int i = 0; i < n; i++)
    //         newArr[nums[i]] += 1;

    //     for (int i = 1; i < 3; i++)
    //         newArr[i] += newArr[i - 1];

    //     int j = 0;
    //     int start = 0;
    //     int end = newArr[j] - 1;

    //     for (size_t i = 0; i < 3; i++)
    //     {
    //         while (start <= end)
    //         {
    //             nums[start] = i;
    //             start++;
    //         }

    //         j++;
    //         end = newArr[j] - 1;
    //     }
    // }

    void sortColors(vector<int> &nums)
    {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        int mid = 0;

        while (mid <= high)
        {
            {
                switch (nums[mid])
                {

                // If the element is 0
                case 0:
                    swap(nums[low++], nums[mid++]);
                    break;

                // If the element is 1 .
                case 1:
                    mid++;
                    break;

                // If the element is 2
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
                }
            }
        }
    }
};

int main()
{
    Solution s;

    vector<int> nums = {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);

    for (auto x : nums)
    {
        cout << x << " , ";
    }
}