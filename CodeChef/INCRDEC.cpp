#include <bits/stdc++.h>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

void solve()
{
    int n, x, maxOfA = 0;

    cin >> n;

    vector<int> a;

    unordered_map<int, int> hash;

    bool impossible = false;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        maxOfA = max(maxOfA, x);
        a.push_back(x);

        if (hash.find(x) == hash.end())
            hash[x] = 1;
        else
        {
            hash[x] += 1;

            if (hash[x] >= 3)
            {
                impossible = true;
            }
        }
    }

    if (hash[maxOfA] >= 2 || impossible)
        cout << "NO\n";
    else
    {
        cout << "YES\n";

        vector<int> ascending;
        vector<int> descending;

        unordered_map<int, int> asc;

        for (auto x : a)
        {
            if (x != maxOfA)
            {
                if (asc.find(x) == asc.end())
                {
                    asc[x] = 1;
                    ascending.push_back(x);
                }
                else
                {
                    descending.push_back(x);
                }
            }
        }

        sort(ascending.begin(), ascending.end());
        sort(descending.begin(), descending.end(), greater<int>());

        for (auto x : ascending)
            cout << x << " ";
        cout << maxOfA << " ";
        for (auto x : descending)
            cout << x << " ";
        cout<<"\n";
    }
}

int main()
{
    IOS;
    int t;
    cin >> t;

    while (t--)
        solve();
}