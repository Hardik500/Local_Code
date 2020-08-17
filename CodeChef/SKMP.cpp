#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string x, y, z;
    cin >> x >> y;

    string temp = y;

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int m = x.size();
    int n = y.size();
    int j = 0;

    bool xhere = false;

    for (int i = 0; i < m; i++)
    {
        if (x[i] == y[j])
            j += 1;
        else
            z += x[i];
    }

    string a = "";

    bool filled = false;

    for (int i = 0; i < m - n; i++)
    {
        if(z[i] < temp[0])
            a += z[i];
        else{
            if(z[i] == temp[0]){
                if(z[i + 1] < temp[1])
                    a += z[i];
                else
                    a += temp;
            }
            else
                a += temp;
        }
    }
}

int main()
{
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
        solve();
}