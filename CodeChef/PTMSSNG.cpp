#include <bits/stdc++.h>

using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define int long long

void solve()
{
    int n, x, y;
    cin >> n;

    unordered_map<int, int> rectX, rectY;

    for (int i = 0; i < 4 * n - 1; i++)
    {
        cin >> x >> y;

        if (rectX.find(x) == rectX.end())
            rectX[x] = 1;
        else
        {
            rectX[x] -= 1;
            if (rectX[x] == 0)
            {
                rectX.erase(x);
            }
        }

        if (rectY.find(y) == rectY.end())
            rectY[y] = 1;
        else
        {
            rectY[y] -= 1;
            if (rectY[y] == 0)
            {
                rectY.erase(y);
            }
        }
    }

    cout << rectX.begin()->first << " " << rectY.begin()->first << "\n";
}

int32_t main()
{
    IOS;
    int t;
    cin >> t;

    while (t--)
        solve();
}