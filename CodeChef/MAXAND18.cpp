#include <bits/stdc++.h>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define int long long

using namespace std;

bool pro(const pair<int, int> &x, const pair<int, int> &y)
{
    if (x.first == y.first)
        if (x.second < y.second)
            return true;
        else
            return false;
    else if (x.first > y.first)
        return true;
    else
        return false;
}

void solve()
{
    int n, k, x;
    cin >> n >> k;
    vector<pair<int, int>> b(30);

    for (int i = 0; i < 30; i++)
    {
        b[i].first = 0;
        b[i].second = i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        for (int j = 0; j < 30; j++)
        {
            if (x & (1 << j))
                b[j].first += 1 << j;
        }
    }

    sort(b.begin(), b.end(), pro);

    int ans = 0;

    for (int i = 0; i < k; i++)
        ans += 1 << b[i].second;

    cout << ans << "\n";
}

int32_t main()
{
    IOS;
    int t;
    cin >> t;

    while (t--)
        solve();
}