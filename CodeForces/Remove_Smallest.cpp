#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, temp;
    cin >> n;

    bool notfound = false;

    vector<int> x;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        x.push_back(temp);
    }

    sort(x.begin(), x.end());

    for (int i = 0; i < n - 1; i++)
    {
        if(x[i + 1] - x[i] > 1){
            notfound = true;
            break;
        }
    }

    if(notfound)
        cout<<"NO\n";
    else
        cout<<"YES\n";


}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}