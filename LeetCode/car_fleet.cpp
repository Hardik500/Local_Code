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
    int check_same_nos(vector<int> v)
    {
        unordered_map<int, int> x;

        for (auto s : v)
        {
            x[s] += 1;
        }

        return x.size();
    }

    int carFleet(int target, vector<int> position, vector<int> speed)
    {
        int j = 0;
        vector<pair<int, int>> x;
        vector<int> times;

        for (int i = 0; i < position.size(); i++)
            x.push_back(make_pair(position[i], speed[i]));

        sort(x.begin(), x.end(), pro);

        for (int i = 0; i < position.size(); i++)
            times.push_back(float(target - x[i].first) / x[i].second);

        for (int i = 0; i < x.size(); i++)
            cout << x[i].first << " " << x[i].second << " " << times[i] << "\n";

        int ans = 0, t = position.size();

        while (--t > 0)
        {
            int lead = times[t];

            if (lead < times[t - 1])
                ans += 1; // if lead arrives sooner, it can't be caught
            else
                times[t - 1] = lead; // else, fleet arrives at later time 'lead'
        }

        return ans + (t == 0 ? 1 : 0); //remaining car is fleet(if it exists)
    }
};

int main()
{
    Solution s;

    cout << s.carFleet(12, {10, 8, 0, 6, 2}, {2, 4, 1, 1, 3});
}