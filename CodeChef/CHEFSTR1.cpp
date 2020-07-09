#include <bits/stdc++.h>

using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define int long long

int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0, S = 0, prev = -1, sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> S;
            if (prev != -1)
            {
                if (prev > S)
                {
                    sum += prev - S - 1;
                }
                else if(prev < S)
                {
                    sum += S - prev - 1;
                }
            }
            prev = S;
        }

        cout << sum << "\n";
    }
}