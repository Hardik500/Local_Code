#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int totalLength = nums1.size() + nums2.size();

        int i = 0, j = 0;

        int mid;

        if (totalLength % 2 == 0)
            mid = totalLength / 2 - 1;
        else
            mid = totalLength / 2;

        while ((i + j) < mid)
        {
            if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }

        int a = 0;

        if (totalLength % 2 == 0)
        {
            if (nums1[i] < nums2[j])
            {
                a += nums1[i];
                i++;
            }
            else
            {
                a += nums2[j];
                j++;
            }

            if (nums1[i] < nums2[j])
            {
                a += nums1[i];
                i++;
            }
            else
            {
                a += nums2[j];
                j++;
            }

            return a / 2.0;
        }
        else
        {
            if (nums1[i] < nums2[j])
            {
                a += nums1[i];
                i++;
            }
            else
            {
                a += nums2[j];
                j++;
            }

            return a;
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, int n, vector<int> &nums2, int m)
    {
        int begin1 = 0, end1 = n;

        while (begin1 <= end1)
        {
            int i1 = (begin1 + end1) / 2;
            int i2 = (n + m + 1) / 2 - i1;

            int min1 = (i1 == n) ? INT_MAX : nums1[i1];
            int max1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];

            int min2 = (i2 == m) ? INT_MAX : nums2[i2];
            int max2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];

            if ((max1 <= min2) && (max2 <= min1))
            {
                if ((m + n) % 2 == 0)
                    return ((double)(max(max1, max2) + min(min1, min2)) / 2);
                else
                    return ((double)max(max1, max2));
            }
            else if (max1 > min2)
                end1 = i1 - 1;
            else
                begin1 = i1 + 1;
        }
    return -1;

    }

};

int main()
{
    Solution s;
    vector<int> nums1 = {10, 20, 30, 40, 50};
    vector<int> nums2 = {5, 15, 25, 35, 45, 55, 65, 75, 85};
    cout << s.findMedianSortedArrays(nums1, 5, nums2, 9);
}