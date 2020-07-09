#include <bits/stdc++.h>

using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define int long long

void solve()
{
    int k;
    cin >> k;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == 0 and j == 0)
                cout << "O";
            else if (k > 0)
            {
                cout << ".";
            }
            else
                cout << "X";
            k -= 1;
        }
        cout << "\n";
    }
}

int32_t main()
{
    IOS;
    int t;
    cin >> t;

    while (t--)
        solve();
}