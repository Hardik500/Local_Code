#include <bits/stdc++.h>

using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define int long long

void solve()
{
    int N, X, x, a;
    cin >> N >> X;
    x = X;

    multiset<int> arr;

    for (size_t i = 0; i < N; i++)
    {
        cin >> a;
        arr.insert(a);
    }

    int noOfDays = 0;

    auto it = arr.begin();

    while (it != arr.end())
    {
        while (x < *it)
        {
            x *= 2;
            noOfDays += 1;
        }

        x = max(X, 2 * (*it)); // keep X ( the one from input ) unchanged.
        noOfDays++;

        advance(it, 1);
    }

    cout << noOfDays << "\n";
}

int32_t main()
{
    IOS;
    int t;
    cin >> t;

    while (t--)
        solve();
}