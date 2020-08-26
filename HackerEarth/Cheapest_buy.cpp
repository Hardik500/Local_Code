#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;

    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    int cost = 0;

    unordered_map<int, int> x;

    for (int i = 0; i < n; i++)
        x[i + 1] = 0;

    bool done = false;

    int count = 0;

}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
}