#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    static bool pro(const pair<int, int> x, const pair<int, int> y)
    {
        return x.first < y.first;
    }

public:

    int carFleet(int target, vector<int> position, vector<int> speed)
    {
        int j = 0;
        vector<pair<int, int>> x;
        vector<float> times;

        if(position.size() == 0)
            return 0;

        for (int i = 0; i < position.size(); i++)
            x.push_back(make_pair(position[i], speed[i]));

        sort(x.begin(), x.end(), pro);

        for (int i = 0; i < position.size(); i++)
            times.push_back(float(target - x[i].first) / (x[i].second));

        int ans = 0, t = position.size();

        while (--t)
        {
            if (times[t] < times[t - 1])
                ans += 1; // if lead arrives sooner, it can't be caught
            else
                times[t - 1] = times[t]; // else, fleet arrives at later time 'lead'
        }


        return ans + (t == 0 ? 1 : 0); //remaining car is fleet(if it exists)
    }
};

int main()
{
    Solution s;

    cout << s.carFleet(10, {}, {});
}