#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x, temp;
    cin >> n >> x;

    vector<int> a;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.rbegin(), a.rend());

    int maxNoOfTeams = 0, curr = 1;

    for (auto s : a)
    {
        if (s * curr >= x)
        {
            maxNoOfTeams += 1;
            curr = 0;
        }

        curr += 1;
    }

    cout << maxNoOfTeams << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
}