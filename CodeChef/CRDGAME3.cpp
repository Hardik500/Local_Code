#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n1, n2;

    cin >> n1 >> n2;

    int s1 = 1, s2 = 1;

    if (n1 > 9)
    {
        int temp = n1 / 9;
        s1 = temp;

        if (n1 - temp * 9 > 0)
        {
            s1 += 1;
        }
    }

    if (n2 > 9)
    {
        int temp = n2 / 9;
        s2 = temp;

        if (n2 - temp * 9 > 0)
        {
            s2 += 1;
        }
    }

    if (s2 <= s1)
        cout << 1 << " " << s2 << "\n";
    else
        cout << 0 << " " << s1 << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}