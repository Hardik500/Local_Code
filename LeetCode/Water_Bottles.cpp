#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int sum = numBottles, fullBottle = numBottles, extraBottle = 0;
        while (fullBottle >= numExchange)
        {
            extraBottle = fullBottle % numExchange;
            fullBottle = fullBottle / numExchange;
            sum += fullBottle;

            fullBottle += extraBottle;
        }

        return sum;
    }
};

int main()
{
    int x, y;
    cin >> x >> y;
    Solution s;
    cout << s.numWaterBottles(x, y);
}