#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int size = flowerbed.size();

        if(n == 0)
            return true;

        for (int i = 0; i < size; i++)
        {
            bool current = flowerbed[i] == 0;
            bool prev = (i - 1 >= 0) ? flowerbed[i - 1] == 0 : true;
            bool next = (i + 1 < size) ? flowerbed[i + 1] == 0 : true;

            if (i == 0 && current && next)
            {
                flowerbed[i] = 1;
                n--;
            }
            else if (i == size - 1 && current && prev)
            {
                flowerbed[i] = 1;
                n--;
            }
            else if (current && next && prev)
            {
                flowerbed[i] = 1;
                n--;
            }

            if (n == 0)
                break;
        }

        if (n == 0)
            return true;
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> flowerbed = {0, 0, 0, 0, 0, 1, 0, 0};
    int n = 0;
    cout << s.canPlaceFlowers(flowerbed, n);
}