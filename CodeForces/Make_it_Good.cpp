#include <bits/stdc++.h>

using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

void solve()
{
    int n, z;
    cin >> n;
    vector<int> a(n);

    for (auto &it : a) cin >> it;

    int pos = n - 1;

    while(pos > 0 and a[pos - 1] >= a[pos]) pos -= 1;
    while(pos > 0 and a[pos - 1] <= a[pos]) pos -= 1;
    cout<<pos<<"\n";
}

int main()
{
    IOS;
    int t = 0;
    cin >> t;

    while (t--)
        solve();
}