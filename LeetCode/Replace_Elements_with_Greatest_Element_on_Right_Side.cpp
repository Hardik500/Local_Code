#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int size = arr.size();
        int greatest = arr[size - 1];

        vector<int> arr2(size);

        arr2[size - 1] = -1;

        for (int i = size - 2; i >= 0; i--)
        {
            arr2[i] = greatest;

            if (arr[i] > greatest)
                greatest = arr[i];
        }

        return arr2;
    }
};

int main()
{
    vector<int> x = {17, 18, 5, 4, 6, 1};

    Solution s;

    vector<int> y = s.replaceElements(x);

    for(auto p:y)
        cout<<p<<" ";
}