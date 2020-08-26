#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        while (i >= 0)
            nums1[k--] = nums1[i--];

        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};

int main()
{
    Solution s;

    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};

    int n = 1, m = 1;

    s.merge(nums1, n, nums2, m);

    for (auto x : nums1)
    {
        cout << x << "\n";
    }
}