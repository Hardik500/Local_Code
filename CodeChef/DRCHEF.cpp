#include <bits/stdc++.h>

using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define int long long

void solve()
{
    int N, x, a;
    cin >> N >> x;

    multiset<int> arr;

    for (size_t i = 0; i < N; i++)
    {
        cin >> a;
        arr.insert(a);
    }

    int noOfDays = 0, temp = 0, smallerCountries = 0;

    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        if (*it < x)
            smallerCountries += 1;
    }

    auto it = arr.begin();

    advance(it, smallerCountries);

    while (it != arr.end())
    {
        while (x < *it)
        {
            x *= 2;
            noOfDays += 1;
        }

        temp = x - *it;
        
        if(temp)
            x = *it;

        noOfDays += 1;
        x *= 2;

        advance(it, 1);
    }

    noOfDays += smallerCountries;

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