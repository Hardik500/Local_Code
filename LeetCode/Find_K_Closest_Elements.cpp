#include <bits/stdc++.h>

using namespace std;

vector<int> findClosestElements(vector<int> &A, int k, int x)
{
    int left = 0, right = A.size() - k;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (x - A[mid] > A[mid + k] - x)
            left = mid + 1;
        else
            right = mid;
    }
    return vector<int>(A.begin() + left, A.begin() + left + k);
}

int main()
{
    vector<int> arr = {3, 4, 5, 6, 7, 8};
    int target = 3;
    int noOfElements = 4;

    for (auto x : findClosestElements(arr, noOfElements, target))
        cout << x << " ";
}