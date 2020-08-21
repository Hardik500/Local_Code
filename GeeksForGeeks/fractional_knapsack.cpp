#include <bits/stdc++.h>

using namespace std;

bool comp(pair<double, double> x, pair<double, double> y)
{
    if (x.first / x.second > y.first / y.second)
        return true;
    return false;
}

void solve()
{
    double n, w;
    cin >> n >> w;

    vector<pair<double, double>> z;

    int x, y;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        z.push_back(make_pair(x, y));
    }

    sort(z.begin(), z.end(), comp);

    double v = 0;
    int i = 0;

    while (w > 0 && i < n)
    {
        if (z[i].second <= w)
        {
            v += z[i].first;
            w -= z[i].second;
        }
        else
        {
            double temp = z[i].first * (w / z[i].second);
            v += temp;
            w = 0;
        }

        i += 1;
    }
    cout << round(v * 100) / 100 << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
}