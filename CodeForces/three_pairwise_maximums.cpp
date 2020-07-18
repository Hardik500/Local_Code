#include <bits/stdc++.h>

using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

void solve()
{
    long long int x, y, z;

    cin >> x >> y >> z;
    long long int maximum = max(x, max(y, z));
    long long int minimum = min(x, min(y, z));

    int count = 0;

    if(x == maximum)
        count += 1;
    if(y == maximum)
        count += 1;
    if(z == maximum)
        count += 1;

    if (count>=2)
    {
        cout << "YES\n";
        cout << minimum << " " << minimum << " " << maximum << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    IOS;
    int t = 0;
    cin >> t;

    while (t--)
        solve();
}