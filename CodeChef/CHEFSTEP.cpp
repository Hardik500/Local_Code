#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, d;
    cin >> n >> k;
    string x;

    while (n--)
    {
        cin >> d;
        if (d % k)
            x += "0";
        else
            x += "1";
    }

    cout << x << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}