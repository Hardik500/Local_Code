#include <bits/stdc++.h>

using namespace std;

int ans = 4;

bool isBadVersion(int n)
{
    if (n < ans)
        return false;
    else
        return true;
}

int firstBadVersion(int n)
{
    int left = 1;
    int right = n;
    int mid = 0;

    while (left < right)
    {
        mid = left + (right - left) / 2;

        if (isBadVersion(mid))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int main()
{
    cout << firstBadVersion(5);
}