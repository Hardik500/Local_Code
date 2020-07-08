#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int s, n;
    cin >> s >> n;

    int noOfCoins = 0;

    if (s == 1)
        noOfCoins = 1;
    else if (n > s)
    {
        if (s % 2)
            noOfCoins = 2;
        else
            noOfCoins = 1;
    }
    else if (n == s)
    {
        if (s % 2)
            noOfCoins = 2;
        else
            noOfCoins = 1;
    }
    else
    {
        noOfCoins = s / n;

        int remainder = s % n;

        if (remainder % 2)
        {
            remainder -= 1;
            noOfCoins += 1;
        }

        if (remainder)
        {
            noOfCoins += 1;
        }
    }

    cout << noOfCoins << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}