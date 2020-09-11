#include <bits/stdc++.h>

using namespace std;

int extremeInsertionIndex(vector<int> nums, int target, bool leftY)
{
    int left = 0;
    int right = nums.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] > target || (leftY && target == nums[mid]))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

pair<int, int> search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    pair<int, int> p = {-1, -1};

    int leftIdx = extremeInsertionIndex(nums, target, true);

    if (leftIdx == nums.size() || nums[leftIdx] != target) {
        return p;
    }

    p.first = leftIdx;
    p.second = extremeInsertionIndex(nums, target, false) - 1;

    return p;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    pair<int, int> p;

    p = search(nums, target);

    cout << p.first << " " << p.second << "\n";
}