#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int sum = numBottles, fullBottle = numBottles, extraBottle = 0;
        if (numBottles >= numExchange)
        {
            while (fullBottle >= numExchange)
            {
                extraBottle = fullBottle % numExchange;
                fullBottle = fullBottle / numExchange;                
                sum += fullBottle;

                fullBottle += extraBottle;
            }
        }
        else
            sum = numBottles;

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