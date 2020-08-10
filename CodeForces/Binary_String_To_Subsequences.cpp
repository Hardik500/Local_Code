#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    string arr;

    cin >> arr;

    int c = 0, c0 = 0, c1 = 0;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '0')
        {
            if (c1 > 0)
            {
                v.push_back(c - c0);
                c1--;
                c0++;
            }
            else
            {
                c++;
                v.push_back(c);
                c0++;
            }
        }
        else if (arr[i] == '1')
        {
            if (c0 > 0)
            {
                v.push_back(c1 + 1);
                c0--;
                c1++;
            }
            else
            {
                c++;
                v.push_back(c);
                c1++;
            }
        }
    }

    cout << c << "\n";
    for (int i = 0; i < n; i++)
        cout<<v[i]<<" ";
    cout << "\n";
}

int main()
{
    int t;
    cin.tie();
    cout.tie();
    cin >> t;

    while (t--)
        solve();
}