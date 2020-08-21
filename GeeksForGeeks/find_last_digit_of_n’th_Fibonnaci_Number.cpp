#include <bits/stdc++.h>

using namespace std;

int febo[61];

void calcfebo()
{
    febo[0] = 0;
    febo[1] = 1;
    for (int i = 2; i < 60; ++i)
        febo[i] = (febo[i - 1] + febo[i - 2]) % 10;
}

int32_t main()
{
    calcfebo();
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        cout<<febo[n % 60]<<"\n";
    }
}