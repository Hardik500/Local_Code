#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    bool found = false;
    int count = 1, i;

    if (n % 2 == 0)
    {
        cout << (n / 2) << " " << (n / 2) << "\n";
    }
    else
    {
        for (i = 3; i < n; i += 2)
        {
            if (n % i == 0)
            {
                found = true;
                break;
            }
            else
            {
                found = false;
            }

            count += 1;
        }

        if (found)
        {
            cout << count * (n / i) << " " << (count + 1) * (n / i) << "\n";
        }
        else
        {
            cout << 1 << " " << (n - 1) << "\n";
        }
    }
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