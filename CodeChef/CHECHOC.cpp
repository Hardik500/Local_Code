#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if (n * m > 1)
        x = min(x, y);
    y = min(y, 2 * x);
    cout << (n * m + 1) / 2 * x + (n * m) / 2 * (y - x) << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}