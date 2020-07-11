#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int p = 3, i = 1;

    while (i <= n)
    {
        cout<<p<<" ";
        i += 1;
    }

    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}