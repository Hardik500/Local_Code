#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0;
    int h = n - 1;

    while (l < h)
    {
        int mid = (l + h) / 2;

        if (nums[mid] > nums[h])
            l = mid + 1;
        else
            h = mid;
    }

    int rotatedIndex = l;
    l = 0;
    h = n - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        int realmid = (mid + rotatedIndex) % n;

        if (nums[realmid] == target)
            return realmid;
        else if (nums[realmid] < target)
            l = mid + 1;
        else
            h = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> nums = {7, 8, 9, 10, 0, 1, 2, 3, 4, 5};
    int target = 2;

    cout << search(nums, target);
}