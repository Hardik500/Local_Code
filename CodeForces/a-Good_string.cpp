#include <bits/stdc++.h>

using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int calc(const string &s, char c)
{
    if (s.size() == 1)
    {
        return s[0] != c;
    }
    int mid = s.size() / 2;
    int cntl = calc(string(s.begin(), s.begin() + mid), c + 1);
    cntl += s.size() / 2 - count(s.begin() + mid, s.end(), c);
    int cntr = calc(string(s.begin() + mid, s.end()), c + 1);
    cntr += s.size() / 2 - count(s.begin(), s.begin() + mid, c);
    return min(cntl, cntr);
}

void solve()
{
    int n;
    string s;

    cin >> n >> s;

    cout << calc(s, 'a') << endl;
}

int main()
{
    IOS;
    int t = 0;
    cin >> t;

    while (t--)
        solve();
}