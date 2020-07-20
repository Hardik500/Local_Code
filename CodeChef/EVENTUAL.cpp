#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    char x;

    bool done = false;

    vector<int> c(26);

    for (int i = 0; i < n; i++)
    {
        cin>>x;
        c[x - 'a'] += 1;
    }

    for(auto x:c){
        if(x%2){
            cout<<"NO\n";
            done = true;
            break;
        }
    }

    if(not done){
        cout<<"YES\n";
    }
}

int main()
{
    int t;

    cin >> t;

    while (t--)
        solve();
}